#ifndef AUCTION_MEDIATOR
#define AUCTION_MEDIATOR

#include "bidder.hpp"
#include "mediator.hpp"

#include <string>
#include <vector>
class AuctionMediator : public Mediator {
  std::vector<Bidder *> m_participants;

public:
  void place_bid(Bidder *sender, int amount) override {
    for (auto p : m_participants) {
      if (p != sender) {
        p->recv_message(std::to_string(amount));
      }
    }
  }
  void add_participant(Bidder *p) override { m_participants.push_back(p); }
};

#endif // !AUCTION_MEDIATOR
