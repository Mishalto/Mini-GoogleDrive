#include <IoThread.h>

IoThread::IoThread(boost::asio::io_context& io_context)
    : io_context_(io_context) {
}

void IoThread::io_run() {
    io_thread_ = std::thread([this]() {
        io_context_.run();
    });
}

void IoThread::io_stop() {
    io_context_.stop();
    if (io_thread_.joinable()) {
        io_thread_.join();
    }
};
