// Copyright 2017 <Célian Garcia>

#include <gtest/gtest.h>

TEST(SimpleTest1, PositiveNos) {
    ASSERT_EQ(6, 2+4);
    ASSERT_EQ(4, 2+2);
}

TEST(SimpleTest2, PositiveNos) {
    ASSERT_EQ(6, 3*2);
    ASSERT_EQ(4, 2*2);
}
