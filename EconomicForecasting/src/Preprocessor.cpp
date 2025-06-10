#include "ef/Preprocessor.hpp"
#include <cmath>
#include <algorithm>
#include <numeric>

namespace ef {

void Preprocessor::fillMissing(TimeSeries& ts) {
    for (size_t i = 0; i < ts.values.size(); ++i) {
        if (std::isnan(ts.values[i])) {
            ts.values[i] = (i>0 ? ts.values[i-1] : 0.0);
        }
    }
}

void Preprocessor::trainScaler(const TimeSeries& ts) {
    mean_ = std::accumulate(ts.values.begin(), ts.values.end(), 0.0) / ts.values.size();
    double sumsq = 0.0;
    for (double v : ts.values) sumsq += (v - mean_) * (v - mean_);
    std_ = std::sqrt(sumsq / ts.values.size());
    if (std_ == 0) std_ = 1;
}

void Preprocessor::applyScaler(TimeSeries& ts) const {
    for (double& v : ts.values) {
        v = (v - mean_) / std_;
    }
}

} // namespace ef
