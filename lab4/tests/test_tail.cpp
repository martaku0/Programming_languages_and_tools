#include <gtest/gtest.h>
#include "../include/commands.hpp"

TEST(TailTest, DefaultNoArguments) {
    std::vector<std::string> expected = {
        "apple 50", "Banana 10", "cherry 30", "apple pie 20", "123 numbers"
    };
    EXPECT_EQ(expected, tail(test_data, {}));
}

TEST(TailTest, LastNLines) {
    std::vector<std::string> expected = {"apple pie 20", "123 numbers"};
    EXPECT_EQ(expected, tail(test_data, {"-n", "2"}));
}

TEST(TailTest, FromNthLine) {
    std::vector<std::string> expected = {"apple pie 20", "123 numbers"};
    EXPECT_EQ(expected, tail(test_data, {"+4"}));
}

TEST(TailTest, LastCharacters) {
    std::vector<std::string> expected = {"123 numbers"};
    EXPECT_EQ(expected, tail(test_data, {"-c", "12"}));
}
