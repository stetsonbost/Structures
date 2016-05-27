// -*- C++ -*-
/**
 * \file  LinkedList-private.h
 * \author Stetson Bost
 * \brief Implements the details of the LinkedList Iterator classes
 */

#include <cassert>
#include <cstddef>
#include <iostream> 



// -------------------------------
//   LinkedList Iterator Class 
// -------------------------------

// template <class Item>
// LinkedList<Item>::Iterator::Iterator() : current_(nullptr) {}

template <class Item>
template <bool iteratorIsConst>
LinkedList<Item>::Iterator<iteratorIsConst>::Iterator() : current_(nullptr) {}

template <class Item>
template <bool iteratorIsConst>
LinkedList<Item>::Iterator<iteratorIsConst>& 
    LinkedList<Item>::Iterator<iteratorIsConst>::operator++() {
  current_ = current_->next_;
  return current_;
}

template <class Item>
template <bool iteratorIsConst>
LinkedList<Item>::Iterator<iteratorIsConst>& 
    LinkedList<Item>::Iterator<iteratorIsConst>::operator--() {
  current_ = current_->prev_;
  return current_;
}

template <class Item>
template <bool iteratorIsConst>
Item*& LinkedList<Item>::Iterator<iteratorIsConst>::operator*() const {
  return current_->value;
}

template <class Item>
template <bool iteratorIsConst>
bool LinkedList<Item>::Iterator<iteratorIsConst>::operator==(
    const Iterator& rhs) const {
  return current_ == rhs.current_;
}

template <class Item>
template <bool iteratorIsConst>
bool LinkedList<Item>::Iterator<iteratorIsConst>::operator!=(
    const Iterator& rhs) const {
  return !operator==(rhs);
}

// --------------------------------------
//   LinkedList ReverseIterator Class 
// --------------------------------------

template <class Item>
template <bool iteratorIsConst>
LinkedList<Item>::ReverseIterator<iteratorIsConst>::ReverseIterator()
    : current_(nullptr) {}

template <class Item>
template <bool iteratorIsConst>
LinkedList<Item>::ReverseIterator<iteratorIsConst>& 
    LinkedList<Item>::ReverseIterator<iteratorIsConst>::operator++() {
  current_ = current_->next_;
  return current_;
}

template <class Item>
template <bool iteratorIsConst>
LinkedList<Item>::ReverseIterator<iteratorIsConst>& 
    LinkedList<Item>::ReverseIterator<iteratorIsConst>::operator--() {
  current_ = current_->prev_;
  return current_;
}

template <class Item>
template <bool iteratorIsConst>
Item*& LinkedList<Item>::ReverseIterator<iteratorIsConst>::operator*() const {
  return current_;
}

template <class Item>
template <bool iteratorIsConst>
bool LinkedList<Item>::ReverseIterator<iteratorIsConst>::operator==(
    const ReverseIterator& rhs) const {
  return current_ == rhs.current_;
}

template <class Item>
template <bool iteratorIsConst>
bool LinkedList<Item>::ReverseIterator<iteratorIsConst>::operator!=(
    const ReverseIterator& rhs) const {
  return !operator==(rhs);
}
