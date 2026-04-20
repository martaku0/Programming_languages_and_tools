#pragma once
#include <string>

#include "../include/MapDirection.hpp"
#include "../include/MoveDirection.hpp"
#include "../include/Vector2d.hpp"

class Car 
{
    private:
    MapDirection::MapDirection orientation;
    Vector2d position;

    Vector2d mapBottomLeft;
    Vector2d mapTopRight;

    public:
    Car(int x, int y, Vector2d lowerLeft, Vector2d upperRight);

    std::string toString();
    Vector2d getPosition() const;
    bool isAt(Vector2d targetPosition);
    void move(MoveDirection direction);
};