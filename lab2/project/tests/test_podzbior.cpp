#include <gtest/gtest.h>
#include "../include/operacje.hpp"

TEST(PodzbiorTest, Basic) {
    int A[] = {1,2};
    int B[] = {1,2,3};
    int C[] = {3,4};
    EXPECT_TRUE(podzbior(A,2,B,3));
    EXPECT_FALSE(podzbior(C,2,B,3));
}
