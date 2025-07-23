#pragma once

#include <boost/asio.hpp>
#include <ConnectionManager.h>

// StressTest is a class designed to perform high-load testing of a server,
// simulating up to 28 000 concurrent connections.
// It uses the ConnectionManager class to manage connection attempts and track statistics,
// including counts of successful and failed connections.

class StressTest {
private:
    using tcp = boost::asio::ip::tcp;

    boost::asio::io_context io_context_;

    // ServerData endpoint changes:
    // Default: 127.0.0.1:12345 (configurable in ServerData.h)
    tcp::endpoint server_;

    // Tracks connection attempts and results.
    ConnectionManager connection_manager_;

    // Initiates a single asynchronous connection as part of the stress test.
    void connect();

public:
    // The constructor initializes class fields by standard—each one explicitly
    // Then, it requests the planned connection count.
    StressTest();

    // Starts the stress test: creates all connections and runs the I/O event loop using 4 threads.
    void start_test();
};