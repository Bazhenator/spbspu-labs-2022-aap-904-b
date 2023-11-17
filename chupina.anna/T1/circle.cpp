#include "circle.h"
#include <stdexcept>
#include <cmath>

chupina::Circle::Circle(Point_t pos, double R):
  pos_(pos),
  R_(R)
{
  if (R <= 0) {
    throw std::runtime_error("Incorrect circle data");
  }
}

double chupina::Circle::getArea() const
{
  return M_PI * pow(R_, 2);
}
chupina::Rectangle_t chupina::Circle::getFrameRect() const
{
  return Rectangle_t {2 * R_, 2 * R_, pos_};
}
void chupina::Circle::move(const Point_t & destination)
{
  pos_.x_ = destination.x_;
  pos_.y_ = destination.y_;
}
void chupina::Circle::move(const double x, const double y)
{
  pos_.x_ += x;
  pos_.y_ += y;
}
void chupina::Circle::doScale(const double factor)
{
  R_ *= factor;
}
chupina::Shape* chupina::Circle::clone()
{
  Circle* temp = new Circle(pos_, R_);
  return temp;
}
