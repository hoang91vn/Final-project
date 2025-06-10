#include "output_writer.hpp"
#include <fstream>
#include <filesystem>

bool write_forecast_csv(const std::string& path,
                        const std::string& series,
                        const std::string& method,
                        const std::vector<std::string>& weeks,
                        const std::vector<double>& values) {
    namespace fs = std::filesystem;
    fs::create_directories(fs::path(path).parent_path());
    std::ofstream file;
    bool exists = fs::exists(path);
    file.open(path, exists ? std::ios::app : std::ios::out);
    if(!file) return false;
    if(!exists) file << "series,method,week,value\n";
    for(size_t i=0;i<weeks.size() && i<values.size();++i) {
        file << series << ',' << method << ',' << weeks[i] << ',' << values[i] << '\n';
    }
    return true;
}
