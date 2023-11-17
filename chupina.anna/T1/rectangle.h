#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "Shape.h"

namespace chupina {
  class Rectangle : public Shape {
    public:
      Rectangle() = delete;
      Rectangle(Point_t leftLowerAngle, Point_t rightUpperAngle);
      Rectangle(const Rectangle &) = delete;
      Rectangle(Rectangle &&) = delete;
      ~Rectangle() = default;

      Rectangle & operator=(const Rectangle &) = delete;
      Rectangle & operator=(Rectangle &&) = delete;

      double getArea() const override;
      chupina::Rectangle_t getFrameRect() const override;
      void move(const Point_t & destination) override;
      void move(const double x, const double y) override;
      Shape* clone() override;
    private:
      Point_t leftLowerAngle_, rightUpperAngle_, pos_;
      void doScale(const double factor) override;
  };
}

#endif

