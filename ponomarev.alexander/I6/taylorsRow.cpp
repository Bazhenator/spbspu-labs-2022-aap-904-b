#include "taylorsRow.h"
#include <cmath>

double ponomarev::calculateTaylorsRow(const double x, const double absError, std::size_t numberMax)
{
  double summ = 0;
  double value = x;
  double denumirator = 0;
  while ((std::abs(value) > absError) && (numberMax--)) {
    summ += value;
    denumirator += 2.0;
    value = value * x * x * ((denumirator - 1.0) * (denumirator - 1.0)) / (denumirator * (denumirator + 1.0));
  }
  if (std::abs(value) > absError) {
    throw std::runtime_error("Accuracy isn't reached.");
  }
  return summ;
}
