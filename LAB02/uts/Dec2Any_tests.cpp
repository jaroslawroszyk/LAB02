#include <gtest/gtest.h>
#include "Dec2Any.h"
#include <string>
#include <vector>

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

TEST_F(Dec2AnyTests, ConvertNegativeNumbersToPositive)
{
    EXPECT_EQ(su.convertNegativeToPositive(-1), 1);
    EXPECT_EQ(su.convertNegativeToPositive(-100), 100);
    EXPECT_EQ(su.convertNegativeToPositive(10), 10);
    EXPECT_EQ(su.convertNegativeToPositive(-1000), 1000);
}

TEST_F(Dec2AnyTests, foo)
{
    //do it with params test
    EXPECT_EQ(su.dec2Any(120, 16), "78");
}

class Dec2AnyTestsParameterizedTestFixture : public ::testing::TestWithParam<std::tuple<int, int, std::string>>
{
};

TEST_P(Dec2AnyTestsParameterizedTestFixture, OddYearsAreNotLeapYears)
{
    auto inputValue = std::get<0>(GetParam());
    auto inputBase = std::get<1>(GetParam());
    auto output = std::get<2>(GetParam());
    EXPECT_EQ(output, su.dec2Any(inputValue, inputBase));
}

INSTANTIATE_TEST_SUITE_P(
        Dec2AnyTestsParameterizedTest,
        Dec2AnyTestsParameterizedTestFixture,
        ::testing::Values(
                std::make_tuple(23, 1, "0"),
                std::make_tuple(6923, 0, "0"),
                std::make_tuple(673, 37, "0"),
                std::make_tuple(13, 372, "0"),
                std::make_tuple(-13, 2, "1101"),
                std::make_tuple(123, 2, "1111011"),
                std::make_tuple(2022, 2, "11111100110")
        ));


