#ifndef COMPLEXQUAD_H
#define COMPLEXQUAD_H

#include "Shape.h"
#include "base-types.h"

namespace ponomarev {
  class Complexquad: public Shape {
    public:
      Complexquad() = delete;
      Complexquad(point_t lowerLeftPoint, point_t upperRightPoint, point_t lowerRightPoint, point_t upperLeftPoint);
      Complexquad(const Complexquad &) = delete;
      Complexquad(Complexquad &&) = delete;
      ~Complexquad() = default;

      Complexquad &operator=(const Complexquad &) = delete;
      Complexquad &operator=(Complexquad &&) = delete;

      double getArea() const override;
      rectangle_t getFrameRect() const override;
      void move(const point_t &destination) override;
      void move(double x, double y) override;
      Complexquad *clone() const override;
    private:
      void doScale(double multiplier) override;

      point_t lowerLeftPoint_;
      point_t upperRightPoint_;
      point_t lowerRightPoint_;
      point_t upperLeftPoint_;
      point_t centerPoint_;
  };
}

#endif
