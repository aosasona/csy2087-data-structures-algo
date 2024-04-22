#include <optional>

#include "node.hh"

class LinkedList {
public:
  LinkedList();
  ~LinkedList();
  void insert(int);
  std::optional<const Node *> get(int) const;
  void remove(int);
  bool is_empty() const;
  void print();

private:
  Node *head;
  std::optional<Node *> get_last_node();
};
