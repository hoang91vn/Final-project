#include "ef/XGBoostModel.hpp"
#include <numeric>

namespace ef {

XGBoostModel::XGBoostModel() { booster_ = nullptr; }

XGBoostModel::~XGBoostModel() { }

void XGBoostModel::train(const std::vector<std::vector<double>>& /*X*/,
                         const std::vector<double>& y) {
    if (y.empty()) return;
    mean_ = std::accumulate(y.begin(), y.end(), 0.0) / y.size();
}

std::vector<double> XGBoostModel::predict(const std::vector<std::vector<double>>& X) {
    return std::vector<double>(X.size(), mean_);
}

} // namespace ef
