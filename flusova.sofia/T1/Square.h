#ifndef SQUARE_H
#define SQUARE_H
#include "Shape.h"

namespace flusova {
  class Square: public Shape {
  public:
    Square(const point_t& leftUnder_, const double& side_);
    ~Square() = default;
    double getArea() const override;
    flusova::rectangle_t getFrameRect() const override;
    void move(const point_t& point) override;
    void move(const double x, const double y) override;
    Square* clone() const noexcept override;
  private:
    void doScale(double coef) override;
    point_t centre_;
    double side_;
  };
}
#endif

