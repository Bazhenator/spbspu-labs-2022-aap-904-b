#include "Shape.h"
#include <stdexcept>

void chupina::Shape::scale(const double factor)
{
  if (factor <= 0) {
    throw std::runtime_error("Scale factor is incorrect");
  }
  doScale(factor);
}
