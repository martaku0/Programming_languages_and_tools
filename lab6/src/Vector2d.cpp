#include "../include/Vector2d.hpp"
#include <algorithm>

Vector2d::Vector2d(int x, int y){
    this->x = x;
    this->y = y;
}

int Vector2d::getX() const { return this->x; }

int Vector2d::getY() const { return this->y; }

bool Vector2d::operator==(const Vector2d& other) const {
    return this->x == other.x && this->y == other.y;
}

std::string Vector2d::toString(){
    return "(" + std::to_string(this->x) + "," + std::to_string(this->y) + ")";
}

bool Vector2d::precedes(Vector2d other){
    if(this->x > other.x || this->y > other.y) return false;
    return true;
}

bool Vector2d::follows(Vector2d other){
    if(this->x < other.x || this->y < other.y) return false;
    return true;
}

Vector2d Vector2d::add(Vector2d other){
    return Vector2d(this->x + other.x, this->y + other.y);
}

Vector2d Vector2d::subtract(Vector2d other){
    return Vector2d(this->x - other.x, this->y - other.y);
}

Vector2d Vector2d::upperRight(Vector2d other){
    return Vector2d(std::max(this->x, other.x), std::max(this->y, other.y));
}

Vector2d Vector2d::lowerLeft(Vector2d other){
    return Vector2d(std::min(this->x, other.x), std::min(this->y, other.y));
}

Vector2d Vector2d::opposite(){
    return Vector2d(-this->x, -this->y);
}