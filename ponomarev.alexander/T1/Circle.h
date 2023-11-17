#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"
#include "base-types.h"

namespace ponomarev {
  class Circle: public Shape {
    public:
      Circle() = delete;
      Circle(point_t centerPoint, double radius);
      Circle(const Circle &) = delete;
      Circle(Circle &&) = delete;
      ~Circle() = default;

      Circle &operator=(const Circle &) = delete;
      Circle &operator=(Circle &&) = delete;

      double getArea() const override;
      rectangle_t getFrameRect() const override;
      void move(const point_t &destination) override;
      void move(double x, double y) override;
      Circle *clone() const override;
    private:
      void doScale(double multiplier) override;

      double radius_;
      point_t centerPoint_;
  };
}

#endif
