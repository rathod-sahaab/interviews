#ifndef BIDDER_HPP
#define BIDDER_HPP

#include "mediator.hpp"
#include <cstdio>
#include <string>

class Bidder {
  std::string m_name;
  Mediator *m_mediator;

public:
  Bidder(std::string name, Mediator *m) : m_name(name), m_mediator(m) {}

  void recv_message(std::string s) {
    printf("[%s] new bid: %s\n", m_name.c_str(), s.c_str());
  }
};

#endif // !BIDDER_HPP
