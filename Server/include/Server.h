#pragma once

#include <boost/asio.hpp>
#include <Acceptor.h>
#include <ServerConfig.h>
#include <IoThread.h>
#include <ServerStatus.h>

class Server {
private:
    using tcp = boost::asio::ip::tcp;

    boost::asio::io_context io_context_;
    IoThread io_thread_;
    ServerConfig cfg_;
    Acceptor acceptor_;
    ServerStatus server_status_;

public:
    explicit Server();
    ~Server();

    void start();
    void stop();
};
