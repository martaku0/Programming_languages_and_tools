#include "../include/RectangularMap.hpp"
#include "../include/MapVisualizer.hpp"
#include <iostream>

RectangularMap::RectangularMap(int width, int height) 
    : width(width), height(height), lowerLeft(Vector2d(0, 0)), upperRight(Vector2d(width - 1, height - 1)), carCount(0) {
    
    for (int i = 0; i < 10; ++i) {
        cars[i] = nullptr;
    }
}

bool RectangularMap::place(Car* car) {
    if (carCount >= 10) return false;
    
    if (isOccupied(car->getPosition())) return false; 

    cars[carCount] = car;
    carCount++;
    return true;
}

Car* RectangularMap::objectAt(Vector2d position) {
    for (int i = 0; i < carCount; ++i) {
        if (cars[i]->isAt(position)) {
            return cars[i];
        }
    }
    return nullptr;
}

bool RectangularMap::isOccupied(Vector2d position) {
    return objectAt(position) != nullptr;
}

std::vector<MoveDirection> RectangularMap::parse(int argc, char* argv[]) {
    std::vector<MoveDirection> directions;
    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        if (arg == "f") directions.push_back(FORWARD);
        else if (arg == "b") directions.push_back(BACKWARD);
        else if (arg == "l") directions.push_back(LEFT);
        else if (arg == "r") directions.push_back(RIGHT);
    }
    return directions;
}

void RectangularMap::run(const std::vector<MoveDirection>& moves) {
    if (carCount == 0) return;

    for (int i = 0; i < moves.size(); ++i) {
        Car* currentCar = cars[i % carCount];
        currentCar->move(moves[i]);

        std::cout << "--- After move of car " << (i % carCount + 1) << " ---" << std::endl;
        std::cout << this->toString() << std::endl;
    }
}

std::string RectangularMap::toString() {
    MapVisualizer visualizer(*this);
    return visualizer.draw(lowerLeft, upperRight);
}