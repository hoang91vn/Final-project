#include "forecast.hpp"
#include <numeric>
#include <limits>

std::vector<double> forecast_sma(const std::vector<double>& series, size_t window, size_t steps) {
    std::vector<double> data(series.begin(), series.end());
    std::vector<double> result;
    for(size_t s=0; s<steps; ++s) {
        size_t start = data.size()>window ? data.size()-window : 0;
        double sum=0; size_t count=0;
        for(size_t i=start;i<data.size();++i){ sum+=data[i]; ++count; }
        double val = count? sum/count : std::numeric_limits<double>::quiet_NaN();
        data.push_back(val);
        result.push_back(val);
    }
    return result;
}

std::vector<double> forecast_exp(const std::vector<double>& series, double alpha, size_t steps) {
    if(series.empty()) return {};
    double s = series[0];
    for(size_t i=1;i<series.size();++i) s = alpha*series[i] + (1-alpha)*s;
    std::vector<double> result(steps, s);
    return result;
}
