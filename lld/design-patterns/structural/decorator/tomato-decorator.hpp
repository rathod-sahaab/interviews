#ifndef TOMATO_DECORATOR_HPP
#define TOMATO_DECORATOR_HPP

#include "pizza-decorator.hpp"
#include <vector>

class TomatoDecorator : public PizzaDecorator {
public:
  TomatoDecorator(Pizza *base_pizza) : PizzaDecorator(base_pizza) {}

  float get_cost() override { return 15.0 + PizzaDecorator::get_cost(); }

  std::vector<std::string> get_ingredients() override {
    auto base_ingredients = PizzaDecorator::get_ingredients();
    base_ingredients.push_back("Tomatoes");

    return base_ingredients;
  }
};

#endif //! TOMATO_DECORATOR_HPP
