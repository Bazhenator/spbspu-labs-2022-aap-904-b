#include "Rectangle.h"
#include <cmath>
#include <stdexcept>
#include "base-types.h"

oleynikova::Rectangle::Rectangle(point_t leftPoint, point_t rightPoint):
  leftPoint_(leftPoint),
  rightPoint_(rightPoint)
{
  if ((leftPoint.x_ > rightPoint.x_) || (leftPoint.y_ > rightPoint.y_)) {
    throw std::runtime_error("Incorrect parameters\n");
  }
  center_ = ((leftPoint_ + rightPoint_) * 0.5);
}

double oleynikova::Rectangle::getArea() const
{
  return (rightPoint_.x_ - leftPoint_.x_) * (rightPoint_.y_ - leftPoint_.y_);
}

void oleynikova::Rectangle::move(double x, double y)
{
  point_t distance{x, y};
  center_ = center_ + distance;
  leftPoint_ = leftPoint_ + distance;
  rightPoint_ = rightPoint_ + distance;
}

void oleynikova::Rectangle::move(const oleynikova::point_t &newCenter)
{
  double dx, dy;
  dx = newCenter.x_ - center_.x_;
  dy = newCenter.y_ - center_.y_;
  leftPoint_.x_ = leftPoint_.x_ + dx;
  leftPoint_.y_ = leftPoint_.y_ + dy;
  rightPoint_.x_ = rightPoint_.x_ + dx;
  rightPoint_.y_ = rightPoint_.y_ + dy;
  center_ = newCenter;
}

oleynikova::rectangle_t oleynikova::Rectangle::getFrameRect() const
{
  rectangle_t frameRect;
  frameRect.width_ = rightPoint_.x_ - leftPoint_.x_;
  frameRect.height_ = rightPoint_.y_ - leftPoint_.y_;
  frameRect.pos_ = center_;
  return frameRect;
}

void oleynikova::Rectangle::doScale(double rate)
{
  rectangle_t frameRect = getFrameRect();
  rightPoint_.x_ = center_.x_ + frameRect.width_ / 2 * rate;
  rightPoint_.y_ = center_.y_ + frameRect.height_ / 2 * rate;
  leftPoint_.x_ = center_.x_ - frameRect.width_ / 2 * rate;
  leftPoint_.y_ = center_.y_ - frameRect.height_ / 2 * rate;
}

oleynikova::Rectangle *oleynikova::Rectangle::clone() const
{
  Rectangle *temp = new Rectangle(leftPoint_, rightPoint_);
  return temp;
}
