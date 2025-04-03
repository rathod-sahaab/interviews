#ifndef SHAPE_FACTORY_INTERFACE_HPP
#define SHAPE_FACTORY_INTERFACE_HPP

#include "shape.hpp"

enum ShapeKind {
  CIRCLE,
  RECTANGLE,
};

// interface
class ShapeFactory {
public:
  virtual Shape *createShape(ShapeKind) = 0;
};

#endif // !SHAPE_FACTORY_INTERFACE_HPP
