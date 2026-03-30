#include <gtest/gtest.h>
#include "../include/operacje.hpp"

TEST(WspolnaTest, Basic) {
    int A[] = {1,2,3};
    int B[] = {3,4,5};
    int C[MAX];
    int nC = wspolna(A,3,B,3,C);

    int expected[] = {3};
    EXPECT_EQ(nC, 1);
    EXPECT_EQ(C[0], expected[0]);
}