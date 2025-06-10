#pragma once
#include <map>
#include <string>

std::map<std::string,double> load_fred_series(const std::string& series_id, const std::string& api_key);
