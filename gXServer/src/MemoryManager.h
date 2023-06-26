// *************************************
// Voyager Infrastructure - gXServer
// 'MemoryManager.h'
// Author: Juan Carlos Juárez
// Contact: jc.juarezgarcia@outlook.com
// *************************************

#ifndef MEMORY_MANAGER_
#define MEMORY_MANAGER_

#include <list>

#include "Constants.h"

namespace gX {

    class MemoryManager {

        public:

            // MemoryManager constructor.
            MemoryManager();

        public:

            // Claims initial memory block of defined size.
            void ClaimMemoryBlock();

            // Allocates memory chunk for a byte array of defined size.
            MemoryAddress AllocateMemory(const Byte* p_ByteArray, UInt64 p_ByteArraySize);

        private:

            // Handle to the first memory address of the node's claimed memory.
            MemoryAddress m_MemoryBlockStartingAddress;

            // Container that stores all Memory Blade Vectors for the given node.
            // std::list<std::unique_ptr<MemoryBladeVector>> m_MemoryBladeVectorContainer;

    };

} // namespace gX.

#endif
