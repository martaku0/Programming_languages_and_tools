#pragma once
#include <string>

class Vector2d
{
    private:
    int x, y;

    public:
    Vector2d(int x, int y);

    int getX() const;
    int getY() const;
    bool operator==(const Vector2d& other) const;
    std::string toString();
    bool precedes(Vector2d other);
    bool follows(Vector2d other);
    Vector2d add(Vector2d other);
    Vector2d subtract(Vector2d other);
    Vector2d upperRight(Vector2d other);
    Vector2d opposite();
};