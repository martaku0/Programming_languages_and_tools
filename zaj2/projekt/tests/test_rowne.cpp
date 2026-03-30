#include <gtest/gtest.h>
#include "../include/operacje.hpp"

TEST(RowneTest, Basic) {
    int A[] = {1,2,3};
    int B[] = {1,2,3};
    int C[] = {1,2,4};
    EXPECT_TRUE(rowne(A,3,B,3));
    EXPECT_FALSE(rowne(A,3,C,3));
}