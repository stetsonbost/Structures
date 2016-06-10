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

template <class Item, bool isMaxHeap>
template <bool iteratorIsConst>
Heap<Item, isMaxHeap>::Iterator<iteratorIsConst>::Iterator(
    size_t index, std::vector<Item>* data) : index_(index), data_(data) {
}


template <class Item, bool isMaxHeap>
template <bool iteratorIsConst>
Heap<Item, isMaxHeap>::Iterator<iteratorIsConst>& 
    Heap<Item, isMaxHeap>::Iterator<iteratorIsConst>::operator++() {
  index_ = ++index_;
  return index_;
}

template <class Item, bool isMaxHeap>
template <bool iteratorIsConst>
Heap<Item, isMaxHeap>::Iterator<iteratorIsConst>& 
    Heap<Item, isMaxHeap>::Iterator<iteratorIsConst>::operator--() {
  index_ = --index_;
  return index_;
}

template <class Item, bool isMaxHeap>
template <bool iteratorIsConst>
Item*& Heap<Item, isMaxHeap>::Iterator<iteratorIsConst>::operator*() {
  return *data_[index_];
}

template <class Item, bool isMaxHeap>
template <bool iteratorIsConst>
bool Heap<Item, isMaxHeap>::Iterator<iteratorIsConst>::operator==(
    const Iterator& rhs) const {
  return index_ == rhs.index_;
}

template <class Item, bool isMaxHeap>
template <bool iteratorIsConst>
bool Heap<Item, isMaxHeap>::Iterator<iteratorIsConst>::operator!=(
    const Iterator& rhs) const {
  return !operator==(rhs);
}


// -------------------------------
//   Heap ReverseIterator Class 
// -------------------------------

template <class Item, bool isMaxHeap>
template <bool iteratorIsConst>
Heap<Item, isMaxHeap>::ReverseIterator<iteratorIsConst>::ReverseIterator(
    size_t index, std::vector<Item>* data) : index_(index), data_(data) {
}


template <class Item, bool isMaxHeap>
template <bool iteratorIsConst>
Heap<Item, isMaxHeap>::ReverseIterator<iteratorIsConst>& 
    Heap<Item, isMaxHeap>::ReverseIterator<iteratorIsConst>::operator++() {
  index_ = --index_;
  return index_;
}

template <class Item, bool isMaxHeap>
template <bool iteratorIsConst>
Heap<Item, isMaxHeap>::ReverseIterator<iteratorIsConst>& 
    Heap<Item, isMaxHeap>::ReverseIterator<iteratorIsConst>::operator--() {
  index_ = ++index_;
  return index_;
}

template <class Item, bool isMaxHeap>
template <bool iteratorIsConst>
Item*& Heap<Item, isMaxHeap>::ReverseIterator<iteratorIsConst>::operator*() {
  return *data_[index_];
}

template <class Item, bool isMaxHeap>
template <bool iteratorIsConst>
bool Heap<Item, isMaxHeap>::ReverseIterator<iteratorIsConst>::operator==(
    const ReverseIterator& rhs) const {
  return index_ == rhs.index_;
}

template <class Item, bool isMaxHeap>
template <bool iteratorIsConst>
bool Heap<Item, isMaxHeap>::ReverseIterator<iteratorIsConst>::operator!=(
    const ReverseIterator& rhs) const {
  return !operator==(rhs);
}
