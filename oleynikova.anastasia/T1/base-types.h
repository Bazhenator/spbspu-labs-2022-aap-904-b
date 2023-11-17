#ifndef BASE_TYPES_H
#define BASE_TYPES_H

namespace oleynikova {

  struct point_t
  {
    double x_, y_;
  };

  struct rectangle_t
  {
    double width_, height_;
    point_t pos_;
  };
  point_t operator-(const point_t &leftPoint, const point_t rightPoint);
  point_t operator+(const point_t &leftPoint, const point_t rightPoint);
  point_t operator*(const point_t &point, const double rate);
}

#endif
