#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"
#include "base-types.h"

namespace ponomarev {
  class Rectangle: public Shape {
    public:
      Rectangle() = delete;
      Rectangle(const Rectangle &) = delete;
      Rectangle(Rectangle &&) = delete;
      Rectangle &operator=(const Rectangle &) = delete;
      Rectangle &operator=(Rectangle &&) = delete;

      Rectangle(point_t lowerLeftPoint, point_t upperRightPoint);
      ~Rectangle() = default;

      double getArea() const override;
      rectangle_t getFrameRect() const override;
      void move(const point_t &destination) override;
      void move(double x, double y) override;
      Rectangle *clone() const override;
    private:
      void doScale(double multiplier) override;

      point_t lowerLeftPoint_;
      point_t upperRightPoint_;
      point_t centerPoint_;
  };
}

#endif
