#include "Shape.h"
#include <stdexcept>

void oleynikova::Shape::scale(double rate)
{
  if (rate <= 0) {
    throw std::runtime_error("Rate must be positive\n");
  }
  doScale(rate);
}
