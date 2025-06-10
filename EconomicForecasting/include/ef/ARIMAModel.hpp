#ifndef EF_ARIMA_MODEL_HPP
#define EF_ARIMA_MODEL_HPP

#include "ForecastModel.hpp"
#include <vector>

namespace ef {

class ARIMAModel : public ForecastModel {
public:
    ARIMAModel(int p=1, int d=0, int q=0);
    void train(const std::vector<std::vector<double>>& X,
               const std::vector<double>& y) override;
    std::vector<double> predict(const std::vector<std::vector<double>>& X) override;
private:
    int p_, d_, q_;
    std::vector<double> coef_;
};

} // namespace ef

#endif
