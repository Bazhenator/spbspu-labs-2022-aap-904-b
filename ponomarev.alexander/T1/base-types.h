#ifndef BASE_TYPES_H
#define BASE_TYPES_H

#include <iostream>

namespace ponomarev {
  struct point_t
  {
    double x_;
    double y_;
  };
  struct rectangle_t
  {
    double width_;
    double height_;
    point_t pos_;
  };
  point_t operator+(const point_t &left, const point_t &right);
  point_t operator-(const point_t &left, const point_t &right);
  point_t operator*(const point_t &left, const double right);
  bool operator==(const point_t &left, const point_t &right);
  bool operator>(const point_t &left, const point_t &right);
  std::istream &operator>>(std::istream &in, point_t &obj);
  std::ostream &operator<<(std::ostream &out, const rectangle_t &obj);
}

#endif
