// -*- C++ -*-
/**
 * \file Heap.h
 * \author Stetson Bost
 * \brief Max Heap
 *
 */

#ifndef HEAP_H
#define HEAP_H
#include <cstddef>
#include <iostream>

template <class Item>
class Heap {
 public:
  /**
   * \brief Default constructor
   */
  Heap();

  /**
   * \brief Copy constructor
   */
  Heap(const Heap& heap);

  /**
   * \brief Assignment operator
   */
  Heap<Item> operator=(const Heap& heap);

  /**
   * \brief Default destructor
   */
  ~Heap();

  /**
   * \return Size of the heap
   */
  size_t size() const;

  /**
   * \return True if heap is empty, false otherwise
   */
  bool isEmpty() const;

  /**
   * /return Top item on the heap
   * \note Should only be called if top_ is not nullptr
   */
  Item& top() const;

  /**
   * \brief Inserts node with value at position before the
   *     node specified by iterator
   */
  void insert(const Item& value);

  /**
   * \brief Erases specified item
   * \note Does nothing if item is not in heap
   */
  void erase(const Item& value);

  /**
   * \returns True if two heaps hold same values, False otherwise
   */
  bool operator==(const Heap<Item>& rhs) const;

  /**
   * \return True if and only if operator== returns False
   */
  bool operator!=(const Item& rhs) const;

  /**
   * \brief Finds the first instance of value in the heap
   * \return Pointer for the first first instance of the value
   * \note If value is not in heap, returns nullptr
   */
  Item* find(const Item& value) const;

  /**
   * \brief Prints all values in heap to terminal
   */
  void outputAllValues() const;
  
 private:
  /// size of the heap
  size_t size_;
  /// pointers to the top of the heap
  Item* top_;
};

#endif  // HEAP_H
