#ifndef EF_FORECAST_MODEL_HPP
#define EF_FORECAST_MODEL_HPP

#include <vector>

namespace ef {

class ForecastModel {
public:
    virtual ~ForecastModel() = default;
    virtual void train(const std::vector<std::vector<double>>& X,
                       const std::vector<double>& y) = 0;
    virtual std::vector<double> predict(const std::vector<std::vector<double>>& X) = 0;
};

} // namespace ef

#endif
