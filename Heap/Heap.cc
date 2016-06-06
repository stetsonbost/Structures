// -*- C++ -*-
/**
 * \file Heap.cc
 * \author Stetson Bost
 * \brief Implements the details of the Heap class
 */

#include "Heap.h"

#include <cassert>
#include <cstddef>
#include <iostream>
#include <vector>

template <class Item, bool isMaxHeap>
Heap<Item, isMaxHeap>::Heap() : data_(new std::vector<Item>) {
}

template <class Item, bool isMaxHeap>
Heap<Item, isMaxHeap>::Heap(const Heap& heap) {
  // vector assignment
  *data_ = *heap.data_;
}

template <class Item, bool isMaxHeap>
Heap<Item, isMaxHeap> Heap<Item, isMaxHeap>::operator=(const Heap& heap) {
  *data_ = *heap.data_;
}

template <class Item, bool isMaxHeap>
Heap<Item, isMaxHeap>::~Heap() {
  delete data_;
  data_ = nullptr;
}

template <class Item, bool isMaxHeap>
size_t Heap<Item, isMaxHeap>::size() const {
  return data_->size();
}

template <class Item, bool isMaxHeap>
bool Heap<Item, isMaxHeap>::isEmpty() const {
  return data_->empty();
}

template <class Item, bool isMaxHeap>
Item& Heap<Item, isMaxHeap>::peekTop() const {
  // assumes that first element of data exists
  return *data_->begin();
}

template <class Item, bool isMaxHeap>
void Heap<Item, isMaxHeap>::insert(const Item& value) {
  data_->push_back(value);
  if (true) {
    //TODO
  }
}

template <class Item, bool isMaxHeap>
void Heap<Item, isMaxHeap>::erase(iterator& iter) {

}

template <class Item, bool isMaxHeap>
Item& Heap<Item, isMaxHeap>::removeTop() {
  // save value of top (to be returned)
  Item topValue = data_[0];
  // erase the top (includes readjusting heap structure)
  iterator top = iterator(0);
  erase(top);
  // return value of top
  return topValue;
}

template <class Item, bool isMaxHeap>
bool Heap<Item, isMaxHeap>::operator==(const Heap<Item, isMaxHeap>& rhs) const {

}

template <class Item, bool isMaxHeap>
bool Heap<Item, isMaxHeap>::operator!=(const Heap<Item, isMaxHeap>& rhs) const {

}

template <class Item, bool isMaxHeap>
Item* Heap<Item, isMaxHeap>::find(const Item& value) const {

}

template <class Item, bool isMaxHeap>
void Heap<Item, isMaxHeap>::outputAllValues() const {
  for (iterator iter = begin(); iter != end() ; ++iter) {
    std::cout << *iter;
  }
  std::cout << std::endl;
}

template <class Item, bool isMaxHeap>
void Heap<Item, isMaxHeap>::swap(iterator& value1, iterator& value2) {
  Item& temp = *value1;
  *value1 = *value2;
  *value2 = temp;
}

template <class Item, bool isMaxHeap>
typename Heap<Item, isMaxHeap>::iterator Heap<Item, isMaxHeap>::parent(iterator& child)
    const {
  size_t parent = ((child.index_ + 1) / 2) - 1;
  return iterator(parent);
}

template <class Item, bool isMaxHeap>
typename Heap<Item, isMaxHeap>::iterator Heap<Item, isMaxHeap>::lchild(iterator& parent)
    const {
  size_t lchild = (parent.index_ * 2) + 1;
  return iterator(lchild);
}

template <class Item, bool isMaxHeap>
typename Heap<Item, isMaxHeap>::iterator Heap<Item, isMaxHeap>::rchild(iterator& parent)
    const {
  size_t rchild = (parent.index_ * 2) + 2;
  return iterator(rchild);
}


template <class Item, bool isMaxHeap>
typename Heap<Item, isMaxHeap>::iterator Heap<Item, isMaxHeap>::begin() const {
  return iterator(0);
}

template <class Item, bool isMaxHeap>
typename Heap<Item, isMaxHeap>::iterator Heap<Item, isMaxHeap>::end() const {
  return iterator(size());
}

template <class Item, bool isMaxHeap>
typename Heap<Item, isMaxHeap>::const_iterator Heap<Item, isMaxHeap>::cbegin() const {
  return const_iterator(0);
}

template <class Item, bool isMaxHeap>
typename Heap<Item, isMaxHeap>::const_iterator Heap<Item, isMaxHeap>::cend() const {
  return const_iterator(size());
}
