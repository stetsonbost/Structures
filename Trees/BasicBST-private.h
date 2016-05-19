// -*- C++ -*-
/**
 * \file  BasicBST-private.h
 * \author Stetson Bost
 * \brief Implements the details of the BasicBST class
 */

#include <cassert>
#include <cstddef>
// #include <string>

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
  if (node != nullptr) {
    destroyNode(node->left_);
    destroyNode(node->right_);
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
  insertNode(value, root_);
}

template <class Item>
void BasicBST<Item>::insertNode(const Item& value, Node& node) {
  if (node == nullptr) {
    node = new Node{value,nullptr,nullptr};
    ++size_;
  }
  if (value < node->value_) {
    insertNode(value, node->left_);
  }
  if (value > node->value_) {
    insertNode(value, node->right_);
  }
  // do nothing if value == node->value_ to avoid duplicates
}

template <class Item>
void BasicBST<Item>::erase(const Item& value) {
	if (root_ != nullptr) {
    eraseNode(value, root_);
  }
}

template <class Item>
void BasicBST<Item>::eraseNode(const Item& value, Node*& node) {
  if (value == node->value_) {
    // TODO: the complicated deleting... many cases...
    if (value == node->value_) {
      if (node->left_ == nullptr && node->right_ == nullptr) {
        //TODO: Check this??????????????
        // set node's parent's left/right child to nullptr
        if (node != root_) {
          eraseChildNode(root_, node);
        }
        delete node;
        node = nullptr;
      } else {
        if (node->left_ != nullptr) {
          // TODO: replace node with node that is largest value in the left subtree
        } else {
          // TODO: replace node with node that is smallest value in the right subtree
        }
      }
    }
  } else {
    if (value < node->value_ && node->left_ != nullptr) {
      eraseNode(value, node->left_);
    } 
    if (value > node->value_ && node->right_ != nullptr) {
      eraseNode(value, node->right_);
    }
  }
}

template <class Item>
void BasicBST<Item>::eraseChildNode(Node*& parent, const Node*& child) const {
  if (parent->left_ == child) {
    parent->left_ == nullptr;
  }
  if (parent->right_ == child) {
    parent->right_ == nullptr;
  }

}

template <class Item>
typename BasicBST<Item>::iterator BasicBST<Item>::find(const Item& value) const {
  return findNode(value, root_);
}

template <class Item>
typename BasicBST<Item>::iterator BasicBST<Item>::findNode(
    const Item& value, const Node& node) const {
  if (node == nullptr) {
    return iterator(nullptr); // nullptr; // means value is not in subtree
  }
  if (value == node->value_) {
    return iterator(node); // &node; // means value is in subtree
  }
  if (node < node->value_) {
    return findNode(value, node->left_);
  }
  if (value > node->value_) {
    return findNode(value, node->right_);
  }
}

template <class Item>
typename BasicBST<Item>::iterator BasicBST<Item>::begin() const {
	if (root_ != nullptr) {
    return beginNode(root_);
  }
  return iterator(nullptr);
}

template <class Item>
typename BasicBST<Item>::iterator BasicBST<Item>::beginNode(const Node& node)
    const {
  if (node->left_ == nullptr) {
    return iterator(node);
  }
  return beginNode(node->left_);
}

template <class Item>
typename BasicBST<Item>::iterator BasicBST<Item>::end() const {
	return iterator(nullptr);
}

// template <class Item>
// const_iterator BasicBST<Item>::begin() const {
// 	//TODO
// }

// template <class Item>
// const_iterator BasicBST<Item>::end() const {
// 	//TODO
// }


template <class Item>
double BasicBST<Item>::calculateAverageNodeDepth() const {
  //TODO
}

template <class Item>
int BasicBST<Item>::calculateHeight() const {
  //TODO
}

template <class Item>
void BasicBST<Item>::outputAllValues() const {
  if (root_ != nullptr) {
    outputAllValuesNode(root_);
  }
}

template <class Item>
void BasicBST<Item>::outputAllValuesNode(const Node* node) const {
  if (node->left_ != nullptr) {
    outputAllValuesNode(node->left_);
  }
  std::cout << node->value_;
  if (node->right_ != nullptr) {
    outputAllValuesNode(node->right_);
  }
}

// -------------------------------------
// Implementation of BasicBST::Iterator
// -------------------------------------

template <class Item>
BasicBST<Item>::Iterator::Iterator(const Node* node) : node_{node} {
}