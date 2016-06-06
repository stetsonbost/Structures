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

template <class Item>
Heap<Item>::Heap() : data_(new std::vector<Item>) {
}

template <class Item>
Heap<Item>::Heap(const Heap& heap) {
  //TODO
}

template <class Item>
Heap<Item> Heap<Item>::operator=(const Heap& heap) {
  *data_ = *heap.data_;
}

template <class Item>
Heap<Item>::~Heap() {
  delete data_;
  data_ = nullptr;
}

template <class Item>
size_t Heap<Item>::size() const {
  return data_->size();
}

template <class Item>
bool Heap<Item>::isEmpty() const {
  return data_->empty();
}

template <class Item>
Item& Heap<Item>::peekTop() const {
  // assumes that first element of data exists
  return *data_->begin();
}

template <class Item>
void Heap<Item>::insert(const Item& value) {
  data_->push_back(value);
  if (true) {
    //TODO
  }
}

template <class Item>
void Heap<Item>::erase(iterator& iter) {

}

template <class Item>
Item& Heap<Item>::removeTop() {
  // save value of top (to be returned)
  Item topValue = data_[0];
  // erase the top (includes readjusting heap structure)
  iterator top = iterator(0);
  erase(top);
  // return value of top
  return topValue;
}

template <class Item>
bool Heap<Item>::operator==(const Heap<Item>& rhs) const {

}

template <class Item>
bool Heap<Item>::operator!=(const Item& rhs) const {

}

template <class Item>
Item* Heap<Item>::find(const Item& value) const {

}

template <class Item>
void Heap<Item>::outputAllValues() const {
  for (iterator iter = begin(); iter != end() ; ++iter) {
    std::cout << *iter;
  }
  std::cout << std::endl;
}

template <class Item>
void Heap<Item>::swap(iterator& value1, iterator& value2) {
  Item& temp = *value1;
  *value1 = *value2;
  *value2 = temp;
}

template <class Item>
typename Heap<Item>::iterator Heap<Item>::parent(iterator& child)
    const {
  size_t parent = ((child.index_ + 1) / 2) - 1;
  return iterator(parent);
}

template <class Item>
typename Heap<Item>::iterator Heap<Item>::lchild(iterator& parent)
    const {
  size_t lchild = (parent.index_ * 2) + 1;
  return iterator(lchild);
}

template <class Item>
typename Heap<Item>::iterator Heap<Item>::rchild(iterator& parent)
    const {
  size_t rchild = (parent.index_ * 2) + 2;
  return iterator(rchild);
}


template <class Item>
typename Heap<Item>::iterator Heap<Item>::begin() const {
  return iterator(0);
}

template <class Item>
typename Heap<Item>::iterator Heap<Item>::end() const {
  return iterator(size());
}

template <class Item>
typename Heap<Item>::const_iterator Heap<Item>::cbegin() const {
  return const_iterator(0);
}

template <class Item>
typename Heap<Item>::const_iterator Heap<Item>::cend() const {
  return const_iterator(size());
}
