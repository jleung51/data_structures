/*
 *
 * Name: Jeffrey Leung
 * Date: 2015-04-02
 *
 * This program tests implementations of the binary tree in binary_node.cpp.
 *
 */

#include <iostream>
#include <assert.h>

#include "binary_tree.hpp"

int main()
{
  BinaryNode root( 1 );
  BinaryNode node1( 1 );
  BinaryNode node2( 2 );

  node1.SetValue( 2 );

  root.AssignNode( &node1, LEFT  );
  root.AssignNode( &node2, RIGHT );

  std::cout << "Test 1: 1 = " << root.GetValue() << "\n";
  std::cout << "Test 2: " << node1.GetValue() << " = " << node2.GetValue() << "\n";

  int node_found = root.NodeExists( RIGHT );
  std::cout << "Test 3: 2 = " << node_found << "\n";

  root.RemoveNode( RIGHT );
  node_found = root.NodeExists( RIGHT );
  std::cout << "Test 4: 0 = " << node_found << "\n";

  root.AssignNode( &node2, RIGHT );
  std::cout << "Test 5: ";
  root.PrintTree();
  std::cout << " = [ 2 1 2 ]\n";

  BinaryNode* found = root.Search( 1 );
  assert( found != NULL );
  std::cout << "Test 6: (This is the test)\n";

  int sum = root.CountNodes();
  std::cout << "Test 7: 3 = " << sum << "\n";


  root.RemoveNode( LEFT );
  root.RemoveNode( RIGHT );
  root.SetValue( 5 );

  BinaryNode node0 = BinaryNode( 0 );
  BinaryNode node3 = BinaryNode( 3 );
  BinaryNode node8 = BinaryNode( 8 );
  BinaryNode node7 = BinaryNode( 7 );
  BinaryNode node9 = BinaryNode( 9 );

  root.InsertSorted( &node0 );
  root.InsertSorted( &node3 );
  root.InsertSorted( &node8 );
  root.InsertSorted( &node7 );
  root.InsertSorted( &node9 );
  std::cout << "Test 8: These numbers should be in order: ";
  root.PrintTree();
  std::cout << "\n";


  root.RemoveSorted( 3 );
  root.RemoveSorted( 7 );
  std::cout << "Test 9: [ 0 5 8 9 ] = ";
  root.PrintTree();
  std::cout << "\n";

  return 0;
}
