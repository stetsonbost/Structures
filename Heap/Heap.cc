// -*- C++ -*-
/**
 * \file LinkedList.cc
 * \author Stetson Bost
 * \brief Implements the details of the LinkedList class
 */

#include "Heap.h"

#include <cassert>
#include <cstddef>
#include <iostream> 

template <class Item>
Heap<Item>::Heap() : size_(0), top_(nullptr) {
}

template <class Item>
Heap<Item>::Heap(const Heap& heap) {
  //TODO
}

template <class Item>
Heap<Item> Heap<Item>::operator=(const Heap& heap) {
  //TODO
}

template <class Item>
Heap<Item>::~Heap() {
  delete top_;
  top_ = nullptr;
}

template <class Item>
size_t Heap<Item>::size() const {
  return size_;
}

template <class Item>
bool Heap<Item>::isEmpty() const {
  return size_ == 0;
}

template <class Item>
Item& Heap<Item>::top() const {
  // assume top_ != nullptr
  return *top_;
}

template <class Item>
void Heap<Item>::insert(const Item& value) {
  
}

template <class Item>
void Heap<Item>::erase(const Item& value) {

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
  
}