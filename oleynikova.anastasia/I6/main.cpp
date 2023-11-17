#include <iostream>
#include "outputTable.h"
#include "FactoringLn.h"

int main()
{
  std::cout << "Enter accuracy, maximum number of terms, interval, step";
  double absError, step, start, end;
  size_t numberMax;
  std::cin >> absError >> numberMax >> start >> end >> step;
  if (!(std::cin) || (absError <= 0) || (step <= 0) || (start > end)) {
    std::cerr << "Invalid input";
    return 1;
  }
  try {
    oleynikova::outputTable(absError, numberMax, start, end, step);
  }
  catch (const std::runtime_error & e) {
    std::cout << e.what();
    return 1;
  }
  return 0;
}
