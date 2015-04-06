/*
 *
 * Name: Jeffrey Leung
 * Date: 2015-04-06
 *
 * This program contains implementations of a binary tree, composed of nodes.
 *
 */

#ifndef BINARY_NODE_HPP
#define BINARY_NODE_HPP

#include <iostream>
#include <assert.h>
#include <stdlib.h>

enum direction
{
  LEFT,
  RIGHT
};

template <typename T>
class BinaryNode
{
  private:
    T value;
    BinaryNode* left;
    BinaryNode* right;

    void PrintTreeElements();  // Only for use by PrintTree()
    void ElementsToArray( T* array, int* elements_copied );  // Only for use by ToArray().

  public:

    // CONSTRUCTOR:
    BinaryNode( T new_value );

    // ESSENTIAL METHODS:
    void SetValue( T num );
    T GetValue();
    void AssignNode( BinaryNode* new_node, direction d );  // Assigns a new child node.
    void RemoveNode( direction d );  // Removes a child node.

    // UTILITY METHODS:
    void PrintTree();  // Prints nodes from left to right
    int CountNodes();
    int NodeExists( direction d );  // Returns nonzero if the node's direction d is non-null.

    // SORTED BINARY TREE (numerical) METHODS:
    // Called by the root of the binary tree unless otherwise specified.
    void ToArray( T* array );  // Returns the elements of the binary tree in the given array.
    void Sort(); //TODO
    BinaryNode* Search( T target );  // Returns the pointer of the target, or NULL if not found.
    void InsertSorted( BinaryNode* node );
    void RemoveSorted( T num );  // Nothing happens if the value is not found or the root is the
                                 // node to be removed.
};



// Constructor
template <class T>
BinaryNode<T>::BinaryNode( T new_value )
{
  value = new_value;
  left = NULL;
  right = NULL;
}



// ESSENTIAL METHODS:

// This method assigns a new value to the binary node.
template <class T>
void BinaryNode<T>::SetValue( T new_value )
{
  value = new_value;
  return;
}

// This method returns the value of the binary node.
template <class T>
T BinaryNode<T>::GetValue()
{
  return value;
}

// This method assigns a new node to an empty node pointer.
template <class T>
void BinaryNode<T>::AssignNode( BinaryNode* new_node, direction d )
{
  if( d == LEFT )
  {
    if( left != NULL )
    {
      std::cout << "There is already a node to the left of " << value << "; ";
      std::cout << "you cannot assign another node there.\n";
      exit( 1 );
    }
    else
    {
      left = new_node;
    }
  }

  else if( d == RIGHT )
  {
    if( right != NULL )
    {
      std::cout << "There is already a node to the right of " << value << "; ";
      std::cout << "you cannot assign another node there.\n";
      exit( 1 );
    }
    else
    {
      right = new_node;
    }
  }

  return;
}

// This method removes all nodes below the given node in the given direction, but does not
// remove the current node.
template <class T>
void BinaryNode<T>::RemoveNode( direction d )
{
  if( d == LEFT )
  {
    left = NULL;
  }
  else if( d == RIGHT )
  {
    right = NULL;
  }

  return;
}



// UTILITY METHODS:

// Only for use by PrintTree().
// This method recursively prints the elements of a binary tree tree in order from left to right.
template <class T>
void BinaryNode<T>::PrintTreeElements()
{
  if( left != NULL )
  {
    (*left).PrintTreeElements();
  }

  std::cout << value << " ";

  if( right != NULL )
  {
    (*right).PrintTreeElements();
  }

  return;
}

// This wrapper method recursively prints the elements of a binary tree in order from left to
// right, formatted.
template <class T>
void BinaryNode<T>::PrintTree()
{
  std::cout << "[ ";
  PrintTreeElements();
  std::cout << "]";

  return;
}

// This method returns the number of elements under and including the given node.
template <class T>
int BinaryNode<T>::CountNodes()
{
  int sum = 1;

  if( left != NULL )
  {
    sum += (*left).CountNodes();
  }
  if( right != NULL )
  {
    sum += (*right).CountNodes();
  }

  return sum;
}

// This method returns nonzero if the node in the given direction exists, and 0 otherwise.
template <class T>
int BinaryNode<T>::NodeExists( direction d )
{
  int node_found = 0;

  if( d == LEFT )
  {
    if( left != NULL )
    {
      node_found = 1;
    }
  }

  else if( d == RIGHT )
  {
    if( right != NULL )
    {
      node_found = 2;
    }
  }

  return node_found;
}



// SORTED BINARY TREE (numerical) METHODS:

// Only for use by ToArray().
// This function recursively places the elements in a binary tree into an array.
// 'elements_copied' must be initialized to 0.
template <class T>
void BinaryNode<T>::ElementsToArray( T array[], int* elements_copied )
{
  if( left != NULL )
  {
    left->ElementsToArray( array, elements_copied );
  }

  #pragma GCC diagnostic push  // Ignores GCC warning that elements_copied is unused
  #pragma GCC diagnostic ignored "-Wunused-value"

  array[*elements_copied] = value;
  (*elements_copied)++;

  #pragma GCC diagnostic pop

  if( right != NULL )
  {
    right->ElementsToArray( array, elements_copied );
  }

  return;
}

// This wrapper function places the elements of a binary tree (from left to right) into an array.
template <class T>
void BinaryNode<T>::ToArray( T* array )
{
  if( array == NULL )
  {
    std::cout << "Error: ToArray() received an invalid pointer for an array.\n";
    exit( 1 );
  }

  int elements_copied = 0;
  ElementsToArray( array, &elements_copied );

  return;
}

//TODO
// This function sorts the elements of a binary tree from least to greatest, and optimizes
// the positioning of the elements in the tree.
template <class T>
void BinaryNode<T>::Sort()
{
  int num = CountNodes();
  T array[num];

  ToArray( array );

  // Add mergesort with template

  return;
}

// This method returns the address of the binary node containing the target, or NULL if the target
// is not found.
// Called by the root.
template <class T>
BinaryNode<T>* BinaryNode<T>::Search( T target )
{
  BinaryNode* found = NULL;

  if( value == target )
  {
    found = this;
  }
  else if( value < target && left != NULL )
  {
    found = (*left).Search( target );
  }
  else if( value > target && right != NULL )
  {
    found = (*right).Search( target );
  }

  return found;
}

// This method adds a node in a sorted position in the binary tree.
// Called by the root.
template <class T>
void BinaryNode<T>::InsertSorted( BinaryNode<T>* node )
{
  if( node == NULL )
  {
    std::cout << "Error: InsertSorted() was given an invalid pointer for a node.\n";
    exit( 1 );
  }

  BinaryNode* node_search = this;
  while( node_search->left != node && node_search->right != node )
  {
    // Less than or equal to the current node
    if( node->value <= node_search->value )
    {
      if( node_search->left == NULL )
      {
        node_search->left = node;
      }
      else
      {
        node_search = node_search->left;
      }
    }

    // Greater than the current node
    else
    {
      if( node_search->right == NULL )
      {
        node_search->right = node;
      }
      else
      {
        node_search = node_search->right;
      }
    }
  }

  return;
}

// This method removes the first appearance of a node with the given value in a sorted binary tree.
// Nothing happens if the value is not found or the node to be removed is the root.
template <class T>
void BinaryNode<T>::RemoveSorted( T num )
{
  BinaryNode* node_search = this;

  while( num != node_search->value )
  {

    if( node_search->left != NULL && num == node_search->left->value )
    {
      node_search->left = NULL;
      return;
    }
    else if( node_search->right != NULL && num == node_search->right->value )
    {
      node_search->right = NULL;
      return;
    }

    if( num < node_search->value )
    {
      if( node_search->left == NULL )
      {
        return;
      }
      node_search = node_search->left;
    }

    else if( num > node_search->value )
    {
      if( node_search->right == NULL )
      {
        return;
      }
      node_search = node_search->right;
    }
  }

  return;
}

#endif
