/*
 *
 * Name: Jeffrey Leung
 * Date: 2015-04-01
 *
 * This program contains methods which operate on sorted binary trees.
 * This program should be kept with binary_tree_basic.cpp for its constructor and methods.
 *
 */

#include <iostream>
#include <assert.h>

#include "binary_tree.hpp"

// This method returns the address of the binary node containing the target, or NULL if the target
// is not found.
// Called by the root.
BinaryNode* BinaryNode::Search( int target )
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
void BinaryNode::InsertSorted( BinaryNode* node )
{
  BinaryNode* node_search = this;
  while( node_search->left != node && node_search->right != node )
  {
    // Less than or equal to
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

    // Greater than
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
