#pragma once
#include<string>

namespace MapDirection
{
    enum MapDirection {
        NORTH,
        SOUTH,
        WEST,
        EAST
    };

    std::string toString(MapDirection dir);
    MapDirection next(MapDirection dir);
    MapDirection previous(MapDirection dir);
}