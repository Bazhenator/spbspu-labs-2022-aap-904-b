#ifndef COMPOSITE_SHAPE_H
#define COMPOSITE_SHAPE_H

#include <cstddef>
#include "base-types.h"
#include "Shape.h"

namespace oleynikova{
  class CompositeShape {
  public:
    CompositeShape();
    explicit CompositeShape(size_t size);
    CompositeShape(const CompositeShape &shape);
    CompositeShape(CompositeShape &&shape) noexcept;
    ~CompositeShape();
    CompositeShape &operator=(const CompositeShape &shape);
    CompositeShape &operator=(CompositeShape &&shape) noexcept;
    double getArea() const;
    rectangle_t getFrameRect() const;
    void move(const point_t &point);
    void move(double x, double y);
    void scale(double rate);
    void push_back(Shape *shape);
    void pop_back();
    bool empty() const;
    size_t size() const;
    Shape *at(size_t id) const;
    Shape *operator[](size_t id) const;
    CompositeShape* clone() const;
  private:
    size_t size_;
    size_t count_;
    Shape **data_;
  };
}

#endif
