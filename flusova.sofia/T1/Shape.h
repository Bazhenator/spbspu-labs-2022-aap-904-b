#ifndef SHAPE_H
#define SHAPE_H
#include "base-types.h"

namespace flusova {
  class Shape {
  public:
    virtual ~Shape() = default;
    virtual double getArea() const = 0;
    virtual flusova::rectangle_t getFrameRect() const = 0;
    virtual void move(const point_t& point) = 0;
    virtual void move(const double x, const double y) = 0;
    void scale(double coef);
    virtual Shape* clone() const noexcept = 0;
  private:
    virtual void doScale(double coef) = 0;
  };
}
#endif

