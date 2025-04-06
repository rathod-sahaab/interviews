#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "shape-visitor.hpp"
#include "shape.hpp"

class Circle : public Shape {
  float m_radius;

public:
  Circle(float radius) : m_radius(radius) {}

  float get_radius() const { return m_radius; }

  float area() override {
    const auto radius = this->m_radius;
    return 3.14 * radius * radius;
  }

  void accept(ShapeVisitor &v) override { v.visit(*this); }
};

#endif // !CIRCLE_HPP
