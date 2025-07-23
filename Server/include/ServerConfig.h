#pragma once

#include  <boost/asio.hpp>

class ServerConfig {
private:
    using tcp = boost::asio::ip::tcp;
    unsigned short port;
    tcp protocol;

public:
    ServerConfig();

    [[nodiscard]] int get_port() const;

    [[nodiscard]] const tcp &get_protocol() const;
};
