#include <gtest/gtest.h>
#include "../include/commands.hpp"

TEST(SortTest, DefaultNoArguments) {
    std::vector<std::string> expected = {
        "123 numbers", "Banana 10", "apple 50", "apple pie 20", "cherry 30"
    };
    EXPECT_EQ(expected, sort(test_data, {}));
}

TEST(SortTest, DefaultAlphabetical) {
    std::vector<std::string> expected = {
        "123 numbers", "Banana 10", "apple 50", "apple pie 20", "cherry 30"
    };
    EXPECT_EQ(expected, sort(test_data, {}));
}

TEST(SortTest, NumericByColumn) {
   std::vector<std::string> expected = {
        "apple pie 20", 
        "123 numbers", 
        "Banana 10", 
        "cherry 30", 
        "apple 50"
    };
    EXPECT_EQ(expected, sort(test_data, {"-k", "2", "-n"}));
}
