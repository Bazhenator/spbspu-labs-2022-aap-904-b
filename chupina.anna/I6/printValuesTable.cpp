#include "printValuesTable.h"
#include <iostream>
#include <cmath>
#include <iomanip>

void chupina::printValuesRow(const double & xValue, const double & absError,
                             const unsigned & termsAmount)
{
  std::cout << std::left << std::setw(10) << xValue <<
               std::left << std::setw(20) <<
               chupina::calculateExponentToThePowerOfX(xValue, absError, termsAmount) <<
               std::left << std::setw(10) << exp(xValue) << '\n';
}
void chupina::printValuesTable(const double & begin, const double & end, const double & step,
                               const unsigned & termsAmount, const double & absError)
{
  std::cout << std::left << std::setw(10) << "xValue" <<
               std::left << std::setw(20) << "function output" <<
               std::left << std::setw(10) << "standart function output" << '\n';
  for (double x = begin + step; x < end; x += step) {
    printValuesRow(x, absError, termsAmount);
  }
}
