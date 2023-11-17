#include "exponent.h"
#include <iostream>
#include <cmath>

chupina::ExponentToThePowerOfX::ExponentToThePowerOfX(double xValue):
  x_(xValue),
  factorial_(1.0),
  number_(2)
{
  if (x_ <= -1 || x_ >= 1) {
    throw std::out_of_range("x value must be in (-1; 1)");
  }
}
double chupina::ExponentToThePowerOfX::operator()()
{
  x_ *= x_;
  factorial_ *= number_++;
  return (x_ / factorial_);
}
double chupina::calculateExponentToThePowerOfX(const double & x, const double & absError,
                                                                 const unsigned & termsAmount)
{
  chupina::ExponentToThePowerOfX exponent(x);
  double exp = 1 + x;
  double term = x;
  for (size_t i = 2; i < termsAmount && std::abs(term) > absError; i++) {
    term = exponent();
    exp += term;
  }
  if (term > absError) {
    throw std::runtime_error("Accuracy hasn't been reached");
  }
  return exp;
}
