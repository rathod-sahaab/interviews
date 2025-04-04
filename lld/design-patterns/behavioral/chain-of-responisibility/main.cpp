#include "pg-phonepe.hpp"
#include "pg-stripe.hpp"
#include <iostream>
#include <vector>
using namespace std;
int main(int argc, char *argv[]) {
  vector<pair<int, int>> order_amounts{{1, 100}, {2, 200}, {3, 300}};

  {
    PGPhonepe *phonepe = new PGPhonepe();
    PGStripe *stripe = new PGStripe();

    phonepe->set_next(stripe);

    for (const auto &[order, amount] : order_amounts) {
      const auto phonepe_chain_res = phonepe->create_payment_url(order, amount);

      std::cout << "[PhonePe chain result] (" << amount
                << "):" << phonepe_chain_res.value_or("Failed") << "\n";
      std::cout << "-------------------------------------------------\n";
    }
    delete phonepe;
    delete stripe;
  }
  {
    PGPhonepe *phonepe = new PGPhonepe();
    PGStripe *stripe = new PGStripe();

    stripe->set_next(phonepe);

    for (const auto &[order, amount] : order_amounts) {
      const auto stripe_chain_res = stripe->create_payment_url(order, amount);

      std::cout << "[Stripe chain result] (" << amount
                << "):" << stripe_chain_res.value_or("Failed") << "\n";
      std::cout << "-------------------------------------------------\n";
    }
    delete phonepe;
    delete stripe;
  }

  return 0;
}
