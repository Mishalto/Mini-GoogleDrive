#include <Server.h>
#include <Logger.h>
#include <Acceptor.h>

Server::Server()
    : io_thread_(io_context_),
      acceptor_(io_context_, cfg_),
      server_status_() {
    Logger::log("Server started.");
    server_status_.start_server();
}

Server::~Server() {
    stop();
    Logger::log("Server stopped.");
}

void Server::start() {
    acceptor_.start_accept();
    io_thread_.io_run();
}

void Server::stop() {
    if (server_status_.is_running()) {
        server_status_.stop_server();
        io_thread_.io_stop();
    }
}
