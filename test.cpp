/*
 *
 * Name: Jeffrey Leung
 * Date: 2015-04-07
 *
 * This program tests implementations of the binary tree in binary_node.cpp.
 *
 */

#include <iostream>
#include <assert.h>

#include "binary_tree.hpp"

int main()
{
  BinaryNode<int> root( 1 );
  BinaryNode<int> node1( 1 );
  BinaryNode<int> node2( 2 );

  node1.SetValue( 2 );

  root.AssignNode( &node1, LEFT  );
  root.AssignNode( &node2, RIGHT );

  std::cout << "Test 1: 1 = " << root.GetValue() << "\n";
  std::cout << "Test 2: " << node1.GetValue() << " = " << node2.GetValue() << "\n";

  int node_found = root.NodeExists( RIGHT );
  std::cout << "Test 3: 1 = " << node_found << "\n";

  node2.RemoveNode();
  node_found = root.NodeExists( RIGHT );
  std::cout << "Test 4: 0 = " << node_found << "\n";

  root.AssignNode( &node2, RIGHT );
  std::cout << "Test 5: ";
  root.PrintTree();
  std::cout << " = [ 2 1 2 ]\n";

  BinaryNode<int>* found = root.Search( 1 );
  assert( found != NULL );
  std::cout << "Test 6: (This is the test)\n";

  int sum = root.CountNodes();
  std::cout << "Test 7: 3 = " << sum << "\n";


  node1.RemoveNode();
  node2.RemoveNode();
  root.SetValue( 5 );

  BinaryNode<int> node0 = BinaryNode<int>( 0 );
  BinaryNode<int> node3 = BinaryNode<int>( 3 );
  BinaryNode<int> node8 = BinaryNode<int>( 8 );
  BinaryNode<int> node7 = BinaryNode<int>( 7 );
  BinaryNode<int> node9 = BinaryNode<int>( 9 );

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

  std::cout << "\n";
  std::cout << "A visualization of the final structure:\n\n";
  root.PrintNodes();
  std::cout << "\n";

  return 0;
}
