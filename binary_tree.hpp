#ifndef BINARY_NODE_HPP
#define BINARY_NODE_HPP

enum direction
{
  LEFT,
  RIGHT
};

class BinaryNode
{
  private:
    int value;
    BinaryNode* left;
    BinaryNode* right;

    void PrintTree_();  // Only for use by PrintTree()

  public:

    // binary_tree_basic.cpp

    BinaryNode( int num );

    // ESSENTIAL METHODS:
    int GetValue();
    void SetValue( int num );
    void AssignNode( BinaryNode* new_node, direction d );  // Assigns a new child node.
    void RemoveNode( direction d );  // Removes a child node.
    // UTILITY METHODS:
    void PrintTree();  // Prints nodes from left to right
    int CountNodes();
    int NodeExists( direction d );  // Returns nonzero if the node's direction d is non-null.


    // binary_tree_sorted.cpp

    // SORTED BINARY TREE METHODS:
    // Called by the root of the binary tree unless otherwise specified.
    void Sort(); //TODO
    BinaryNode* Search( int target );  // Returns the pointer of the target, or NULL if not found.
    void InsertSorted( BinaryNode* node );
    void RemoveSorted( int num );  // Nothing happens if the value is not found or the root is the
                                   // node to be removed.
};

#endif
