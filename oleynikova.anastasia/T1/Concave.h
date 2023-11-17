#ifndef CONCAVE_H
#define CONCAVE_H

#include "base-types.h"
#include "Shape.h"

namespace oleynikova {
  class Concave: public Shape {
  public:
    Concave() = delete;
    Concave(point_t left, point_t upper, point_t right, point_t inner);
    Concave(const Concave &) = delete;
    Concave(Concave &&) = delete;
    ~Concave() = default;
    Concave &operator=(const Concave &) = delete;
    Concave &operator=(Concave &&) = delete;
    double getArea() const override;
    void move(const point_t &newCenter) override;
    void move(double x, double y) override;
    rectangle_t getFrameRect() const override;
    Concave *clone() const override;
  private:
    void doScale(double rate) override;
    point_t left_, upper_, inner_, right_, center_;
  };
}

#endif
