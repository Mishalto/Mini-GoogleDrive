#include <Session.h>
#include <Logger.h>

Session::Session(std::shared_ptr<tcp::socket> socket)
    : socket_(std::move(socket)) {
    Logger::log("Someone started connecting");
}

void Session::info() const {
    const std::string client_addr = socket_->remote_endpoint().address().to_string();
    Logger::log("Connected from ", client_addr);
}
