#ifndef CIRCLE_H
#define CIRCLE_H
#include "Shape.h"

namespace chupina{
  class Circle: public Shape{
    public:
      Circle() = delete;
      Circle(Point_t pos, double R);
      Circle(const Circle &) = delete;
      Circle(Circle &&) = delete;
      ~Circle() = default;

      Circle & operator=(const Circle &) = delete;
      Circle & operator=(Circle &&) = delete;

      double getArea() const override;
      chupina::Rectangle_t getFrameRect() const override;
      void move(const Point_t & destination) override;
      void move(const double x, const double y) override;
      Shape* clone() override;
    private:
      Point_t pos_;
      double R_;
      void doScale(const double factor) override;
  };
}

#endif

