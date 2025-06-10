#include "ef/ARIMAModel.hpp"
#include <numeric>

namespace ef {

ARIMAModel::ARIMAModel(int p, int d, int q) : p_(p), d_(d), q_(q) {}

void ARIMAModel::train(const std::vector<std::vector<double>>& X,
                       const std::vector<double>& y) {
    if (X.empty()) return;
    size_t n = X.size();
    coef_.assign(p_, 0.0);
    for (int j = 0; j < p_; ++j) {
        double num = 0.0, den = 0.0;
        for (size_t i = 0; i < n; ++i) {
            num += X[i][j] * y[i];
            den += X[i][j] * X[i][j];
        }
        coef_[j] = den != 0 ? num / den : 0.0;
    }
}

std::vector<double> ARIMAModel::predict(const std::vector<std::vector<double>>& X) {
    std::vector<double> preds;
    for (const auto& row : X) {
        double pred = 0.0;
        for (int j = 0; j < p_ && j < (int)row.size(); ++j) {
            pred += coef_[j] * row[j];
        }
        preds.push_back(pred);
    }
    return preds;
}

} // namespace ef
