#include "CompositeShape.h"
#include <utility>

ponomarev::CompositeShape::CompositeShape():
  data_(nullptr),
  capacity_(0),
  stored_(0)
{}
ponomarev::CompositeShape::CompositeShape(const std::size_t capacity):
  data_(new ponomarev::Shape*[capacity]),
  capacity_(capacity),
  stored_(0)
{}
ponomarev::CompositeShape::CompositeShape(const CompositeShape &obj):
  data_(new ponomarev::Shape*[obj.capacity_]),
  capacity_(obj.capacity_),
  stored_(obj.stored_)
{
  for (std::size_t i = 0; i < obj.stored_; i++) {
    data_[i] = obj.data_[i]->clone();
  }
}
void ponomarev::CompositeShape::swap(ponomarev::CompositeShape &obj) noexcept
{
  std::swap(data_, obj.data_);
  std::swap(capacity_, obj.capacity_);
  std::swap(stored_, obj.stored_);
}
ponomarev::CompositeShape::CompositeShape(CompositeShape &&obj) noexcept:
  data_(obj.data_),
  capacity_(obj.capacity_),
  stored_(obj.stored_)
{
  obj.data_ = nullptr;
  obj.capacity_ = 0;
  obj.stored_ = 0;
}
ponomarev::CompositeShape::~CompositeShape()
{
  while (stored_) {
    pop_back();
  }
  delete[] data_;
}

ponomarev::CompositeShape &ponomarev::CompositeShape::operator=(const CompositeShape &obj)
{
  if (this != &obj) {
    ponomarev::CompositeShape temp(obj);
    ponomarev::CompositeShape::swap(temp);
  }
  return *this;
}
ponomarev::CompositeShape &ponomarev::CompositeShape::operator=(CompositeShape &&obj) noexcept
{
  if (this != &obj) {
    ponomarev::CompositeShape::swap(obj);
  }
  return *this;
}
ponomarev::Shape *ponomarev::CompositeShape::operator[](std::size_t id) const
{
  return data_[id];
}

double ponomarev::CompositeShape::getArea() const
{
  double sum = 0;
  for (std::size_t i = 0; i < stored_; sum += data_[i++]->getArea());
  return sum;
}
ponomarev::rectangle_t ponomarev::CompositeShape::getFrameRect() const
{
  ponomarev::point_t upperRight, lowerLeft;
  for (std::size_t i = 0; i < stored_; i++) {
    rectangle_t temp(data_[i]->getFrameRect());
    upperRight.x_ = ((upperRight.x_ < temp.pos_.x_ + temp.width_*0.5) || i == 0 ? temp.pos_.x_ + temp.width_*0.5 : upperRight.x_);
    upperRight.y_ = ((upperRight.y_ < temp.pos_.y_ + temp.width_*0.5) || i == 0 ? temp.pos_.y_ + temp.height_*0.5 : upperRight.y_);
    lowerLeft.x_ = ((lowerLeft.x_ > temp.pos_.x_ - temp.width_*0.5) || i == 0 ? temp.pos_.x_ - temp.width_*0.5 : lowerLeft.x_);
    lowerLeft.y_ = ((lowerLeft.y_ > temp.pos_.y_ - temp.width_*0.5) || i == 0 ? temp.pos_.y_ - temp.height_*0.5 : lowerLeft.y_);
  }
  double width = upperRight.x_ - lowerLeft.x_;
  double height = upperRight.y_ - lowerLeft.y_;
  ponomarev::point_t centerPoint{lowerLeft.x_ + 0.5 * width, lowerLeft.y_ + 0.5 * height};
  return rectangle_t{width, height, centerPoint};
}
void ponomarev::CompositeShape::move(const point_t &destination)
{
  for (std::size_t i = 0; i < stored_; data_[i++]->move(destination));
}
void ponomarev::CompositeShape::move(double x, double y)
{
  for (std::size_t i = 0; i < stored_; data_[i++]->move(x, y));
}
void ponomarev::CompositeShape::scale(double multiplier)
{
  for (std::size_t i = 0; i < stored_; data_[i++]->scale(multiplier));
}
ponomarev::CompositeShape *ponomarev::CompositeShape::clone() const
{
  return new CompositeShape(*this);
}

void ponomarev::CompositeShape::push_back(Shape *shp)
{
  stored_++;
  if (stored_ > capacity_) {
    ponomarev::CompositeShape temp(capacity_ + 10);
    for (std::size_t i = 0; i < (stored_ - 1); i++) {
      temp.push_back(data_[i]);
    }
    ponomarev::CompositeShape::swap(temp);
    temp.stored_--;
    stored_++;
  }
  data_[stored_ - 1] = shp->clone();
}
void ponomarev::CompositeShape::pop_back()
{
  delete data_[stored_ - 1];
  data_[stored_ - 1] = nullptr;
  stored_--;
}
ponomarev::Shape *ponomarev::CompositeShape::at(std::size_t id) const
{
  if (id >= stored_) {
    throw std::out_of_range("CompositeShape index is out of range.");
  }
  return data_[id];
}
bool ponomarev::CompositeShape::empty() const
{
  return !stored_;
}
std::size_t ponomarev::CompositeShape::size() const
{
  return stored_;
}
