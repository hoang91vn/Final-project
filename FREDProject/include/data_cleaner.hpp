#pragma once
#include <map>
#include <string>
#include <limits>

struct RowData { double icsa{std::numeric_limits<double>::quiet_NaN()}; double unrate{std::numeric_limits<double>::quiet_NaN()}; double jtsjol{std::numeric_limits<double>::quiet_NaN()}; };

std::map<std::string,RowData> merge_series(
    const std::map<std::string,double>& icsa,
    const std::map<std::string,double>& unrate,
    const std::map<std::string,double>& jtsjol,
    const std::string& startDate,
    const std::string& endDate);
