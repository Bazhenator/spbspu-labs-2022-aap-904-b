#include "CompositeShape.h"
#include <iostream>
#include <limits>

chupina::CompositeShape::CompositeShape():
  size_(0),
  shapes_(nullptr)
{}
chupina::CompositeShape::CompositeShape(const CompositeShape & right):
  CompositeShape()
{
  for (size_t i = 0; i < right.size_; push_back(right.shapes_[i++]));
}
chupina::CompositeShape::CompositeShape(CompositeShape && obj) noexcept :
  size_(obj.size_),
  shapes_(obj.shapes_)
{
  obj.shapes_ = nullptr;
  obj.size_ = 0;
}
chupina::CompositeShape::~CompositeShape()
{
  for (size_t i = 0; i < size_; ++i) {
    delete shapes_[i];
  }
  delete [] shapes_;
}

chupina::CompositeShape & chupina::CompositeShape::operator=(const CompositeShape & right)
{
  if (this != &right) {
    CompositeShape temp(right);
    swap(temp);
  }
  return *this;
}
chupina::CompositeShape & chupina::CompositeShape::operator=(CompositeShape && right) noexcept
{
  if (this != &right) {
    swap(right);
  }
  return *this;
}
chupina::Shape & chupina::CompositeShape::operator[](size_t id) const
{
  if (id < size_) {
    return *shapes_[id];
  }
  throw std::runtime_error("Index out of range");
}


double chupina::CompositeShape::getArea() const
{
  double totalArea = 0;
  for (size_t i = 0; i < size_; i++) {
    totalArea += shapes_[i]->getArea();
  }
  return totalArea;
}
chupina::Rectangle_t chupina::CompositeShape::getFrameRect() const
{
  double minX = std::numeric_limits<double>::max();
  double minY = std::numeric_limits<double>::max();
  double maxX = std::numeric_limits<double>::min();
  double maxY = std::numeric_limits<double>::min();
  for (size_t i = 0; i < size_; i++) {
    Rectangle_t temp = shapes_[i]->getFrameRect();
    minX = std::min(minX, temp.pos_.x_ - temp.width_ / 2.0);
    minY = std::min(minY, temp.pos_.y_ - temp.height_ / 2.0);
    maxX = std::max(maxX, temp.pos_.x_ + temp.width_ / 2.0);
    maxY = std::max(maxY, temp.pos_.y_ + temp.height_ / 2.0);
  }
  Rectangle_t answer;
  answer.width_ = maxX - minX;
  answer.height_ = maxY - minY;
  answer.pos_= Point_t{(maxX + minX) / 2.0, (maxY + minY) / 2.0};
  return answer;
}
void chupina::CompositeShape::move(const Point_t & destination)
{
  for (size_t i = 0; i < size_; i++) {
    shapes_[i]->move(destination);
  }
}
void chupina::CompositeShape::move(const double x, const double y)
{
  for (size_t i = 0; i < size_; i++) {
    shapes_[i]->move(x, y);
  }
}
void chupina::CompositeShape::scale(const double factor)
{
  for (size_t i = 0; i < size_; i++) {
    shapes_[i]->scale(factor);
  }
}
chupina::CompositeShape * chupina::CompositeShape::clone() const
{
  CompositeShape * temp = new CompositeShape(*this);
  return temp;
}

void chupina::CompositeShape::push_back(Shape * shape)
{
  Shape ** newShapes = new Shape * [++size_];
  for (Shape **i = shapes_, **j = newShapes; i != shapes_ + size_ - 1; (*j++) = (*i++));
  delete [] shapes_;
  shapes_ = newShapes;
  shapes_[size_ - 1] = shape->clone();
}
void chupina::CompositeShape::pop_back()
{
  delete shapes_[--size_];
  Shape** newShapes = new Shape * [size_];
  for (Shape** i = shapes_, **j = newShapes; i != shapes_ + size_ - 2; ++i, ++j) {
    *j = *i;
  }
  delete[] shapes_;
  shapes_ = newShapes;
}
chupina::Shape& chupina::CompositeShape::at(size_t id) const
{
  if (id < size_) {
    return *shapes_[id];
  }
  throw std::runtime_error("Index out of range");
}
bool chupina::CompositeShape::empty() const
{
  return size_ == 0;
}
size_t chupina::CompositeShape::size() const
{
  return size_;
}
void chupina::CompositeShape::swap(CompositeShape & right) noexcept
{
  std::swap(size_, right.size_);
  std::swap(shapes_, right.shapes_);
}
