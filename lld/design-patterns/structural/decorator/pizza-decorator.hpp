#ifndef PIZZA_DECORATOR_HPP
#define PIZZA_DECORATOR_HPP

#include "pizza.hpp"

class PizzaDecorator : public Pizza {
  Pizza *m_internal_pizza;

public:
  PizzaDecorator(Pizza *base_pizza) : m_internal_pizza(base_pizza) {}

  float get_cost() override { return m_internal_pizza->get_cost(); }

  std::vector<std::string> get_ingredients() override {
    return m_internal_pizza->get_ingredients();
  }

  virtual ~PizzaDecorator() { delete m_internal_pizza; }
};

#endif // !PIZZA_DECORATOR_HPP
