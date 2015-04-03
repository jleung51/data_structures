#ifndef BINARY_NODE_HPP
#define BINARY_NODE_HPP

enum direction
{
  LEFT,
  RIGHT
};

template <typename Type>
class BinaryNode
{
  private:
    Type value;
    BinaryNode* left;
    BinaryNode* right;

    void PrintTree_();  // Only for use by PrintTree()

  public:

    // Methods from binary_tree_basic.cpp:

    BinaryNode<Type>( Type num );

    // ESSENTIAL METHODS:
    Type GetValue();
    void SetValue( Type num );
    void AssignNode( BinaryNode* new_node, direction d );  // Assigns a new child node.
    void RemoveNode( direction d );  // Removes a child node.
    // UTILITY METHODS:
    void PrintTree();  // Prints nodes from left to right
    Type CountNodes();
    Type NodeExists( direction d );  // Returns nonzero if the node's direction d is non-null.


    // Methods from binary_tree_sorted.cpp:

    // SORTED BINARY TREE METHODS:
    // Called by the root of the binary tree unless otherwise specified.
    void Sort(); //TODO
    BinaryNode* Search( Type target );  // Returns the pointer of the target, or NULL if not found.
    void InsertSorted( BinaryNode* node );
    void RemoveSorted( Type num );  // Nothing happens if the value is not found or the root is the
                                 // node to be removed.
};

#endif
