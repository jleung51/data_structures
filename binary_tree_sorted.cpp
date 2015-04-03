/*
 *
 * Name: Jeffrey Leung
 * Date: 2015-04-02
 *
 * This program contains methods which operate on sorted binary trees.
 * This program should be kept with binary_tree_basic.cpp for its constructor and methods.
 *
 */

#include <iostream>
#include <assert.h>

#include "binary_tree.hpp"

//TODO
//void Sort()

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
void BinaryNode::RemoveSorted( int num )
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
