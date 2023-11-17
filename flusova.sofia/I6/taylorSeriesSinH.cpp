#include "taylorSeriesSinH.h"
#include <iostream>
#include <climits>

flusova::CalculateSinH::CalculateSinH(size_t numberMax, double absError, double x):
  numberMax_(numberMax),
  cnt_(1),
  absError_(absError),
  x_(x),
  factorial_(1),
  deg_(x)
{
  if (x < -1 || x > 1)
  {
    throw std::out_of_range("Value must be in entered range!");
  }
}

double flusova::CalculateSinH::operator()() {
  double currentMember = deg_ / factorial_;
  deg_ *= x_ * x_;
  factorial_ *= (cnt_ + 1) * (cnt_ + 2);
  cnt_ += 2;
  return currentMember;
}
double flusova::calculateSinHLine(size_t numberMax, double absError, double x) {
  double sum = 0.0, lastArg;
  flusova::CalculateSinH example(numberMax, absError, x);
  while (example.cnt_ < example.numberMax_ * 2)
  {
    if (INT_MAX - 1 < sum)
    {
      throw std::runtime_error("Overflow!");
    } else {
      sum += example.operator()();
    }
  }
  lastArg = example.operator()();
  if (lastArg > example.absError_)
  {
    throw std::runtime_error("Accuracy hasn't been achieved!");
  }
  return sum;
}
