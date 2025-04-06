#ifndef STATE_HPP
#define STATE_HPP

#include <ostream>
struct State {
  int pos_x = 0;
  int pos_y = 0;

  void set_state(int x, int y) {
    pos_x = x;
    pos_y = y;
  }

  void set_state(State s) {
    pos_x = s.pos_x;
    pos_y = s.pos_y;
  }
};

std::ostream &operator<<(std::ostream &os, const State &s) {
  os << "State{x=" << s.pos_x << ", y=" << s.pos_y << "}";
  return os;
}

#endif // !STATE_HPP
