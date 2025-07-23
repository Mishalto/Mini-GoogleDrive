#pragma once

#include <mutex>
#include <stddef.h>

// Class responsible for managing connection limits and tracking statistics
class ConnectionManager {
private:
    size_t limit_;
    size_t successful_attempts_;
    size_t failed_attempts_;

    std::mutex sync_mutex;

public:
    ConnectionManager();

    // Getters
    [[nodiscard]] size_t successful_attempts() const;
    [[nodiscard]] size_t failed_attempts() const;
    [[nodiscard]] size_t get_limit() const;

    // Initializes the maximum number of connection from user input
    void init_limit();

    // Increments the count of successful connections (thread-safe)
    void add_success();

    // Increments the count of failed connections (thread-safe)
    void add_failed();

    // Prints information about current connection statistics and limits
    void info() const;
};
