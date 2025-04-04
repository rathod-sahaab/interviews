#include "generic-application-builder.hpp"
#include "https-application-builder.hpp"

int main(int argc, char *argv[]) {
  {
    GenericApplicationBuilder *b = new GenericApplicationBuilder;

    b->set_api_key("generic_api_key")
        ->set_jwt_secret("generic_jwt_secret")
        ->set_keep_alive_seconds(10)
        ->set_port(3030);

    Application *app = b->build();

    std::cout << *app;

    delete app;
    delete b;
  }

  {
    HttpsApplicationBuilder *b = new HttpsApplicationBuilder;

    b->set_api_key("https_api_key")
        ->set_jwt_secret("https_jwt_secret")
        ->set_keep_alive_seconds(11);

    Application *app = b->build();

    std::cout << *app;

    delete app;
    delete b;
  }
  return 0;
}
