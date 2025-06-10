#include "ef/Evaluator.hpp"
#include <cmath>

namespace ef {

double Evaluator::rmse(const std::vector<double>& actual, const std::vector<double>& pred) {
    double sum = 0.0;
    for (size_t i=0;i<actual.size();++i) {
        double diff = actual[i] - pred[i];
        sum += diff*diff;
    }
    return std::sqrt(sum / actual.size());
}

double Evaluator::mape(const std::vector<double>& actual, const std::vector<double>& pred) {
    double sum = 0.0;
    for (size_t i=0;i<actual.size();++i) {
        if (actual[i] != 0)
            sum += std::abs((actual[i]-pred[i]) / actual[i]);
    }
    return sum / actual.size() * 100.0;
}

} // namespace ef
