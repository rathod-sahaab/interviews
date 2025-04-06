#ifndef SNAPSHOT_HPP
#define SNAPSHOT_HPP

#include "state.hpp"
class Snapshot {
  State m_state;

public:
  Snapshot(State s) : m_state(s) {}

  State get_state() const { return m_state; }
};

#endif // !SNAPSHOT_HPP
