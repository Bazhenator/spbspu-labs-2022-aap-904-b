#ifndef SINX_H
#define SINX_H
#include <cstddef>
#include <iostream>
#include <cmath>
namespace siobko
{
  class Sinx
  {
  public:
    Sinx(double x);
    ~Sinx() = default;
    long double operator()();

  private:
    long double x, originalX;
    size_t factorial = 1u, it = 1u;
  };
  long double calculateSinFunction(const double& absError, const double& x, const size_t& numberAmount);
  bool checkAccuracy(long double tmp, const double& absError);
  void outputAnswerLine(std::ostream& out, const double& x, const double& absError, const size_t& numbersAmount);
  void outputAnswerTable(std::ostream& out, const double& step, const double& begin, const double& end,
    const size_t& numbersAmount, const double& absError);
}
#endif
