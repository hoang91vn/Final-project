#include <gtest/gtest.h>
#include "ef/ARIMAModel.hpp"

TEST(ARIMA, Basic) {
    std::vector<std::vector<double>> X = {{1,2},{2,3},{3,4}};
    std::vector<double> y = {3,4,5};
    ef::ARIMAModel m(2,0,0);
    m.train(X,y);
    auto p = m.predict(X);
    EXPECT_EQ(p.size(), y.size());
}
