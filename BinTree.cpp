#include "BinTree.h"
using namespace std;


// --------------------- Overloaded << -----------------------------------------
// 
// --------------------------------------------------------------
ostream &operator<<(ostream &output, const BinTree &tree)
{
    tree.inorderHelper(tree.root);
    output << endl;
    return output;
}

// --------------------- inorderHelper -----------------------------------------
// 
// --------------------------------------------------------------
void BinTree::inorderHelper(Node* curr) const
{
    if (curr != nullptr)
    {
        inorderHelper(curr->left);
        cout << *curr->data << " ";
        inorderHelper(curr->right);
    }
}

// --------------------- Default Constructor -----------------------------------------
// 
// --------------------------------------------------------------
BinTree::BinTree()
{
    this->root = nullptr;
}

// --------------------- Copy Constructor -----------------------------------------
// 
// --------------------------------------------------------------
BinTree::BinTree(const BinTree &inputTree)
{
    this->root = nullptr;
    *this = inputTree;
}

// --------------------- Destructor -----------------------------------------
// 
// --------------------------------------------------------------
BinTree::~BinTree()
{
    this->makeEmpty();
}

// --------------------- isEmpty -----------------------------------------
// 
// --------------------------------------------------------------
bool BinTree::isEmpty() const
{
    if (this->root == nullptr)
    {
        return true;
    }
    return false;
}

// --------------------- makeEmpty -----------------------------------------
// 
// --------------------------------------------------------------
void BinTree::makeEmpty()
{
    makeEmptyHelper(root);
}

// --------------------- makeEmptyHelper -----------------------------------------
//
// --------------------------------------------------------------
void BinTree::makeEmptyHelper(Node*& curr)
{
    if (curr != nullptr)    
    {
        makeEmptyHelper(curr->left);
        makeEmptyHelper(curr->right);    

        if (curr->data != nullptr)
        {
            delete curr->data;   
            curr->data = nullptr;
        }

        delete curr; 
        curr = nullptr;
    }
}

// --------------------- Overloaded = -----------------------------------------
// 
// --------------------------------------------------------------
BinTree& BinTree::operator=(const BinTree &otherTree)
{
    if (*this == otherTree)
    {
        return *this;
    }

    this->makeEmpty(); 

    assignmentHelper(this->root, otherTree.root);

    return *this;  
}

// --------------------- assignmentHelper -----------------------------------------
// 
// --------------------------------------------------------------
void BinTree::assignmentHelper(Node* &leftTree, Node* rightTree)
{
    if (rightTree == nullptr)
    {
        leftTree = nullptr;
    }
    else
    {
        leftTree = new Node();
        NodeData *tempTree = new NodeData(*rightTree->data);
        leftTree->data = tempTree;

        assignmentHelper(leftTree->left, rightTree->left);
        assignmentHelper(leftTree->right, rightTree->right);
    }
}

// --------------------- Overloaded == -----------------------------------------
// 
// --------------------------------------------------------------
bool BinTree::operator==(const BinTree &rightTree) const
{
    if (this->root == nullptr && rightTree.root == nullptr)
    {
        return true;
    }
    else
    {
        return equalityHelper(this->root, rightTree.root);
    }
}

// --------------------- equalityComparisonHelper -----------------------------------------
// 
// --------------------------------------------------------------
bool BinTree::equalityHelper(Node* leftNode, Node* rightNode) const
{
    if (leftNode == nullptr || rightNode == nullptr)
    {
        return false;   
    }

    if (leftNode == nullptr && rightNode == nullptr)
    {
        return true;   
    }

    if (leftNode != nullptr && rightNode != nullptr && (*leftNode->data == *rightNode->data))
    {
        return true;
    }

    return ((*leftNode->data == *rightNode->data)
           && equalityHelper(leftNode->left, rightNode->left)
           && equalityHelper(leftNode->right, rightNode->right));
}

// --------------------- Overloaded != -----------------------------------------
// 
// --------------------------------------------------------------
bool BinTree::operator!=(const BinTree &rightTree) const
{
    return !(*this == rightTree);
}

// --------------------- insert -----------------------------------------
// 
// --------------------------------------------------------------
bool BinTree::insert(NodeData* toInsert)
{
    return insertHelper(this->root, toInsert);
}

// --------------------- insertHelper -----------------------------------------
// 
// --------------------------------------------------------------
bool BinTree::insertHelper(Node* &curr, NodeData* toInsert)
{
    if (curr == nullptr)    
    {
        curr = new Node;   
        curr->data = toInsert;   
        curr->left = nullptr;   
        curr->right = nullptr;  
    }

    if (*toInsert != *curr->data)
    {
        if (*toInsert < *curr->data)
        {
            insertHelper(curr->left, toInsert);
        }
        if (*toInsert > *curr->data)
        {
            insertHelper(curr->right, toInsert);
        }
    }
    return true;    
}

// --------------------- retrieve -----------------------------------------
// 
// --------------------------------------------------------------
bool BinTree::retrieve(const NodeData &compare, NodeData* &retrieve) const
{
    Node* curr = root;

    if (curr != nullptr)
    {
        retrieveHelper(curr, compare, retrieve);
    }
    else
    {
        return false;
    }

    if (retrieve != nullptr)
    {
        assert(*retrieve == compare);

        return true;
    }
    else
    {
        return false;
    }
}

// --------------------- retrieveHelper -----------------------------------------
//
// --------------------------------------------------------------
void BinTree::retrieveHelper(Node* curr, const NodeData &compare, NodeData* &retrieve) const
{
    if (curr == nullptr)    
    {
        retrieve = nullptr; 
    }
    else if (*curr->data == compare)   
    {
        retrieve = curr->data;  
    }
    else if (*curr->data < compare)
    {
        retrieveHelper(curr->right, compare, retrieve);  
    }
    else 
    {
        retrieveHelper(curr->left, compare, retrieve);   
    }
}

// --------------------- getHeight -----------------------------------------
// 
// --------------------------------------------------------------
int BinTree::getHeight(const NodeData &node) const
{
    bool found = false;
    return getHeightHelper(this->root, node, found);
}

// --------------------- getHeightHelper -----------------------------------------
// 
// --------------------------------------------------------------
int BinTree::getHeightHelper(Node *thisRoot, const NodeData &node, bool &found) const
{
    int left;
    int right;
    
    if(thisRoot == nullptr)
    {
        return 0;
    }
    else if(*thisRoot->data == node)
    {
        NodeData *objectFound;
        found = retrieve(node, objectFound);
        
        if(found == true)
        {
            return depth(thisRoot);
        }
    }
    else
    {
        if(thisRoot->left != nullptr)
        {
            left = getHeightHelper(thisRoot->left, node, found);
            if(found == true)
            {
                return left;
            }
        }
        if(thisRoot->right != nullptr)
        {
            right = getHeightHelper(thisRoot->right, node, found);
            if(found == true)
            {
                return right;
            }
        }
        return 0;
    }
    return 0;
}

int BinTree::depth(Node* thisRoot) const
{
    int left;
    int right;
    
    if(thisRoot == nullptr)
    {
        return 0;
    }
    else if(thisRoot->left == nullptr &&
                            thisRoot->right == nullptr)
    {
        return 1;
    }
    else
    {
        left = depth(thisRoot->left);
        right = depth(thisRoot->right);
        
        return 1 + max(left, right);
    }
    return 0;
}

// --------------------- secondGetHeightHelper -----------------------------------------
// 
// --------------------------------------------------------------
// int BinTree::recursiveGetHeightHelper(Node* curr) const
// {
//     if (curr == nullptr)
//     {
//         return 0;   
//     }
//     else
//     {
//         return 1 + max(recursiveGetHeightHelper(curr->left), recursiveGetHeightHelper(curr->right));
//     }
// }

// --------------------- bstreeToArrayHelper -----------------------------------------
// 
// --------------------------------------------------------------
void BinTree::bstreeToArray(NodeData* arrayToFill[])
{
    bstreeToArrayHelper(this->root, arrayToFill);

    this->makeEmpty();  
}

// --------------------- bstreeToArrayHelper -----------------------------------------
// 
// --------------------------------------------------------------
int BinTree::bstreeToArrayHelper(Node* curr, NodeData* arrayToFill[]) const
{
    if (curr == nullptr)
    {
        return 0;
    }

    int left = bstreeToArrayHelper(curr->left, arrayToFill);

    NodeData *temp;
    temp = curr->data; 
    curr->data = nullptr; 
    *(arrayToFill + left) = temp; 
    temp = nullptr;

    int right = bstreeToArrayHelper(curr->right, arrayToFill + left + 1);

    return left + right + 1; 
}

// --------------------- arrayToBSTree -----------------------------------------
// 
// --------------------------------------------------------------
void BinTree::arrayToBSTree(NodeData* array[])
{
    arrayToTreeHelper(array, 0, (sizeOf(array) - 1));
}

int BinTree::sizeOf(NodeData* array[]) const
{
    int size = 0;
    
    // While not NULL, go ahead and proceed
    while (array[size] != NULL)
    {
        // Increment size
        size++;
    }
    
    return size;
}


// --------------------- arrayToBSTreeHelper -----------------------------------------
// 
// --------------------------------------------------------------
void BinTree::arrayToTreeHelper(NodeData* array[], int start, int end)
{
     if (start > end)
    {
        return;
    }
    
    int mid = start + ((end - start) / 2);
    NodeData* temp = new NodeData(*array[mid]);
    insert(temp);
    delete array[mid];
    
    arrayToTreeHelper(array, start, (mid - 1));
    arrayToTreeHelper(array, (mid + 1), end); 
}

// --------------------- displaySideways -----------------------------------------
//
// --------------------------------------------------------------
void BinTree::displaySideways() const
{
    sideways(root, 0);  // get her comments
}

// --------------------- sideways -----------------------------------------
//
// --------------------------------------------------------------
void BinTree::sideways(Node* curr, int level) const
{
    if (curr != nullptr) {
        level++;
        sideways(curr->right, level);

        for (int i = level; i >= 0; i--) {
            cout << "    ";
        }

        cout << *curr->data << endl;        
        sideways(curr->left, level);
    }
}