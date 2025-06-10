#ifndef EF_EVALUATOR_HPP
#define EF_EVALUATOR_HPP

#include <vector>

namespace ef {

class Evaluator {
public:
    static double rmse(const std::vector<double>& actual, const std::vector<double>& pred);
    static double mape(const std::vector<double>& actual, const std::vector<double>& pred);
};

} // namespace ef

#endif
