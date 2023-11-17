#include "Complexquad.h"
#include <cmath>
#include <stdexcept>
#include <algorithm>

ponomarev::Complexquad::Complexquad(point_t lowerLeftPoint, point_t upperRightPoint, point_t lowerRightPoint, point_t upperLeftPoint):
  lowerLeftPoint_(lowerLeftPoint),
  upperRightPoint_(upperRightPoint),
  lowerRightPoint_(lowerRightPoint),
  upperLeftPoint_(upperLeftPoint)
{
  point_t vectorR(upperRightPoint_ - lowerLeftPoint_);
  point_t vectorL(upperLeftPoint_ - lowerRightPoint_);
  // set line in format Ax + By + C = 0
  double A1 = vectorR.y_;
  double B1 = -vectorR.x_;
  double C1 = lowerLeftPoint_.y_*upperRightPoint_.x_ - lowerLeftPoint_.x_*upperRightPoint_.y_;
  double A2 = vectorL.y_;
  double B2 = -vectorL.x_;
  double C2 = lowerRightPoint_.y_*upperLeftPoint_.x_ - lowerRightPoint_.x_*upperLeftPoint_.y_;
  double det = A1*B2 - B1*A2;
  double detX = -C1*B2 + C2*B1;
  double detY = -A1*C2;
  if (!det) {
    throw std::runtime_error("Complexquad parameters aren't correct.\n");
  }
  centerPoint_.x_ = detX/det;
  centerPoint_.y_ = detY/det;
  if (centerPoint_ == lowerLeftPoint_ || centerPoint_ == upperRightPoint_
      || centerPoint_ == lowerRightPoint_ || centerPoint_ == upperLeftPoint_) {
    throw std::runtime_error("Complexquad parameters aren't correct.\n");
  }
}
double ponomarev::Complexquad::getArea() const
{
  double vectorUL[] = {upperLeftPoint_.x_ - centerPoint_.x_, upperLeftPoint_.y_ - centerPoint_.y_};
  double vectorLL[] = {lowerLeftPoint_.x_ - centerPoint_.x_, lowerLeftPoint_.y_ - centerPoint_.y_};
  double vectorUR[] = {upperRightPoint_.x_ - centerPoint_.x_, upperRightPoint_.y_ - centerPoint_.y_};
  double vectorLR[] = {lowerRightPoint_.x_ - centerPoint_.x_, lowerRightPoint_.y_ - centerPoint_.y_};
  return 0.5 * (std::abs(vectorUL[0]*vectorLL[1] - vectorUL[1]*vectorLL[0]) + std::abs(vectorUR[0]*vectorLR[1] - vectorUR[1]*vectorLR[0]));
}
ponomarev::rectangle_t ponomarev::Complexquad::getFrameRect() const
{
  double rEdgeX = std::max({upperRightPoint_.x_, lowerRightPoint_.x_, lowerLeftPoint_.x_, upperLeftPoint_.x_});
  double lEdgeX = std::min({upperRightPoint_.x_, lowerRightPoint_.x_, lowerLeftPoint_.x_, upperLeftPoint_.x_});
  double uEdgeY = std::max({upperRightPoint_.y_, lowerRightPoint_.y_, lowerLeftPoint_.y_, upperLeftPoint_.y_});
  double lEdgeY = std::min({upperRightPoint_.y_, lowerRightPoint_.y_, lowerLeftPoint_.y_, upperLeftPoint_.y_});
  rectangle_t temp;
  temp.width_ = rEdgeX - lEdgeX;
  temp.height_ = uEdgeY - lEdgeY;
  temp.pos_ = point_t{rEdgeX - temp.width_ * 0.5, uEdgeY - temp.height_ * 0.5};
  return temp;
}
void ponomarev::Complexquad::move(const point_t &destination)
{
  point_t offsetVector(destination - centerPoint_);
  upperRightPoint_ = upperRightPoint_ + offsetVector;
  lowerLeftPoint_ = lowerLeftPoint_ + offsetVector;
  upperLeftPoint_ = upperLeftPoint_ + offsetVector;
  lowerRightPoint_ = lowerRightPoint_ + offsetVector;
  centerPoint_ = centerPoint_ + offsetVector;
}
void ponomarev::Complexquad::move(double x, double y)
{
  point_t temp;
  temp.x_ = x;
  temp.y_ = y;
  upperRightPoint_ = upperRightPoint_ + temp;
  lowerLeftPoint_ = lowerLeftPoint_ + temp;
  upperLeftPoint_ = upperLeftPoint_ + temp;
  lowerRightPoint_ = lowerRightPoint_ + temp;
  centerPoint_ = centerPoint_ + temp;
}
void ponomarev::Complexquad::doScale(double multiplier)
{
  upperRightPoint_ = centerPoint_ + (upperRightPoint_ - centerPoint_)*multiplier;
  lowerLeftPoint_ = centerPoint_ + (lowerLeftPoint_ - centerPoint_)*multiplier;
  upperLeftPoint_ = centerPoint_ + (upperLeftPoint_ - centerPoint_)*multiplier;
  lowerRightPoint_ = centerPoint_ + (lowerRightPoint_ - centerPoint_)*multiplier;
}
ponomarev::Complexquad *ponomarev::Complexquad::clone() const
{
  return new Complexquad(lowerLeftPoint_, upperRightPoint_, lowerRightPoint_, upperLeftPoint_);
}
