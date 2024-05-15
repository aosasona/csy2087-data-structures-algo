#include "include/linked_list.hh"
#include <cstdio>
#include <iostream>
#include <string>

const uint BUF_LEN = 16;

LinkedList::LinkedList() { this->head = NULL; }

LinkedList::~LinkedList() {
  Node *current_node = this->head;
  while (current_node != NULL) {

    // Take the next node and store the pointer so we can delete it later
    Node *next_node = current_node->next;

    // If we have no next node, set our head to NULL and break out
    if (next_node == NULL) {
      std::printf("> Freeing head node: ");
      this->head->print();
      this->head = NULL;
      break;
    }

    std::printf("> Freeing node: ");
    next_node->print();

    // Point our next node in the head to the next of the one we are about to
    // delete so that we retain the "chain"
    this->head->next = next_node->next;

    // It is safe to free the memory the memory belonging to our old "next node"
    // now since we have removed it from the node
    delete next_node;
  }
}

void LinkedList::insert(int value) {
  Node *node = new Node(value);

  // If we have no nodes in the list yet, set the head node
  if (this->head == NULL) {
    this->head = node;
    return;
  }

  Node *last_node = this->get_last_node();
  if (last_node == NULL) {
    return;
  }

  last_node->next = node;
}

Node *LinkedList::get_last_node() {
  // we don't need to check if the head is empty here because we will break out
  // in the first iteration anyway when our current_node tests positive to the
  // null check in the loop

  Node *current_node = this->head; // where we currently are in the list
  Node *previous_node = NULL;      // the last valid node we visited
  while (current_node != NULL) {
    previous_node = current_node;
    current_node = current_node->next;
  }

  return previous_node;
}

// Traverse the list until we find the first match and return it
// It is being returned as a const pointer because we don't want the user to
// modify the content of the address
const Node *LinkedList::get(int value) {
  const Node *current_node = this->head;
  const Node *node = NULL;

  while (current_node != NULL) {
    if (current_node->data == value) {
      node = current_node;
      break;
    }

    current_node = current_node->next;
  }

  return node;
}

void LinkedList::remove(int value) {
  Node *current_node = this->head;
  Node *target_node = NULL;

  while (current_node != NULL) {
    if (current_node->data == value) {
      target_node = current_node;
      break;
    }

    current_node = current_node->next;
  }

  if (target_node == NULL) {
    std::printf("[WARNING] value `%d` is not present in the list!\n", value);
    return;
  }

  // If the current node is also the head, trying to do it the normal way will
  // cause an error since we don't have a node to the left
  if (current_node == this->head) {
    this->head = target_node->next;
  } else {
    current_node->next = target_node->next;
  }

  delete target_node;
}

void LinkedList::print() {
  if (this->head == NULL) {
    std::cout << "> Nodes -> []\n";
    return;
  }

  int n;
  char bf[BUF_LEN];
  std::string list_str = "> List nodes\n\t";

  Node *current_node = this->head;
  while (current_node != NULL) {
    n = std::snprintf(bf, BUF_LEN, "Node(%d)-->", current_node->data);
    if (n >= 0 && n < BUF_LEN) {
      list_str += bf;
    }

    current_node = current_node->next;
  }

  list_str += "(NULL)";

  std::cout << list_str << std::endl;
}

// Warning: this "consumes" the list, you could ideally mark the node you want
// the loop to stop at instead of removing the node completely
void LinkedList::print_reverse() {
  int n;
  char bf[BUF_LEN];
  std::string list_str = "> List nodes\n\t(NULL)<--";

  while (this->head->next != NULL) {
    Node *prev_node = NULL;
    Node *tail = this->head;
    Node *last_tail = NULL;

    for (;;) {
      if (tail->next == NULL) {
        break;
      }

      prev_node = tail;
      tail = tail->next;
    }

    n = std::snprintf(bf, BUF_LEN, "Node(%d)<--", tail->data);
    if (n >= 0 && n < BUF_LEN) {
      list_str += bf;
    }

    prev_node->next = NULL;
    tail = this->head;
  }

  printf("%sHead(%d)\n", list_str.c_str(), this->head->data);
}
