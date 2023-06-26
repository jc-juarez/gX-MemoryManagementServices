// *************************************
// Voyager Infrastructure - gXServer
// 'MemoryQueryHandler.cxx'
// Author: Juan Carlos Juárez
// Contact: jc.juarezgarcia@outlook.com
// *************************************

#include <thread>
#include <string>
#include <sstream>
#include <iostream>

// #include <rocksdb/db.h>

#include "MemoryQueryHandler.h"

namespace gX {

    MemoryQueryHandler::MemoryQueryHandler(std::unique_ptr<MemoryManager> p_MemoryManager) {

        m_MemoryManager = std::move(p_MemoryManager);

        m_ZeroMQContext = zmq::context_t(1);
        m_FrontendSocket = zmq::socket_t(m_ZeroMQContext, zmq::socket_type::router);
        m_BackendSocket = zmq::socket_t(m_ZeroMQContext, zmq::socket_type::dealer);

        m_FrontendSocket.bind(Text::c_TCPPortBinding);
        m_BackendSocket.bind(Text::c_ThreadPoolBinding);

        m_AcceptedCommands.insert(Text::c_AllocateMemoryCmd);

    }

    void MemoryQueryHandler::Start() {

        // Initialize thread pool.
        for (UInt32 thread_id = 0; thread_id < Numerics::c_QueryHandlerThreadPoolSize; ++thread_id) {
            std::thread HandleQueryTask(&MemoryQueryHandler::HandleQuery, this, std::ref(m_ZeroMQContext), thread_id);
            HandleQueryTask.detach();
        }

        zmq::proxy(m_FrontendSocket, m_BackendSocket, nullptr);

    }

    void MemoryQueryHandler::Reply(const MemoryAddress p_pMemoryAddressPointer, zmq::socket_t* p_Socket) {

        std::stringstream memoryAddressFormatter;
        memoryAddressFormatter << p_pMemoryAddressPointer;

        std::string memoryAddressString {memoryAddressFormatter.str()};

        zmq::message_t reply(memoryAddressString.size());
        memcpy(reply.data(), memoryAddressString.data(), memoryAddressString.size());

        (*p_Socket).send(reply);

    }

    void MemoryQueryHandler::HandleQuery(zmq::context_t& p_ZeroMQContext, int p_ThreadId) {

        zmq::socket_t socket(p_ZeroMQContext, zmq::socket_type::rep);
        socket.connect(Text::c_ThreadPoolBinding);

        while (true) {

            zmq::message_t request;
            socket.recv(request);

            UInt64 byteArraySize = static_cast<UInt64>(request.size());
            const Byte* byteArray = static_cast<const Byte*>(request.data());

            MemoryAddress allocationMemoryAddress = (*GetMemoryManager())->AllocateMemory(byteArray, byteArraySize);

            Reply(allocationMemoryAddress, &socket);

        }

    }

    std::unique_ptr<MemoryManager>* MemoryQueryHandler::GetMemoryManager() {

        return &(m_MemoryManager);

    }

} // namespace gX.
