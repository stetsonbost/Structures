// -*- C++ -*-
/**
 * \file MedianHeap.h
 * \author Stetson Bost
 * \brief Max MedianHeap
 *
 */

#ifndef MEDIAN_HEAP_H
#define MEDIAN_HEAP_H

#include "Heap.h"

#include <cstddef>
#include <iostream>
#include <vector>

template <class Item>
class MedianHeap {
 private:
  // forward declaration of private iterator classes
  template <bool iteratorIsConst>
  class Iterator;

 public:
  using iterator = MedianHeap<Item>::Iterator<false>;
  using const_iterator = MedianHeap<Item>::Iterator<true>;

  /**
   * \brief Default constructor
   */
  MedianHeap();

  /**
   * \brief Copy constructor
   */
  MedianHeap(const MedianHeap& heap);

  /**
   * \brief Assignment operator
   */
  MedianHeap<Item> operator=(const MedianHeap& heap);

  /**
   * \brief Default destructor
   */
  ~MedianHeap();

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
  Item& median() const;

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
  Item& removeMedian();

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
  /// pointer to median (will be nullptr if heap has even size)
  Item* median_;
  /// Max heap of values less than median
  Heap<Item, true> left_;
  /// Min heap of values greater than median
  Heap<Item, false> right_;

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
                                  MedianHeap<Item>::const_iterator,
                                  MedianHeap<Item>::iterator>::type;
    using difference_type = ptrdiff_t;
    using iterator_category = std::bidirectional_iterator_tag;
    using const_reference = const value_type&;

    using max_reverse_iterator =  Heap<Item, true>::ReverseIterator<false>;
    using min_iterator =  Heap<Item, false>::Iterator<false>;

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
    friend class MedianHeap;          ///< Only friends create these iterators
    Iterator(Item* median, max_reverse_iterator* left,
        min_iterator* right);         ///< Parameterized Constructor
    Item* median_;
    max_reverse_iterator* left_;  ///< The current index in the MedianHeap
    min_iterator* right_;         ///< The vector holding the data
  };
};

#include "MedianHeap-private.h"

#endif  // MEDIAN_HEAP_H