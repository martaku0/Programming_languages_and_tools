#include "../include/Car.hpp"

Car::Car(int x, int y, Vector2d lowerLeft, Vector2d upperRight) 
    : orientation(MapDirection::NORTH), 
      position(Vector2d(x, y)), 
      mapBottomLeft(lowerLeft), 
      mapTopRight(upperRight)
{}

std::string Car::toString() {
    switch (orientation) {
        case MapDirection::NORTH: return "^";
        case MapDirection::SOUTH: return "v";
        case MapDirection::EAST:  return ">";
        case MapDirection::WEST:  return "<";
        default: return "?";
    }
}

Vector2d Car::getPosition() const { 
    return this->position; 
}

bool Car::isAt(Vector2d targetPosition) {
    return position == targetPosition;
}

void Car::move(MoveDirection direction) {
    switch (direction) {
        case RIGHT:
            orientation = MapDirection::next(orientation);
            break;
        case LEFT:
            orientation = MapDirection::previous(orientation);
            break;
        case FORWARD:
        case BACKWARD:
        {
            Vector2d step(0, 0);
            switch (orientation) {
                case MapDirection::NORTH: 
                    step = Vector2d(0, 1); 
                    break;
                case MapDirection::SOUTH: 
                    step = Vector2d(0, -1); 
                    break;
                case MapDirection::EAST:  
                    step = Vector2d(1, 0); 
                    break;
                case MapDirection::WEST:  
                    step = Vector2d(-1, 0); 
                    break;
            }

            Vector2d intendedPos = position;
            if (direction == FORWARD) {
                intendedPos = position.add(step);
            } else {
                intendedPos = position.subtract(step);
            }

            if (intendedPos.follows(mapBottomLeft) && intendedPos.precedes(mapTopRight)) {
                position = intendedPos;
            } else {
                if (direction == FORWARD) {
                    position = position.subtract(step);
                } else {
                    position = position.add(step);
                }
            }
            break;
        }
    }
}