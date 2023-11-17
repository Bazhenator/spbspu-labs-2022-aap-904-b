#ifndef COMPOSITE_SHAPE_H
#define COMPOSITE_SHAPE_H
#include <cstddef>
#include "Shape.h"

namespace chupina{
  class CompositeShape {
    public:
      CompositeShape();
      CompositeShape(const CompositeShape & right);
      CompositeShape(CompositeShape && obj) noexcept;
      ~CompositeShape();

      CompositeShape & operator=(const CompositeShape & right);
      CompositeShape & operator=(CompositeShape && right) noexcept;
      Shape & operator[](size_t id) const;

      double getArea() const;
      Rectangle_t getFrameRect() const;
      void move(const Point_t & destination);
      void move(const double x, const double y);
      void scale(const double factor);
      CompositeShape * clone() const;
      void push_back(Shape* shp);
      void pop_back();
      Shape & at(size_t id) const;
      bool empty() const;
      size_t size() const;
      void swap(CompositeShape & right) noexcept;
    private:
      size_t size_;
      Shape ** shapes_;
  };
}

#endif
