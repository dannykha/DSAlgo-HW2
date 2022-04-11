#include "BinTree.h"

using namespace std;

BinTree::BinTree()
{
    this->root = nullptr;
}

BinTree::BinTree(const BinTree &other)
{
    root = copyHelper(other.root);
}

BinTree::~BinTree()
{
    deleter(root);
}

bool BinTree::isEmpty() const
{
    if (root->data == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void BinTree::makeEmpty()
{
    deleter(root);

    root->left = nullptr;
    root->right = nullptr;
    root->data = nullptr;
}

void BinTree::deleter(Node* otherRoot)
{
    if (otherRoot != nullptr)
    {
        deleter(otherRoot->left);
        deleter(otherRoot->right);
        if (otherRoot != root)
    {
        delete otherRoot;
    }
    }
    else 
    {
        return;
    }
}

BinTree& BinTree::operator=(const BinTree &other)
{
    if (other.root == nullptr)
    {
        root == nullptr;
    }
    else if (*this == other)
    {
        return *this;
    }
    else 
    {
        makeEmpty();
        root = copyHelper(other.root);
    }
    return *this;
}

BinTree::Node* BinTree::copyHelper(Node *other)
{
    Node* tempRoot = nullptr;
    if (other == nullptr)
    {
        tempRoot = nullptr;
    }
    else 
    {
        tempRoot = new Node();
        tempRoot->data = other->data;
        
        tempRoot->left = copyHelper(other->left);
        tempRoot->right = copyHelper(other->right);
    }
    return tempRoot;
}

bool BinTree::operator==(const BinTree &other) const
{
    if (this->root == nullptr && other.root == nullptr)
    {
        return true;
    }
    else 
    {
        return equalityHelper(this->root, other.root);
    }
}

bool BinTree::operator!=(const BinTree &other) const
{
    if (this->root == nullptr && other.root == nullptr)
    {
        return false;
    }
    else
    {
        return !(*this == other);
    }
}

bool BinTree::equalityHelper(Node* xNode, Node* yNode) const
{
    if (xNode == nullptr || yNode == nullptr)
    {
        return false;
    }
    if (*xNode->data == *yNode->data)
    {
        if (xNode->left == nullptr && yNode->left == nullptr && xNode->right == nullptr && yNode->right == nullptr)
        {
            return true;
        }
    }
    return (*xNode->data == *yNode->data && equalityHelper(xNode->left, yNode->left) && equalityHelper(xNode->right, yNode->right));
}

bool BinTree::insert(NodeData* inserting)
{
    return insertHelper(this->root, inserting);
}

bool BinTree::insertHelper(Node* thisRoot, NodeData* insertNode)
{
    if (thisRoot == nullptr)
    {
        thisRoot = new Node;
        thisRoot->data = insertNode;
        thisRoot->left = nullptr;
        thisRoot->right = nullptr;

        return true;
    }
    else if (*insertNode < *thisRoot->data)
    {
        insertHelper(thisRoot->left, insertNode);
    }
    else if (*insertNode > *thisRoot->data)
    {
        insertHelper(thisRoot->right, insertNode);
    }
    else
    {
        return false;
    }
    return true;
}

bool BinTree::retrieve(const NodeData& retrieving, NodeData* &retrieved) 
{

}

bool BinTree::retrieveHelper(Node* thisRoot, const NodeData &other, NodeData* &otherData) const
{

}

int BinTree::getHeight(const NodeData &other) const
{

}

int BinTree::getHeightHelper(const NodeData &other, Node* curr) const
{
    
}

void BinTree::bstreeToArray(NodeData* fillArray[])
{

}

void BinTree::arrayToBSTree(NodeData* inputArray[])
{
    this->makeEmpty();

    int high = 0;

    
}

void BinTree::arrayToBSTreeHelper(Node* curr, NodeData* inputArray[], int low, int high)
{
    if (low > high)
    {
        curr = nullptr;
    }
    else
    {
        int mid = (low + high) / 2;

        NodeData* temp;
        temp = inputArray[mid];
        inputArray[mid] = nullptr;

        insert(temp);
        arrayToBSTreeHelper(curr, inputArray, low, mid - 1);
        arrayToBSTreeHelper(curr, inputArray, mid + 1, high);
    }
}

void BinTree::displaySideways() const
{
    sidewaysHelper(root, 0);
}

void BinTree::sidewaysHelper(Node* curr, int level) const
{
    if (curr != nullptr)
    {
        level++;
        sidewaysHelper(curr->right, level);

        for (int i = level; i >= 0; i--)
        {
            cout << "   ";
        }

        cout << *curr->data << endl;
        sidewaysHelper(curr->left, level);
    }
}

