#include "Concave.h"
#include <cmath>
#include <stdexcept>
#include <algorithm>
#include "base-types.h"

oleynikova::Concave::Concave(point_t left, point_t upper, point_t right, point_t inner) :
  left_(left),
  upper_(upper),
  inner_(inner),
  right_(right)
{
  double a = sqrt(pow((upper_.y_ + left_.y_), 2) + pow((upper_.y_ - left_.y_), 2));
  double b = sqrt(pow((right_.y_ + upper_.y_), 2) + pow((right_.y_ - upper_.y_), 2));
  double c = sqrt(pow((right_.y_ + left_.y_), 2) + pow((right_.y_ - left_.y_), 2));
  if ((a < b + c) && (b < c + a) && (c < a + b)) {
    a = (left_.x_ - inner_.x_) * (upper_.y_ - left_.y_) - (upper_.x_ - left_.x_) * (left_.y_ - inner_.y_);
    b = (upper_.x_ - inner_.x_) * (right_.y_ - upper_.y_) - (right_.x_ - upper_.x_) * (upper_.y_ - inner_.y_);
    c = (right_.x_ - inner_.x_) * (left_.y_ - right_.y_) - (left_.x_ - right_.x_) * (right_.y_ - inner_.y_);
    if ((a > 0 && b > 0 && c > 0) || (a < 0 && b < 0 && c < 0)) {
      center_ = inner_;
    }
  }
  else {
    throw std::runtime_error("Incorrect parameters\n");
  }
}

double oleynikova::Concave::getArea() const
{
  rectangle_t frameRect = this->getFrameRect();
  double p1 = (upper_.y_ - left_.y_) * (upper_.x_ - left_.x_) / 2;
  double p2 = (right_.x_ - upper_.x_) * (upper_.y_ - right_.y_) / 2;
  double p3 = 0;
  double p4 = 0;
  if (upper_.y_ > right_.y_) {
    p3 = (right_.x_ - left_.x_) * (inner_.y_ - left_.y_) / 2;
    p4 = (right_.y_ - left_.y_) * (right_.x_ - inner_.x_) / 2;
  }
  else {
    p3 = (right_.x_ - left_.x_) * (frameRect.height_) / 2;
    p4 = (inner_.y_ - left_.y_) * (frameRect.width_) / 2;
  }
  return ((frameRect.width_ * frameRect.height_) - p1 - p2 - p3 - p4);
}

void oleynikova::Concave::move(double x, double y)
{
  point_t temp{x, y};
  left_ = left_ + temp;
  right_ = right_ + temp;
  inner_ = inner_ + temp;
  upper_ = upper_ + temp;
  center_ = inner_;
}

void oleynikova::Concave::move(const point_t &newCenter)
{
  left_ = left_ + (newCenter - center_);
  right_ = right_ + (newCenter - center_);
  upper_ = upper_ + (newCenter - center_);
  inner_ = inner_ + (newCenter - center_);
  center_ = newCenter;
}

oleynikova::rectangle_t oleynikova::Concave::getFrameRect() const
{
  point_t left;
  left.x_ = std::min({ upper_.x_, inner_.x_, left_.x_, right_.x_ });
  left.y_ = std::min({ upper_.y_, inner_.y_, left_.y_, right_.y_ });
  point_t right;
  right.x_ = std::max({ upper_.x_, inner_.x_, left_.x_, right_.x_ });
  right.y_ = std::max({ upper_.y_, inner_.y_, left_.y_, right_.y_ });
  rectangle_t rect;
  rect.width_ = right.x_ - left.x_;
  rect.height_ = right.y_ - left.y_;
  rect.pos_.x_ = left.x_ + rect.width_ / 2;
  rect.pos_.y_ = left.y_ + rect.height_ / 2;
  return rect;
}

void oleynikova::Concave::doScale(double rate)
{
  left_ = center_ + (left_ - center_) * rate;
  right_ = center_ + (right_ - center_) * rate;
  upper_ = center_ + (upper_ - center_) * rate;
  inner_ = center_ + (inner_ - center_) * rate;
}

oleynikova::Concave *oleynikova::Concave::clone() const
{
  Concave *temp = new Concave(left_, upper_, right_, inner_);
  return temp;
}
