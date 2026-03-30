#include <gtest/gtest.h>
#include "../include/operacje.hpp"

TEST(RoznicaTest, Basic) {
    int A[] = {1,2,3};
    int B[] = {3,4,5};
    int C[MAX];
    int nC = roznica(A,3,B,3,C);

    int expected[] = {1,2};
    EXPECT_EQ(nC, 2);
    for(int i=0;i<nC;i++)
        EXPECT_EQ(C[i], expected[i]);
}