#pragma once
#include <vector>
#include <string>

namespace utils {
std::vector<double> moving_average(const std::vector<double>& data, size_t window);
std::string add_days(const std::string& date, int days);
}
