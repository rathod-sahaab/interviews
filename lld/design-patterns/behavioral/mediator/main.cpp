#include "auction-mediator.hpp"
#include "mediator.hpp"
int main(int argc, char *argv[]) {

  Mediator *am = new AuctionMediator;

  const std::vector<Bidder *> bidders{
      new Bidder("1", am), new Bidder("2", am), new Bidder("3", am),
      new Bidder("4", am), new Bidder("5", am),
  };

  for (auto b : bidders) {
    am->add_participant(b);
  }

  for (int i = 0; i < bidders.size(); ++i) {
    am->place_bid(bidders[i], 100 + i);
  }

  return 0;
}
