// *************************************
// Voyager Infrastructure - gXServer
// 'MemoryManager.cxx'
// Author: Juan Carlos Juárez
// Contact: jc.juarezgarcia@outlook.com
// *************************************

#include <stdexcept>

#include "MemoryManager.h"

namespace gX {

    MemoryManager::MemoryManager() {

        ClaimMemoryBlock();

    }

    void MemoryManager::ClaimMemoryBlock() {

        m_MemoryBlockStartingAddress = nullptr;

        try {
            
            m_MemoryBlockStartingAddress = std::malloc(static_cast<size_t>(Numerics::c_MemoryClaimSizeGiB));

            if (m_MemoryBlockStartingAddress == nullptr) {
                throw std::bad_alloc();
            }

            // Memory Block claimed successfully.
        }
        catch (const std::bad_alloc& e) {
            
            throw std::runtime_error("<!> gXServer Error: Failed to claim initial Memory Block.");

        }

    }

    MemoryAddress MemoryManager::AllocateMemory(const Byte* p_ByteArray, UInt64 p_ByteArraySize) {

        // Cast the the starting address to a byte pointer.
        Byte* initialMemoryAddressOffset = static_cast<Byte*>(m_MemoryBlockStartingAddress);

        for (UInt64 byteIndex = 0; byteIndex < p_ByteArraySize; ++byteIndex, ++p_ByteArray) {
            initialMemoryAddressOffset[byteIndex] = Byte(*(p_ByteArray));
        }

        return static_cast<MemoryAddress>(initialMemoryAddressOffset);

    }

} // namespace gX.
