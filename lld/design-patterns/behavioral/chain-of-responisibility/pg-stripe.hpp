#ifndef PG_STRIPE
#define PG_STRIPE

#include "pg-base.hpp"
#include <cstdlib>

class PGStripe : public PGBase {
public:
  std::optional<std::string> create_payment_url(int order_id, int amount) {
    const auto success = 100 < amount and amount <= 200;
    if (success) {
      return "https://stripe.com";
    } else {
      return this->PGBase::create_payment_url(order_id, amount);
    }
  }
};

#endif // !PG_STRIPE
