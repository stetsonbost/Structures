// -*- C++ -*-
/**
 * \file LinkedList.h
 * \author Stetson Bost
 * \brief doubly-linked list
 *
 */

#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include <cstddef>
#include <iostream>

template <class Item>
class LinkedList {
 private:
  template <bool iteratorIsConst>
  class Iterator;

  template <bool iteratorIsConst>
  class ReverseIterator;

 public:
  using iterator = LinkedList::Iterator<false>;
  using const_iterator = Iterator<true>;
  using reverse_iterator = ReverseIterator<false>;
  using reverse_const_iterator = ReverseIterator<true>;

  /*
   * \brief Default constructor
   */
  LinkedList();

  /*
   * \brief Copy constructor
   */
  LinkedList(const LinkedList& list);

  /*
   * \brief Assignment operator
   */
  LinkedList<Item> operator=(const LinkedList& list);

  /*
   * \brief Default destructor
   */
  ~LinkedList();

  /*
   * \brief returns size of the list
   */
  size_t size() const;
  bool isEmpty() const;
  Item& front() const;
  Item& back() const;
  void assign(const LinkedList<Item>& list);
  void push_front(const Item& value);
  Item& pop_front();
  void push_back(const Item& value);
  Item& pop_back();
  iterator insert(iterator position, const Item& value);
  iterator erase(iterator position);
  void remove(const Item& value);
  void merge(LinkedList<Item>& list);
  Item& operator+=(const Item& rhs);
  bool operator==(const Item& rhs) const;
  bool operator!=(const Item& rhs) const;
  void outputAllValues() const;

  /*
   * \brief Finds the first instance of value in the list
   * \return iterator for the first first instance of the value
   */
  iterator find(const Item& value) const;
  
  /// Return an iterator to the first element in the Tree
  iterator begin() const;
  /// Return an iterator to "one past the last"
  iterator end() const;
  /// Return a const iterator to the first element in the Tree
  const_iterator cbegin() const;
  /// Return a const iterator to "one past the last"
  const_iterator cend() const;

  /// Return a reverse iterator to the first element in the Tree
  reverse_iterator rbegin() const;
  /// Return a reverse iterator to "one past the last"
  reverse_iterator rend() const;
  /// Return a const reverse iterator to the first element in the Tree
  const_reverse_iterator crbegin() const;
  /// Return a const reverse iterator to "one past the last"
  const_reverse_iterator crend() const;


 private:
  /// size of the list
  size_t size_;
  /// pointers to the first and last elements of the list
  Node* first_;
  Node* last_;

  struct Node {
   public:
    Item& value_;
    Node* next_;
    Node* prev_;
  };

  /***
   * \class Iterator
   * \brief STL-style iterator for LinkedList.
   */
  template <bool iteratorIsConst>
  class Iterator {
   public:
    // Definitions that are required for this class to be a well-behaved
    // STL-style iterator that moves forward through a collection of ints.
    using value_type = Item;
    using reference =
        typename std::conditional<iteratorIsConst, const value_type&,
                                  value_type&>::type;
    using pointer =
        typename std::conditional<iteratorIsConst, const value_type*,
                                  value_type*>::type;
    using iterator_type =
        typename std::conditional<iteratorIsConst,
                                  LinkedList<Item>::const_iterator,
                                  LinkedList<Item>::iterator>::type;
    using difference_type = ptrdiff_t;
    using iterator_category = std::bidirectional_iterator_tag;
    using const_reference = const value_type&;

    // Provide all the usual operations for a forward iterator
    Iterator();
    Iterator(const Iterator&);
    Iterator& operator=(const Iterator&);
    ~Iterator();

    Iterator& operator++();
    Iterator& operator--();
    Item& operator*() const;
    bool operator==(const Iterator& rhs) const;
    bool operator!=(const Iterator& rhs) const;

   private:
    friend class LinkedList;
    Iterator(Item* const start);  ///< Only friends create these iterators
    Item* current_;               ///< The current value in the vector
  };

  /***
   * \class ReverseIterator
   * \brief STL-style reverse iterator for LinkedList.
   */
  template <bool iteratorIsConst>
  class ReverseIterator {
   public:
    // Definitions that are required for this class to be a well-behaved
    // STL-style iterator that moves forward through a collection of ints.
    using value_type = Item;
    using reference =
        typename std::conditional<iteratorIsConst, const value_type&,
                                  value_type&>::type;
    using pointer =
        typename std::conditional<iteratorIsConst, const value_type*,
                                  value_type*>::type;
    using iterator_type =
        typename std::conditional<iteratorIsConst,
                                  LinkedList<Item>::const_reverse_iterator,
                                  LinkedList<Item>::reverse_iterator>::type;
    using difference_type = ptrdiff_t;
    using iterator_category = std::bidirectional_iterator_tag;
    using const_reference = const value_type&;

    // Provide all the usual operations for a forward iterator
    ReverseIterator();
    ReverseIterator(const ReverseIterator&);
    ReverseIterator& operator=(const ReverseIterator&);
    ~ReverseIterator();

    ReverseIterator& operator++();
    ReverseIterator& operator--();
    Item& operator*() const;
    bool operator==(const ReverseIterator& rhs) const;
    bool operator!=(const ReverseIterator& rhs) const;

   private:
    friend class LinkedList;
    ReverseIterator(Item* const start);  ///< Only friends create these iterators
    Item* current_;                      ///< The current value in the vector
  };
};

#include "LinkedList-private.h"

#endif  // LINKED_LIST_H
