#ifndef PAYMENTS_SERVICE_IMPL
#define PAYMENTS_SERVICE_IMPL

#include "payments-service.hpp"
#include <iostream>
#include <string>

class PaymentsServiceImpl : public PaymentsService {
  std::string m_api_key;

public:
  PaymentsServiceImpl(std::string m_api_key) {}

  std::string create_payment_url(int amount, int order_id) override {
    std::cout << "<PaymentsServiceImpl>\n";

    // logic begins
    std::string payment_link = "https://payments.com/" +
                               std::to_string(amount) + "@" +
                               std::to_string(order_id);

    std::cout << "</PaymentsServiceImpl>\n";
    return payment_link;
  }
};

#endif // !PAYMENTS_SERVICE_IMPL
