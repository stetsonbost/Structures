// -*- C++ -*-
/**
 * \file  BasicBST-private.h
 * \author Stetson Bost
 * \brief Implements the details of the BasicBST class
 */

#include <math.h>
#include <cassert>
#include <cstddef>
#include <string>

template <class Item>
BasicBST<Item>::BasicBST() : size_(0), root_(nullptr) {}

template <class Item>
BasicBST<Item>::BasicBST(const BasicBST& tree) {
  //TODO
}

template <class Item>
BasicBST<Item> BasicBST<Item>::operator=(const BasicBST& tree) {
  //TODO
}

template <class Item>
BasicBST<Item>::~BasicBST() {
  destroyNode(root_);
}

template <class Item>
void BasicBST<Item>::destroyNode(Node& node) {
  if node != nullptr {
    destroyNode(node.left);
    destroyNode(node.right);
  }
  delete node;
  node = nullptr;
}

template <class Item>
size_t BasicBST<Item>::size() const {
  return size_;
}

template <class Item>
void BasicBST<Item>::insert(const Item& value) {
  insertNode(value,node);
}

template <class Item>
void BasicBST<Item>::insertNode(const Item& value, Node& node) {
  if node == nullptr {
    node = new Node{value,nullptr,nullptr};
    ++size_;
  }
  if value < node.value_ {
    insertNode(value, node.left);
  }
  if value > node.value_ {
    insertNode(value, node.right);
  }
  // do nothing if value == node.value_ to avoid duplicates
}

template <class Item>
Node* BasicBST<Item>::find(const Item& value) const {
  findNode(value, root_);
}

template <class Item>
Node* BasicBST<Item>::findNode(const Item& value, const Node& node)
    const {
  if node == nullptr {
    return nullptr; // means value is not in subtree
  }
  if value == node.value {
    return &node; // means value is in subtree
  }
  if node < node.value_ {
    return findNode(value, node.left);
  }
  if value > node.value_ {
    return findNode(value, node.right);
  }
}

template <class Item>
double BasicBST<Item>::calculateAverageNodeDepth() const {
  //TODO
}

template <class Item>
int BasicBST<Item>::calculateHeight() const {
  //TODO
}
