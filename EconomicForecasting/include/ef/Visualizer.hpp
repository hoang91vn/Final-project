#ifndef EF_VISUALIZER_HPP
#define EF_VISUALIZER_HPP

#include "DataStructures.hpp"
#include <string>

namespace ef {

class Visualizer {
public:
    static void plot(const std::vector<double>& actual,
                     const std::vector<double>& pred,
                     const std::string& path);
};

} // namespace ef

#endif
