#ifndef PAYMENT_GATEWAY_HPP
#define PAYMENT_GATEWAY_HPP

#include <optional>
#include <string>

class PaymentGateway {
public:
  virtual void set_next(PaymentGateway *p) = 0;
  virtual std::optional<std::string> create_payment_url(int order_id,
                                                        int amount) = 0;
};

#endif // !PAYMENT_GATEWAY_HPP
