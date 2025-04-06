#include "history.hpp"
#include "original.hpp"
#include "snapshot.hpp"
#include "state.hpp"
#include <iostream>
int main(int argc, char *argv[]) {

  Original original(State{.pos_x = 0, .pos_y = 0});

  History history;

  history.add_snapshot(original.snap()); // 0, 0
  std::cout << original.snap().get_state() << std::endl;

  original.move(1, 2);

  history.add_snapshot(original.snap()); // 1, 2
  std::cout << original.snap().get_state() << std::endl;

  original.move(2, 4);
  original.move(4, 5);

  history.add_snapshot(original.snap()); // saves  4,5
  std::cout << original.snap().get_state() << std::endl;

  {
    const std::optional<Snapshot> restored = history.undo();

    original.restore(
        restored.value_or(Snapshot(State{.pos_x = 0, .pos_y = 0})));
  }

  std::cout << original.snap().get_state() << std::endl; // 1, 2
  original.move(3, 3);

  history.add_snapshot(original.snap()); // 3,3
  std::cout << original.snap().get_state() << std::endl;

  original.move(5, 5);

  history.add_snapshot(original.snap()); // saves  5,5
  std::cout << original.snap().get_state() << std::endl;

  {
    const std::optional<Snapshot> restored = history.undo();

    original.restore(
        restored.value_or(Snapshot(State{.pos_x = 0, .pos_y = 0})));
  }

  std::cout << original.snap().get_state() << std::endl; // 3, 3

  return 0;
}
