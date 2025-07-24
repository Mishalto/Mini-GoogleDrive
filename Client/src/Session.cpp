#include <Session.h>
#include <Logger.h>

Session::Session(std::shared_ptr<tcp::socket> socket)
    : socket_(std::move(socket)) {
    Logger::log("Session initialized.");
}

Session::~Session() {
    Logger::log("Session ended.");
}

void Session::start() const {
    auto self = shared_from_this();
    Logger::log("Session started.");
    Logger::log(socket_->remote_endpoint().address().to_string());
}
