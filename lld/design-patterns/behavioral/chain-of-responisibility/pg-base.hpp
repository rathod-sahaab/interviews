#ifndef PG_BASE_HPP
#define PG_BASE_HPP

#include "payment-gateway.hpp"
#include <optional>
#include <string>

class PGBase : public PaymentGateway {
  PaymentGateway *m_next;

public:
  PGBase() : m_next(nullptr) {}

  void set_next(PaymentGateway *p) override { this->m_next = p; }

  std::optional<std::string> create_payment_url(int order_id,
                                                int amount) override {
    if (this->m_next == nullptr) {
      return std::nullopt;
    }

    return this->m_next->create_payment_url(order_id, amount);
  }
};

#endif // !PG_BASE_HPP
