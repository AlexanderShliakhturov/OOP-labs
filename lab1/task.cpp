#include <iostream>
#include <utility>
#include "lab1.h"
using namespace std;

int main()
{
  int n;
  std::cout << "enter value: ";
  std::cin  >> n;
  pair <int,int> ans = closest_pair_tonum(n);
  std::cout << ans.first << "," << ans.second << std::endl;

  return 0;
}