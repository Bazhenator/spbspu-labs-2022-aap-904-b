#ifndef GET_RESULT_H
#define GET_RESULT_H

#include <cstddef>

namespace oleynikova {
  class FactoringLn
  {
  public:
    explicit FactoringLn(double x);
    ~FactoringLn();
    double operator()();
    friend double getResult(FactoringLn &x, const double & absError, const size_t & numberMax);
  private:
    double x_;
    double value_;
    double denominator_;
  };
  double getResult(FactoringLn &x, const double & absError, const size_t & numberMax);
}

#endif
