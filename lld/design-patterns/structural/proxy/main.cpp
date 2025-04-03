#include "cache-payments-service.hpp"
#include "logged-payments-service.hpp"
#include "payment-service-impl.hpp"
#include "payments-service.hpp"
#include <iostream>
int main(int argc, char *argv[]) {
  PaymentsService *p = new PaymentsServiceImpl("credentials");
  PaymentsService *c = new CachedPaymentsService(p);
  PaymentsService *l = new LoggedPaymentsService(c);

  std::cout << "First Payment Link  >\n"
            << l->create_payment_url(123, 987) << "\n";
  std::cout << "----------------------------------------\n";
  std::cout << "Final Payment Link  >\n"
            << l->create_payment_url(321, 987) << "\n";

  return 0;
}
