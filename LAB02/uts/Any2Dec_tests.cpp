#include <gtest/gtest.h>
#include "Any2Dec.h"

using namespace TaskFour;

class Any2DecTests : public ::testing::Test
{
protected:
    Any2DecTests() = default;

    ~Any2DecTests() override = default;
};

Any2Dec sutt;

TEST_F(Any2DecTests, ShouldThrowExceptionWhenBaseIsLessThanTwo)
{

    EXPECT_THROW({
        try
        {
            EXPECT_EQ(sutt.any2Dec("23", 1), 0);
            EXPECT_EQ(sutt.any2Dec("23", 37), 0);
        }
        catch (const std::out_of_range &e)
        {
            EXPECT_STREQ("Base cannot be less than 2 or more than thirtysix", e.what());
            throw;
        }
    }, std::exception);
}

class Any2DecTestsParameterizedTestFixture : public ::testing::TestWithParam<std::tuple<const char*, int, int>>
{
};

TEST_P(Any2DecTestsParameterizedTestFixture, OddYearsAreNotLeapYears)
{
    const char* inputValue = std::get<0>(GetParam());
    auto inputBase = std::get<1>(GetParam());
    auto output = std::get<2>(GetParam());
    EXPECT_EQ(output, sutt.any2Dec(inputValue, inputBase));
}

INSTANTIATE_TEST_SUITE_P(
        Any2DecTestsParameterizedTests,
        Any2DecTestsParameterizedTestFixture,
        ::testing::Values(
                std::make_tuple("16AH", 19, 9232)
//                std::make_tuple("23", 1, 0)
        ));

