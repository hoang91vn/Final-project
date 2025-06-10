#ifndef EF_PREPROCESSOR_HPP
#define EF_PREPROCESSOR_HPP

#include "DataStructures.hpp"
#include <vector>

namespace ef {

class Preprocessor {
public:
    static void fillMissing(TimeSeries& ts);
    void trainScaler(const TimeSeries& ts);
    void applyScaler(TimeSeries& ts) const;
private:
    double mean_{0};
    double std_{1};
};

} // namespace ef

#endif
