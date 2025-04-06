#include "area-visitor.hpp"
#include "circle.hpp"
#include "csv-visitor.hpp"
#include "rect.hpp"
#include "shape.hpp"
#include <iostream>
#include <vector>

int main(int argc, char *argv[]) {
  std::vector<Shape *> shapes{
      new Circle(1.0),    new Rect(1.0, 2.0), new Circle(2.0),
      new Rect(2.0, 3.0), new Circle(3.0),    new Rect(3.0, 4.0),
  };

  {
    CsvVisitor csv_visitor;
    std::cout << "----CSV----\n";
    std::cout << "Shape kind, Dimensions\n";
    for (const auto &shape : shapes) {
      shape->accept(csv_visitor);
    }
  }
  {
    AreaVisitor area_visitor;
    std::cout << "----Area----\n";
    std::cout << "Shape kind, Area\n";
    for (const auto &shape : shapes) {
      shape->accept(area_visitor);
    }
  }

  for (auto &shape : shapes) {
    delete shape;
  }

  return 0;
}
