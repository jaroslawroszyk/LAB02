#include <gtest/gtest.h>
#include "Dec2Any.h"

using namespace TaskThree;

class Dec2AnyTests : public ::testing::Test
{
protected:
    Dec2AnyTests() = default;

    ~Dec2AnyTests() override = default;
};

Dec2Any su;

TEST_F(Dec2AnyTests, GivenBaseIsLessThanTwoAndMoreThan36ShouldReturnZero)
{
    EXPECT_EQ(su.dec2Any(122, 1), "0");
    EXPECT_EQ(su.dec2Any(122, 37), "0");
}

TEST_F(Dec2AnyTests,ConvertNegativeNumbersToPositive)
{
    EXPECT_EQ(su.convertNegativeNumberToPositive(-1),1);
    EXPECT_EQ(su.convertNegativeNumberToPositive(-100),100);
    EXPECT_EQ(su.convertNegativeNumberToPositive(10),10);
    EXPECT_EQ(su.convertNegativeNumberToPositive(-1000),1000);
}

TEST_F(Dec2AnyTests,foo)
{
    //do it with params test
    EXPECT_EQ(su.dec2Any(120,16),"78");
}