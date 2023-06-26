// *************************************
// Voyager Infrastructure - gXServer
// 'MemoryQueryHandler.h'
// Author: Juan Carlos Juárez
// Contact: jc.juarezgarcia@outlook.com
// *************************************

#ifndef MEMORY_QUERY_HANDLER_
#define MEMORY_QUERY_HANDLER_

#include <memory>
#include <unordered_set>

#include <zmq.hpp>

#include "Constants.h"
#include "MemoryManager.h"

namespace gX {

    class MemoryQueryHandler {

        public:

            // MemoryQueryHandler constructor.
            MemoryQueryHandler(std::unique_ptr<gX::MemoryManager> p_MemoryManager);

        public:

            // Start query handling thread pool.
            void Start();

            // Reply to a memory query with an array of bytes.
            void Reply(const MemoryAddress p_pMemoryAddressPointer, zmq::socket_t* p_Socket);

            // Method for handling and processing inbound memory-related queries.
            void HandleQuery(zmq::context_t& p_ZeroMQContext, int p_ThreadId);

            // Getter for the Memory Manager handle.
            std::unique_ptr<gX::MemoryManager>* GetMemoryManager();

        private:

            // Handle to main MemoryManager reference.
            std::unique_ptr<gX::MemoryManager> m_MemoryManager;

            // ZeroMQ context type for IPC.
            zmq::context_t m_ZeroMQContext;

            // ZeroMQ Frontend socket. This will bind to the TCP 
            // routing mechanism for inbound requests.
            zmq::socket_t m_FrontendSocket;

            // ZeroMQ Backend socket. This will bind to the in-process 
            // thread pool for query handling.
            zmq::socket_t m_BackendSocket;

            // Set of accepted gXServer command for accepting or denying a query.
            std::unordered_set<std::string_view> m_AcceptedCommands;

    };

} // namespace gX.

#endif
