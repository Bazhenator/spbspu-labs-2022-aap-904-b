#include "Parallelogram.h"
#include <stdexcept>
#include <cmath>

flusova::Parallelogram::Parallelogram(const flusova::point_t& A, const flusova::point_t& B, const flusova::point_t& C):
  A_(A),
  B_(B),
  C_(C)
{
  if (!((A_.y_ == B_.y_ || B_.y_ == C_.y_)) || (A_ == B_) || (A_ == C_) || (B_ == C_))
  {
    throw std::runtime_error("Invalid values!");
  }
}
double flusova::Parallelogram::getArea() const {
  if (A_.y_ == B_.y_)
  {
    return std::abs((A_.x_ - B_.x_) * (A_.y_ - C_.y_));
  }
  return std::abs((C_.x_ - B_.x_) * (A_.y_ - C_.y_));
}
flusova::rectangle_t flusova::Parallelogram::getFrameRect() const {
  double centreX = (A_.x_ + C_.x_) / 2;
  double centreY = (A_.y_ + C_.y_) / 2;
  double width_ = 2 * std::max(abs(centreX - C_.x_), abs(centreX - B_.x_));
  double height_ = 2 * std::max(abs(centreY - C_.y_), abs(centreY - B_.y_));
  return {width_, height_, {centreX, centreY}};
}
void flusova::Parallelogram::move(const double x, const double y) {
  flusova::point_t add{x, y};
  A_ += add;
  B_ += add;
  C_ += add;
}
void flusova::Parallelogram::move(const flusova::point_t& point) {
  move(point.x_ - (A_.x_ + C_.x_) / 2, point.y_ - (A_.y_ + C_.y_) / 2);
}
void flusova::Parallelogram::doScale(double coef) {
  flusova::point_t centre{getFrameRect().pos_.x_, getFrameRect().pos_.y_};
  double dX_A = A_.x_ - centre.x_, dY_A = A_.y_ - centre.y_;
  double dX_B = B_.x_ - centre.x_, dY_B = B_.y_ - centre.y_;
  double dX_C = C_.x_ - centre.x_, dY_C = C_.y_ - centre.y_;
  A_.x_ = centre.x_ + dX_A * coef; A_.y_ = centre.y_ + dY_A * coef;
  B_.x_ = centre.x_ + dX_B * coef; B_.y_ = centre.y_ + dY_B * coef;
  C_.x_ = centre.x_ + dX_C * coef; C_.y_ = centre.y_ + dY_C * coef;
}
flusova::Parallelogram* flusova::Parallelogram::clone() const noexcept {
  Parallelogram* cloneParal = new Parallelogram(A_, B_, C_);
  return cloneParal;
}
