#include <ServerConfig.h>
#include <Logger.h>

ServerConfig::ServerConfig()
    : port(12345), protocol(tcp::v4()) {
    Logger::log("Server config ready.");
}

int ServerConfig::get_port() const {
    return port;
}

const ServerConfig::tcp &ServerConfig::get_protocol() const {
    return protocol;
}

