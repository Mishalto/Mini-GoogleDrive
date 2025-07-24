#pragma once
#include <string_view>

namespace Server {
    constexpr std::string_view address = "127.0.0.1";
    constexpr unsigned short port = 12345;
}

namespace ThreadPool {
    constexpr u_int8_t thread_count = 4;
}