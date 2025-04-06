#ifndef HISTORY_HPP
#define HISTORY_HPP

#include "snapshot.hpp"
#include <optional>
#include <vector>
class History {
  std::vector<Snapshot> m_snapshots;

public:
  void add_snapshot(Snapshot s) { m_snapshots.push_back(s); }
  std::optional<Snapshot> undo() {
    if (m_snapshots.empty()) {
      return std::nullopt;
    }

    m_snapshots.pop_back();

    if (m_snapshots.empty()) {
      return std::nullopt;
    }

    return Snapshot(m_snapshots.back());
  }
};
#endif // !HISTORY_HPP
