#pragma once

#include <atomic>

class ServerStatus {
    std::atomic<bool> is_running_;

public:
    ServerStatus() = default;

    void start_server();

    void stop_server();

    [[nodiscard]] bool is_running() const;

    [[nodiscard]] bool is_stopped() const;
};
