// -*- C++ -*-
/**
 * \file MedianHeap.cc
 * \author Stetson Bost
 * \brief Implements the details of the MedianHeap class
 */

#include "MedianHeap.h"
#include "Heap.h"

#include <cassert>
#include <cstddef>
#include <iostream>
#include <vector>

template <class Item>
MedianHeap<Item>::MedianHeap() {
}

template <class Item>
MedianHeap<Item>::MedianHeap(const MedianHeap& heap) {
}

template <class Item>
MedianHeap<Item> MedianHeap<Item>::operator=(const MedianHeap& heap) {
}

template <class Item>
MedianHeap<Item>::~MedianHeap() {
}

template <class Item>
size_t MedianHeap<Item>::size() const {
}

template <class Item>
bool MedianHeap<Item>::isEmpty() const {
}

template <class Item>
Item& MedianHeap<Item>::median() const {
}

template <class Item>
void MedianHeap<Item>::insert(const Item& value) {
}


template <class Item>
void MedianHeap<Item>::erase(iterator& iter) {
}


template <class Item>
Item& MedianHeap<Item>::removeMedian() {
}

template <class Item>
typename MedianHeap<Item>::iterator
    MedianHeap<Item>::find(const Item& value) const {
  if (median_ != nullptr && *median_ == value) {
  	return iterator(median_, nullptr, nullptr);
  }
	if (value < median()) {
  	left_.find(median_);
  }
  if (value > median()) {
  	right.find(value);
  }
}

template <class Item>
void MedianHeap<Item>::outputAllValues() const {
}

template <class Item>
void MedianHeap<Item>::swap(iterator& value1, iterator& value2) {
}

template <class Item>
typename MedianHeap<Item>::iterator
    MedianHeap<Item>::parent(iterator& child)  const {
}

template <class Item>
typename MedianHeap<Item>::iterator
    MedianHeap<Item>::lchild(iterator& parent) const {
}

template <class Item>
typename MedianHeap<Item>::iterator 
    MedianHeap<Item>::rchild(iterator& parent) const {
}


template <class Item>
typename MedianHeap<Item>::iterator MedianHeap<Item>::begin() const {
}

template <class Item>
typename MedianHeap<Item>::iterator MedianHeap<Item>::end() const {
}

template <class Item>
typename MedianHeap<Item>::const_iterator MedianHeap<Item>::cbegin()
    const {
}

template <class Item>
typename MedianHeap<Item>::const_iterator MedianHeap<Item>::cend()
    const {
}
