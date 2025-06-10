#ifndef EF_DATA_STRUCTURES_HPP
#define EF_DATA_STRUCTURES_HPP

#include <string>
#include <vector>
#include <stdexcept>
#include <sstream>
#include <iomanip>

namespace ef {

struct Date {
    int year{0}, month{0}, day{0};
    static Date parse(const std::string& str) {
        Date d;
        if (str.size() != 10 || str[4] != '-' || str[7] != '-') {
            throw std::runtime_error("Invalid date format");
        }
        d.year = std::stoi(str.substr(0,4));
        d.month = std::stoi(str.substr(5,2));
        d.day = std::stoi(str.substr(8,2));
        return d;
    }
    std::string to_string() const {
        std::ostringstream oss;
        oss << std::setfill('0') << std::setw(4) << year << '-'
            << std::setw(2) << month << '-' << std::setw(2) << day;
        return oss.str();
    }
};

struct TimeSeries {
    std::vector<Date> dates;
    std::vector<double> values;
};

} // namespace ef

#endif
