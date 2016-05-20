// -*- C++ -*-
/**
 * \file BasicBST.h
 * \author Stetson Bost
 * \brief Serves as a fully-implemented base class for other BSTs
 *
 */


#ifndef BASIC_BST_H
#define BASIC_BST_H
#include <cstddef>
#include <iostream>
// #include <string>

template <class Item>
class BasicBST {
 private:
  //template <class iteratorIsConst>
  class Iterator; //<iteratorIsConst>;

 public:
  using iterator = BasicBST::Iterator; // <false>;
  // using const_iterator = Iterator<true>;

  /*
   * \brief Default constructor
   */
  BasicBST();

  /*
   * \brief Copy constructor
   */
  BasicBST(const BasicBST& tree);

  /*
   * \brief Assignment operator
   */
  BasicBST<Item> operator=(const BasicBST& tree);

  /*
   * \brief Default destructor
   */
  ~BasicBST();

  /*
   * \brief returns size of the tree
   */
  size_t size() const;

  /*
   * \brief Inserts key into the tree
   */
  void insert(const Item& value);
  
  /**
   * \brief Erase element at iter
   * \param iter iterator pointing to the character to erase ????????????????????
   *
   * \warning invalidates all iterators except the returned iterator ??????????????????????
   */
  void erase(const Item& value);

  /*
   * \brief Finds a value in the tree
   * \TODO: MAKE THIS RETURN A NODE* or ITERATOR POINTING TO THE FOUND LOCATION!!!!!!!!!
   */
  iterator find(const Item& value) const;
  
  /// Return an iterator to the first element in the Tree
  iterator begin() const;
  /// Return an iterator to "one past the last"
  iterator end() const;
  // /// Return a const iterator to the first element in the Tree
  // const_iterator begin() const;
  // /// Return a const iterator to "one past the last"
  // const_iterator end() const;

  /*
   * \brief Calculates average node depth of tree
   */
  double calculateAverageNodeDepth() const;

  /*
   * \brief Calculates height of tree
   */
  int calculateHeight() const;

  void outputAllValues() const;

 private:
  class Node {
    Item value_;
    Node* left_;
    Node* right_;

    friend class BasicBST;
    friend class BasicBST<Item>::Iterator;
  };

  void BasicBSTNode(Node*& newTree, const Node*& oldTree);
  void destroyNode(Node& node);
  void insertNode(const Item& value, Node& node);
  void eraseNode(const Item& value, Node*& node);
  void resetParentChild(Node*& parent, const Node*& child,
      const Node*& newChild) const;
  iterator findNode(const Item& value, const Node& node) const;
  iterator beginNode(const Node& node) const;
  void outputAllValuesNode(const Node* node) const;
  iterator leftmostNode(const Node*& node) const;
  iterator rightmostNode(const Node*& node) const;

  /// size of the tree
  size_t size_;
  /// pointer to the root of the tree
  Node* root_;

  // template <bool iteratorIsConst>
  class Iterator {
   public:
    // Definitions that are required for this class to be a well-behaved
    // STL-style iterator that moves forward through a collection of ints.
    using value_type = Item;
    using reference = value_type&;
    using pointer = value_type*;
    using difference_type = ptrdiff_t;
    using iterator_category = std::forward_iterator_tag;

    /*
     * \brief Default constructor - disabled
     */
    Iterator() = default;
    // Iterator(const Iterator&) = default;
    // Iterator& operator=(const Iterator&) = default;
    ~Iterator() = default;

    /**
     * This member function serves two purposes, depending on the type
     * of this iterator.
     *
     * If this iterator is not a const_iterator
     *  (i.e., iteratorIsConst is false), then this member function
     *  is the copy constructor.
     *
     * If this iterator is a const_iterator (i.e., iteratorIsConst is true),
     * then this member function converts a non-const iterator to a
     * const_iterator.
     */
    Iterator(const BasicBST<Item>::iterator& iter) = default;

    // // Make Iterator STL-friendly with these typedefs:
    // using value_type = char;
    // // The reference type depends (at compile-time!) on whether
    // //  the iterator is a const_iterator or not.
    // using reference =
    //     typename std::conditional<iteratorIsConst, const value_type&,
    //                               value_type&>::type;
    // // The pointer type depends (at compile-time!) on whether
    // //  the iterator is a const_iterator or not.
    // using pointer =
    //     typename std::conditional<iteratorIsConst, const value_type*,
    //                               value_type*>::type;
    // using difference_type = ptrdiff_t;
    // using iterator_category = std::bidirectional_iterator_tag;
    // using const_reference = const value_type&;

    // // Operations
    // Iterator& operator++();
    // Iterator& operator--();
    // reference operator*() const;
    // bool operator==(const Iterator& rhs) const;
    // bool operator!=(const Iterator& rhs) const;

   private:
    friend class BasicBST;

    /// Parameterized Constructor
    Iterator(const Node* node);

    /// Private data members
    Node* node_;
    // Node* next_; // ??? maybe ???
    // Node* prev_; // ??? maybe ???
  };
};

#include "BasicBST-private.h"

#endif  // BASIC_BST_H
