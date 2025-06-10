#include "fred_loader.hpp"
#include <curl/curl.h>
#include <sstream>
#include <iostream>

namespace {
size_t write_callback(void* contents, size_t size, size_t nmemb, void* userp) {
    size_t total = size * nmemb;
    std::string* s = static_cast<std::string*>(userp);
    s->append(static_cast<char*>(contents), total);
    return total;
}
}

std::map<std::string,double> load_fred_series(const std::string& series_id, const std::string& api_key) {
    std::map<std::string,double> result;
    std::string frequency = (series_id == "ICSA") ? "w" : "m";
    std::string url = "https://api.stlouisfed.org/fred/series/observations?series_id=" + series_id +
                      "&api_key=" + api_key + "&file_type=csv&frequency=" + frequency;

    CURL* curl = curl_easy_init();
    if(!curl) {
        std::cerr << "Failed to init curl" << std::endl;
        return result;
    }
    std::string response;
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
    CURLcode res = curl_easy_perform(curl);
    curl_easy_cleanup(curl);
    if(res != CURLE_OK) {
        std::cerr << "curl error: " << curl_easy_strerror(res) << std::endl;
        return result;
    }

    std::istringstream ss(response);
    std::string line;
    getline(ss, line); // header
    while(getline(ss, line)) {
        std::istringstream ls(line);
        std::string date, value;
        getline(ls, date, ',');
        getline(ls, value, ',');
        try {
            double v = std::stod(value);
            result[date] = v;
        } catch (...) {
            // skip
        }
    }
    return result;
}
