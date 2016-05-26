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
 // private:
  // forward declaration of private iterator classes
  template <bool iteratorIsConst>
  class Iterator;

  template <bool iteratorIsConst>
  class ReverseIterator;

 public:
  using iterator = LinkedList<Item>::Iterator<false>;
  using const_iterator = LinkedList<Item>::Iterator<true>;
  using reverse_iterator = LinkedList<Item>::ReverseIterator<false>;
  using const_reverse_iterator = LinkedList<Item>::ReverseIterator<true>;

  /**
   * \brief Default constructor
   */
  LinkedList();

  /**
   * \brief Copy constructor
   */
  LinkedList(const LinkedList& list);

  /**
   * \brief Assignment operator
   */
  LinkedList<Item> operator=(const LinkedList& list);

  /**
   * \brief Default destructor
   */
  ~LinkedList();

  /**
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

  /**
   * \brief Inserts node with value at position before the
   *     node specified by iterator
   */
  iterator insert(iterator position, const Item& value);
  iterator erase(iterator position);
  void remove(const Item& value);

  /**
   * \brief Appends one list to another
   * \details Calls push_back on each element of list
   * \note Not a member function of std::list
   */
  void append(const LinkedList<Item>& list);

  /**
   * \brief Appends one element to *this
   * \details Calls push_back
   * \note Not a member function of std::list
   */
  Item& operator+=(const Item& rhs);
  bool operator==(const LinkedList<Item>& rhs) const;
  bool operator!=(const Item& rhs) const;

  /**
   * \brief Finds the first instance of value in the list
   * \return iterator for the first first instance of the value
   * \note If value is not in list, returns iterator(nullptr)
   */
  iterator find(const Item& value) const;
  void outputAllValues() const;
  
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
  struct Node {
   public:
    Item& value_;
    Node* next_;
    Node* prev_;
  };

  /// size of the list
  size_t size_;
  /// pointers to the first and last elements of the list
  Node* first_;
  Node* last_;
 
  /**
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
    Iterator(const Iterator&) = default;
    Iterator& operator=(const Iterator&) = default;
    ~Iterator() = default;

    Iterator& operator++();
    Iterator& operator--();
    Node*& operator*() const;
    bool operator==(const Iterator& rhs) const;
    bool operator!=(const Iterator& rhs) const;

   private:
    friend class LinkedList;
    Iterator(Node* const start);  ///< Only friends create these iterators
    Node* current_;               ///< The current value in the vector
  };

  /**
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
    ReverseIterator(const ReverseIterator&) = default;
    ReverseIterator& operator=(const ReverseIterator&) = default;
    ~ReverseIterator() = default;

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
