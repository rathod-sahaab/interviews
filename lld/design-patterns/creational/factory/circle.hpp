#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "shape.hpp"

class Circle : public Shape {
  float m_radius;

public:
  Circle(float radius) : m_radius(radius) {}

  float area() override {
    const auto radius = this->m_radius;
    return 3.14 * radius * radius;
  }
};

#endif // !CIRCLE_HPP
