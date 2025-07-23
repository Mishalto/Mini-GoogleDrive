cmake_minimum_required(VERSION 3.31)
project(Server)

set(CMAKE_CXX_STANDARD 20)

add_executable(Server main.cpp
        src/Server.cpp
        src/Logger.cpp
        src/Acceptor.cpp
        src/Session.cpp
        src/ServerConfig.cpp
        src/IoThread.cpp
        src/ServerStatus.cpp
        include/ServerStatus.h
)

find_package(boost_asio CONFIG REQUIRED)

target_link_libraries(Server PRIVATE Boost::asio)

target_include_directories(Server PRIVATE include)