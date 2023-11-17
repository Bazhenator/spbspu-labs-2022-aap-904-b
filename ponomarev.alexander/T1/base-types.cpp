#include "base-types.h"

ponomarev::point_t ponomarev::operator+(const point_t &left, const point_t &right)
{
  return point_t{left.x_ + right.x_, left.y_ + right.y_};
}
ponomarev::point_t ponomarev::operator-(const point_t &left, const point_t &right)
{
  return point_t{left.x_ - right.x_, left.y_ - right.y_};
}
ponomarev::point_t ponomarev::operator*(const point_t &left, const double right)
{
  return point_t{left.x_ * right, left.y_ * right};
}
bool ponomarev::operator==(const point_t &left, const point_t &right)
{
  return (left.x_ == right.x_) && (left.y_ == right.y_);
}
bool ponomarev::operator>(const point_t &left, const point_t &right)
{
  return (left.x_ > right.x_) && (left.y_ > right.y_);
}
std::istream &ponomarev::operator>>(std::istream &in, point_t &obj)
{
  return (in >> obj.x_ >> obj.y_);
}

std::ostream &ponomarev::operator<<(std::ostream &out, const rectangle_t &obj)
{
  return (out << obj.pos_.x_ - obj.width_*0.5 << ' ' << obj.pos_.y_ - obj.height_*0.5 <<
         ' ' << obj.pos_.x_ + obj.width_*0.5 << ' ' << obj.pos_.y_ + obj.height_*0.5);
}
