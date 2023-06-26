// *************************************
// Voyager Infrastructure - gXServer
// 'Constants.h'
// Author: Juan Carlos Juárez
// Contact: jc.juarezgarcia@outlook.com
// *************************************

#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <string>

namespace gX {

    // Alias Types.

    // Unsigned 64 bits.
    using UInt64 = unsigned long long;

    // Unsigned 32 bits.
    using UInt32 = unsigned int;

    // Unsigned 16 bits.
    using UInt16 = unsigned short;

    // Unsigned 8 bits.
    using UInt8 = unsigned char;

    // Signed 64 bits.
    using Int64 = long long;

    // Signed 32 bits.
    using Int32 = int;

    // Signed 16 bits.
    using Int16 = short;

    // Signed 8 bits.
    using Int8 = char;
    using Byte = char;

    // Pointer to memory address.
    using MemoryAddress = void*;

    // Status Code alias.
    using StatusCode = UInt32;

    class StatusCodes {

        private:

            // Static class.
            StatusCodes() = delete;

        // Status Codes Constants.
        public:

            // Default successful status code.
            static inline constexpr StatusCode c_Success {0};

    };

    class Numerics {

        private:

            // Static class.
            Numerics() = delete;

        // Numeric Constants.
        public:

            // Number of threads for the Query Handler thread pool to spawn.
            static inline constexpr UInt32 c_QueryHandlerThreadPoolSize {100};

            // Size of memory for the gXServer to claim from the node in GiB.
            static inline constexpr UInt64 c_MemoryClaimSizeGiB {1024LL * 1024LL * 1024LL * 6LL};

    };

    class Text {

        private:

            // Static class.
            Text() = delete;

        // Text Constants.
        public:

            // String literal for TCP port binding.
            static inline const char* c_TCPPortBinding {"tcp://*:5555"};

            // String literal for thread pool binding.
            static inline const char* c_ThreadPoolBinding {"inproc://workers"};

            // Inbound command for allocating a memory chunk with defined size in bytes.
            static inline constexpr std::string_view c_AllocateMemoryCmd {"ALLOC"};

    };

} // namespace gX.

#endif