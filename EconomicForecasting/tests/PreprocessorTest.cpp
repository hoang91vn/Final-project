#include <gtest/gtest.h>
#include <limits>
#include <cmath>
#include "ef/Preprocessor.hpp"

TEST(Preprocessor, FillMissing) {
    ef::TimeSeries ts;
    ts.values = {1.0, std::numeric_limits<double>::quiet_NaN(), 3.0};
    ef::Preprocessor::fillMissing(ts);
    EXPECT_FALSE(std::isnan(ts.values[1]));
    EXPECT_EQ(ts.values[1], 1.0);
}

TEST(Preprocessor, Scaler) {
    ef::TimeSeries ts;
    ts.values = {1.0,2.0,3.0};
    ef::Preprocessor p; p.trainScaler(ts); p.applyScaler(ts);
    EXPECT_NEAR(ts.values[0], -1.2247, 1e-3);
}

