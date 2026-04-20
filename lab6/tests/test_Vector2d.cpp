#include <gtest/gtest.h>
#include "../include/objects.hpp"
#include "../src/Vector2d.cpp"

TEST(Vector2dTest, EqualityOperatorCorrectlyComparesVectors) {
    Vector2d v1(2, 3);
    Vector2d v2(2, 3);
    Vector2d v3(4, 5);
    
    EXPECT_TRUE(v1 == v2);
    EXPECT_FALSE(v1 == v3);
}

TEST(Vector2dTest, ToStringReturnsCorrectFormat) {
    Vector2d v(2, 3);
    Vector2d v2(-1, -5);

    EXPECT_EQ(v.toString(), "(2,3)");
    EXPECT_EQ(v2.toString(), "(-1,-5)");
}

TEST(Vector2dTest, PrecedesChecksIfVectorIsSmallerOrEqual) {
    Vector2d v1(1, 1);
    Vector2d v2(2, 2);
    Vector2d v3(1, 2);
    Vector2d v4(0, 5);

    EXPECT_TRUE(v1.precedes(v2));  // (1,1) <= (2,2) - True
    EXPECT_TRUE(v1.precedes(v1));  // (1,1) <= (1,1) - True
    EXPECT_TRUE(v1.precedes(v3));  // (1,1) <= (1,2) - True
    EXPECT_FALSE(v2.precedes(v1)); // (2,2) <= (1,1) - False
    EXPECT_FALSE(v1.precedes(v4)); // (1,1) <= (0,5) - False (1 > 0 on X axis)
}

TEST(Vector2dTest, FollowsChecksIfVectorIsGreaterOrEqual) {
    Vector2d v1(2, 2);
    Vector2d v2(1, 1);
    Vector2d v3(2, 1);
    Vector2d v4(5, 0);

    EXPECT_TRUE(v1.follows(v2));  // (2,2) >= (1,1) - True
    EXPECT_TRUE(v1.follows(v1));  // (2,2) >= (2,2) - True
    EXPECT_TRUE(v1.follows(v3));  // (2,2) >= (2,1) - True
    EXPECT_FALSE(v2.follows(v1)); // (1,1) >= (2,2) - False
    EXPECT_FALSE(v1.follows(v4)); // (2,2) >= (5,0) - False, (2 < 5 on X axis)
}

TEST(Vector2dTest, AddCombinesTwoVectorsCorrectly) {
    Vector2d v1(2, 3);
    Vector2d v2(1, 4);
    Vector2d result = v1.add(v2);
    
    EXPECT_TRUE(result == Vector2d(3, 7));
}

TEST(Vector2dTest, SubtractRemovesTwoVectorsCorrectly) {
    Vector2d v1(5, 5);
    Vector2d v2(2, 3);
    Vector2d result = v1.subtract(v2);
    
    EXPECT_TRUE(result == Vector2d(3, 2));
}

TEST(Vector2dTest, UpperRightReturnsMaxOfCoordinates) {
    Vector2d v1(1, 5);
    Vector2d v2(4, 2);
    Vector2d result = v1.upperRight(v2);
    
    EXPECT_TRUE(result == Vector2d(4, 5));
}

TEST(Vector2dTest, OppositeReturnsInvertedCoordinates) {
    Vector2d v1(2, -3);
    Vector2d result1 = v1.opposite();
    
    Vector2d v2(0, 5);
    Vector2d result2 = v2.opposite();

    EXPECT_TRUE(result1 == Vector2d(-2, 3));
    EXPECT_TRUE(result2 == Vector2d(0, -5));
}