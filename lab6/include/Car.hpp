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

    const Vector2d mapBottomLeft;
    const Vector2d mapTopRight;

    public:
    Car(int x, int y);

    std::string toString();
    Vector2d getPosition() const;
    bool isAt(Vector2d targetPosition);
    void move(MoveDirection direction);
};