#pragma once

#include "nodedata.h"
using namespace std;

class BinTree
{

    friend ostream& operator<<(ostream &output, const BinTree&);

public:
    BinTree();
    BinTree(const BinTree &);
    ~BinTree();

    bool isEmpty() const;

    void makeEmpty();

    BinTree& operator=(const BinTree&);

    bool operator==(const BinTree &other) const;
    bool operator!=(const BinTree &other) const;

    bool insert(NodeData*);

    bool retrieve(const NodeData&, NodeData* &);

    int getHeight(const NodeData&) const;

    void bstreeToArray(NodeData* []);

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

    Node* copyHelper(Node* other);

    void deleter(Node* otherRoot);

    bool equalityHelper(Node* x, Node* y) const;

    bool insertHelper(Node* thisRoot, NodeData* insertNode);

    bool retrieveHelper(Node* thisRoot, const NodeData &other, NodeData* &otherData) const;

    int getHeightHelper(const NodeData &, Node*) const;

    int bstreeToArrayHelper(Node*) const;

    void arrayToBSTreeHelper(Node*, NodeData* [], int, int);

    void sidewaysHelper(Node*, int) const;
};