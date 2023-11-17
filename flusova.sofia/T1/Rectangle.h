#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "Shape.h"

namespace flusova {
  class Rectangle : public Shape {
  public:
    Rectangle(const point_t l, const point_t r);
    ~Rectangle() = default;
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t& point) override;
    void move(const double x, const double y) override;
    Rectangle * clone() const noexcept override;
  private:
    void doScale(double coef) override;
    double width_, height_;
    point_t p_;
  };
}
#endif
