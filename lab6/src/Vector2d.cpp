#include "../include/objects.hpp"

class Vector2d
{
    private:
    int x, y;

    public:
    Vector2d(int x_, int y_){
        this->x = x;
        this->y = y;
    }

    bool operator==(const Vector2d& other) const {
        return this->x == other.x && this->y == other.y;
    }

    std::string toString(){
        std::string pos = "(" + std::to_string(this->x) + "," + std::to_string(this->y) + ")";
        return pos;
    }

    bool precedes(Vector2d other){
        if(this->x > other.x || this->y > other.y){
            return false;
        }
        
        return true;
    }

    bool follows(Vector2d other){
        if(this->x < other.x || this->y < other.y){
            return false;
        }
        
        return true;
    }

    Vector2d add(Vector2d other){
        Vector2d newVect2d(this->x + other.x, this->y + other.y);
        return newVect2d;
    }

    Vector2d subtract(Vector2d other){
        Vector2d newVect2d(this->x - other.x, this->y - other.y);
        return newVect2d;
    }

    Vector2d upperRight(Vector2d other){
        Vector2d newVect2d(std::max(this->x, other.x), std::max(this->y, other.y));
        return newVect2d;
    }

    Vector2d opposite(){
        Vector2d newVect2d(-this->x, -this->y);
        return newVect2d;
    }
};