#include "../include/commands.hpp"

int main() {
    std::vector<std::string> lines;
    std::vector<std::string> args;
    std::string line;
    std::string command;

    if (std::getline(std::cin, line)) {
        std::stringstream ss(line);
        std::string word;

        ss >> command; // eg. "tail"

        while (ss >> word) {
            args.push_back(word); // eg. "-n", "5"
        }
    }

    while (std::getline(std::cin, line)) {
        lines.push_back(line);
    }

    std::cout << "---------" << std::endl;
    std::vector<std::string> result;

    if (command == "tail") {
        result = tail(lines, args);
    } 
    else if (command == "sort") {
        result = sort(lines, args);
    } 
    else if (command == "grep") {
        result = grep(lines, args);
    }
    else {
        std::cerr << "[ERROR]: Unknown command '" << command << "'" << std::endl;
        return -1;
    }

    for (const auto& res_line : result) {
        std::cout << res_line << "\n";
    }

    return 0;
}