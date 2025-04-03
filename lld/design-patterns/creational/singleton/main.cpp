#include "config.hpp"
#include <iostream>

int main(int argc, char *argv[]) {

  for (int i = 0; i < 5; ++i) {
    const Config *config = Config::getInstance();
  }

  return 0;
}
