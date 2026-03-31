#include <gtest/gtest.h>
#include "../include/commands.hpp"

TEST(GrepTest, DefaultNoArguments) {
    std::vector<std::string> expected = {};
    EXPECT_EQ(expected, grep(test_data, {}));
}

TEST(GrepTest, IgnoreCase) {
    std::vector<std::string> expected = {"Banana 10"};
    EXPECT_EQ(expected, grep(test_data, {"-i", "bAnAnA"}));
}

TEST(GrepTest, LineNumbers) {
    std::vector<std::string> expected = {"3:cherry 30"};
    EXPECT_EQ(expected, grep(test_data, {"-n", "cherry"}));
}

TEST(GrepTest, WholeWord) {
    std::vector<std::string> expected = {"apple 50", "apple pie 20"};
    EXPECT_EQ(expected, grep(test_data, {"-w", "apple"}));
}

TEST(GrepTest, CountMatches) {
    std::vector<std::string> expected = {"2"};
    EXPECT_EQ(expected, grep(test_data, {"-c", "apple"}));
}
