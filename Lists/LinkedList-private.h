// -*- C++ -*-
/**
 * \file  LinkedList-private.h
 * \author Stetson Bost
 * \brief Implements the details of the LinkedList class
 */

#include <cassert>
#include <cstddef>

template <class Item>
LinkedList<Item>::LinkedList() : size_(0), first_(nullptr), last_(nullptr) {}

template <class Item>
LinkedList<Item>::LinkedList(const LinkedList<Item>& list) {
  // TODO
}

template <class Item>
LinkedList<Item>::~LinkedList(const LinkedList<Item>& list) {
  // TODO
}

template <class Item>
LinkedList<Item> LinkedList<Item>::operator=(const LinkedList<Item>& list) {
  // TODO
}

template <class Item>
size_t LinkedList<Item>::size() const {
  return size_;
}

template <class Item>
bool LinkedList<Item>::isEmpty() const {
  return (size_ == 0);
}

template <class Item>
Item& LinkedList<Item>::front() const {
  return first_->value_;
}

template <class Item>
Item& LinkedList<Item>::back() const {
  return last_->value_;
}

template <class Item>
void LinkedList<Item>::assign(const LinkedList<Item>& list){
  // use assignment operator
  this = list;
}

template <class Item>
void LinkedList<Item>::push_front(const Item& value) {
  Node* node = new Node{value, first_, nullptr};
  first_->prev_ = node;
  first_= node;
}

template <class Item>
Item& LinkedList<Item>::pop_front() {
  Item value = first_->value_;
  first_ = first_->next_;
  delete first_->prev_;
  first_->prev_ = nullptr;
  return value;
}

template <class Item>
void LinkedList<Item>::push_back(const Item& value) {
  Node* node = new Node{value, last_, nullptr};
  last_->next_ = node;
  last_= node;
}

template <class Item>
Item& LinkedList<Item>::pop_back() {
  Item value = last_->value_;
  last_ = last_->prev_;
  delete last_->next_;
  last_->next_ = nullptr;
  return value;
}