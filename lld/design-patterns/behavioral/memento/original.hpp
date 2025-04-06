#ifndef ORIGINAL_HPP
#define ORIGINAL_HPP

#include "snapshot.hpp"
#include "state.hpp"

class Original {
  State m_state;

public:
  Original(State s) : m_state(s) {}

  Snapshot snap() { return Snapshot(m_state); }
  void restore(Snapshot snap) { m_state.set_state(snap.get_state()); }

  // mutations
  void move(int x, int y) { m_state.set_state(x, y); }
};

#endif // !ORIGINAL_HPP
