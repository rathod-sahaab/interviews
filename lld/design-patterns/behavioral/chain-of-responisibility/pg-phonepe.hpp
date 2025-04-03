#ifndef PG_PHONEPE
#define PG_PHONEPE

#include "pg-base.hpp"
#include <cstdlib>

class PGPhonepe : public PGBase {
public:
  std::optional<std::string> create_payment_url(int order_id, int amount) {
    const auto success = amount <= 100;
    if (success) {
      return "https://phonepe.com";
    } else {
      return this->PGBase::create_payment_url(order_id, amount);
    }
  }
};

#endif // !PG_PHONEPE
