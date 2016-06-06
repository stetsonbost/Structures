// -*- C++ -*-
/**
 * \file  Heap-private.h
 * \author Stetson Bost
 * \brief Implements the details of the Heap Iterator classes
 */

#include <cassert>
#include <cstddef>
#include <iostream> 
#include <vector>


// -------------------------------
//   Heap Iterator Class 
// -------------------------------

template <class Item>
template <bool iteratorIsConst>
Heap<Item>::Iterator<iteratorIsConst>::Iterator(
    size_t index, std::vector<Item>* data) : index_(index), data_(data) {
}


template <class Item>
template <bool iteratorIsConst>
Heap<Item>::Iterator<iteratorIsConst>& 
    Heap<Item>::Iterator<iteratorIsConst>::operator++() {
  index_ = ++index_;
  return index_;
}

template <class Item>
template <bool iteratorIsConst>
Heap<Item>::Iterator<iteratorIsConst>& 
    Heap<Item>::Iterator<iteratorIsConst>::operator--() {
  index_ = --index_;
  return index_;
}

template <class Item>
template <bool iteratorIsConst>
Item*& Heap<Item>::Iterator<iteratorIsConst>::operator*() {
  return *data_[index_];
}

template <class Item>
template <bool iteratorIsConst>
bool Heap<Item>::Iterator<iteratorIsConst>::operator==(
    const Iterator& rhs) const {
  return index_ == rhs.index_;
}

template <class Item>
template <bool iteratorIsConst>
bool Heap<Item>::Iterator<iteratorIsConst>::operator!=(
    const Iterator& rhs) const {
  return !operator==(rhs);
}
