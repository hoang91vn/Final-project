#include <gtest/gtest.h>
#include "ef/Visualizer.hpp"
#include <fstream>

TEST(Visualizer, Plot) {
    std::vector<double> a = {1,2,3};
    std::vector<double> p = {1,2,3};
    ef::Visualizer::plot(a,p,"test.png");
    std::ifstream f("test.png");
    EXPECT_TRUE(f.good());
    f.close();
    std::remove("test.png");
}
