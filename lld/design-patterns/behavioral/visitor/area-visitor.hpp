
#ifndef AREA_VISITOR_HPP
#define AREA_VISITOR_HPP

#include "circle.hpp"
#include "rect.hpp"
#include "shape-visitor.hpp"
#include <iostream>

class AreaVisitor : public ShapeVisitor {
public:
  void visit(Circle &c) override {
    std::cout << "Circle, area:" << c.area() << "\n";
  };
  virtual void visit(Rect &r) override {
    std::cout << "Rectangle, area:" << r.area() << "\n";
  };
};

#endif // !AREA_VISITOR_HPP
