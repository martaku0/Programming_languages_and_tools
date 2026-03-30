#include <gtest/gtest.h>
#include "../include/operacje.hpp"

TEST(SymTest, Basic) {
    int A[] = {1,2,3};
    int B[] = {3,4,5};
    int C[MAX];
    int nC = sym(A,3,B,3,C);

    int expected[] = {1,2,4,5};
    EXPECT_EQ(nC, 4);
    for(int i=0;i<nC;i++)
        EXPECT_EQ(C[i], expected[i]);
}