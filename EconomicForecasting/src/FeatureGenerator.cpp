#include "ef/FeatureGenerator.hpp"

namespace ef {

void FeatureGenerator::createLaggedFeatures(const TimeSeries& ts, size_t window,
                                            std::vector<std::vector<double>>& X,
                                            std::vector<double>& y) {
    if (ts.values.size() <= window) return;
    for (size_t i = window; i < ts.values.size(); ++i) {
        std::vector<double> row;
        for (size_t j = i - window; j < i; ++j) {
            row.push_back(ts.values[j]);
        }
        X.push_back(row);
        y.push_back(ts.values[i]);
    }
}

} // namespace ef
