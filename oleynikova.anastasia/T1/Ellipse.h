#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "base-types.h"
#include "Shape.h"

namespace oleynikova {
  class Ellipse: public Shape {
  public:
    Ellipse() = delete;
    Ellipse(point_t center, double verticRad, double horizontRad);
    Ellipse(const Ellipse &) = delete;
    Ellipse(Ellipse &&) = delete;
    ~Ellipse() = default;
    Ellipse &operator=(const Ellipse&) = delete;
    Ellipse &operator=(Ellipse &&) = delete;
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t &newCenter) override;
    void move(double x, double y) override;
    Ellipse *clone() const override;
  private:
    void doScale(double rate) override;
    point_t center_;
    double verticRad_;
    double horizontRad_;
  };
}

#endif
