#pragma once

#include <memory>
#include <boost/asio.hpp>

class Session {
private:
    using tcp = boost::asio::ip::tcp;

    std::shared_ptr<tcp::socket> socket_;

public:
    explicit Session(std::shared_ptr<tcp::socket> socket);

    void info() const;
};
