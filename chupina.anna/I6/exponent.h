#ifndef EXPONENT_H
#define EXPONENT_H
#include <cstddef>

namespace chupina {
  class ExponentToThePowerOfX
  {
    public:
      explicit ExponentToThePowerOfX(double xValue);
      ~ExponentToThePowerOfX() = default;
      double operator()();
    private:
      double x_;
      unsigned long long factorial_;
      unsigned number_;
  };
  double calculateExponentToThePowerOfX(const double & x, const double & absError, const unsigned & termsAmount);
}

#endif
