#include "outputTable.h"
#include <cmath>
#include <iostream>
#include <iomanip>
#include "FactoringLn.h"

void oleynikova::outputTable(const double &absError, const size_t &numberMax, const double &start, const double &end, const double &step)
{
  for (double x = start + step; x < end; x += step) {
    oleynikova::FactoringLn ln(x);
    std::cout << std::setw(10) << x;
    std::cout << std::setw(20) << std::log(x + sqrt(x * x + 1));
    std::cout << std::setw(20) << getResult(ln, absError, numberMax) << "\n";
  }
}
