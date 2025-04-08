#ifndef MEDIATOR_HPP
#define MEDIATOR_HPP

class Bidder;
class Mediator {
public:
  virtual void place_bid(Bidder *sender, int amount) = 0;
  virtual void add_participant(Bidder *p) = 0;
};

#endif // !MEDIATOR_HPP
