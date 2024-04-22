#include "include/node.hh"
#include <cstddef>
#include <cstdio>

Node::Node(int value) {
  this->data = value;
  this->next = NULL;
}

void Node::print() const {
  std::printf("Node(value=%d, next=%p)\n", this->data, this->next);
}
