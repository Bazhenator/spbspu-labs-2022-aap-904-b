#include "base-types.h"

oleynikova::point_t oleynikova::operator-(const point_t &leftPoint, const point_t rightPoint)
{
  oleynikova::point_t result;
  result.x_ = leftPoint.x_ - rightPoint.x_;
  result.y_ = leftPoint.y_ - rightPoint.y_;
  return result;
}

oleynikova::point_t oleynikova::operator+(const point_t &leftPoint, const point_t rightPoint)
{
  oleynikova::point_t result;
  result.x_ = leftPoint.x_ + rightPoint.x_;
  result.y_ = leftPoint.y_ + rightPoint.y_;
  return result;
}

oleynikova::point_t oleynikova::operator*(const point_t &point, const double rate)
{
  oleynikova::point_t result;
  result.x_ = point.x_ * rate;
  result.y_ = point.y_ * rate;
  return result;
}
