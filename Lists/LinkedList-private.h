// -*- C++ -*-
/**
 * \file  LinkedList-private.h
 * \author Stetson Bost
 * \brief Implements the details of the LinkedList class
 */

#include <cassert>
#include <cstddef>


// ----------------------
//   LinkedList Class 
// ----------------------

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
  ++size_;
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
  ++size_;
}

template <class Item>
Item& LinkedList<Item>::pop_back() {
  Item value = last_->value_;
  last_ = last_->prev_;
  delete last_->next_;
  last_->next_ = nullptr;
  return value;
}

template <class Item>
typename LinkedList<Item>::iterator LinkedList<Item>::insert(
    iterator position, const Item& value) {
  Node* node = new Node{value, *position, *position->prev_};
  node->prev_->next_ = node;
  node->next_->prev_ = node;
  return iterator(node);
}

template <class Item>
typename LinkedList<Item>::iterator LinkedList<Item>::erase(iterator position) {
  iterator nextIter = new iterator(*position->next_);
  if (*position->prev_ != nullptr) {
    *position->prev_->next_ = *position->next_;
  }
  if (*position->next_ != nullptr) {
    *position->next_->prev_ = *position->prev_;
  }
  delete *position;
  return nextIter;
}

template <class Item>
void LinkedList<Item>::remove(const Item& value) {
  iterator iter = begin()
  while (iter != end()) {
    if (*iter->value_ == value) {
      // erase value at current iter's node, returns iter for next node 
      iter = erase(iter);
    } else {
      ++iter;
    }
  }
}

template <class Item>
void LinkedList<Item>::append(const LinkedList<Item>& list) {
  for (iterator iter = list.begin(); iter != list.end(); ++iter) {
    // copies over list at end of *this
    push_back(*iter->value_);
  }
}

template <class Item>
Item& LinkedList<Item>::operator+=(const Item& rhs) {
  push_back(rhs);
}

template <class Item>
bool LinkedList<Item>::operator==(const LinkedList<Item>& rhs) const {
  if (size_ != rhs.size_) {
    for (iterator thisIter = begin(), iterator rhsIter = rhs.begin();
        (thisIter != end()) && (rhsIter != rhs.end());
        ++thisIter, ++rhsIter) {
      if (*thisIter->value_ != *rhsIter->value_) {
        return false;
      }
    }
    return true;
  }
  return false;
}

template <class Item>
bool LinkedList<Item>::operator!=(const Item& rhs) const {
  return !operator==(rhs);
}

template <class Item>
void LinkedList<Item>::outputAllValues() const {
  // TODO
}



// -------------------------------
//   LinkedList Iterator Class 
// -------------------------------
