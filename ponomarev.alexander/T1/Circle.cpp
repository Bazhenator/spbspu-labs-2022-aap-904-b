#include "Circle.h"
#include <stdexcept>
#include <cmath>

ponomarev::Circle::Circle(point_t centerPoint, double radius):
  radius_(radius),
  centerPoint_(centerPoint)
{
  if (radius <= 0) {
    throw std::runtime_error("Circle parameters aren't correct.\n");
  }
}
double ponomarev::Circle::getArea() const
{
  return 2 * std::acos(0.0) * radius_ * radius_;
}
ponomarev::rectangle_t ponomarev::Circle::getFrameRect() const
{
  rectangle_t temp;
  temp.width_ = 2 * radius_;
  temp.height_= 2 * radius_;
  temp.pos_ = centerPoint_;
  return temp;
}
void ponomarev::Circle::move(const point_t &destination)
{
  centerPoint_ = destination;
}
void ponomarev::Circle::move(double x, double y)
{
  centerPoint_ = point_t{centerPoint_.x_ + x, centerPoint_.y_ + y};
}
void ponomarev::Circle::doScale(double multiplier)
{
  radius_ *= multiplier;
}
ponomarev::Circle *ponomarev::Circle::clone() const
{
  return new Circle(centerPoint_, radius_);
}
