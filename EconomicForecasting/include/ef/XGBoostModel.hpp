#ifndef EF_XGBOOST_MODEL_HPP
#define EF_XGBOOST_MODEL_HPP

#include "ForecastModel.hpp"
#include <vector>
#include <memory>

namespace ef {

using BoosterHandle = void*;

class XGBoostModel : public ForecastModel {
public:
    XGBoostModel();
    ~XGBoostModel();
    void train(const std::vector<std::vector<double>>& X,
               const std::vector<double>& y) override;
    std::vector<double> predict(const std::vector<std::vector<double>>& X) override;
private:
    BoosterHandle booster_{nullptr};
    double mean_{0};
};

} // namespace ef

#endif
