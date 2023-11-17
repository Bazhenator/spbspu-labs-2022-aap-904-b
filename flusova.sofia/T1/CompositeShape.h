#ifndef COMPOSITE_SHAPE_H
#define COMPOSITE_SHAPE_H
#include <cstddef>
#include "base-types.h"
#include "Shape.h"

namespace flusova {
  class CompositeShape {
  public:
    CompositeShape();
    explicit CompositeShape(const size_t& size);
    CompositeShape(const CompositeShape& other);
    CompositeShape(CompositeShape&& other) noexcept;
    ~CompositeShape();
    double getArea() const;
    rectangle_t getFrameRect() const;
    void move(const point_t& point);
    void move(const double x, const double y);
    void scale(const double& coef);
    CompositeShape* clone() const noexcept;
    void swap(CompositeShape& nextShape) noexcept;
    void push_back(Shape* shp);
    void pop_back();
    Shape * at(size_t id) const;
    Shape * operator[](size_t index);
    bool empty() const;
    size_t size() const;
  private:
    size_t size_;
    Shape** composite_;
  };
}
#endif
