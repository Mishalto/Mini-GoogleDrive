#include <Logger.h>

#include <iostream>

void Logger::log(const std::string_view log_info, const std::string_view log_info_2) {
    std::cout << log_info << log_info_2 << std::endl;
}

void Logger::error(const std::string_view error) {
    std::cerr << error << std::endl;
}