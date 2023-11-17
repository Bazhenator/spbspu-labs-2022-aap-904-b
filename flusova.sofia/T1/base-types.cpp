#include "base-types.h"

bool flusova::operator== (const flusova::point_t& p, const flusova::point_t& yaP) {
  if ((p.x_ == yaP.x_) && (p.y_ == yaP.y_)) {
    return true;
  } else {
    return false;
  }
}
flusova::point_t flusova::operator+= (flusova::point_t& p, flusova::point_t& yaP) {
  p.x_ += yaP.x_;
  p.y_ += yaP.y_;
  return {p.x_, p.y_};
}
flusova::point_t flusova::operator+= (flusova::point_t& p, double k) {
  p.x_ += k;
  p.y_ += k;
  return {p.x_, p.y_};
}
