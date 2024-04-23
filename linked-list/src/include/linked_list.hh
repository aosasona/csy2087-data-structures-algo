#include "node.hh"

class LinkedList {
public:
  LinkedList();
  ~LinkedList();
  void insert(int);
  const Node *get(int);
  void remove(int);
  void print();

private:
  Node *head;
  Node *get_last_node();
};
