// *************************************
// Voyager Infrastructure - gXServer
// 'gXServer.h'
// Author: Juan Carlos Juárez
// Contact: jc.juarezgarcia@outlook.com
// *************************************

#ifndef GX_SERVER_
#define GX_SERVER_

#include <memory>

// #include <rocksdb/db.h>

#include "MemoryQueryHandler.h"

namespace gX {

    class gXServer {

        public:

            // gXServer constructor.
            gXServer();

        public:

            // Runs gXServer.
            void Run();

        private:

            // Query Handler Manager handle for handling incoming queries.
            std::unique_ptr<gX::MemoryQueryHandler> m_MemoryQueryHandler;

    };

} // namespace gX.

#endif
