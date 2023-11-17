#include "rectangle.h"
#include <stdexcept>

chupina::Rectangle::Rectangle(Point_t leftLowerAngle, Point_t rightUpperAngle) :
  leftLowerAngle_(leftLowerAngle),
  rightUpperAngle_(rightUpperAngle),
  pos_(Point_t{(leftLowerAngle.x_ + rightUpperAngle.x_) / 2, (leftLowerAngle.y_ + rightUpperAngle.y_) / 2})
{
  if (leftLowerAngle.x_ >= rightUpperAngle.x_ || leftLowerAngle.y_ >= rightUpperAngle.y_) {
    throw std::runtime_error ("Incorrect rectangle data");
  }
}

double chupina::Rectangle::getArea() const
{
  return (rightUpperAngle_.x_ - leftLowerAngle_.x_) * (rightUpperAngle_.y_ - leftLowerAngle_.y_);
}
chupina::Rectangle_t chupina::Rectangle::getFrameRect() const
{
  return Rectangle_t {rightUpperAngle_.x_ - leftLowerAngle_.x_, rightUpperAngle_.y_ - leftLowerAngle_.y_, pos_};
}
void chupina::Rectangle::move(const Point_t & destination)
{
  double difX = destination.x_ - pos_.x_;
  double difY = destination.y_ - pos_.y_;
  leftLowerAngle_ = {leftLowerAngle_.x_ + difX, leftLowerAngle_.y_ + difY};
  rightUpperAngle_ = {rightUpperAngle_.x_ + difX, rightUpperAngle_.y_ + difY};
  pos_ = destination;
}
void chupina::Rectangle::move(const double x, const double y)
{
  leftLowerAngle_.x_ += x;
  leftLowerAngle_.y_ += y;
  rightUpperAngle_.x_ += x;
  rightUpperAngle_.y_ += y;
  pos_.x_ += x;
  pos_.y_ += y;
}
void chupina::Rectangle::doScale(const double factor)
{
  Rectangle_t temp = getFrameRect();
  double difX = (temp.width_ - temp.width_ * factor) / 2.0;
  double difY = (temp.height_ - temp.height_ * factor) / 2.0;
  leftLowerAngle_.x_ += difX;
  leftLowerAngle_.y_ += difY;
  rightUpperAngle_.x_ -= difX;
  rightUpperAngle_.y_ -= difY;
}
chupina::Shape* chupina::Rectangle::clone()
{
  Rectangle* temp = new Rectangle(leftLowerAngle_, rightUpperAngle_);
  return temp;
}
