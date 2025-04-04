#ifndef PIZZA_HPP
#define PIZZA_HPP

#include <string>
#include <vector>

class Pizza {
public:
  virtual float get_cost() = 0;
  virtual std::vector<std::string> get_ingredients() = 0;

  virtual ~Pizza() {}
};

#endif // !PIZZA_HPP
