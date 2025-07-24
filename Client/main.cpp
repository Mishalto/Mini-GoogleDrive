#include <boost/asio.hpp>
#include <iostream>

#include "Client.h"

int main() {
    Client client;
    client.start();

    std::cin.get();

    return 0;
}
