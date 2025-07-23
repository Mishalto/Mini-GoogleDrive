#pragma once

#include <boost/asio.hpp>
#include <ConnectionManager.h>

class StressTest {
private:
    using tcp = boost::asio::ip::tcp;

    boost::asio::io_context io_context_;
    tcp::endpoint server_;
    ConnectionManager connection_manager_;

    void connect();
public:
    StressTest();

    void start_test();
};