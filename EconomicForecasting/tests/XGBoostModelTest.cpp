#include <gtest/gtest.h>
#include "ef/XGBoostModel.hpp"

TEST(XGBoost, Basic) {
    std::vector<std::vector<double>> X = {{1,2},{2,3},{3,4}};
    std::vector<double> y = {3,4,5};
    ef::XGBoostModel m;
    m.train(X,y);
    auto p = m.predict(X);
    EXPECT_EQ(p.size(), y.size());
}
