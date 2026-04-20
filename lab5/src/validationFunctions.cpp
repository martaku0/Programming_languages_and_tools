#include "../include/functions.hpp"

bool hasLength(const char* password) {
    return std::strlen(password) >= 8;
}

bool hasSpecialChar(const char* password) {
    for (int i = 0; i < std::strlen(password); ++i) {
        if (std::ispunct(password[i])) {
            return true;
        }
    }
    return false;
}

bool hasDigit(const char* password) {
    for (int i = 0; i < std::strlen(password); ++i) {
        if (std::isdigit(password[i])) {
            return true;
        }
    }
    return false;
}