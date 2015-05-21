/*
 *
 * Author: Jeffrey Leung
 * Last edited: 2015-05-21
 *
 * This program contains the implementation of a binary tree, composed of nodes of any given type.
 *
 */

#pragma once

#include <iostream>
#include <assert.h>
#include <stdlib.h>

enum class direction
{
  kLeft,
  kRight,
};

template <class T>
class BinaryNode
{
  public:

    // CONSTRUCTOR:
    BinaryNode( T new_value );

    // ESSENTIAL METHODS:
    void SetValue( T num );
    T GetValue();
    void AssignNode( BinaryNode* new_node, direction d );  // Assigns a new child node.
    void RemoveNode();

    // UTILITY METHODS:
    void PrintTree();  // Prints nodes from left to right
    void PrintNodes();  // Prints a description of nodes and their hierarchy.
                        // Describes how the binary tree should be drawn visually.
    int CountNodes();  // Includes itself and all child nodes.
    int Height();  // Length of longest branch from the root.
                   // A binary tree consisting of one node has a height of 0.
    int NodeExists( direction d );  // Returns nonzero if the node's direction d is non-null.

    // SORTED BINARY TREE (numerical) METHODS:
    // Called by the root of the binary tree unless otherwise specified.
    void ToArray( T* array );  // Returns the elements of the binary tree in the given array.
    BinaryNode* Search( T target );  // Returns the pointer of the target, or nullptr if not found.
    void InsertSorted( BinaryNode* node );
    void RemoveSorted( T num );  // All nodes below are removed as well.
                                 // Nothing happens if the value is not found or the root is the
                                 // node to be removed.

  private:
    T value;
    BinaryNode* left;
    BinaryNode* right;
    BinaryNode* parent;

    void PrintNodes_Depth( unsigned int depth );  // Only for use by PrintNodes_().
    void PrintNodes_( unsigned int depth );  // Only for use by PrintNodes().
    void PrintTreeElements();  // Only for use by PrintTree().
    void ElementsToArray( T* array, int* elements_copied );  // Only for use by ToArray().
};



// Constructor
template <class T>
BinaryNode<T>::BinaryNode( T new_value )
{
  value = new_value;
  left = nullptr;
  right = nullptr;
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
  if( d == direction::kLeft )
  {
    if( left != nullptr )
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

  else if( d == direction::kRight )
  {
    if( right != nullptr )
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
  new_node->parent = this;

  return;
}

// This method removes the given node.
template <class T>
void BinaryNode<T>::RemoveNode()
{
  if( parent->left == this )
  {
    parent->left = nullptr;
    parent = nullptr;
  }
  else if( parent->right == this )
  {
    parent->right = nullptr;
    parent = nullptr;
  }

  return;
}



// UTILITY METHODS:

// Only for use by PrintTree().
// This method recursively prints the elements of a binary tree in order from left to right.
template <class T>
void BinaryNode<T>::PrintTreeElements()
{
  if( left != nullptr )
  {
    left->PrintTreeElements();
  }

  std::cout << value << " " ;

  if( right != nullptr )
  {
    right->PrintTreeElements();
  }

  return;
}

// This wrapper method recursively prints the elements of a binary tree in order from left to
// right, formatted.
template <class T>
void BinaryNode<T>::PrintTree()
{
  std::cout << "[ " ;
  PrintTreeElements();
  std::cout << "]" ;

  return;
}

// Only for use by PrintNodes_().
// This function prints the indentation of a given node.
template <class T>
void BinaryNode<T>::PrintNodes_Depth( unsigned int depth )
{
  unsigned int i;
  for( i = 0; i < depth; i++ )
  {
    std::cout << "  " ;
  }
  return;
}

// Only for use by PrintNodes().
// This method recursively prints each node and its children in a binary tree.
// 'depth' must be initially called as 0.
template <class T>
void BinaryNode<T>::PrintNodes_( unsigned int depth )
{
  PrintNodes_Depth( depth );
  std::cout << "Node: " << value << "\n" ;

  // Left/right pointers:

  PrintNodes_Depth( depth );
  if( left != nullptr )
  {
    std::cout << "Left of " << value << ":  " << left->value << "\n" ;
  }
  else
  {
    std::cout << "There are no nodes to the left of " << value << ".\n" ;
  }

  PrintNodes_Depth( depth );
  if( right != nullptr )
  {
    std::cout << "Right of " << value << ": " << right->value << "\n" ;
  }
  else
  {
    std::cout << "There are no nodes to the right of " << value << ".\n" ;
  }

  // Children
  if( left != nullptr )
  {
    std::cout << "\n";
    left->PrintNodes_( depth+1 );
  }
  if( right != nullptr )
  {
    std::cout << "\n";
    right->PrintNodes_( depth+1 );
  }

  return;
}

// This wrapper method prints a visualization of each node and its children in a binary tree.
// The method is designed so the user can generate the binary tree on paper from the description.
template <class T>
void BinaryNode<T>::PrintNodes()
{
  PrintNodes_( 0 );
  return;
}

// This method returns the number of elements under and including the given node.
template <class T>
int BinaryNode<T>::CountNodes()
{
  int sum = 1;

  if( left != nullptr )
  {
    sum += left->CountNodes();
  }
  if( right != nullptr )
  {
    sum += right->CountNodes();
  }

  return sum;
}

// This method returns the height (i.e. the longest branch from the root) of the binary tree.
// A binary tree consisting of one node has a height of 0.
// Called by the root.
template <class T>
int BinaryNode<T>::Height()
{
  if( left == nullptr && right == nullptr )
  {
    return 0;
  }

  int left_height;
  int right_height;

  if( left != nullptr )
  {
    left_height = left->Height();
  }
  else
  {
    left_height = 0;
  }

  if( right != nullptr )
  {
    right_height = right->Height();
  }
  else
  {
    right_height = 0;
  }

  if( right > left )
  {
    return right_height + 1;
  }
  else
  {
    return left_height + 1;
  }

}

// This method returns nonzero if the node in the given direction exists, and 0 otherwise.
template <class T>
int BinaryNode<T>::NodeExists( direction d )
{
  int node_found = 0;

  if( d == direction::kLeft )
  {
    if( left != nullptr )
    {
      node_found = -1;
    }
  }

  else if( d == direction::kRight )
  {
    if( right != nullptr )
    {
      node_found = 1;
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
  if( left != nullptr )
  {
    left->ElementsToArray( array, elements_copied );
  }

  #pragma GCC diagnostic push  // Ignores GCC warning that elements_copied is unused
  #pragma GCC diagnostic ignored "-Wunused-value"

  array[*elements_copied] = value;
  (*elements_copied)++;

  #pragma GCC diagnostic pop

  if( right != nullptr )
  {
    right->ElementsToArray( array, elements_copied );
  }

  return;
}

// This wrapper function places the elements of a binary tree (from left to right) into an array.
template <class T>
void BinaryNode<T>::ToArray( T* array )
{
  if( array == nullptr )
  {
    std::cout << "Error: ToArray() received an invalid pointer for an array.\n" ;
    exit( 1 );
  }

  int elements_copied = 0;
  ElementsToArray( array, &elements_copied );

  return;
}

// This method returns the address of the binary node containing the target, or nullptr if the
// target is not found.
// Called by the root.
template <class T>
BinaryNode<T>* BinaryNode<T>::Search( const T kTarget )
{
  BinaryNode* found = nullptr;

  if( value == kTarget )
  {
    found = this;
  }
  else if( kTarget < value && left != nullptr )
  {
    found = left->Search( kTarget );
  }
  else if( kTarget > value && right != nullptr )
  {
    found = right->Search( kTarget );
  }

  return found;
}

// This method adds a node in a sorted position in the binary tree.
// Called by the root.
template <class T>
void BinaryNode<T>::InsertSorted( BinaryNode<T>* node )
{
  if( node == nullptr )
  {
    std::cout << "Error: InsertSorted() was given an invalid pointer for a node.\n";
    exit( 1 );
  }

  BinaryNode* node_search = this;  // Future parent pointer of the new node

  // While the node has not yet been assigned
  while( node_search->left != node && node_search->right != node )
  {
    // Less than or equal to the current node
    if( node->value <= node_search->value )
    {
      if( node_search->left == nullptr )
      {
        node_search->left = node;
        node->parent = node_search;
      }
      else
      {
        node_search = node_search->left;
      }
    }

    // Greater than the current node
    else
    {
      if( node_search->right == nullptr )
      {
        node_search->right = node;
        node->parent = node_search;
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
// All nodes below it are removed as well.
// Nothing happens if the value is not found or the node to be removed is the root.
template <class T>
void BinaryNode<T>::RemoveSorted( T num )
{
  BinaryNode* node_remove = Search( num );

  if( node_remove != nullptr )
  {
    // If the node is its parent's left child
    if( node_remove->parent->left == node_remove )
    {
      node_remove->parent->left = nullptr;
    }

    // If the node is its parent's right child
    else if( node_remove->parent->right == node_remove )
    {
      node_remove->parent->right = nullptr;
    }
  }

  return;
}
