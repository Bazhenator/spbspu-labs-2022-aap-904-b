#ifndef SHAPE_H
#define SHAPE_H

#include "base-types.h"

namespace oleynikova {
  class Shape {
  public:
    virtual ~Shape() = default;
    virtual double getArea() const = 0;
    virtual void move(const point_t &newCenter) = 0;
    virtual void move(double x, double y) = 0;
    virtual rectangle_t getFrameRect() const = 0;
    void scale(double rate);
    virtual Shape *clone() const = 0;
  private:
    virtual void doScale(double rate) = 0;
  };
}

#endif
