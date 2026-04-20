#include <gtest/gtest.h>
#include "../include/Car.hpp"

TEST(CarTest, InitialPositionAndIsAt) {
    Car car(2, 2);
    
    EXPECT_TRUE(car.isAt(Vector2d(2, 2)));
    EXPECT_FALSE(car.isAt(Vector2d(3, 3)));
}

TEST(CarTest, ToStringReturnsCorrectFormat) {
    Car car(1, 3);
    
    EXPECT_EQ(car.toString(), "^");
}

TEST(CarTest, TurningChangesOrientation) {
    Car car(2, 2); // default NORTH ("^")
    
    car.move(RIGHT);
    EXPECT_EQ(car.toString(), ">");
    
    car.move(RIGHT);
    EXPECT_EQ(car.toString(), "v");
    
    car.move(LEFT);
    EXPECT_EQ(car.toString(), ">");
}

TEST(CarTest, MovingChangesPositionCorrectly) {
    Car car(2, 2); // Default NORTH
    
    car.move(FORWARD);
    EXPECT_TRUE(car.isAt(Vector2d(2, 3)));
    
    car.move(BACKWARD);
    EXPECT_TRUE(car.isAt(Vector2d(2, 2)));
    
    car.move(RIGHT); // Turn East (EAST)
    car.move(FORWARD);
    EXPECT_TRUE(car.isAt(Vector2d(3, 2)));
}

TEST(CarTest, BouncesOffMapBoundaries) {
    // Upper edge (y = 4)
    Car carTop(2, 4);
    carTop.move(FORWARD); // Attempts to move on (2,5), bounces off (2,3)
    EXPECT_TRUE(carTop.isAt(Vector2d(2, 3)));

    // Lower edge (y = 0)
    Car carBottom(2, 0);
    carBottom.move(BACKWARD); // Attempts to move back to (2,-1), bounces off (2,1)
    EXPECT_TRUE(carBottom.isAt(Vector2d(2, 1)));

    // Right edge (x = 4)
    Car carRight(4, 2);
    carRight.move(RIGHT);
    carRight.move(FORWARD); // Attempts to move to (5,2), bounces off (3,2)
    EXPECT_TRUE(carRight.isAt(Vector2d(3, 2)));

    // Left edge (x = 0)
    Car carLeft(0, 2);
    carLeft.move(LEFT);
    carLeft.move(FORWARD); // Attempts to move on (-1,2), bounces off at (1,2)
    EXPECT_TRUE(carLeft.isAt(Vector2d(1, 2)));
}