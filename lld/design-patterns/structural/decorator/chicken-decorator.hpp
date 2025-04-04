
#ifndef CHICKEN_DECORATOR_HPP
#define CHICKEN_DECORATOR_HPP

#include "pizza-decorator.hpp"
#include <vector>

class ChickenDecorator : public PizzaDecorator {
public:
  ChickenDecorator(Pizza *base_pizza) : PizzaDecorator(base_pizza) {}

  float get_cost() override { return 15.0 + PizzaDecorator::get_cost(); }

  std::vector<std::string> get_ingredients() override {
    auto base_ingredients = PizzaDecorator::get_ingredients();
    base_ingredients.push_back("Chickens");

    return base_ingredients;
  }
};

#endif //! CHICKEN_DECORATOR_HPP
