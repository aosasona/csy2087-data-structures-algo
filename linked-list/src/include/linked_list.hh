#include <optional>

struct Node {
  int data;
  Node *next;
  Node(int);
};

class LinkedList {
public:
  LinkedList();
  ~LinkedList();
  void insert(int);
  std::optional<int> get(int) const;
  bool is_empty() const;

private:
  Node *head;
};
