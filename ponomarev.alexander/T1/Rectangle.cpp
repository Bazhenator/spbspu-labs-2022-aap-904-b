#include "Rectangle.h"
#include <stdexcept>
#include <cmath>

ponomarev::Rectangle::Rectangle(point_t lowerLeftPoint, point_t upperRightPoint):
  lowerLeftPoint_(lowerLeftPoint),
  upperRightPoint_(upperRightPoint)
{
  if (!(upperRightPoint_ > lowerLeftPoint_)) {
    throw std::runtime_error("Rectangle parameters aren't correct.\n");
  }
  centerPoint_ = (lowerLeftPoint_ + upperRightPoint_)*0.5;
}
double ponomarev::Rectangle::getArea() const
{
  return std::abs(upperRightPoint_.x_ - lowerLeftPoint_.x_) * std::abs(upperRightPoint_.y_ - lowerLeftPoint_.y_);
}
ponomarev::rectangle_t ponomarev::Rectangle::getFrameRect() const
{
  rectangle_t temp;
  temp.width_ = std::abs(upperRightPoint_.x_ - lowerLeftPoint_.x_);
  temp.height_ = std::abs(upperRightPoint_.y_ - lowerLeftPoint_.y_);
  temp.pos_ = centerPoint_;
  return temp;
}
void ponomarev::Rectangle::move(const point_t &destination)
{
  centerPoint_ = destination;
  rectangle_t temp = getFrameRect();
  upperRightPoint_.x_ = centerPoint_.x_ + temp.width_ / 2;
  upperRightPoint_.y_ = centerPoint_.y_ + temp.height_ / 2;
  lowerLeftPoint_.x_ = centerPoint_.x_ - temp.width_ / 2;
  lowerLeftPoint_.y_ = centerPoint_.y_ - temp.height_ / 2;
}
void ponomarev::Rectangle::move(double x, double y)
{
  upperRightPoint_.x_ += x;
  upperRightPoint_.y_ += y;
  lowerLeftPoint_.x_ += x;
  lowerLeftPoint_.y_ += y;
  centerPoint_.x_ += x;
  centerPoint_.y_ += y;
}
void ponomarev::Rectangle::doScale(double multiplier)
{
  rectangle_t temp = getFrameRect();
  upperRightPoint_.x_ = centerPoint_.x_ + temp.width_ / 2 * multiplier;
  upperRightPoint_.y_ = centerPoint_.y_ + temp.height_ / 2 * multiplier;
  lowerLeftPoint_.x_ = centerPoint_.x_ - temp.width_ / 2 * multiplier;
  lowerLeftPoint_.y_ = centerPoint_.y_ - temp.height_ / 2 * multiplier;
}
ponomarev::Rectangle *ponomarev::Rectangle::clone() const
{
  return new Rectangle(lowerLeftPoint_, upperRightPoint_);
}
