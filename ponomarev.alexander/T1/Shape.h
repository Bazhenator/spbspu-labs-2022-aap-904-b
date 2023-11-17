#ifndef SHAPE_H
#define SHAPE_H
#include "base-types.h"

namespace ponomarev {
  class Shape {
    public:
      virtual ~Shape() {}
      virtual double getArea() const = 0;
      virtual rectangle_t getFrameRect() const = 0;
      virtual void move(const point_t &destination) = 0;
      virtual void move(double x, double y) = 0;
      void scale(double multiplier);
      virtual Shape *clone() const = 0;
    private:
      virtual void doScale(double multiplier) = 0;
  };
}

#endif
