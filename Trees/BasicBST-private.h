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
BasicBST<Item>::BasicBST() : size_(0), root_(nullptr) {
}

template <class Item>
BasicBST<Item>::BasicBST(const BasicBST& tree) {
  assert(root_ == nullptr);
  BasicBSTNode(root_, tree.root_);
  assert(size_ == tree.size_);
}

template <class Item>
void BasicBST<Item>::BasicBSTNode(Node*& newTree, const Node*& oldTree) {
  if (oldTree != nullptr) {
  newTree = new Node{oldTree->value};
  ++size_;
  BasicBSTNode(newTree->left_, oldTree->left_);
  BasicBSTNode(newTree->right_, oldTree->right_);
  }
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
  delete node;
  node = nullptr;
  }
}

template <class Item>
BasicBST<Item> BasicBST<Item>::operator=(const BasicBST& tree) {
  // Destroy old tree then create new one
  destroyNode(root_);
  BasicBSTNode(root_, tree.root_);
  assert(size_ == tree.size_);
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
  /*
   * WE CAN ASSUME THAT ROOT IS NOT NULLPTR BY PRECONDITION
   */
  // if (value == node->value_) {
  // TODO: the complicated deleting... many cases...
  if (value == node->value_) {
    // if node is leaf
    if (node->left_ == nullptr && node->right_ == nullptr) {
      // set node's parent's left/right child to nullptr
      if (node != root_) {
        resetParentChild(root_, node, nullptr);
      }
      delete node;
      node = nullptr;
      } else {
        if (node->left_ != nullptr) {
          // Replace node with largest valued node in the left subtree
          //   Note: this will have no right child because it is largest
          Node* maxLeft = rightmostNode(node->left_).node_;
          // Fix all the pointers from parents to children
          if (node != root_) {
            // Set node's parent's child with maxLeft (replace node)
            resetParentChild(root_, node, maxLeft);
          }
          // Set maxLeft's right to node's right
          maxLeft->right_ = node->right_;
          if (maxLeft != node->left_) {
            // Set maxLeft's parent's right to maxLeft's left
            //   Note: doesn't matter if maxLeft's parent is node 
            resetParentChild(node, maxLeft, maxLeft->left_);
            // Set maxLeft's left to node's left
            //   Note: set to nullptr if maxLeft's parent is node
            maxLeft->left_ = node->left_;          
          } else {
            maxLeft->left_ = nullptr;
          }
          // Delete node
          node->left_ = nullptr;
          node->right_ = nullptr;
          delete node;
          node = maxLeft;
        } else {
          // Replace node with least valued node in the right subtree
          //   Note: this will have no left child because it is least
          Node* minRight = leftmostNode(node->right_).node_;
          // Fix all the pointers from parents to children
          if (node != root_) {
            // Set node's parent's child with minRight (replace node)
            resetParentChild(root_, node, minRight);
          }
          // Set minRight's left to node's left
          minRight->left_ = node->left_;
          if (minRight != node->right_) {
            // Set minRight's parent's left to minRight's right
            //   Note: doesn't matter if minRight's parent is node 
            resetParentChild(node, minRight, minRight->right_);
            // Set minRight's right to node's right
            //   Note: set to nullptr if minRight's parent is node
            minRight->right_ = node->right_;          
          } else {
            minRight->right_ = nullptr;
          }
          // Delete node
          node->left_ = nullptr;
          node->right_ = nullptr;
          delete node;
          node = minRight;
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
void BasicBST<Item>::resetParentChild(Node*& parent, const Node*& child, const Node*& newChild) const {
  // if child must be to left of parent
  if (child->value_ < parent->value_) {
  // if child *is* left node of parent
  if (parent->left_ == child) {
    parent->left_ == newChild;
  } // keep looking for child to left
  else {
    eraseChildNode(parent->left_, child);
  }
  }
  // if child must be to right of parent
  if (child->value_ > parent->value_) {
  // if child *is* right node of parent
  if (parent->right_ == child) {
   parent->right_ == newChild;
  } // keep looking for child to right
  else {
    eraseChildNode(parent->left_, child);
  }
  }
}

template <class Item>
typename BasicBST<Item>::iterator BasicBST<Item>::leftmostNode(const Node*& node) const {
  if (node->left_ == nullptr) {
  return new iterator(node);
  }
  return leftmostNode(node->left_);
}

template <class Item>
typename BasicBST<Item>::iterator BasicBST<Item>::rightmostNode(const Node*& node) const {
  if (node->right_ == nullptr) {
  return new iterator(node);
  }
  return rightmostNode(node->right_);
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
//  //TODO
// }

// template <class Item>
// const_iterator BasicBST<Item>::end() const {
//  //TODO
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