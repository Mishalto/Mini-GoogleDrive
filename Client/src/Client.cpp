#include <Client.h>
#include <iostream>
#include <ServerConfig.h>

#include <Logger.h>

#include "Session.h"

Client::Client()
    : io_context_(),
      io_thread_(io_context_) {
    Logger::log("Client initialized.");
    Logger::log("Connect to: ", ServerConfig::ip_addr,
                ":", std::to_string(ServerConfig::port));
}

Client::~Client() {
    io_thread_.io_stop();
    Logger::log("Client destructed");
}

void Client::connect() {
    auto socket = std::make_shared<tcp::socket>(io_context_);
    socket->async_connect(ServerConfig::Endpoint::endpoint, [socket](const auto& err) {
        if (!err) {
            Logger::log("Connected.");
            const auto session = std::make_shared<Session>(socket);
            session->start();
        } else {
            Logger::error(err.message());
        }
    });
}

void Client::start() {
    connect();
    io_thread_.io_run();
}