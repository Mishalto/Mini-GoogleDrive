cmake_minimum_required(VERSION 3.31)
project(Client)

set(CMAKE_CXX_STANDARD 20)

add_executable(Client main.cpp
        src/Client.cpp
        src/IoThread.cpp
        src/Logger.cpp)

find_package(boost_asio CONFIG REQUIRED)

target_link_libraries(Client PRIVATE Boost::asio)

target_include_directories(Client PRIVATE include)