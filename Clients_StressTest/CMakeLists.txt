cmake_minimum_required(VERSION 3.31)
project(Clients_StressTest)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fsanitize=thread -g -O1")

add_executable(Clients_StressTest main.cpp
        src/StressTest.cpp
        include/StressTest.h
        include/ServerData.h
        src/ConnectionManager.cpp
        include/ConnectionManager.h
)

find_package(boost_asio CONFIG REQUIRED)

target_link_libraries(Clients_StressTest PRIVATE Boost::asio)

target_include_directories(Clients_StressTest PRIVATE include)