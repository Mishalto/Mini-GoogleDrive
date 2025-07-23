#pragma once

#include <atomic>
#include <thread>
#include <boost/asio.hpp>

class IoThread {
private:
    boost::asio::io_context& io_context_;
    std::thread io_thread_;

public:
    explicit IoThread(boost::asio::io_context& io_context);

    void io_run();

    void io_stop();
};