#include "lab1.h"
#include <gtest/gtest.h>
#include <utility>



TEST(test_01, basic_test_10)
{
    // Arrange:
    int n = 10;
    // Act:
    std::pair<int, int> result = closest_pair_tonum(n);
    // Assert:
    ASSERT_TRUE(result == std::make_pair(5, 4));
}

TEST(test_02, basic_test_50)
{
    int n = 50;

    std::pair<int, int> result = closest_pair_tonum(n);

    ASSERT_TRUE(result == std::make_pair(45, 36));
}

TEST(test_03, basic_test_30)
{
    int n = 30;

    std::pair<int, int> result = closest_pair_tonum(n);

    ASSERT_TRUE(result == std::make_pair(29, 20));
}

TEST(test_04, with_no_answer)
{
    int n = 4;

    std::pair<int, int> result = closest_pair_tonum(n);
    
    ASSERT_TRUE(result == std::make_pair(0, 0));
}

TEST(test_05, zero)
{
    int n = 0;

    std::pair<int, int> result = closest_pair_tonum(n);

    ASSERT_TRUE(result == std::make_pair(0, 0));
}

TEST(test_06, below_zero)
{
    int n = -999;

    std::pair<int, int> result = closest_pair_tonum(n);
    
    ASSERT_TRUE(result == std::make_pair(0, 0));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}