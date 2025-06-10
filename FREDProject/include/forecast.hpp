#pragma once
#include <vector>
#include <cstddef>

enum class ForecastMethod { SMA, EXP };

std::vector<double> forecast_sma(const std::vector<double>& series, size_t window, size_t steps);
std::vector<double> forecast_exp(const std::vector<double>& series, double alpha, size_t steps);
