#include "data_cleaner.hpp"
#include <algorithm>
#include <cmath>

std::map<std::string,RowData> merge_series(
    const std::map<std::string,double>& icsa,
    const std::map<std::string,double>& unrate,
    const std::map<std::string,double>& jtsjol,
    const std::string& startDate,
    const std::string& endDate) {

    std::map<std::string,RowData> result;
    for(const auto& [date,val] : icsa) {
        if(date < startDate || date > endDate) continue;
        RowData row; row.icsa = val;
        auto uit = unrate.upper_bound(date);
        if(uit!=unrate.begin()) {
            --uit;
            row.unrate = uit->second;
        }
        auto jit = jtsjol.upper_bound(date);
        if(jit!=jtsjol.begin()) {
            --jit;
            row.jtsjol = jit->second;
        }
        result[date] = row;
    }
    return result;
}
