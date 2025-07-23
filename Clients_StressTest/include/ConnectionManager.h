#pragma once

#include <mutex>
#include <stddef.h>

class ConnectionManager {
private:
    size_t max_connections_;
    size_t successful_connections_;
    size_t failed_connections_;

    std::mutex sync_mutex;
public:
    ConnectionManager();

    [[nodiscard]] size_t successful_attempts() const;
    [[nodiscard]] size_t failed_attempts() const;
    [[nodiscard]] size_t max_connections() const;

    void init_max_connections();

    void add_success();
    void add_failed();

    void info() const;
};
