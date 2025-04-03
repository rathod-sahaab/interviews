#ifndef SERVICE_HPP
#define SERVICE_HPP

#include <string>

class PaymentsService {
public:
  virtual std::string create_payment_url(int amount, int order_id) = 0;
};

#endif // !SERVICE_HPP
