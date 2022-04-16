#pragma once
#include "nodedata.h"
#include <cassert>
using namespace std;

class BinTree
{
    
    friend ostream& operator<<(ostream &output, const BinTree &);

public:
    
    BinTree();								
    BinTree(const BinTree &inputTree);				
    ~BinTree();								

    bool isEmpty() const;					
    void makeEmpty();						

   
    BinTree& operator=(const BinTree &);

   
    bool operator==(const BinTree &) const;
    bool operator!=(const BinTree &) const;


    bool insert(NodeData*);

  
    bool retrieve(const NodeData &compare, NodeData* &retrieve) const;

   
    int getHeight(const NodeData &node) const;

   
    void bstreeToArray(NodeData* arrayToFill[]);

   
    void arrayToBSTree(NodeData* []);

 
    void displaySideways() const;

private:
    struct Node
    {
        NodeData* data;						
        Node* left;							
        Node* right;						
    };
    Node* root;								

    void inorderHelper(Node* curr) const;

    void makeEmptyHelper(Node*& curr);

    void assignmentHelper(Node* &leftTree, Node* rightTree);

    bool equalityHelper(Node*, Node*) const;

    bool insertHelper(Node* &curr, NodeData*);

    void retrieveHelper(Node* curr, const NodeData &compare, NodeData* &retrieve) const;

    int getHeightHelper(Node *root, const NodeData &node, bool &found) const;

    int depth(Node* root) const;

    //int recursiveGetHeightHelper(Node*) const;

    int sizeOf(NodeData* array[]) const;

    int bstreeToArrayHelper(Node *curr, NodeData* arrayToFill[]) const;

    void arrayToTreeHelper(NodeData* array[], int left, int right);

    void sideways(Node*, int) const;

    int sizeOfArray;
    int size;
};
