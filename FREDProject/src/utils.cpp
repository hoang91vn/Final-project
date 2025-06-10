#include "utils.hpp"
#include <deque>
#include <numeric>
#include <sstream>
#include <iomanip>
#include <ctime>
#include <chrono>

namespace utils {
std::vector<double> moving_average(const std::vector<double>& data, size_t window) {
    std::vector<double> result;
    std::deque<double> dq;
    double sum=0;
    for(double v: data) {
        dq.push_back(v);
        sum += v;
        if(dq.size()>window) { sum -= dq.front(); dq.pop_front(); }
        result.push_back(sum / dq.size());
    }
    return result;
}

std::string add_days(const std::string& date, int days) {
    std::tm tm = {};
    std::istringstream ss(date);
    ss >> std::get_time(&tm, "%Y-%m-%d");
    auto tp = std::chrono::system_clock::from_time_t(std::mktime(&tm));
    tp += std::chrono::hours(days*24);
    std::time_t tt = std::chrono::system_clock::to_time_t(tp);
    std::tm tm2 = *std::gmtime(&tt);
    char buf[11];
    std::strftime(buf, sizeof(buf), "%Y-%m-%d", &tm2);
    return buf;
}
}
