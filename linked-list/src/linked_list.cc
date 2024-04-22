#include "include/linked_list.hh"
#include <cstdio>
#include <iostream>
#include <optional>
#include <string>

const uint BUF_LEN = 256;

LinkedList::LinkedList() { this->head = NULL; }

LinkedList::~LinkedList() {
  // Node *current_node = this->head;
  // while (current_node != NULL) {
  //   auto next = current_node->get_next();
  //   if (next != NULL) {
  //     current_node = next;
  //     delete current_node;
  //   }
  // }
  //
  // this->head = NULL;
}

bool LinkedList::is_empty() const { return (this->head == NULL); }

void LinkedList::insert(int value) {
  Node node = Node(value);

  if (this->head == NULL) {
    this->head = &node;
    return;
  }

  std::optional<Node *> last_node = this->get_last_node();
  if (!last_node.has_value()) {
    return;
  }

  // TODO: remove
  std::printf("last_node before setting next: ");
  last_node.value()->print();

  //////
  last_node.value()->set_next(node);
  //////

  // TODO: remove
  std::printf("last_node: ");
  last_node.value()->print();

  // TODO: remove
  std::printf("node: ");
  node.print();
}

std::optional<Node *> LinkedList::get_last_node() {
  // we don't need to check if the head is empty here because we will break out
  // in the first iteration anyway when our current_node tests positive to the
  // null check in the loop

  Node *current_node = this->head; // where we currently are in the list
  Node *previous_node = NULL;      // the last valid node we visited
  while (current_node != NULL) {
    previous_node = current_node;
    current_node = current_node->get_next();
  }

  return previous_node == NULL ? std::nullopt
                               : std::optional<Node *>(previous_node);
}

std::optional<const Node *> LinkedList::get(int value) const {
  const Node *current_node = this->head;
  const Node *node = NULL;

  while (current_node != NULL) {
    if (current_node->value() == value) {
      node = current_node;
      break;
    }

    current_node = current_node->get_next();
  }

  return node == NULL ? std::nullopt : std::optional<const Node *>(node);
}

void LinkedList::remove(int value) {
  Node *current_node = this->head;
  Node *target_node = NULL;

  while (current_node != NULL) {
    if (current_node->value() == value) {
      target_node = current_node;
      break;
    }

    current_node = current_node->get_next();
  }

  if (target_node == NULL) {
    throw std::invalid_argument("value is not present in the list!");
  }

  current_node->set_next(*target_node->get_next());
  delete target_node;
}

void LinkedList::print() {
  if (this->head == NULL) {
    std::cout << "Empty list";
    return;
  }

  int n;
  char bf[BUF_LEN];
  std::string list_str = "";

  Node *current_node = this->head;
  while (current_node != NULL) {
    n = std::snprintf(bf, BUF_LEN, "Node(%d)-->", current_node->value());
    if (n >= 0 && n < BUF_LEN) {
      list_str += bf;
    }

    current_node = current_node->get_next();
    // std::cout << current_node->get_next() << std::endl;
    break;
  }

  list_str.pop_back();
  list_str.pop_back();
  list_str.pop_back();

  std::cout << list_str;
}
