#pragma once

#include <boost/asio.hpp>

#include <IoThread.h>

class Client {
private:
    using tcp = boost::asio::ip::tcp;

    boost::asio::io_context io_context_;
    IoThread io_thread_;

    void connect();

public:
    explicit Client();

    ~Client();

    void start();
};
