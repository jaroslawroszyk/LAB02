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

TEST_F(Dec2AnyTests, ConvertNegativeNumbersToPositive)
{
    EXPECT_EQ(su.convertNegativeToPositive(-1), 1);
    EXPECT_EQ(su.convertNegativeToPositive(-100), 100);
    EXPECT_EQ(su.convertNegativeToPositive(10), 10);
    EXPECT_EQ(su.convertNegativeToPositive(-1000), 1000);
}

TEST_F(Dec2AnyTests, GivenStringShouldBeReverse)
{
    std::string input {"wsb"};
    su.reverseStr(input);
    std::string output {"bsw"};
    EXPECT_EQ(input, output);
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
                std::make_tuple(2022, 2, "11111100110"),
                std::make_tuple(100, 4, "1210"),
                std::make_tuple(169, 4, "2221"),
                std::make_tuple(21, 5, "41"),
                std::make_tuple(691, 5, "10231"),
                std::make_tuple(1231, 5, "14411"),
                std::make_tuple(21, 7, "30"),
                std::make_tuple(512, 7, "1331"),
                std::make_tuple(312, 9, "376"),
                std::make_tuple(3214312, 9, "6038177"),
                std::make_tuple(21, 11, "1A"),
                std::make_tuple(21241, 11, "14A60"),
                std::make_tuple(164, 11, "13A"),
                std::make_tuple(231, 13, "14A"),
                std::make_tuple(23123, 13, "A6A9"),
                std::make_tuple(112, 15, "77"),
                std::make_tuple(11212, 15, "34C7"),
                std::make_tuple(41, 17, "27"),
                std::make_tuple(4112, 17, "E3F"),
                std::make_tuple(41122, 17, "864G"),
                std::make_tuple(232, 19, "C4"),
                std::make_tuple(9232, 19, "16AH"),
                std::make_tuple(412, 21, "JD"),
                std::make_tuple(424, 21, "K4"),
                std::make_tuple(412, 23, "HL"),
                std::make_tuple(21345, 23, "1H81")));


