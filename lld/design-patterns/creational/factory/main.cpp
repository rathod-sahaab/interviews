#include "circle.hpp"
#include "shape-factory-impl.hpp"
#include "shape-factory-interface.hpp"
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
  // customise the factory logic instead of passing params
  ShapeFactoryInterface *sf1 = new ShapeFactoryImpl(5, 5, 15);

  // keep createShape common
  Shape *c1 = sf1->createShape(ShapeKind::CIRCLE);
  Shape *r1 = sf1->createShape(ShapeKind::RECTANGLE);

  ShapeFactoryInterface *sf2 = new ShapeFactoryImpl(1, 1, 1);

  Shape *c2 = sf2->createShape(ShapeKind::CIRCLE);
  Shape *r2 = sf2->createShape(ShapeKind::RECTANGLE);

  std::vector<Shape *> shapes{c1, c2, r1, r2};

  for (const auto shape : shapes) {
    std::cout << "Area: " << shape->area() << "\n";
  }

  return 0;
}
