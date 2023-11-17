#ifndef BASE_TYPES_H
#define BASE_TYPES_H

namespace chupina {
  struct Point_t {
    double x_;
    double y_;
  };
  struct Rectangle_t {
    double width_;
    double height_;
    Point_t pos_;
  };
}

#endif
