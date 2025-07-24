#pragma once
#include <memory>
#include <boost/asio.hpp>

class Session : public std::enable_shared_from_this<Session> {
private:
    using tcp = boost::asio::ip::tcp;
    std::shared_ptr<tcp::socket> socket_;

public:
    explicit Session(std::shared_ptr<tcp::socket> socket);

    ~Session();

    void start() const;
};
