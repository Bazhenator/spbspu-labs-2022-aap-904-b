#ifndef TAYLOR_SERIES_SINH_H
#define TAYLOR_SERIES_SINH_H
#include <cstddef>

namespace flusova {
  class CalculateSinH {
  public:
    explicit CalculateSinH(size_t numberMax, double absError, double x);
    ~CalculateSinH() = default;
    double operator()();
    std::size_t numberMax_, cnt_;
    double absError_;
  private:
    double x_;
    double factorial_, deg_;
  };
  double calculateSinHLine(size_t numberMax, double absError, double x);
}

#endif


