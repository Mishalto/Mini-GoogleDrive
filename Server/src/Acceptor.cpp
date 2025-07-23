#include <Acceptor.h>
#include <Logger.h>
#include <Session.h>

Acceptor::Acceptor(boost::asio::io_context& io_context, const ServerConfig& cfg)
    : io_context_(io_context),
      endpoint_(cfg.get_protocol(), cfg.get_port()),
      acceptor_(io_context, endpoint_) {
    Logger::log("Acceptor ready: port ", std::to_string(cfg.get_port()));
}

void Acceptor::start_accept() {
    auto socket = std::make_shared<tcp::socket>(io_context_);
    Logger::log("Waiting client...");
    acceptor_.async_accept(*socket, [this, socket](const boost::system::error_code& err) {
        if (!err) {
            const auto session = std::make_shared<Session>(socket);
            session->info();
        } else {
            Logger::error(err.message());
        }
        start_accept();
    });
}
