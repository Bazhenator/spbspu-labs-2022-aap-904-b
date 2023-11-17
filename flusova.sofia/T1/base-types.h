#ifndef BASE_TYPES_H
#define BASE_TYPES_H

namespace flusova {
  struct point_t {
    double x_, y_;
  };
  struct rectangle_t {
    double width_, height_;
    point_t pos_;
  };
  bool operator== (const point_t& p, const point_t& yaP);
  point_t operator+= (point_t& p, point_t& yaP);
  point_t operator+= (point_t& p, double k);
}
#endif
