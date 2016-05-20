// -*- C++ -*-
/**
 * \file SinglyLinked.h
 * \author Stetson Bost
 * \brief Singly-linked list
 *
 */

#ifndef SINGLY_LINKED_H
#define SINGLY_LINKED_H
#include <cstddef>
#include <iostream>
// #include <string>

template <class Item>
class SinglyLinked {
 private:
  //template <class iteratorIsConst>
  class Iterator; //<iteratorIsConst>;

 public:
  using iterator = SinglyLinked::Iterator; // <false>;
  // using const_iterator = Iterator<true>;

  /*
   * \brief Default constructor
   */
  SinglyLinked();

  /*
   * \brief Copy constructor
   */
  SinglyLinked(const SinglyLinked& list);

  /*
   * \brief Assignment operator
   */
  SinglyLinked<Item> operator=(const SinglyLinked& list);

  /*
   * \brief Default destructor
   */
  ~SinglyLinked();

  /*
   * \brief returns size of the list
   */
  size_t size() const;
  bool isEmpty() const;
  Item& front() const;
  void assign(SinglyLinked<Item> list);
  iterator push_front(const Item& value);
  Item& pop_front();
  iterator insert_after(iterator position, const Item& value);
  iterator erase_after(iterator position);
  

  /*
   * \brief Finds a value in the tree
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

  void outputAllValues() const;

 private:
  /// size of the list
  size_t size_;
  /// pointer to the root of the tree
  Node* first_;

  struct Node {
   public:
    Item& value_;
    Node* next_;
  };
};

#include "SinglyLinked-private.h"

#endif  // SINGLY_LINKED_H
