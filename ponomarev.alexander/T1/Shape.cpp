#include "Shape.h"

void ponomarev::Shape::scale(double multiplier)
{
  if (multiplier <= 0) {
    throw std::runtime_error("Scaling coefficient isn't positive.\n");
  }
  doScale(multiplier);
}
