#include <iostream>
#include <utility>
#include <math.h>
#include "lab1.h"

std::pair<int, int> closest_pair_tonum(int n)
{
    std::pair<int, int> answer;
    bool is_sum_square;
    bool is_diff_square;

    for (int i = n; i > 0; i--)
    {
        for (int j = n - 1; j > 0; j--)
        {
            is_sum_square = sqrt(i + j) == int(sqrt(i + j));
            is_diff_square = (sqrt(i - j) == int(sqrt(i - j)));

            if (i > j && is_sum_square && is_diff_square && (i < n))
            {
                answer.first = i;
                answer.second = j;
                return answer;
            }
        }
    }
    
    answer.first = 0;
    answer.second = 0;
    return answer;
}
