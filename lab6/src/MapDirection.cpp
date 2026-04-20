#include "../include/objects.hpp"

namespace MapDirection
{
    std::string toString(MapDirection dir){
        switch(dir){
            case NORTH: return "Północ";
            case SOUTH: return "Południe";
            case WEST:  return "Zachód";
            case EAST:  return "Wschód";
            default: return "";
        }
    }

    MapDirection next(MapDirection dir){
        switch(dir){
            case NORTH: return MapDirection::EAST;
            case SOUTH: return MapDirection::WEST;
            case WEST:  return MapDirection::NORTH;
            case EAST:  return MapDirection::SOUTH;
            default: return MapDirection::NORTH;
        }
    }

    MapDirection previous(MapDirection dir){
        switch(dir){
            case NORTH: return MapDirection::WEST;
            case SOUTH: return MapDirection::EAST;
            case WEST:  return MapDirection::SOUTH;
            case EAST:  return MapDirection::NORTH;
            default: return MapDirection::NORTH;
        }
    }
}