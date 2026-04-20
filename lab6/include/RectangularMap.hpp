#pragma once
#include <vector>
#include <string>

#include "Vector2d.hpp"
#include "MoveDirection.hpp"
#include "Car.hpp"

class RectangularMap {
private:
    int width;
    int height;
    Vector2d lowerLeft;
    Vector2d upperRight;
    
    Car* cars[10]; 
    int carCount;

public:
    RectangularMap(int width, int height);
    bool place(Car* car);
    Car* objectAt(Vector2d position);
    bool isOccupied(Vector2d position);
    std::vector<MoveDirection> parse(int argc, char* argv[]);
    void run(const std::vector<MoveDirection>& moves);
    std::string toString();
};