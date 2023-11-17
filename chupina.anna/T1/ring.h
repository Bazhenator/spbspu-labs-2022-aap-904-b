#ifndef RING_H
#define RING_H
#include "Shape.h"

namespace chupina {
  class Ring : public Shape {
    public:
      Ring() = delete;
      Ring(Point_t pos, double R, double r);
      Ring(const Ring &) = delete;
      Ring(Ring &&) = delete;
      ~Ring() = default;

      Ring & operator=(const Ring &) = delete;
      Ring & operator=(Ring &&) = delete;

      double getArea() const override;
      chupina::Rectangle_t getFrameRect() const override;
      void move(const Point_t & destination) override;
      void move(const double x, const double y) override;
      Shape* clone() override;
    private:
      Point_t pos_;
      double R_, r_;
      void doScale(const double factor) override;
  };
}

#endif


