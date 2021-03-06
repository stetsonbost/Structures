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

  template <bool iteratorIsConst>
  class ReverseIterator;

 public:
  using iterator = Heap<Item, isMaxHeap>::Iterator<false>;
  using const_iterator = Heap<Item, isMaxHeap>::Iterator<true>;
  using reverse_iterator = Heap<Item, isMaxHeap>::ReverseIterator<false>;
  using const_reverse_iterator = Heap<Item, isMaxHeap>::ReverseIterator<true>;

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

  /// Return an iterator to the first element in the Heap
  iterator begin() const;
  /// Return an iterator to "one past the last"
  iterator end() const;
  /// Return a const iterator to the first element in the Heap
  const_iterator cbegin() const;
  /// Return a const iterator to "one past the last"
  const_iterator cend() const;

  /// Return an reverse iterator to the first element in the Heap
  iterator rbegin() const;
  /// Return an reverse iterator to "one past the last" (max unsigned int)
  iterator rend() const;
  /// Return a const reverse iterator to the first element in the Heap
  const_iterator crbegin() const;
  /// Return a const reverse iterator to "one past the last" (max unsigned int)
  const_iterator crend() const;
  
 private:
  /**
   * \brief Swaps 2 elements in the heap
   * \note Iterators will point to same memory locations as parameters,
   *     but values at the memory will (probably) be different
   */
  void swap(iterator& value1, iterator& value2);

  /**
   * \brief Gives iterator pointing to parent of child
   * \note If child is on top of the stack, parent index = 0
   */
  iterator parent(iterator& child) const;

  /**
   * \brief Gives iterator pointing to left child of parent
   * \note If parent has no left child, lchild data = nullptr
   */
  iterator lchild(iterator& parent) const;

  /**
   * \brief Gives iterator pointing to right child of parent
   * \note If parent has no right child, rchild data = nullptr
   */
  iterator rchild(iterator& parent) const;

  /**
   * \brief Helper function for insert in max heap
   */
  void maxInsert(iterator& iter, iterator& parent);

  /**
   * \brief Helper function for insert in min heap
   */
  void minInsert(iterator& iter, iterator& parent);

  /**
   * \brief Helper function for erase in max heap
   */
  void maxErase(iterator& iter, iterator& lchild, iterator& rchild);

  /**
   * \brief Helper function for erase in min heap
   */
  void minErase(iterator& iter, iterator& lchild, iterator& rchild);

  /// pointers to vector representing heap
  std::vector<Item>* data_;

  /**
   * \class Iterator
   * \brief STL-style iterator for Heap.
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

    // Provide all the usual operations for an iterator
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
    friend class Heap;                ///< Only friends create these iterators
    Iterator(size_t index,
        std::vector<Item>* data);     ///< Parameterized Constructor
    size_t index_;                    ///< The current index in the Heap
    std::vector<Item>* data_;         ///< The vector holding the data
  };

  /**
   * \class ReverseIterator
   * \brief STL-style iterator for LinkedList.
   */
  template <bool iteratorIsConst>
  class ReverseIterator {
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

    // Provide all the usual operations for an iterator
    ReverseIterator() = default;
    ReverseIterator(const ReverseIterator&) = default;
    ReverseIterator& operator=(const ReverseIterator&) = default;
    ~ReverseIterator() = default;

    ReverseIterator& operator++();
    ReverseIterator& operator--();
    Item*& operator*();
    bool operator==(const ReverseIterator& rhs) const;
    bool operator!=(const ReverseIterator& rhs) const;

   private:
    friend class Heap;                ///< Only friends create these iterators
    ReverseIterator(size_t index,
        std::vector<Item>* data);     ///< Parameterized Constructor
    size_t index_;                    ///< The current index in the Heap
    std::vector<Item>* data_;         ///< The vector holding the data
  };
};

#include "Heap-private.h"

#endif  // HEAP_H
