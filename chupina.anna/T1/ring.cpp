#include "ring.h"
#include <stdexcept>
#include <cmath>

chupina::Ring::Ring(Point_t pos, double R, double r) :
  pos_(pos),
  R_(R),
  r_(r)
{
  if (R <= 0 || r <= 0 || R <= r) {
    throw std::runtime_error("Incorrect ring data");
  }
}

double chupina::Ring::getArea() const
{
  return M_PI * (pow(R_, 2) - pow(r_, 2));
}
chupina::Rectangle_t chupina::Ring::getFrameRect() const
{
  return Rectangle_t{ 2 * R_, 2 * R_, pos_ };
}
void chupina::Ring::move(const Point_t & destination)
{
  pos_.x_ = destination.x_;
  pos_.y_ = destination.y_;
}
void chupina::Ring::move(const double x, const double y)
{
  pos_.x_ += x;
  pos_.y_ += y;
}
void chupina::Ring::doScale(const double factor)
{
  R_ *= factor;
  r_ *= factor;
}
chupina::Shape* chupina::Ring::clone()
{
  Ring* temp = new Ring(pos_, R_, r_);
  return temp;
}
