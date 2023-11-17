#ifndef COMPOSITE_SHAPE_H
#define COMPOSITE_SHAPE_H

#include <cstddef>
#include "base-types.h"
#include "Shape.h"

namespace ponomarev {
  class CompositeShape {
    public:
      CompositeShape();
      CompositeShape(std::size_t capacity);
      CompositeShape(const CompositeShape &obj);
      CompositeShape(CompositeShape &&obj) noexcept;
      ~CompositeShape();

      void swap(CompositeShape &obj) noexcept;
      CompositeShape &operator=(const CompositeShape &obj);
      CompositeShape &operator=(CompositeShape &&obj) noexcept;
      Shape *operator[](std::size_t id) const;

      double getArea() const;
      rectangle_t getFrameRect() const;
      void move(const point_t &destination);
      void move(double x, double y);
      void scale(double multiplier);
      CompositeShape *clone() const;

      void push_back(Shape *shp);
      void pop_back();
      Shape *at(std::size_t id) const;
      bool empty() const;
      std::size_t size() const;
    private:
      Shape **data_;
      std::size_t capacity_;
      std::size_t stored_;
  };
}

#endif
