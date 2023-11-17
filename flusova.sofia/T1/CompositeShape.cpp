#include "CompositeShape.h"
#include <stdexcept>
#include <cstddef>
#include <climits>
#include "Shape.h"

flusova::CompositeShape::CompositeShape():
  size_(0),
  composite_(nullptr)
{}
flusova::CompositeShape::CompositeShape(const size_t& size):
  size_(size),
  composite_(new Shape*[size])
{}
flusova::CompositeShape::CompositeShape(const CompositeShape& other):
  size_(other.size_),
  composite_(new Shape*[other.size_])
{
  for (size_t i = 0; i < other.size_; ++i)
  {
    composite_[i] = other.composite_[i]->clone();
  }
}
flusova::CompositeShape::CompositeShape(CompositeShape&& other) noexcept:
  size_(other.size_),
  composite_(other.composite_)
{
  other.composite_ = nullptr;
  other.size_ = 0;
}
flusova::CompositeShape::~CompositeShape()
{
  for (size_t i = 0; i < size_; ++i)
  {
    delete composite_[i];
  }
  delete [] composite_;
}
double flusova::CompositeShape::getArea() const
{
  double area = 0.0;
  for (size_t i = 0; i < size_; ++i)
  {
    area += composite_[i]->getArea();
  }
  return area;
}
flusova::rectangle_t flusova::CompositeShape::getFrameRect() const
{
  double maxX = INT_MIN, maxY = INT_MIN, minX = INT_MAX, minY = INT_MAX;
  for (size_t i = 0; i < size_; ++i)
  {
    double rightX = composite_[i]->getFrameRect().pos_.x_ + composite_[i]->getFrameRect().width_ / 2;
    double upperY = composite_[i]->getFrameRect().pos_.y_ + composite_[i]->getFrameRect().height_ / 2;
    double leftX = composite_[i]->getFrameRect().pos_.x_ - composite_[i]->getFrameRect().width_ / 2;
    double lowerY = composite_[i]->getFrameRect().pos_.y_ - composite_[i]->getFrameRect().height_ / 2;
    if (maxX < rightX)
    {
      maxX = rightX;
    }
    if (maxY < upperY)
    {
      maxY = upperY;
    }
    if (minX > leftX)
    {
      minX = leftX;
    }
    if (minY > lowerY)
    {
      minY = lowerY;
    }
  }
  return {maxX - minX, maxY - minY, {(maxX - minX) / 2, (maxY - minY) / 2}};
}
void flusova::CompositeShape::move(const double x, const double y)
{
  point_t add{x, y};
  for (size_t i = 0; i < size_; ++i)
  {
    composite_[i]->move(add);
  }
}
void flusova::CompositeShape::move(const point_t& point)
{
  for (size_t i = 0; i < size_; ++i)
  {
    composite_[i]->move(point.x_, point.y_);
  }
}
void flusova::CompositeShape::scale(const double& coef)
{
  for (size_t i = 0; i < size_; ++i)
  {
    composite_[i]->scale(coef);
  }
}
flusova::CompositeShape* flusova::CompositeShape::clone() const noexcept
{
  CompositeShape * tempShape = new CompositeShape(size_);
  for (size_t i = 0; i < size_; ++i)
  {
    tempShape->composite_[i] = composite_[i];
  }
  return tempShape;
}
void flusova::CompositeShape::swap(CompositeShape& nextShape) noexcept
{
  std::swap(size_, nextShape.size_);
  std::swap(composite_, nextShape.composite_);
}
void flusova::CompositeShape::push_back(Shape *composite)
{
  if (composite == nullptr) {
    throw std::invalid_argument("Incorrect Shape!");
  }
  Shape** tempComp = new Shape*[size_ + 1];
  for (std::size_t i = 0; i < size_; i++)
  {
    tempComp[i] = composite_[i];
  }
  tempComp[size_] = composite->clone();
  size_++;
  std::swap(tempComp, composite_);
  delete[] tempComp;
}
void flusova::CompositeShape::pop_back()
{
  Shape** tempComp = new Shape*[size_ - 1];
  for (std::size_t i = 0; i < size_ - 1; i++)
  {
    tempComp[i] = composite_[i];
  }
  size_--;
  std::swap(tempComp, composite_);
  delete[] tempComp;
}
flusova::Shape* flusova::CompositeShape::at(size_t index) const
{
  if (index >= size_)
  {
    throw std::out_of_range("Index is out of range!");
  }
  return composite_[index];
}
bool flusova::CompositeShape::empty() const
{
  return size_ == 0;
}
size_t flusova::CompositeShape::size() const
{
  return size_;
}
flusova::Shape* flusova::CompositeShape::operator[](size_t index)
{
  if (index >= size_)
  {
    throw std::runtime_error("Index is out of range!");
  }
  return composite_[index];
}
