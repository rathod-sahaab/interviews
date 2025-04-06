#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "shape-visitor.hpp"
class Shape {
public:
  virtual float area() = 0;

  // Has same implementation for all but here function overloaded
  // visitor method won't be able to guess the real type.
  virtual void accept(ShapeVisitor &visitor) = 0;

  virtual ~Shape() = default;
};

#endif // !INTEREFACE
