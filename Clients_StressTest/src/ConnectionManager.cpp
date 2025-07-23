#include <ConnectionManager.h>
#include <iostream>
#include <mutex>

ConnectionManager::ConnectionManager()
    : max_connections_(),
      successful_connections_(),
      failed_connections_() {
}

void ConnectionManager::add_failed() {
    std::lock_guard<std::mutex> locker(sync_mutex);
    ++failed_connections_;
}

void ConnectionManager::add_success() {
    std::lock_guard<std::mutex> locker(sync_mutex);
    ++successful_connections_;
}

size_t ConnectionManager::failed_attempts() const {
    return failed_connections_;
}

size_t ConnectionManager::successful_attempts() const {
    return successful_connections_;
}

size_t ConnectionManager::max_connections() const {
    return max_connections_;
}


void ConnectionManager::info() const {
    std::cout << max_connections_ << ": "
            << successful_connections_ << " / " << failed_connections_ << std::endl;
}

void ConnectionManager::init_max_connections() {
    std::cout << "Number of connections: ";
    std::cin >> max_connections_;
}

