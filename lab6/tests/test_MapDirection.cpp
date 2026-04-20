#include <gtest/gtest.h>
#include "../include/objects.hpp"

TEST(MapDirectionTest, ToStringConvertsCorrectly) {
    EXPECT_EQ(MapDirection::toString(MapDirection::NORTH), "Północ");
    EXPECT_EQ(MapDirection::toString(MapDirection::SOUTH), "Południe");
    EXPECT_EQ(MapDirection::toString(MapDirection::WEST), "Zachód");
    EXPECT_EQ(MapDirection::toString(MapDirection::EAST), "Wschód");
}

TEST(MapDirectionTest, NextReturnsClockwiseDirection) {
    EXPECT_EQ(MapDirection::next(MapDirection::NORTH), MapDirection::EAST);
    EXPECT_EQ(MapDirection::next(MapDirection::EAST), MapDirection::SOUTH);
    EXPECT_EQ(MapDirection::next(MapDirection::SOUTH), MapDirection::WEST);
    EXPECT_EQ(MapDirection::next(MapDirection::WEST), MapDirection::NORTH);
}

TEST(MapDirectionTest, PreviousReturnsCounterClockwiseDirection) {
    EXPECT_EQ(MapDirection::previous(MapDirection::NORTH), MapDirection::WEST);
    EXPECT_EQ(MapDirection::previous(MapDirection::WEST), MapDirection::SOUTH);
    EXPECT_EQ(MapDirection::previous(MapDirection::SOUTH), MapDirection::EAST);
    EXPECT_EQ(MapDirection::previous(MapDirection::EAST), MapDirection::NORTH);
}