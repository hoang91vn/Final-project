#include <gtest/gtest.h>
#include "ef/FeatureGenerator.hpp"

TEST(FeatureGenerator, Lagged) {
    ef::TimeSeries ts;
    ts.values = {1,2,3,4};
    ts.dates.resize(4);
    std::vector<std::vector<double>> X; std::vector<double> y;
    ef::FeatureGenerator::createLaggedFeatures(ts, 2, X, y);
    ASSERT_EQ(X.size(), 2);
    EXPECT_EQ(X[0][0], 1);
    EXPECT_EQ(X[0][1], 2);
    EXPECT_EQ(y[0], 3);
}
