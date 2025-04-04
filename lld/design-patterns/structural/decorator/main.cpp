#include "base-margherita.hpp"
#include "cheese-blast-decorator.hpp"
#include "chicken-decorator.hpp"
#include "pizza.hpp"
#include "tomato-decorator.hpp"
#include <iostream>
int main(int argc, char *argv[]) {
  {
    Pizza *margherita = new BaseMargherita;

    Pizza *margherita_cheese_blast = new CheeseBlastDecorator(margherita);
    Pizza *chicken_margherita_cheese_blast =
        new ChickenDecorator(margherita_cheese_blast);
    Pizza *tomato_chicken_margherita_cheese_blast =
        new TomatoDecorator(chicken_margherita_cheese_blast);

    const auto cost = tomato_chicken_margherita_cheese_blast->get_cost();
    const auto ingredients =
        tomato_chicken_margherita_cheese_blast->get_ingredients();

    std::cout << "🍕 Pizza Order Summary\n";
    std::cout << "Cost: $" << cost << "\n";
    std::cout << "Ingredients: [";

    bool first = true;
    for (const auto &ingredient : ingredients) {
      if (!first)
        std::cout << ", ";
      std::cout << ingredient;
      first = false;
    }
    std::cout << "]\n";

    delete tomato_chicken_margherita_cheese_blast;
  }
  return 0;
}
