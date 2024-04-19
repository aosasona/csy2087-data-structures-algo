#include "include/linked_list.hh"

LinkedList::LinkedList() { this->head = NULL; }

LinkedList::~LinkedList() {
  // TODO: implenent destructor
}

bool LinkedList::is_empty() const { return (this->head == NULL); }

void LinkedList::insert(int value) {}

std::optional<int> LinkedList::get(int value) const {}
