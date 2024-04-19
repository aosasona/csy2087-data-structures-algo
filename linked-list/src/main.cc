#include <cassert>
#include <cstdio>
#include <iostream>
#include <unordered_map>

#include "include/linked_list.hh"
#include "include/utils.hh"

int main(int argc, char *arg_list[]) {
  LinkedList list = LinkedList();
  list.insert(5);
  list.insert(3);

  auto i2 = list.get(3);
  assert(i2 == 3);

  return 0;
}
