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
#include <string>

template <class Item>
class BasicBST {
 public:
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
  BasicBST<Item> operator=(const BasicBST& tree) = delete;

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
  void insert(const Item& key);

  /*
   * \brief Inserts node into the tree
   */
  Node* find(const Item& key) const;

  /*
   * \brief Calculates average node depth of tree
   */
  double calculateAverageNodeDepth() const;

  /*
   * \brief Calculates height of tree
   */
  int calculateHeight() const;

 private:
  struct Node {
    Item value_;
    Node* left_;
    Node* right_;
  };

  /*
   * \brief Destructor helper function
   */
  void destroyNode(Node& node);

  /*
   * \brief insert helper function
   */
  void insertNode(const Item& value, Node& node);

  const Node* findNode(const Item& value, const Node& node);

  /// size of the tree
  size_t size_;
  /// pointer to the root of the tree
  Node* root_;
};

#include "BasicBST-private.h"

#endif  // BASIC_BST_H