#include "Rectangle.h"
#include <stdexcept>

flusova::Rectangle::Rectangle(const flusova::point_t l, const flusova::point_t r):
  width_(r.x_ - l.x_),
  height_(r.y_ - l.y_),
  p_(flusova::point_t {(l.x_ + r.x_) / 2.0, (l.y_ + r.y_) / 2.0})
{
  if (width_ <= 0 || height_ <= 0)
  {
    throw std::runtime_error("Incorrect values!");
  }
}
double flusova::Rectangle::getArea() const {
  return width_ * height_;
}
flusova::rectangle_t flusova::Rectangle::getFrameRect() const {
  flusova::rectangle_t frameRect;
  frameRect.pos_.x_ = p_.x_;
  frameRect.pos_.y_ = p_.y_;
  frameRect.width_ = width_;
  frameRect.height_ = height_;
  return frameRect;
}
void flusova::Rectangle::move(const double x, const double y) {
  flusova::point_t add{x, y};
  p_ += add;
}
void flusova::Rectangle::move(const flusova::point_t& point) {
  p_ = point;
}
void flusova::Rectangle::doScale(double coef) {
  width_ *= coef;
  height_ *= coef;
}
flusova::Rectangle* flusova::Rectangle::clone() const noexcept {
  Rectangle* cloneRect = new Rectangle({p_.x_ - (width_ / 2), p_.y_ - (height_ / 2)},
                                       {p_.x_ + (width_ / 2), p_.y_ + (height_ / 2)});
  return cloneRect;
}
