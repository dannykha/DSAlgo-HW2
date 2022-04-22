// ------------------------------------------------ BinTree.h -------------------------------------------------------
// Danny Kha CSS 343
// Creation Date: 4/10/22
// Date of Last Modification: 4/22/22
// --------------------------------------------------------------------------------------------------------------------
// Purpose - This is the header class for BinTree and the implementation
// can be seen in BinTree.cpp. 
// BinTree is used to create a binary search tree that has additional functions such as
// converting a bintree to an array and vice versa.
// -------------------------------------------------------------------------------------------------------------------- 
// Notes - Utilizies the nodedata provided class to define nodes within the tree. Each node 
// in the tree holds a NodeData to hold the data.
// -------------------------------------------------------------------------------------------------------------------- 

#pragma once
#include "nodedata.h"
#include <cassert> // using assertion for retrieval function to compare 
using namespace std;

class BinTree
{
    // output overload
    friend ostream& operator<<(ostream &output, const BinTree &tree);

public:

    // constructor
    BinTree();				

    // copy constructor				
    BinTree(const BinTree &inputTree);	

    // destructor			
    ~BinTree();								
				
    // function to make the tree empty
    void makeEmpty();	

    // boolean function to check if tree is empty
    bool isEmpty() const;							

    // assignemnt operator
    BinTree& operator=(const BinTree &otherTree);

    // equality check operator
    bool operator==(const BinTree &rightTree) const;

    // unequality check operator
    bool operator!=(const BinTree &rightTree) const;

    // function to insert NodeData into the BinTree
    bool insert(NodeData* toInsert);

    // function to retrieve the NodeData within a tree
    bool retrieve(const NodeData &compare, NodeData* &retrieve) const;

    // function to get the height of a given value in a tree 
    int getHeight(const NodeData &node) const;

    // function to convert a binary search tree to an array
    void bstreeToArray(NodeData* arrayToFill[]);

    // function to convert a array to a binary search tree
    void arrayToBSTree(NodeData* array[]);

    // function to display the tree sideways
    void displaySideways() const;

private:
    struct Node
    {
        // data pointer
        NodeData* data;		

        // left subtree pointer				
        Node* left;			

        // right subtree pointer		
        Node* right;						
    };
    // root of the tree
    Node* root;								

    // function to help with output overload using inorder traversal
    void inorderHelper(Node* curr) const;

    // function to help the makeEmpty 
    void destroy(Node* &curr);

    // function to help the assignment operator
    void assignmentHelper(Node* &leftTree, Node* rightTree);

    // function to help check for equality of trees
    bool equalityHelper(Node* leftNode, Node* rightNode) const;

    // function to help insert 
    bool insertHelper(Node* &curr, NodeData* toInsert);

    // function to help retrieve
    void retrieveHelper(Node* curr, const NodeData &compare, NodeData* &retrieve) const;

    // function to help get height
    int getHeightHelper(Node* curr, const NodeData &node, bool &found) const;

    // function to help get depth which connects to the height helper
    int recursiveHeightHelper(Node* curr) const;

    // function to find the size of an array from NodeData
    int sizeOf(NodeData* array[]) const;

    // function to help convert a binary search tree to array
    int bstreeToArrayHelper(Node* curr, NodeData* arrayToFill[]) const;

    // function to help convert a array to a binary search tree
    void arrayToTreeHelper(NodeData* array[], int left, int right);

    // function to help display the tree sideways
    void sideways(Node* curr, int level) const;
};
