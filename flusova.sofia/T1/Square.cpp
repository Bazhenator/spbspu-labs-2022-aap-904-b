#include "Square.h"
#include <stdexcept>

flusova::Square::Square(const point_t &leftUnder, const double &side) :
  centre_({leftUnder.x_ + (side) / 2, leftUnder.y_ + (side) / 2}),
  side_(side)
{
  if (side <= 0) {
    throw std::runtime_error("Incorrect values!");
  }
}
double flusova::Square::getArea() const
{
  return side_ * side_;
}
flusova::rectangle_t flusova::Square::getFrameRect() const
{
  return {side_, side_, centre_};
}
void flusova::Square::move(const double x, const double y)
{
  flusova::point_t add{x, y};
  centre_ += add;
}
void flusova::Square::move(const point_t &point)
{
  move(point.x_ - centre_.x_, point.y_ - centre_.y_);
}
void flusova::Square::doScale(double coef)
{
  side_ = coef * side_;
}
flusova::Square *flusova::Square::clone() const noexcept
{
  Square *cloneSquare = new Square({centre_.x_ - (side_ / 2), centre_.y_ - (side_ / 2)}, side_);
  return cloneSquare;
}
