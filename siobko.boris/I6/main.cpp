#include "outputdata.h"
#include <iostream>
#include <cstddef>

int main()
{
  size_t numbersAmount;
  double step, absError, begin, end;
  std::cin >> absError >> numbersAmount >> begin >> end >> step;
  try
  {
    if (!std::cin || absError <= 0.0 || begin > end || numbersAmount <= 0u || step <= 0.0)
    {
      throw std::invalid_argument("Incorrect data");
    }
    siobko::outputAnswerTable(std::cout, step, begin, end, numbersAmount, absError);
    return 0;
  }
  catch (const std::exception& err)
  {
    std::cerr << err.what();
    return 1;
  }
}
