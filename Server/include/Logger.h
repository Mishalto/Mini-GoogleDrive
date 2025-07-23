#pragma once

#include <string_view>

class Logger {
private:
    Logger() = default;

public:
    static void log(std::string_view log_info, std::string_view log_info_2 = "");
    static void error(std::string_view error);
};
