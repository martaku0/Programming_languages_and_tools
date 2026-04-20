#include <iostream>
#include <vector>

#include "../include/RectangularMap.hpp"
#include "../include/Car.hpp"
#include "../include/MoveDirection.hpp"

int main(int argc, char* argv[]) {
    std::cout << "--- Start of simulation ---\n" << std::endl;

    // 5x5 map
    // Note: The Car class has a mapTopRight(4,4) restriction, so if you want a larger map, you must remove this restriction from the Car class!
    RectangularMap map(5, 5);

    Car car1(2, 2);
    Car car2(0, 0);

    if (map.place(&car1)) {
        std::cout << "Car 1 has been successfully added to the position (2,2)" << std::endl;
    }
    if (map.place(&car2)) {
        std::cout << "Car 2 has been successfully added to the position (0,0)" << std::endl;
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