#include <iostream>
#include "circle.hpp"

int main (int argc, char *argv[]) {
  Circle *c = new Circle(1);

  std::cout << "Circle Area:" << c->area() << "\n";

  delete c;
  return 0;
}
