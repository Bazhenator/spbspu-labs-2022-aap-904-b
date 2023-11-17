#include "FactoringLn.h"
#include <cmath>
#include <iostream>

oleynikova::FactoringLn::FactoringLn(double x):
  x_(x),
  value_(x),
  denominator_(0.0)
{
  if ((x_ <= -1.0) || (x >= 1.0)) {
    throw std::runtime_error("Incorrect x");
  }
}

oleynikova::FactoringLn::~FactoringLn()
{}

double oleynikova::FactoringLn::operator()()
{
  denominator_ += 2.0;
  value_ = value_ * x_ * x_ * ((denominator_ - 1.0) * (denominator_- 1.0)) / (denominator_ * (denominator_ + 1.0));
  return value_;
}

double oleynikova::getResult(FactoringLn &x, const double &absError, const size_t &numberMax)
{
  oleynikova::FactoringLn ln(x);
  double result = x.x_;
  int sign = -1;
  for (double i = 1.0; ((i <= numberMax) && (abs(x.denominator_) > absError)); i += 1.0) {
    result += sign * ln();
    sign *= -1;
  }
  if (abs(x.denominator_) > absError) {
    throw std::runtime_error("AbsError was not reached");
  }
  return result;
}
