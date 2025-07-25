#pragma once

#include <string_view>

class Logger {
private:
    Logger() = default;

public:
    static void log(const std::string_view log_info, const std::string_view log_info_2 = "",
                    const std::string_view log_info_3 = "");

    static void error(std::string_view error);
};

