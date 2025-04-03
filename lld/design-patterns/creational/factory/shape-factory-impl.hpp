#ifndef SHAPE_FACTORY_IMPL
#define SHAPE_FACTORY_IMPL

#include "circle.hpp"
#include "rect.hpp"
#include "shape-factory.hpp"
#include "shape.hpp"

class ShapeFactoryImpl : public ShapeFactory {
  float m_radius;
  float m_length;
  float m_breadth;

public:
  ShapeFactoryImpl(float radius, float length, float breadth)
      : m_radius(radius), m_length(length), m_breadth(breadth) {}

  Shape *createShape(ShapeKind kind) override {
    switch (kind) {
    case ShapeKind::CIRCLE:
      return new Circle(this->m_radius);

    case ShapeKind::RECTANGLE:
      return new Rect(this->m_length, this->m_breadth);
    }

    return nullptr;
  }
};

#endif // !SHAPE_FACTORY_IMPL
