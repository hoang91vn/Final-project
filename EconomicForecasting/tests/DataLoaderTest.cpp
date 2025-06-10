#include <gtest/gtest.h>
#include "ef/DataLoader.hpp"
#include <fstream>

TEST(DataLoader, LoadCSV) {
    std::ofstream f("test.csv");
    f << "Date,Value\n2024-01-01,1\n2024-01-08,2\n";
    f.close();
    ef::TimeSeries ts = ef::DataLoader::loadCSV("test.csv");
    EXPECT_EQ(ts.dates.size(), 2);
    EXPECT_EQ(ts.values[0], 1);
    EXPECT_EQ(ts.values[1], 2);
    std::remove("test.csv");
}
