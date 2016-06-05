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
Heap<Item>::Heap() : size_(0), data_(new std::vector<Item>) {
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
  return *data_.begin();
}

template <class Item>
void Heap<Item>::insert(const Item& value) {
  
}

template <class Item>
void Heap<Item>::erase(const Item& value) {

}

template <class Item>
Item& Heap<Item>::removeTop() {
  Item top = data_[0];
  // TODO

  return top;
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
void swap(iterator value1, iterator value2) {
  Item& temp = *value1;
  *value1 = *value2;
  *value2 = temp;
}

template <class Item>
iterator begin() const {
  return iterator(data_.begin());
}

template <class Item>
iterator end() const {
  return iterator(data_.end());
}

template <class Item>
const_iterator cbegin() const {
  return const_iterator(data_.cbegin());
}

template <class Item>
const_iterator cend() const {
  return const_iterator(data_.cend());
}
