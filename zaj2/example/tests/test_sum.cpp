#include <gtest/gtest.h>
#include "../src/sum.cpp"
// Definicje testów jednostkowych
TEST(SumTest, PositiveComponents)
{
    EXPECT_EQ(sum(1, 2), 3); // Sprawdź, czy funkcja 'sum()' dla a=1 i b=2 zwraca liczbę 3
    EXPECT_EQ(sum(2, 2), 4); 
}
TEST(SumTest, NegativeComponents)
{
    EXPECT_EQ(sum(-1, -2), -3);
    EXPECT_EQ(sum(-2, -2), -4);
}                