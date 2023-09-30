#include <gtest/gtest.h>
#include <utility>

#include "main_func.h"
#include "functions.h"
#include "DynamicArray.h"
#include "Octal.h"
#include "main_func.h"

//7467 - 756 = 6511

TEST(test_01, diff_throw_dights)
{
    // Arrange:
    std::string first = "7467";
    std::string second = "756";
    char operand = '-';
    // Act:
    Octal result = main_func(first, operand, second);
    // Assert:
    ASSERT_TRUE(result.to_string() == Octal("6511").to_string());
}

TEST(test_01, equa_minus_equal)
{
    // Arrange:
    std::string first = "7777";
    std::string second = "7777";
    char operand = '-';
    // Act:
    Octal result = main_func(first, operand, second);
    // Assert:
    ASSERT_TRUE(result.to_string() == Octal("0000").to_string());
}

TEST(test_01, zero_minus_zero)
{
    // Arrange:
    std::string first = "0";
    std::string second = "0";
    char operand = '-';
    // Act:
    Octal result = main_func(first, operand, second);
    // Assert:
    ASSERT_TRUE(result.to_string() == Octal("0").to_string());
}

TEST(test_01, zero_plus_zero)
{
    // Arrange:
    std::string first = "0";
    std::string second = "0";
    char operand = '+';
    // Act:
    Octal result = main_func(first, operand, second);
    // Assert:
    ASSERT_TRUE(result.to_string() == Octal("0").to_string());
}

TEST(test_01, sum_throw_dight)
{
    // Arrange:
    std::string first = "7777";
    std::string second = "77";
    char operand = '+';
    // Act:
    Octal result = main_func(first, operand, second);
    // Assert:
    ASSERT_TRUE(result.to_string() == Octal("10076").to_string());
}

TEST(test_01, easy_sum)
{
    // Arrange:
    std::string first = "123";
    std::string second = "123";
    char operand = '+';
    // Act:
    Octal result = main_func(first, operand, second);
    // Assert:
    ASSERT_TRUE(result.to_string() == Octal("246").to_string());
}

TEST(test_01, more_more_than_less)
{
    // Arrange:
    std::string first = "777";
    std::string second = "7";
    char operand = '>';
    // Act:
    std::string result = Octal(first).more_than(Octal(second));
    // Assert:
    ASSERT_TRUE(result == "TRUE");
}

TEST(test_01, more_less_than_less)
{
    // Arrange:
    std::string first = "777";
    std::string second = "7";
    char operand = '<';
    // Act:
    std::string result = Octal(first).less_than(Octal(second));
    // Assert:
    ASSERT_TRUE(result == "FALSE");
}

TEST(test_01, zer0_equal_zero)
{
    // Arrange:
    std::string first = "0";
    std::string second = "0";
    char operand = '=';
    // Act:
    std::string result = Octal(first).equal(Octal(second));
    // Assert:
    ASSERT_TRUE(result == "TRUE");
}

TEST(test_01, zero_more_than_zero)
{
    // Arrange:
    std::string first = "0";
    std::string second = "0";
    char operand = '>';
    // Act:
    std::string result = Octal(first).more_than(Octal(second));
    // Assert:
    ASSERT_TRUE(result == "FALSE");
}

TEST(test_01, zero_less_than_zero)
{
    // Arrange:
    std::string first = "0";
    std::string second = "0";
    char operand = '<';
    // Act:
    std::string result = Octal(first).less_than(Octal(second));
    // Assert:
    ASSERT_TRUE(result == "FALSE");
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}