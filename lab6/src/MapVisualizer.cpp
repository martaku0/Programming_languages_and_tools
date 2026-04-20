#include "../include/MapVisualizer.hpp"
#include <sstream>
#include <iomanip>
// #include <format> // Requires C++20

MapVisualizer::MapVisualizer(RectangularMap& map) : map(map) {}

std::string MapVisualizer::draw(Vector2d lowerLeft, Vector2d upperRight) {
    std::stringstream builder;

    for (int i = upperRight.getY() + 1; i >= lowerLeft.getY() - 1; i--) {
        if (i == upperRight.getY() + 1) {
            builder << drawHeader(lowerLeft, upperRight);
        }

        // Equivalent to String.format("%3d: ", i)
        builder << std::setw(3) << i << ": ";

        for (int j = lowerLeft.getX(); j <= upperRight.getX() + 1; j++) {
            if (i < lowerLeft.getY() || i > upperRight.getY()) {
                builder << drawFrame(j <= upperRight.getX());
            } else {
                builder << CELL_SEGMENT;
                if (j <= upperRight.getX()) {
                    builder << drawObject(Vector2d(j, i));
                }
            }
        }
        builder << "\n";
    }
    return builder.str();
}

std::string MapVisualizer::drawFrame(bool innerSegment) {
    if (innerSegment) {
        return FRAME_SEGMENT + FRAME_SEGMENT;
    } else {
        return FRAME_SEGMENT;
    }
}

std::string MapVisualizer::drawHeader(Vector2d lowerLeft, Vector2d upperRight) {
    std::stringstream builder;
    builder << " y\\x ";
    for (int j = lowerLeft.getX(); j < upperRight.getX() + 1; j++) {
        builder << std::setw(2) << j;
    }
    builder << "\n";
    return builder.str();
}

std::string MapVisualizer::drawObject(Vector2d currentPosition) {
    if (this->map.isOccupied(currentPosition)) {
        // We assume that objectAt returns a pointer or an object, 
        // which can be converted to a string
        auto object = this->map.objectAt(currentPosition);
        if (object != nullptr) {
            // In C++, you must ensure that your objects have a toString() method 
            // or an overloaded << operator
            return object->toString(); 
        }
    }
    return EMPTY_CELL;
}