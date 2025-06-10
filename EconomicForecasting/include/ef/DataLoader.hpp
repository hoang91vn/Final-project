#ifndef EF_DATA_LOADER_HPP
#define EF_DATA_LOADER_HPP

#include "DataStructures.hpp"
#include <string>

namespace ef {

class DataLoader {
public:
    static TimeSeries loadCSV(const std::string& path);
};

} // namespace ef

#endif
