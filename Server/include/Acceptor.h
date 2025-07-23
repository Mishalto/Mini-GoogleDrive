#pragma once

#include <boost/asio.hpp>
#include <ServerConfig.h>

class Acceptor {
private:
    using tcp = boost::asio::ip::tcp;

    boost::asio::io_context& io_context_;
    tcp::endpoint endpoint_;
    tcp::acceptor acceptor_;

public:
    explicit Acceptor(boost::asio::io_context& io_context, const ServerConfig& cfg);

    void start_accept();
};
