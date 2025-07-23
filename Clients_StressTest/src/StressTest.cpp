#include <StressTest.h>

#include <ServerData.h>
#include <iostream>

StressTest::StressTest()
    : io_context_(),
      server_(boost::asio::ip::make_address_v4(Server::address), Server::port),
      connection_manager_() {
    // Reads and sets the maximum number of connections from user input.
    connection_manager_.init_limit();
}

void StressTest::connect() {
    auto socket = std::make_shared<tcp::socket>(io_context_);
    socket->async_connect(server_, [socket, this](const boost::system::error_code& err) {
        // On success, the connection count increments
        // On failure, the failed count increases
        if (!err) {
            connection_manager_.add_success();
        } else {
            connection_manager_.add_failed();
        }

        // Stop the loop when total attempts reach the planned connection count.
        // There's a risk of inconsistency due to sequential calls
        // Consider moving io_context_.stop() to the destructor.
        const size_t total_attempts = connection_manager_.successful_attempts()
                                      + connection_manager_.failed_attempts();
        if (total_attempts >= connection_manager_.get_limit()) {
            io_context_.stop();
        }
    });
}


void StressTest::start_test() {
    const size_t max_connections = connection_manager_.get_limit();

    // Initiate all connection attempts asynchronously.
    for (size_t i = 0; i < max_connections; ++i) {
        connect();
    }

    std::vector<std::thread> pool;
    pool.reserve(4);

    // Create a thread pool of 4 threads to run the io_context event loop.
    // Maybe later need fix magic number
    for (size_t i = 0; i < 4; ++i) {
        pool.emplace_back([this]() {
            io_context_.run();
        });
    }

    // Wait for all threads to finish processing.
    for (auto& t: pool) {
        t.join();
    }

    // Output connection statistics.
    connection_manager_.info();
}
