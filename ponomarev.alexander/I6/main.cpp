#include <iostream>
#include <cstddef>
#include <cmath>
#include "taylorsRow.h"

int main()
{
  std::cout << "Enter accuracy, max number, interval and step:\n";
  double absError, step;
  double interval[2] = {-1, 1};
  std::size_t numberMax;
  std::cin >> absError >> numberMax >> interval[0] >> interval[1] >> step;
  if (std::cin.fail() || step <= 0 || absError <= 0 || interval[0] >= interval[1] ||
                         std::abs(std::max<double>(interval[0], interval[1])) > 1) {
    std::cerr << "Error: Not valid data.";
    return 1;
  }
  std::cout << std::left << std::setw(25) << "x:" <<
               std::left << std::setw(25)<< "Function data:" <<
               std::left << std::setw(25)<< "Built-in function data:" << std::endl;
  for (double x = interval[0] + step; x < interval[1]; x += step) {
    try {
      std::cout << std::left << std::setw(25) << x <<
                   std::left << std::setw(25)<< ponomarev::calculateTaylorsRow(x, absError, numberMax) <<
                   std::left << std::setw(25)<< asin(x) << std::endl;
    } catch (const std::runtime_error &e) {
      std::cout << std::left << std::setw(25) << "Accuracy isn't reached." << std::left << std::setw(25) << asin(x) << std::endl;
    }
  }
  return 0;
}
