// -*- C++ -*-
/**
 * \file  MedianHeap-private.h
 * \author Stetson Bost
 * \brief Implements the details of the MedianHeap Iterator classes
 */

#include <cassert>
#include <cstddef>
#include <iostream> 
#include <vector>


// -------------------------------
//   MedianHeap Iterator Class 
// -------------------------------

template <class Item>
template <bool iteratorIsConst>
MedianHeap<Item>::Iterator<iteratorIsConst>::Iterator() {
}


template <class Item>
template <bool iteratorIsConst>
MedianHeap<Item>::Iterator<iteratorIsConst>& 
    MedianHeap<Item>::Iterator<iteratorIsConst>::operator++() {
}

template <class Item>
template <bool iteratorIsConst>
MedianHeap<Item>::Iterator<iteratorIsConst>& 
    MedianHeap<Item>::Iterator<iteratorIsConst>::operator--() {
}

template <class Item>
template <bool iteratorIsConst>
Item*& MedianHeap<Item>::Iterator<iteratorIsConst>::operator*() {
}

template <class Item>
template <bool iteratorIsConst>
bool MedianHeap<Item>::Iterator<iteratorIsConst>::operator==(
    const Iterator& rhs) const {
}

template <class Item>
template <bool iteratorIsConst>
bool MedianHeap<Item>::Iterator<iteratorIsConst>::operator!=(
    const Iterator& rhs) const {
}
