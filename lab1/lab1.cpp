#include <iostream>
#include <utility>
#include <math.h>
#include "lab1.h"
//using namespace std;

std::pair <int,int> closest_pair_tonum(int n)
{
    for(int i = n; i>0; i--){
        for(int j = n-1; j>0; j--){
             if(i > j && (sqrt(i + j) == int(sqrt(i + j))) && (sqrt(i - j) == int(sqrt(i - j))) && (i < n)){
                //cout << "(" << i << ", " << j << ")" << endl;
                std::pair <int, int> answer;
                answer.first = i;
                answer.second = j;
                return answer;

        }
    }  
    }
    std::pair <int, int> answer;
    answer.first = 0;
    answer.second = 0;
    return answer;            
}

