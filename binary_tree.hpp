/*
 *
 * Name: Jeffrey Leung
 * Date: 2015-04-07
 *
 * This program contains implementations of a binary tree, composed of nodes.
 *
 */

#ifndef BINARY_NODE_HPP
#define BINARY_NODE_HPP

#include <iostream>
#include <assert.h>

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

    void PrintTree_();  // Only for use by PrintTree().
    void PrintNodes_Depth( unsigned int depth );  // Only for use by PrintNodes_().
    void PrintNodes_( unsigned int depth );  // Only for use by PrintNodes().

  public:

    // Constructor
    BinaryNode( T new_value )
    {
      value = new_value;
      left = NULL;
      right = NULL;
    }

    // ESSENTIAL METHODS:
    void SetValue( T num );
    T GetValue();
    void AssignNode( BinaryNode* new_node, direction d );  // Assigns a new child node.
    void RemoveNode( direction d );  // Removes a child node.

    // UTILITY METHODS:
    void PrintTree();  // Prints nodes from left to right
    void PrintNodes();  // Prints a description of nodes and their hierarchy.
                        // Describes how the binary tree should be drawn visually.
    int CountNodes();
    int NodeExists( direction d );  // Returns nonzero if the node's direction d is non-null.

    // SORTED BINARY TREE (numerical) METHODS:
    // Called by the root of the binary tree unless otherwise specified.
    void Sort(); //TODO
    BinaryNode* Search( T target );  // Returns the pointer of the target, or NULL if not found.
    void InsertSorted( BinaryNode* node );
    void RemoveSorted( T num );  // Nothing happens if the value is not found or the root is the
                                 // node to be removed.
};



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
    assert( left == NULL );
    left = new_node;
  }
  else if( d == RIGHT )
  {
    assert( right == NULL );
    right = new_node;
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
void BinaryNode<T>::PrintTree_()
{
  if( left != NULL )
  {
    (*left).PrintTree_();
  }

  std::cout << value << " ";

  if( right != NULL )
  {
    (*right).PrintTree_();
  }

  return;
}

// This wrapper method recursively prints the elements of a binary tree in order from left to
// right, formatted.
template <class T>
void BinaryNode<T>::PrintTree()
{
  std::cout << "[ ";
  PrintTree_();
  std::cout << "]";

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
    std::cout << "  ";
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
  std::cout << "Node: " << value << "\n";

  // Left/right pointers:

  PrintNodes_Depth( depth );
  if( left != NULL )
  {
    std::cout << "Left of " << value << ":  " << left->value << "\n";
  }
  else
  {
    std::cout << "There are no nodes to the left of " << value << ".\n";
  }

  PrintNodes_Depth( depth );
  if( right != NULL )
  {
    std::cout << "Right of " << value << ": " << right->value << "\n";
  }
  else
  {
    std::cout << "There are no nodes to the right of " << value << ".\n";
  }

  // Children
  if( left != NULL )
  {
    std::cout << "\n";
    left->PrintNodes_( depth+1 );
  }
  if( right != NULL )
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

//TODO
//void Sort()

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
