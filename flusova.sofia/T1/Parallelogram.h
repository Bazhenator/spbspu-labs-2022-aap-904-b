#ifndef PARALLELOGRAM_H
#define PARALLELOGRAM_H
#include "Shape.h"

namespace flusova {
  class Parallelogram : public Shape {
  public:
    Parallelogram(const point_t &A, const point_t &B, const point_t &C);
    ~Parallelogram() = default;
    double getArea() const override;
    flusova::rectangle_t getFrameRect() const override;
    void move(const point_t &point) override;
    void move(const double x, const double y) override;
    Parallelogram *clone() const noexcept override;
  private:
    void doScale(double coef) override;
    point_t A_, B_, C_;
  };
}
#endif

