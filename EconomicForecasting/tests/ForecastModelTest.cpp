#include <gtest/gtest.h>
#include "ef/ARIMAModel.hpp"

TEST(ForecastModel, ARIMA) {
    std::vector<std::vector<double>> X = {{1},{2},{3}};
    std::vector<double> y = {2,3,4};
    ef::ARIMAModel m(1,0,0);
    m.train(X,y);
    auto p = m.predict(X);
    EXPECT_EQ(p.size(), 3);
}
