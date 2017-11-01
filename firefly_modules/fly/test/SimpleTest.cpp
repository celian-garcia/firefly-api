//
// Created by celian on 31/10/17.
//

#include <gtest/gtest.h>

TEST(SimpleTest1, PositiveNos) {
    ASSERT_EQ(6, 2+4);
    ASSERT_EQ(4, 2+2);
}

TEST(SimpleTest2, PositiveNos) {
    ASSERT_EQ(6, 3*2);
    ASSERT_EQ(4, 2*2);
}
