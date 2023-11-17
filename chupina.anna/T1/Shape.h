#ifndef SHAPE_H
#define SHAPE_H
#include <string>
#include "base-types.h"

namespace chupina {
  class Shape {
  public:
    virtual ~Shape() = default;
    virtual double getArea() const = 0;
    virtual chupina::Rectangle_t getFrameRect() const = 0;
    virtual void move(const Point_t & destination) = 0;
    virtual void move(const double x, const double y) = 0;
    void scale(const double factor);
    virtual Shape* clone() = 0;
  private:
    virtual void doScale(const double factor) = 0;
  };
}

#endif
