
#ifndef LOGGED_PAYMENTS_SERVICE_HPP
#define LOGGED_PAYMENTS_SERVICE_HPP

#include "payments-service.hpp"

#include <iostream>
#include <unordered_map>
class LoggedPaymentsService : public PaymentsService {
  PaymentsService *m_ps;

public:
  LoggedPaymentsService(PaymentsService *ps) : m_ps(ps) {}

  std::string create_payment_url(int amount, int order_id) override {
    std::cout << "<LoggedPaymentsService>\n";

    // logic begins
    std::cout << "[LPS] Begin Logged Execution:\n";
    std::string payment_link = this->m_ps->create_payment_url(amount, order_id);
    std::cout << "[LPS] End Logged Execution:\n";

    // logic ends
    std::cout << "</LoggedPaymentsService>\n";

    return payment_link;
  }
};

#endif // !LOGGED_PAYMENTS_SERVICE_HPP
