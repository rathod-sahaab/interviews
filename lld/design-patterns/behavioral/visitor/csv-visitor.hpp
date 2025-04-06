#ifndef CSV_VISITOR_HPP
#define CSV_VISITOR_HPP

#include "circle.hpp"
#include "rect.hpp"
#include "shape-visitor.hpp"
#include <iostream>

class CsvVisitor : public ShapeVisitor {
public:
  void visit(Circle &c) override {
    std::cout << "Circle, radius:" << c.get_radius() << "\n";
  };
  virtual void visit(Rect &r) override {
    std::cout << "Rectangle, L:" << r.get_length() << " x B:" << r.get_breadth()
              << "\n";
  };
};

#endif // !CSV_VISITOR_HPP
