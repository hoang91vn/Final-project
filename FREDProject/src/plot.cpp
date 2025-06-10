#include "plot.hpp"
#include "matplotlibcpp.h"
#include <numeric>
#include <iostream>

namespace plt = matplotlibcpp;

void plot_series(const std::string& title,
                 const std::vector<std::string>& dates,
                 const std::vector<double>& raw,
                 const std::vector<double>& trend,
                 const std::vector<std::string>& fDates,
                 const std::vector<double>& fValues,
                 const std::string& outPng) {
    std::vector<int> x(raw.size());
    std::iota(x.begin(), x.end(), 0);
    plt::figure();
    plt::named_plot("raw", x, raw);
    plt::named_plot("trend", x, trend);
    std::vector<int> fx(fValues.size());
    std::iota(fx.begin(), fx.end(), x.back()+1);
    plt::scatter(fx, fValues);
    plt::legend();
    plt::title(title);
    plt::save(outPng);
    plt::close();
}

void ascii_sparkline(const std::string& title, const std::vector<double>& data) {
    static const char* bars = "▁▂▃▄▅▆▇█";
    double minv=*std::min_element(data.begin(), data.end());
    double maxv=*std::max_element(data.begin(), data.end());
    std::cout<<title<<": ";
    for(double v: data){
        size_t idx = (maxv==minv)?0:static_cast<size_t>((v-minv)/(maxv-minv)*7);
        if(idx>7) idx=7;
        std::cout<<bars[idx];
    }
    std::cout<<std::endl;
}
