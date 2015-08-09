/*
 *
 * Author: Jeffrey Leung
 * Last edited: 2015-08-08
 *
 * This C++ program contains the implementation of a node class.
 *
 */
 
#pragma once

#include <iostream>

template <class T>
class BinaryNode
{
  public:
    T value_;
    BinaryNode* left_;
    BinaryNode* right_;
    BinaryNode* parent_;
    bool is_black_;

    // Constructors
    BinaryNode( T new_value );
    BinaryNode( BinaryNode& n );
};

// Parametrized constructor
template <class T>
BinaryNode<T>::BinaryNode( T new_value )
{
  value_  = new_value;
  left_   = nullptr;
  right_  = nullptr;
  parent_ = nullptr;
}

// Copy constructor
template <class T>
BinaryNode<T>::BinaryNode( BinaryNode& N )
{
  value_  = N.value_;
  left_   = nullptr;
  right_  = nullptr;
  parent_ = nullptr;
}
