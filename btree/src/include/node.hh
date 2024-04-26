// TODO: refactor to fit b-tree
struct Node {
  int data;
  Node *next;
  void print() const;
  Node(int);
};
