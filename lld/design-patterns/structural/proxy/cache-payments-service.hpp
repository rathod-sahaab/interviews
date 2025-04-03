#ifndef CACHED_PAYMENTS_SERVICE_HPP
#define CACHED_PAYMENTS_SERVICE_HPP

#include "payments-service.hpp"

#include <iostream>
#include <string>
#include <unordered_map>
class CachedPaymentsService : public PaymentsService {
  std::unordered_map<int, std::string> m_order_payment_link_cache;
  PaymentsService *m_ps;

public:
  CachedPaymentsService(PaymentsService *ps) : m_ps(ps) {}

  std::string create_payment_url(int amount, int order_id) override {
    std::cout << "<CachedPaymentsService>\n";

    // logic begins
    if (this->m_order_payment_link_cache.count(order_id)) {
      std::cout << "[CPS] Cahce Hit!\n";

      // logic ends
      std::cout << "</CachedPaymentsService>\n";

      return m_order_payment_link_cache[order_id];
    }

    std::cout << "[CPS] Cahce Miss :(\n";
    std::string payment_link = this->m_ps->create_payment_url(amount, order_id);

    this->m_order_payment_link_cache[order_id] = payment_link;

    //  logic ends
    std::cout << "</CachedPaymentsService>\n";
    return payment_link;
  }
};

#endif // !CACHED_PAYMENTS_SERVICE_HPP
