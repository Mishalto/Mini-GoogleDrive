#include <StressTest.h>

#include <ServerData.h>
#include <iostream>

StressTest::StressTest()
    : server_(boost::asio::ip::make_address_v4(Server::address), Server::port),
      connection_manager_() {
    connection_manager_.init_max_connections();
}

void StressTest::connect() {
    auto socket = std::make_shared<tcp::socket>(io_context_);
    socket->async_connect(server_, [socket, this](const boost::system::error_code& err) {
        if (!err) {
            connection_manager_.add_success();
        } else {
            connection_manager_.add_failed();
        }

        if (connection_manager_.successful_attempts() + connection_manager_.failed_attempts() >= connection_manager_.max_connections()) {
            io_context_.stop();
        }
    });
}


void StressTest::start_test() {
    const size_t max_connections = connection_manager_.max_connections();
    for (size_t i = 0; i < max_connections; ++i) {
        connect();
    }

    std::vector<std::thread> pool;
    for (size_t i = 0; i < 4; ++i) {
        pool.emplace_back([this]() {
            io_context_.run();
        });
    }

    for (auto& t : pool) {
        t.join();
    }

    connection_manager_.info();
}
