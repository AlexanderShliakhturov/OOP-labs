#include "lab1.h"
#include <gtest/gtest.h>
#include <utility>



TEST(test_01, basic_test_10)
{
    std::pair<int, int> result = closest_pair_tonum(10);
    ASSERT_TRUE(result == std::make_pair(5, 4));
}

TEST(test_02, basic_test_50)
{
    std::pair<int, int> result = closest_pair_tonum(50);
    ASSERT_TRUE(result == std::make_pair(45, 36));
}

TEST(test_03, basic_test_30)
{
    std::pair<int, int> result = closest_pair_tonum(30);
    ASSERT_TRUE(result == std::make_pair(29, 20));
}

TEST(test_04, with_no_answer)
{
    std::pair<int, int> result = closest_pair_tonum(4);
    ASSERT_TRUE(result == std::make_pair(0, 0));
}

TEST(test_05, zero)
{
    std::pair<int, int> result = closest_pair_tonum(0);
    ASSERT_TRUE(result == std::make_pair(0, 0));
}

TEST(test_06, below_zero)
{
    std::pair<int, int> result = closest_pair_tonum(-999);
    ASSERT_TRUE(result == std::make_pair(0, 0));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}