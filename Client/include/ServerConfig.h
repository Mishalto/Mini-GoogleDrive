#pragma once
#include <string_view>
#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/ip/address.hpp>

namespace ServerConfig {
    constexpr std::string_view ip_addr = "127.0.0.1";
    constexpr unsigned short port = 12345;

    namespace Endpoint {
        const boost::asio::ip::tcp::endpoint endpoint(boost::asio::ip::make_address(ip_addr), port);
    }
}