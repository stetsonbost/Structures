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
Heap<Item>::Iterator<iteratorIsConst>(std::vector<Item>::iterator iter) 
    : current_(iter) {
}


template <class Item>
template <bool iteratorIsConst>
Heap<Item>::Iterator<iteratorIsConst>& 
    Heap<Item>::Iterator<iteratorIsConst>::operator++() {
  current_ = ++current_;
  return current_;
}

template <class Item>
template <bool iteratorIsConst>
Heap<Item>::Iterator<iteratorIsConst>& 
    Heap<Item>::Iterator<iteratorIsConst>::operator--() {
  current_ = --current_;
  return current_;
}

template <class Item>
template <bool iteratorIsConst>
Item*& Heap<Item>::Iterator<iteratorIsConst>::operator*() const {
  return *current_;
}

template <class Item>
template <bool iteratorIsConst>
bool Heap<Item>::Iterator<iteratorIsConst>::operator==(
    const Iterator& rhs) const {
  return current_ == rhs.current_;
}

template <class Item>
template <bool iteratorIsConst>
bool Heap<Item>::Iterator<iteratorIsConst>::operator!=(
    const Iterator& rhs) const {
  return !operator==(rhs);
}
