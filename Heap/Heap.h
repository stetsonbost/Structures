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
#include <vector>

template <class Item, bool isMaxHeap>
// template <bool isMaxHeap>
class Heap {
 private:
  // forward declaration of private iterator classes
  template <bool iteratorIsConst>
  class Iterator;

 public:
  using iterator = Heap<Item, isMaxHeap>::Iterator<false>;
  using const_iterator = Heap<Item, isMaxHeap>::Iterator<true>;

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
  Heap<Item, isMaxHeap> operator=(const Heap& heap);

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
  Item& peekTop() const;

  /**
   * \brief Inserts node with value at position before the
   *     node specified by iterator
   */
  void insert(const Item& value);

  /**
   * \brief Erases item specified by iterator
   * \note Does nothing if item is not in heap
   */
  void erase(iterator& iter);

  /**
   * \brief Erases and returns value at the top of the heap
   *     Then rearranges values to be a heap.
   * \note Does nothing if item is not in heap
   */
  Item& removeTop();

  /**
   * \brief Finds the first instance of value in the heap
   * \return Pointer for the first first instance of the value
   * \note If value is not in heap, returns nullptr
   */
  iterator find(const Item& value) const;

  /**
   * \brief Prints all values in heap to terminal
   */
  void outputAllValues() const;

  /// Return an iterator to the first element in the Tree
  iterator begin() const;
  /// Return an iterator to "one past the last"
  iterator end() const;
  /// Return a const iterator to the first element in the Tree
  const_iterator cbegin() const;
  /// Return a const iterator to "one past the last"
  const_iterator cend() const;
  
 private:
  void swap(iterator& value1, iterator& value2);
  iterator parent(iterator& child) const;
  iterator lchild(iterator& parent) const;
  iterator rchild(iterator& parent) const;

  void maxInsert(iterator& iter, iterator& parent);
  void minInsert(iterator& iter, iterator& parent);
  void maxErase(iterator& iter, iterator& lchild, iterator& rchild);
  void minErase(iterator& iter, iterator& lchild, iterator& rchild);

  /// pointers to vector representing heap
  std::vector<Item>* data_;

  /**
   * \class Iterator
   * \brief STL-style iterator for LinkedList.
   */
  template <bool iteratorIsConst>
  class Iterator {
   public:
    // Definitions that are required for this class to be a well-behaved
    // STL-style iterator that moves forward through a collection
    using value_type = Item;
    using reference =
        typename std::conditional<iteratorIsConst, const value_type&,
                                  value_type&>::type;
    using pointer =
        typename std::conditional<iteratorIsConst, const value_type*,
                                  value_type*>::type;
    using iterator_type =
        typename std::conditional<iteratorIsConst,
                                  Heap<Item, isMaxHeap>::const_iterator,
                                  Heap<Item, isMaxHeap>::iterator>::type;
    using difference_type = ptrdiff_t;
    using iterator_category = std::bidirectional_iterator_tag;
    using const_reference = const value_type&;

    // Provide all the usual operations for a forward iterator
    Iterator() = default;
    Iterator(const Iterator&) = default;
    Iterator& operator=(const Iterator&) = default;
    ~Iterator() = default;

    // void swap(Iterator& value1, Iterator& value2);

    Iterator& operator++();
    Iterator& operator--();
    Item*& operator*();
    bool operator==(const Iterator& rhs) const;
    bool operator!=(const Iterator& rhs) const;

   private:
    friend class Heap;                  ///< Only friends create these iterators
    // Iterator(typename std::vector<Item>::iterator iter);    ///< Parameterized Constructor
    // typename std::vector<Item>::iterator current_;          ///< The current index in the Heap
    Iterator(size_t index, std::vector<Item>* data);    ///< Parameterized Constructor
    size_t index_;          ///< The current index in the Heap
    std::vector<Item>* data_;
  };
};

#include "Heap-private.h"

#endif  // HEAP_H
