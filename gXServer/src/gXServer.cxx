// *************************************
// Voyager Infrastructure - gXServer
// 'gXServer.cxx'
// Author: Juan Carlos Juárez
// Contact: jc.juarezgarcia@outlook.com
// *************************************

#include "gXServer.h"
#include "MemoryManager.h"

namespace gX {

    gXServer::gXServer() {
        
        std::unique_ptr<MemoryManager> memoryManager = std::make_unique<gX::MemoryManager>();
        m_MemoryQueryHandler = std::make_unique<gX::MemoryQueryHandler>(std::move(memoryManager));

    }

    void gXServer::Run() {

        m_MemoryQueryHandler->Start();

        // Run forever
        for(;;) {}

    }

} // namespace gX.
