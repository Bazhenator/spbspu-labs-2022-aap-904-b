#include "CheckIfSecondMax.h"

bool siobko::ResultOfCondition(int num1, int num2, int num3)
{
  return ((num2 > num3 && num2 > num1) ? true : false);
}
bool siobko::CheckIfSecondMax::operator()(int num1, int num2, int num3)
{
  return ResultOfCondition(num1, num2, num3);
}
