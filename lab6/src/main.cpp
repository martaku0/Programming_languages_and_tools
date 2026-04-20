#include <iostream>
#include <vector>

#include "../include/RectangularMap.hpp"
#include "../include/Car.hpp"
#include "../include/MoveDirection.hpp"

int main(int argc, char* argv[]) {
    std::cout << "--- Start of simulation ---\n" << std::endl;

    // MAP SIZE:
    int width = 5;
    int height = 10;

    RectangularMap map(width, height);

    Vector2d low(0, 0);
    Vector2d up(width - 1, height - 1);

    // CARS:
    Car car1(2, 2, low, up);
    Car car2(0, 0, low, up);
    Car car3(4, 4, low, up);

    map.place(&car1);
    map.place(&car2);
    map.place(&car3);

    if (map.place(&car1)) {
        std::cout << "Car 1 has been successfully added to the position (2,2)" << std::endl;
    }
    if (map.place(&car2)) {
        std::cout << "Car 2 has been successfully added to the position (0,0)" << std::endl;
    }
    if (map.place(&car3)) {
        std::cout << "Car 3 has been successfully added to the position (4,4)" << std::endl;
    }

    std::cout << "\nInitial state of the map:" << std::endl;
    std::cout << map.toString() << std::endl;

    std::vector<MoveDirection> moves = map.parse(argc, argv);

    if (!moves.empty()) {
        std::cout << "Executing moves..." << std::endl;
        map.run(moves);

        std::cout << "\nFinal state of the map:" << std::endl;
        std::cout << map.toString() << std::endl;
    } else {
        std::cout << "No valid moves to execute. Pass arguments (e.g., f b r l) when running the program." << std::endl;
    }

    std::cout << "--- End of simulation ---\n" << std::endl;
    return 0;
}