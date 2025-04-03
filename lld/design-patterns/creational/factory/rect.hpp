#ifndef RECT_HPP
#define RECT_HPP

#include "shape.hpp"

class Rect : public Shape {
  float m_length, m_breadth;

public:
  Rect(float length, float breadth) : m_length(length), m_breadth(breadth) {}

  float area() override { return this->m_length * this->m_breadth; }
};

#endif // !RECT_HPP
