#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <sstream>
#include <regex>

const int MAX = 10;

const std::vector<std::string> test_data = {
    "apple 50",      // 0
    "Banana 10",     // 1
    "cherry 30",     // 2
    "apple pie 20",  // 3
    "123 numbers"    // 4
};

extern std::vector<std::string> grep(const std::vector<std::string>& lines, const std::vector<std::string>& args);
extern std::vector<std::string> sort(const std::vector<std::string>& lines, const std::vector<std::string>& args);
extern std::vector<std::string> tail(const std::vector<std::string>& lines, const std::vector<std::string>& args);