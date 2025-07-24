#pragma once

#include <boost/asio.hpp>

#include <IoThread.h>

class Client {
private:
    using tcp = boost::asio::ip::tcp;

    boost::asio::io_context io_context_;
    IoThread io_thread_;
    tcp::socket socket_;

    void connect();
public:
    Client();
    ~Client();

    void start();
};
