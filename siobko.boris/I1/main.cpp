#include <iostream>
#include "logic.h"
#include "CheckIfSecondMax.h"

int main()
{
  siobko::CheckIfSecondMax checkIfSecondMax;
  int num1, num2, num3, sum = 0;
  try
  {
    num1 = siobko::enter_num();
  }
  catch (const std::invalid_argument &err)
  {
    std::cout << err.what() << "\n";
    return 0;
  }
  try
  {
    num2 = siobko::enter_num();
  }
  catch (const std::invalid_argument &err)
  {
    std::cout << err.what() << "\n";
    return 0;
  }
  while (true)
  {
    try
    {
      num3 = siobko::enter_num();
    }
    catch (const std::invalid_argument &err)
    {
      std::cout << err.what() << "\n";
      return 0;
    }
    if (num3 == 0)
    {
      std::cout << sum;
      return 0;
    }
    try
    {
      bool ResultOfCondition = checkIfSecondMax(num1, num2, num3);
      int value = ((ResultOfCondition) ? 1 : 0);
      siobko::check_overflow(sum, value);
      sum += value;
    }
    catch (const std::overflow_error &e)
    {
      std::cout << e.what() << "\n";
      return 0;
    }
    num1 = num2;
    num2 = num3;
  }
  std::cout << sum;
}
