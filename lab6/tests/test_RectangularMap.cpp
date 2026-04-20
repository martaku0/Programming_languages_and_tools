#include <gtest/gtest.h>
#include <vector>
#include <string>

#include "../include/RectangularMap.hpp"
#include "../include/Car.hpp"
#include "../include/MoveDirection.hpp"
#include "../include/Vector2d.hpp"

const Vector2d LL(0, 0);
const Vector2d UR(4, 4);

TEST(RectangularMapTest, PlacesCarsCorrectly) {
    RectangularMap map(5, 5);
    Car car1(2, 2, LL, UR);
    Car car2(3, 3, LL, UR);

    EXPECT_TRUE(map.place(&car1));
    EXPECT_TRUE(map.place(&car2));

    EXPECT_TRUE(map.isOccupied(Vector2d(2, 2)));
    EXPECT_TRUE(map.isOccupied(Vector2d(3, 3)));
    
    EXPECT_EQ(map.objectAt(Vector2d(2, 2)), &car1);
    EXPECT_EQ(map.objectAt(Vector2d(3, 3)), &car2);
    
    EXPECT_FALSE(map.isOccupied(Vector2d(0, 0)));
    EXPECT_EQ(map.objectAt(Vector2d(0, 0)), nullptr);
}

TEST(RectangularMapTest, RejectsCarOnOccupiedPosition) {
    RectangularMap map(5, 5);
    Car car1(2, 2, LL, UR);
    Car car2(2, 2, LL, UR); 

    EXPECT_TRUE(map.place(&car1));
    EXPECT_FALSE(map.place(&car2)); 
}

TEST(RectangularMapTest, RejectsMoreThanTenCars) {
    RectangularMap map(10, 10);
    
    Car cars[11] = {
        Car(0,0, LL, UR), Car(0,1, LL, UR), Car(0,2, LL, UR), Car(0,3, LL, UR), Car(0,4, LL, UR),
        Car(1,0, LL, UR), Car(1,1, LL, UR), Car(1,2, LL, UR), Car(1,3, LL, UR), Car(1,4, LL, UR), Car(2,0, LL, UR)
    };

    for (int i = 0; i < 10; ++i) {
        EXPECT_TRUE(map.place(&cars[i]));
    }

    EXPECT_FALSE(map.place(&cars[10]));
}

TEST(RectangularMapTest, ParsesCommandLineArgumentsCorrectly) {
    RectangularMap map(5, 5);
    
    // Simalute arguments (eg. ./main f b x l right r)
    // "x" and "right" are invalid values and should be ignored
    char arg0[] = "program_name";
    char arg1[] = "f";
    char arg2[] = "b";
    char arg3[] = "x";       // to be ignored
    char arg4[] = "l";
    char arg5[] = "right";   // to be ignored
    char arg6[] = "r";
    char* argv[] = { arg0, arg1, arg2, arg3, arg4, arg5, arg6 };
    int argc = 7;

    std::vector<MoveDirection> moves = map.parse(argc, argv);

    ASSERT_EQ(moves.size(), 4);
    EXPECT_EQ(moves[0], FORWARD);
    EXPECT_EQ(moves[1], BACKWARD);
    EXPECT_EQ(moves[2], LEFT);
    EXPECT_EQ(moves[3], RIGHT);
}

TEST(RectangularMapTest, RunsMovesAlternatingly) {
    RectangularMap map(5, 5);
    Car car1(0, 0, LL, UR);
    Car car2(2, 2, LL, UR);

    map.place(&car1);
    map.place(&car2);

    // Sequence test:
    std::vector<MoveDirection> moves = { FORWARD, FORWARD, RIGHT, BACKWARD };

    map.run(moves);

    EXPECT_TRUE(car1.isAt(Vector2d(0, 1)));
    EXPECT_TRUE(car2.isAt(Vector2d(2, 2)));
    
    EXPECT_EQ(car1.toString(), ">");
}