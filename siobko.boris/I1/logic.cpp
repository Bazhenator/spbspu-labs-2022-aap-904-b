#include "logic.h"
#include <iostream>
#include <limits>

void siobko::check_NumIfIsFloat(double &dblnum)
{
  if (dblnum != int(dblnum))
  {
    throw std::invalid_argument("Float numbers are not allowed !!!");
  }
}
void siobko::check_overflow(int &sum, int &summand)
{
  int imax = std::numeric_limits<int>::max();
  if (sum == imax && summand == 1)
  {
    throw std::overflow_error("Overflow !!!!");
  }
}
int siobko::enter_num()
{
  double num;
  std::cin >> num;
  if (!std::cin)
  {
    throw std::invalid_argument("Letters are not allowed !!!");
  }
  check_NumIfIsFloat(num);
  return int(num);
}
