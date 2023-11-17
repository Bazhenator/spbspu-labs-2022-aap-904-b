#include <iostream>
#include "exponent.h"
#include "printValuesTable.h"

int main()
{
  double absError, intervalBegin, intervalEnd, step;
  size_t termsAmount;
  std::cin >> absError >> termsAmount >> intervalBegin >> intervalEnd >> step;
  if (!std::cin || step <= 0 || intervalBegin > intervalEnd || termsAmount <= 0 || absError <= 0) {
    std::cerr << "Incorrect data";
    return 1;
  }
  try {
    chupina::printValuesTable(intervalBegin, intervalEnd, step, termsAmount, absError);
  } catch (const std::exception& e) {
    std::cout << e.what() << '\n';
    return 1;
  }
  return 0;
}
