#ifndef EF_FEATURE_GENERATOR_HPP
#define EF_FEATURE_GENERATOR_HPP

#include "DataStructures.hpp"
#include <vector>

namespace ef {

class FeatureGenerator {
public:
    static void createLaggedFeatures(const TimeSeries& ts, size_t window,
                                     std::vector<std::vector<double>>& X,
                                     std::vector<double>& y);
};

} // namespace ef

#endif
