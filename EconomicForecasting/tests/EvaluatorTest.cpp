#include <gtest/gtest.h>
#include "ef/Evaluator.hpp"

TEST(Evaluator, Metrics) {
    std::vector<double> a = {1,2,3};
    std::vector<double> p = {1,2,4};
    EXPECT_NEAR(ef::Evaluator::rmse(a,p), 0.577, 1e-3);
    EXPECT_NEAR(ef::Evaluator::mape(a,p), 11.111, 1e-2);
}
