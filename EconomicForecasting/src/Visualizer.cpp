#include "ef/Visualizer.hpp"
#include <matplot/matplot.h>

namespace ef {

void Visualizer::plot(const std::vector<double>& actual,
                      const std::vector<double>& pred,
                      const std::string& path) {
    matplot::figure(true);
    matplot::plot(actual);
    matplot::hold(true);
    matplot::plot(pred);
    matplot::legend({"Actual","Forecast"});
    matplot::save(path);
    matplot::close();
}
}
