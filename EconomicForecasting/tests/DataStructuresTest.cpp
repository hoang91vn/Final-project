#include <gtest/gtest.h>
#include "ef/DataStructures.hpp"

TEST(DataStructures, DateParse) {
    ef::Date d = ef::Date::parse("2023-01-02");
    EXPECT_EQ(d.year, 2023);
    EXPECT_EQ(d.month, 1);
    EXPECT_EQ(d.day, 2);
}
