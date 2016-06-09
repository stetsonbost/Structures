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
  // add value to bottom of heap
  data_->push_back(value);
  // get an iterator for the value
  iterator valueIter = iterator(size() - 1, data_);

  // if value is not at root, make an iterator pointing to value's parent
  if (valueIter != begin()) {
    iterator parentIter = parent(valueIter);

    // Now move the value to the correct position in the Heap
    if (isMaxHeap) {
      // For Max Heap:
      maxInsert(valueIter, parentIter);
    } else {
      // For Min Heap:
      minInsert(valueIter, parentIter);
    }
  }
}

template <class Item, bool isMaxHeap>
void Heap<Item, isMaxHeap>::maxInsert(iterator& value, iterator& parent) {
  // if value is greater than parent, swap value and parent
  while (*value > *parent) {
    swap(value, parent);
    value = parent;
    // if value is not at root, make update parent iterator
    if (value.index_ != begin()) {
      parent = parent(value);
    } else {
      // otherwise, the value is in the appropriate place
      break;
    }
  }
}

template <class Item, bool isMaxHeap>
void Heap<Item, isMaxHeap>::minInsert(iterator& value, iterator& parent) {
  // if value is less than parent, swap value and parent
  while (*value < *parent) {
    swap(value, parent);
    value = parent;
    // if value is not at root, make update parent iterator
    if (value.index_ != begin()) {
      parent = parent(value);
    } else {
      // otherwise, the value is in the appropriate place
      break;
    }
  }
}

template <class Item, bool isMaxHeap>
void Heap<Item, isMaxHeap>::erase(iterator& iter) {
  if (size() > 0) {
    iterator lastIter = --end();
    // swap value pointed to by iter with last element
    swap(iter, lastIter);
  }

  // remove value (which must be at end)
  data_->pop_back();

  // Move values in heap to correct positions
  // iter still points to same position but probably differnt value
  if (size() > 1 && iter.index_ != size() - 1) {

    // iterators for both children
    iterator lchildIter = lchild(iter);
    iterator rchildIter = rchild(iter);

    if (isMaxHeap) {
      // For Max Heap:
      maxErase(iter, lchildIter, rchildIter);
    } else {
      // For Min Heap:
      minErase(iter, lchildIter, rchildIter);
    }
  }

}

template <class Item, bool isMaxHeap>
void Heap<Item, isMaxHeap>::maxErase(iterator& iter,
    iterator& lchild, iterator& rchild) {
  // loop until return
  while (true) {
    // there are no children (rchild.data_ will also be nullptr)
    if (lchild.data_ == nullptr) {
      // Heap is valid
      return;
    }

    // only has lchild
    if (rchild.data_ == nullptr) {
      // swap lchild and iter 
      if (*lchild > *iter) {
        swap(lchild, iter);
      }
      // Heap is valid
      return;
    }
    
    // lchild and rchild both exist and 
    if (*rchild > *iter || *lchild > *iter) {
      // rchild should be on top
      if (*rchild > *lchild) {
        swap(rchild, iter);
        iter = rchild;
      } else {
        swap(lchild, iter);
        iter = lchild;
      }

      // get iterators for new children
      lchild = lchild(iter);
      rchild = rchild(iter);

      // now loop again

    } else {
      // Heap is valid
      return;
    }
  }
}

template <class Item, bool isMaxHeap>
void Heap<Item, isMaxHeap>::minErase(iterator& iter,
    iterator& lchild, iterator& rchild) {
  // loop until return
  while (true) {
    // there are no children (rchild.data_ will also be nullptr)
    if (lchild.data_ == nullptr) {
      // Heap is valid
      return;
    }

    // only has lchild
    if (rchild.data_ == nullptr) {
      // swap lchild and iter 
      if (*lchild < *iter) {
        swap(lchild, iter);
      }
      // Heap is valid
      return;
    }
    
    // lchild and rchild both exist and 
    if (*rchild < *iter || *lchild < *iter) {
      // rchild should be on top
      if (*rchild < *lchild) {
        swap(rchild, iter);
        iter = rchild;
      } else {
        swap(lchild, iter);
        iter = lchild;
      }

      // get iterators for new children
      lchild = lchild(iter);
      rchild = rchild(iter);

      // now loop again

    } else {
      // Heap is valid
      return;
    }
  }
}

template <class Item, bool isMaxHeap>
Item& Heap<Item, isMaxHeap>::removeTop() {
  // save value of top (to be returned)
  Item topValue = data_[0];
  // erase the top (includes readjusting heap structure)
  iterator top = iterator(0, data_);
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
typename Heap<Item, isMaxHeap>::iterator
    Heap<Item, isMaxHeap>::parent(iterator& child)  const {
  // if child is not top
  if (child.index_ != 0) {
    size_t parent = ((child.index_ + 1) / 2) - 1;
    return iterator(parent, data_);
  }
  // if child is top
  return iterator(0, data_);
}

template <class Item, bool isMaxHeap>
typename Heap<Item, isMaxHeap>::iterator
    Heap<Item, isMaxHeap>::lchild(iterator& parent) const {
  size_t lchild = (parent.index_ * 2) + 1;
  // if lchild is valid
  if (lchild < size()) {
    return iterator(lchild, data_);
  }
  // if lchild is not valid
  return iterator(0, nullptr);
}

template <class Item, bool isMaxHeap>
typename Heap<Item, isMaxHeap>::iterator 
    Heap<Item, isMaxHeap>::rchild(iterator& parent) const {
  size_t rchild = (parent.index_ * 2) + 2;
  // if rchild is valid
  if (rchild < size()) {
    return iterator(rchild, data_);
  }
  // if rchild is not valid
  return iterator(0, nullptr);
}


template <class Item, bool isMaxHeap>
typename Heap<Item, isMaxHeap>::iterator Heap<Item, isMaxHeap>::begin() const {
  return iterator(0, data_);
}

template <class Item, bool isMaxHeap>
typename Heap<Item, isMaxHeap>::iterator Heap<Item, isMaxHeap>::end() const {
  return iterator(size(), data_);
}

template <class Item, bool isMaxHeap>
typename Heap<Item, isMaxHeap>::const_iterator Heap<Item, isMaxHeap>::cbegin()
    const {
  return const_iterator(0, data_);
}

template <class Item, bool isMaxHeap>
typename Heap<Item, isMaxHeap>::const_iterator Heap<Item, isMaxHeap>::cend()
    const {
  return const_iterator(size(), data_);
}
