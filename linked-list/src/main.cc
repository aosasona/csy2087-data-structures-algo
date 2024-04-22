#include <cassert>

#include "include/linked_list.hh"
#include "include/utils.hh"

int main(int argc, char *arg_list[]) {
  LinkedList list = LinkedList();

  list.insert(5);
  list.insert(3);
  // list.insert(4);

  // assert(list.get(3).has_value());

  // list.print();

  return 0;
}
