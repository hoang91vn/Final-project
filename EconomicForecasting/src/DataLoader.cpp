#include "ef/DataLoader.hpp"
#include <fstream>
#include <sstream>

namespace ef {

TimeSeries DataLoader::loadCSV(const std::string& path) {
    std::ifstream file(path);
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open file: " + path);
    }
    TimeSeries ts;
    std::string line;
    // skip header
    std::getline(file, line);
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string dateStr, valueStr;
        if (!std::getline(ss, dateStr, ',')) continue;
        if (!std::getline(ss, valueStr)) continue;
        ts.dates.push_back(Date::parse(dateStr));
        ts.values.push_back(std::stod(valueStr));
    }
    return ts;
}

} // namespace ef
