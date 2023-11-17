#include "Shape.h"
#include <stdexcept>

void flusova::Shape::scale(double coef)
{
  if (coef <= 0)
  {
    throw std::runtime_error("Scaling coefficient must be positive!");
  }
  doScale(coef);
}
