#include <ConnectionManager.h>
#include <iostream>
#include <mutex>

ConnectionManager::ConnectionManager()
    : limit_(0),
      successful_attempts_(),
      failed_attempts_() {
}

void ConnectionManager::add_failed() {
    std::lock_guard<std::mutex> locker(sync_mutex);
    ++failed_attempts_;
}

void ConnectionManager::add_success() {
    std::lock_guard<std::mutex> locker(sync_mutex);
    ++successful_attempts_;
}

size_t ConnectionManager::failed_attempts() const {
    return failed_attempts_;
}

size_t ConnectionManager::successful_attempts() const {
    return successful_attempts_;
}

size_t ConnectionManager::get_limit() const {
    return limit_;
}


void ConnectionManager::info() const {
    std::cout << limit_ << ": "
            << successful_attempts_ << " / " << failed_attempts_ << std::endl;
}

void ConnectionManager::init_limit() {
    if (!limit_) {
        std::cout << "Number of connections: ";
        std::cin >> limit_;
    }
}
