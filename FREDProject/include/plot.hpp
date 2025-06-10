#pragma once
#include <string>
#include <vector>

void plot_series(const std::string& title,
                 const std::vector<std::string>& dates,
                 const std::vector<double>& raw,
                 const std::vector<double>& trend,
                 const std::vector<std::string>& fDates,
                 const std::vector<double>& fValues,
                 const std::string& outPng);

void ascii_sparkline(const std::string& title, const std::vector<double>& data);
