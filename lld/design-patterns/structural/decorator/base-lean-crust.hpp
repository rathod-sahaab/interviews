#ifndef BASE_LEAN_CRUST_HPP
#define BASE_LEAN_CRUST_HPP

#include "pizza.hpp"
#include <string>
#include <vector>
class BaseLeanCrust : public Pizza {
public:
  float get_cost() override { return 210; }

  std::vector<std::string> get_ingredients() override { return {"Lean Crust"}; }
};

#endif // !BASE_LEAN_CRUST_HPP
