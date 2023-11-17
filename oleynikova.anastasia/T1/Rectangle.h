#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "base-types.h"
#include "Shape.h"

namespace oleynikova {
  class Rectangle: public Shape {
  public:
    Rectangle() = delete;
    Rectangle(point_t leftPoint, point_t rightPoint);
    Rectangle(const Rectangle &) = delete;
    Rectangle(Rectangle &&) = delete;
    ~Rectangle() = default;
    Rectangle &operator=(const Rectangle &) = delete;
    Rectangle &operator=(Rectangle &&) = delete;
    rectangle_t getFrameRect() const override;
    double getArea() const override;
    void move(const point_t &newCenter) override;
    void move(double x, double y) override;
    Rectangle *clone() const override;
  private:
    void doScale(double rate) override;
    point_t leftPoint_;
    point_t rightPoint_;
    point_t center_;
  };
}

#endif
