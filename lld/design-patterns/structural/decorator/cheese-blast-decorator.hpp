#ifndef CHEESE_BLAST_DECORATOR_HPP
#define CHEESE_BLAST_DECORATOR_HPP

#include "pizza-decorator.hpp"
#include <vector>

class CheeseBlastDecorator : public PizzaDecorator {
public:
  CheeseBlastDecorator(Pizza *base_pizza) : PizzaDecorator(base_pizza) {}

  float get_cost() override { return 100.0 + PizzaDecorator::get_cost(); }

  std::vector<std::string> get_ingredients() override {
    auto base_ingredients = PizzaDecorator::get_ingredients();

    // start with cheese blast base;
    base_ingredients.insert(base_ingredients.begin(), "Cheese Blast");

    return base_ingredients;
  }
};

#endif //! CHEESE_BLAST_DECORATOR_HPP
