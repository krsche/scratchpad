#include <iostream>
#include <gtest/gtest.h>

#include "my_math/add.h"
#include "my_math/subtract.h"


TEST(MyMathTest, Basics) {
    EXPECT_EQ(add(1,3), 4);
    EXPECT_EQ(subtract(1,3), -2);
}