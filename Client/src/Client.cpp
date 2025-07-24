#include <Client.h>
#include <iostream>
#include <ServerConfig.h>

#include <Logger.h>

Client::Client()
    : io_context_(),
      io_thread_(io_context_),
      socket_(io_context_) {
    Logger::log("Client initialized.");
    Logger::log("Connect to: ", ServerConfig::ip_addr,
                ":", std::to_string(ServerConfig::port));
}

Client::~Client() {
    io_thread_.io_stop();
    Logger::log("Session ended.");
}

void Client::connect() {
    socket_.async_connect(ServerConfig::Endpoint::endpoint, [](const boost::system::error_code& err) {
        if (!err) {
            Logger::log("Connected.");
        } else {
            Logger::error(err.message());
        }
    });
}

void Client::start() {
    Logger::log("Session started.");
    connect();
    io_thread_.io_run();
}
