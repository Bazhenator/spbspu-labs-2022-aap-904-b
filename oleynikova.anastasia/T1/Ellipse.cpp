#include "Ellipse.h"
#include <stdexcept>
#include <cmath>
#include "base-types.h"

oleynikova::Ellipse::Ellipse(point_t center, double verticRad, double horizontRad) :
  center_(center),
  verticRad_(verticRad),
  horizontRad_(horizontRad)
{
  if (verticRad <= 0 || horizontRad <= 0) {
    throw std::runtime_error("Incorrect parameters\n");
  }
}

double oleynikova::Ellipse::getArea() const
{
  return 2 * std::acos(0) * verticRad_ * horizontRad_;
}

oleynikova::rectangle_t oleynikova::Ellipse::getFrameRect() const
{
  rectangle_t frameRect;
  frameRect.width_ = 2 * horizontRad_;
  frameRect.height_ = 2 * verticRad_;
  frameRect.pos_ = center_;
  return frameRect;
}

void oleynikova::Ellipse::move(const point_t &newCenter)
{
  center_ = newCenter;
}

void oleynikova::Ellipse::move(double x, double y)
{
  center_.x_ += x;
  center_.y_ += y;
}

void oleynikova::Ellipse::doScale(double rate)
{
  horizontRad_ *= rate;
  verticRad_ *= rate;
}

oleynikova::Ellipse *oleynikova::Ellipse::clone() const
{
  Ellipse *temp = new Ellipse(center_, verticRad_, horizontRad_);
  return temp;
}
