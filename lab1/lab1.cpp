#include <iostream>
#include <utility>
#include <math.h>
#include "lab1.h"

std::pair<int, int> closest_pair_tonum(int n)
{
    std::pair<int, int> answer;;

    for (int i = n; i > 0; i--)
    {
        for (int j = n - 1; j > 0; j--)
        {
            bool is_sum_square = sqrt(i + j) == int(sqrt(i + j));
            bool is_diff_square = (sqrt(i - j) == int(sqrt(i - j)));
            bool is_finded = i > j 
                && is_sum_square 
                && is_diff_square 
                && i < n;

            if (is_finded)
            {
                return {i, j};
            }
        }
    }

    return {0, 0};
}
