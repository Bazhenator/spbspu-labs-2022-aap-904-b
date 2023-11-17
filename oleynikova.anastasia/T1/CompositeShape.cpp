#include "CompositeShape.h"
#include <stdexcept>
#include <utility>

oleynikova::CompositeShape::CompositeShape():
  size_(0),
  count_(0),
  data_(nullptr)
{}

oleynikova::CompositeShape::CompositeShape(const size_t size):
  size_(size),
  count_(0),
  data_(new Shape*[size])
{}

oleynikova::CompositeShape::CompositeShape(const CompositeShape &shape)
{
  size_ = shape.size_;
  count_ = shape.count_;
  data_ = new oleynikova::Shape*[size_];
  for (size_t i = 0; i < count_; i++) {
    data_[i] = shape.data_[i]->clone();
  }
}

oleynikova::CompositeShape::CompositeShape(CompositeShape &&shape) noexcept:
  size_(shape.size_),
  count_(shape.count_),
  data_(shape.data_)
{
  shape.size_ = 0;
  shape.count_ = 0;
  shape.data_ = nullptr;
}

oleynikova::CompositeShape &oleynikova::CompositeShape::operator=(const CompositeShape &shape)
{
  if (this != &shape) {
    CompositeShape temp(shape);
    std::swap(temp.data_, data_);
    std::swap(temp.size_, size_);
    std::swap(temp.count_, count_);
  }
  return *this;
}

oleynikova::CompositeShape &oleynikova::CompositeShape::operator=(CompositeShape &&shape) noexcept
{
  if (this != &shape) {
    std::swap(shape.data_, data_);
    std::swap(shape.size_, size_);
    std::swap(shape.count_, count_);
  }
  return *this;
}

oleynikova::CompositeShape::~CompositeShape()
{
  while (count_ > 0) {
    pop_back();
  }
  delete[] data_;
}

double oleynikova::CompositeShape::getArea() const
{
  double result = 0.0;
  for (size_t i = 0; i < count_; i++) {
    result += data_[i]->getArea();
  }
  return result;
}

void oleynikova::CompositeShape::move(const point_t &newCenter)
{
  for (size_t i = 0; i < count_; i++) {
    data_[i]->move(newCenter);
  }
}

void oleynikova::CompositeShape::move(double x, double y)
{
  for (size_t i = 0; i < count_; i++) {
    data_[i]->move(x, y);
  }
}

oleynikova::rectangle_t oleynikova::CompositeShape::getFrameRect() const
{
  rectangle_t frameRect = data_[0]->getFrameRect();
  point_t right, left, maxRight, minLeft;
  right.x_ = frameRect.pos_.x_ + frameRect.width_ / 2;
  right.y_ = frameRect.pos_.y_ + frameRect.height_ / 2;
  left.x_ = frameRect.pos_.x_ - frameRect.width_ / 2;
  left.y_ = frameRect.pos_.y_ - frameRect.height_ / 2;
  for (size_t i = 1; i < count_; ++i) {
    rectangle_t temp = data_[i]->getFrameRect();
    maxRight.x_ = temp.pos_.x_ + temp.width_ / 2;
    minLeft.x_ = temp.pos_.x_ - temp.width_ / 2;
    maxRight.y_ = temp.pos_.y_ + temp.height_ / 2;
    minLeft.y_ = temp.pos_.y_ - temp.height_ / 2;
    right.x_ = (right.x_ < maxRight.x_) ? maxRight.x_ : right.x_;
    right.y_ = (right.y_ < maxRight.y_) ? maxRight.y_ : right.y_;
    left.x_ = (left.x_ > minLeft.x_) ? minLeft.x_ : left.x_;
    left.y_ = (left.y_ > minLeft.y_) ? minLeft.y_ : left.y_;
  }
  point_t center;
  center.x_ = (right.x_ + left.x_) / 2;
  center.y_ = (right.y_ + left.y_) / 2;
  rectangle_t rect;
  rect.pos_ = center;
  rect.height_ = right.y_ - left.y_;
  rect.width_ = right.x_ - left.x_;
  return rect;
}

void oleynikova::CompositeShape::scale(double rate)
{
  for (size_t i = 0; i < count_; i++) {
    data_[i]->scale(rate);
  }
}

bool oleynikova::CompositeShape::empty() const
{
  return !count_;
}

size_t oleynikova::CompositeShape::size() const
{
  return count_;
}

void oleynikova::CompositeShape::push_back(Shape *newShape)
{
  count_ += 1;
  CompositeShape temp = CompositeShape(size_ + 1);
  for (Shape **i = data_; i < (data_ + count_ - 1); i++) {
    temp.push_back(*i);
  }
  std::swap(temp.data_, data_);
  std::swap(temp.size_, size_);
  std::swap(temp.count_, count_);
  temp.count_ -= 1;
  count_ += 1;
  data_[count_ - 1] = newShape->clone();
}

oleynikova::CompositeShape *oleynikova::CompositeShape::clone() const
{
  oleynikova::CompositeShape *temp = new CompositeShape(size_);
  for (size_t i = 0; i < size_; i++) {
    temp->data_[i] = data_[i];
  }
  return temp;
}

void oleynikova::CompositeShape::pop_back()
{
  count_ -= 1;
  delete data_[count_];
  data_[count_] = nullptr;
}

oleynikova::Shape *oleynikova::CompositeShape::at(size_t id) const
{
  if (id >= count_) {
    throw std::runtime_error("Index is out of range");
  }
  return data_[id];
}

oleynikova::Shape *oleynikova::CompositeShape::operator[](size_t id) const
{
  return data_[id];
}
