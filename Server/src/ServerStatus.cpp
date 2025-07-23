#include <ServerStatus.h>

void ServerStatus::start_server() {
    is_running_ = true;
}

void ServerStatus::stop_server() {
    is_running_ = false;
}

bool ServerStatus::is_running() const {
    return is_running_;
}

bool ServerStatus::is_stopped() const {
    return !is_running_;
}