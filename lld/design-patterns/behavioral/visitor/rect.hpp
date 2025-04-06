#ifndef RECT_HPP
#define RECT_HPP

#include "shape-visitor.hpp"
#include "shape.hpp"

class Rect : public Shape {
  float m_length, m_breadth;

public:
  Rect(float length, float breadth) : m_length(length), m_breadth(breadth) {}

  float get_length() const { return m_length; }
  float get_breadth() const { return m_breadth; }

  float area() override { return this->m_length * this->m_breadth; }

  void accept(ShapeVisitor &v) override { v.visit(*this); }
};

#endif // !RECT_HPP
