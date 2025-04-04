#ifndef BASE_MARGHERITA_HPP
#define BASE_MARGHERITA_HPP

#include "pizza.hpp"
#include <string>
#include <vector>
class BaseMargherita : public Pizza {
public:
  float get_cost() override { return 200; }

  std::vector<std::string> get_ingredients() override { return {"Margherita"}; }
};

#endif // !BASE_MARGHERITA_HPP
