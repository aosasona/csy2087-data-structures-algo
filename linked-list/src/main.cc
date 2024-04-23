#include <cassert>

#include "include/linked_list.hh"
#include "include/utils.hh"

int main(int argc, char *arg_list[]) {
  LinkedList list = LinkedList();

  // Insert some values
  list.insert(5);
  list.insert(3);
  list.insert(99);
  list.insert(6);

  // Make sure we can get the values we inserted and that we can't get values
  // that we didn't insert
  assert(list.get(5) != NULL);
  assert(list.get(3) != NULL);
  assert(list.get(99) != NULL);
  assert(list.get(1) == NULL);

  list.remove(5);
  assert(list.get(5) == NULL);

  list.remove(10);

  list.insert(200);
  list.insert(19);

  // Print the list
  // Expected: Node(3)->Node(99)->Node(6)->Node(200)-> Node(19)->(NULL)
  list.print();

  return 0;
}
