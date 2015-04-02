/*
 *
 * Name: Jeffrey Leung
 * Date: 2015-04-01
 *
 * This program contains implementations of a binary tree, composed of nodes.
 *
 */

#include <iostream>
#include <assert.h>

#include "binary_tree.hpp"



// This constructor initializes the given value of a new binary node.
BinaryNode::BinaryNode( int num )
{
  value = num;
  left = NULL;
  right = NULL;
}

/*
// This destructor recursively removes all subnodes as well as the current node.
BinaryNode::~BinaryNode()
{
  if( this != NULL )
  {
		
    if( left != NULL )
    {
      (*left).~BinaryNode();
    }
    if( right != NULL )
    {
      (*right).~BinaryNode();
    }

    delete this;
	}
}
*/



// ESSENTIAL METHODS:

// This method returns the value of the binary node.
int BinaryNode::GetValue()
{
  return value;
}

// This method assigns a new value to the binary node.
void BinaryNode::SetValue( int num )
{
  value = num;
  return;
}

// This method assigns a new node to an empty node pointer.
void BinaryNode::AssignNode( BinaryNode* new_node, direction d )
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
void BinaryNode::RemoveNode( direction d )
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
void BinaryNode::PrintTree_()
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
void BinaryNode::PrintTree()
{
  std::cout << "[ ";
  PrintTree_();
  std::cout << "]";

  return;
}

// This method returns the number of elements under and including the given node.
int BinaryNode::Count()
{
  int sum = 1;

  if( left != NULL )
  {
    sum += (*left).Count();
  }
  if( right != NULL )
  {
    sum += (*right).Count();
  }

  return sum;
}

// This method returns nonzero if the node in the given direction exists, and 0 otherwise.
int BinaryNode::NodeExists( direction d )
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
