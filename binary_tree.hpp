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
    //~BinaryNode();
    // ESSENTIAL METHODS:
    int GetValue();
    void SetValue( int num );
    void AssignNode( BinaryNode* new_node, direction d );  // Assigns the new node to the node's
                                                           // direction d.
    void RemoveNode( direction d );  // Assigns NULL to the node's direction d.
    // UTILITY METHODS:
    void PrintTree();
    int Count();
    int NodeExists( direction d );  // Returns nonzero if the node's direction d is non-null.


    // binary_tree_sorted.cpp

    // SORTED BINARY TREE METHODS:
    BinaryNode* Search( int target );  // Returns the pointer of the target, or NULL if not found.
                                       // Called by the root.
    void InsertSorted( BinaryNode* node );  // Inserts the node in the given tree in a
                                            // sorted position.
                                            // Called by the root.
    void RemoveSorted( int num );  //TODO
};

#endif
