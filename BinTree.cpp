// ------------------------------------------------ BinTree.cpp -------------------------------------------------------
// Danny Kha CSS 343
// Creation Date: 4/11/22
// Date of Last Modification: 4/22/22
// --------------------------------------------------------------------------------------------------------------------
// Purpose - This is the implementation class for BinTree and the header that declares
// the class is within BinTree.h.
// BinTree is used to create a binary search tree that has additional functions such as
// converting a bintree to an array and vice versa.
// -------------------------------------------------------------------------------------------------------------------- 
// Notes - Utilizies the nodedata provided class to define nodes within the tree. Each node 
// in the tree holds a NodeData to hold the data.
// -------------------------------------------------------------------------------------------------------------------- 

#include "BinTree.h"
using namespace std;


// --------------------- Overloaded << --------------------------
// Overloads the output stream to display binary search tree in order.
// Uses inorderHelper to help display with in order traversal.
// --------------------------------------------------------------
ostream &operator<<(ostream &output, const BinTree &tree)
{
    tree.inorderHelper(tree.root);
    output << endl;
    return output;
} // end of Overloaded <<

// --------------------- inorderHelper --------------------------
// Helper function for output overload operator with in order traversal.
// --------------------------------------------------------------
void BinTree::inorderHelper(Node* curr) const
{
    if (root == nullptr)
    {
        return;
    }
    else if (curr != nullptr)
    {
        // inorder traversal
        inorderHelper(curr->left);
        cout << *curr->data << " ";
        inorderHelper(curr->right);
    }
} // end of inorderHelper

// --------------------- Default Constructor --------------------
// Constructor for an empty BinTree with the root being set to null.
// --------------------------------------------------------------
BinTree::BinTree()
{
    this->root = nullptr;
} // end of defualt constructor

// --------------------- Copy Constructor -----------------------
// Constructor to create a deep copy of a inputted BinTree.
// --------------------------------------------------------------
BinTree::BinTree(const BinTree &inputTree)
{
    this->root = nullptr;
    *this = inputTree;
} // end of copy constructor

// --------------------- Destructor -----------------------------
// Destructor to destroy a BinTree.
// Uses makeEmpty() as a helper to destroy.
// --------------------------------------------------------------
BinTree::~BinTree()
{
    this->makeEmpty();
} // end of destructor

// --------------------- makeEmpty ------------------------------
// Destroys the BinTree.
// Calls for the destroy helper.
// --------------------------------------------------------------
void BinTree::makeEmpty()
{
    destroy(root);
} // end of makeEmpty

// --------------------- destroy --------------------------------
// Helper function to makeEmpty and destroys the entire BinTree.
// --------------------------------------------------------------
void BinTree::destroy(Node*& curr)
{
    if (curr != nullptr)    
    {
        destroy(curr->left); // recurse back left to delete left
        destroy(curr->right); // recurse back right to delete right

        if (curr->data != nullptr) 
        {
            delete curr->data; // delete the current data
            curr->data = nullptr; // set it to nul
        }

        delete curr; 
        curr = nullptr; // sets the pointer of current to null
    }
} // end of destroy

// --------------------- isEmpty --------------------------------
// Checks if a BinTree is empty or not.
// --------------------------------------------------------------
bool BinTree::isEmpty() const
{
    if (this->root == nullptr || this->root->data == nullptr) // checking if it is empty
    {
        return true;
    }
    else
    {
        return false;
    }
} // end of isEmpty

// --------------------- Assignment Operator --------------------
// Assignment operator that creates a deep copy from the other tree (right) and 
// copies it to this (left).
// Uses makeEmpty and assignmentHelper to preform.
// --------------------------------------------------------------
BinTree& BinTree::operator=(const BinTree &otherTree)
{
    if (this == &otherTree) // checking if they are already the same
    {
        return *this;
    }
    else
    {
        this->makeEmpty(); // make this empty

        assignmentHelper(this->root, otherTree.root); // assigns other to this
    }
    return *this;  
} // end of assignment operator

// --------------------- assignment Helper ----------------------
// Helper function to the assignment operator. 
// Uses recursion to assign each part of the tree.
// --------------------------------------------------------------
void BinTree::assignmentHelper(Node* &leftTree, Node* rightTree)
{
    if (rightTree == nullptr) // if the right is null, then left is null.
    {
        leftTree = nullptr;
    }
    else
    {
        leftTree = new Node(); // creates a new node 
        NodeData *tempTree = new NodeData(*rightTree->data); // sets them equal

        leftTree->data = tempTree; // sets the data of the left to the brand new tree

        assignmentHelper(leftTree->left, rightTree->left); // assigning the left
        assignmentHelper(leftTree->right, rightTree->right); // assigning the right
    }
} // end of assignment helper

// --------------------- Overloaded == --------------------------
// Overloading the equality operator.
// Uses an equality helper function to preform.
// --------------------------------------------------------------
bool BinTree::operator==(const BinTree &rightTree) const
{
    if (this->root == nullptr && rightTree.root == nullptr) // checking for both being null
    {
        return true;
    }
    else
    {
        return equalityHelper(this->root, rightTree.root); // call to helper function
    }
} // end of equality operator

// --------------------- equalityComparisonHelper ---------------
// Helper function to check equality of trees.
// --------------------------------------------------------------
bool BinTree::equalityHelper(Node* leftNode, Node* rightNode) const
{
    if (leftNode == nullptr || rightNode == nullptr) // checking if either is null
    {
        return false;   
    } 
    else if (leftNode == nullptr && rightNode == nullptr) // another check for if they are both null
    {
        return true;   
    } 
    else if (leftNode != nullptr && rightNode != nullptr 
            && (*leftNode->data == *rightNode->data)) // checking for the data
    {
        return true;
    }
    // if the data is the same then use recursion to traverse and check
    return ((*leftNode->data == *rightNode->data) 
           && equalityHelper(leftNode->left, rightNode->left)
           && equalityHelper(leftNode->right, rightNode->right)); 
} // end of equality helper

// --------------------- Overloaded != --------------------------
// Overloading the unequality operator.
// Uses the already built equality operator and just inverts it.
// --------------------------------------------------------------
bool BinTree::operator!=(const BinTree &rightTree) const
{
    return !(*this == rightTree); // invert the equality.
} // end of unequality operator

// --------------------- insert ---------------------------------
// Function to insert a new NodeData with a new node into a BinTree.
// Uses the insert helper function.
// --------------------------------------------------------------
bool BinTree::insert(NodeData* toInsert)
{
    return insertHelper(this->root, toInsert); // call to insert helper
} // end of insert

// --------------------- insertHelper ---------------------------
// Helper function to insert.
// --------------------------------------------------------------
bool BinTree::insertHelper(Node* &curr, NodeData* toInsert)
{
    if (curr == nullptr) // checking if the current is null
    {
        curr = new Node;   
        curr->data = toInsert;   
        curr->left = nullptr;   
        curr->right = nullptr;

        return true;  
    }

    if (*toInsert != *curr->data) // checking that it is not already equal
    {
        if (*toInsert < *curr->data)
        {
            return insertHelper(curr->left, toInsert); // traverse left
        }

        if (*toInsert > *curr->data)
        {
            return insertHelper(curr->right, toInsert); // traverse right
        }
    }
    return false; 
} // end of insertHelper

// --------------------- retrieve -------------------------------
// Function to check if a NodeData is in the BinTree.
// Uses retrieve helper and assert functions to preform.
// --------------------------------------------------------------
bool BinTree::retrieve(const NodeData &compare, NodeData* &retrieve) const
{
    Node* curr = root; // creating a new Node set to root

    if (curr != nullptr) 
    {
        retrieveHelper(curr, compare, retrieve); // calling retrieve helper
    }
    else
    {
        return false;
    }

    if (retrieve != nullptr)
    {
        assert(*retrieve == compare); // checking if the NodeData retrieved is the same as the one
                                      // to compare with
        return true;
    }
    else
    {
        return false;
    }
} // end of retrieve

// --------------------- retrieveHelper -------------------------
// Helper function to retrieve the NodeData.
// --------------------------------------------------------------
void BinTree::retrieveHelper(Node* curr, const NodeData &compare, NodeData* &retrieve) const
{
    if (curr == nullptr) // checking for null   
    {
        retrieve = nullptr; // setting it to null
    }
    else if (*curr->data == compare)  // found the NodeData!
    {
        retrieve = curr->data;  // setting the retrieve to NodeData that was found
    }
    else if (*curr->data < compare) // since it is greater then then traverse right
    {
        retrieveHelper(curr->right, compare, retrieve);  // traverse right
    }
    else // last case is less then then traverse left 
    {
        retrieveHelper(curr->left, compare, retrieve);   // traverse left
    }
} // end of retrieveHelper

// --------------------- getHeight ------------------------------
// Function that returns the height of a inputted node in a BinTree.
// Uses the get height helper function.
// --------------------------------------------------------------
int BinTree::getHeight(const NodeData &node) const
{
    bool found = false; // setting a boolean to know if you found the node.
    return getHeightHelper(this->root, node, found);
} // end of getHeight

// --------------------- getHeightHelper ------------------------
// Helper function to get the height of the specificed Node.
// Uses retireve and recursiveHeightHelper functions.
// --------------------------------------------------------------
int BinTree::getHeightHelper(Node *curr, const NodeData &node, bool &found) const
{
    int left; // temp left
    int right; // temp right
    
    if(curr == nullptr) // checking for null, return 0
    {
        return 0;
    }
    else if(*curr->data == node) // found it
    {
        NodeData *objFound; // create a new NodeData obj
        found = retrieve(node, objFound); // calls to retrieve to retrieve the found

        if(found == true) // checks if found is true 
        {
            return recursiveHeightHelper(curr); // to find the height of the NodeData
        }
    }
    else // Recurse until found
    {
        if(curr->left != nullptr) // checking left
        {
            left = getHeightHelper(curr->left, node, found); // traverse left

            if(found == true) // if found then return the left
            {
                return left;
            }
        }
        if(curr->right != nullptr) // checking right
        {
            right = getHeightHelper(curr->right, node, found); // traverse right

            if(found == true) // if found then return the right
            {
                return right;
            }
        }
        return 0; // return 0 if not found
    }
    return 0; // return 0 if not found
} // end of getHeightHelper

// --------------------- recursiveHeightHelper ------------------
// Helper function that uses recursion to find the height of the node in the BinTree.
// --------------------------------------------------------------
int BinTree::recursiveHeightHelper(Node* curr) const
{
    if(curr == nullptr)
    {
        return 0; // no root node, no tree, height = 0
    }
    else if(curr->left == nullptr && curr->right == nullptr)
    {
        return 1; // has one root node, so height = 1
    }
    else
    {
        // count for the height of the node in the BinTree.
        return 1 + max(recursiveHeightHelper(curr->left), recursiveHeightHelper(curr->right));
    }
    return 0; // in case, rare case
} // end of recursiveHeightHelper

// --------------------- bstreeToArray -------------------------
// Function that convrts binary search trees to an array.
// Uses bstreeToArray and makeEmpty to preform this action.
// --------------------------------------------------------------
void BinTree::bstreeToArray(NodeData* arrayToFill[])
{
    bstreeToArrayHelper(this->root, arrayToFill); 

    this->makeEmpty();  
} // end of bstreeToArray

// --------------------- bstreeToArrayHelper -----------------------------------------
// Helper to put an entire binary search tree into an array.
// Uses an inorder traversal.
// --------------------------------------------------------------
int BinTree::bstreeToArrayHelper(Node* curr, NodeData* arrayToFill[]) const
{
    if (curr == nullptr) // first checking if nullptr, then just return 0.
    {
        return 0;
    }

    // In order traversal
    int left = bstreeToArrayHelper(curr->left, arrayToFill); // traverse left

    NodeData *temp; // create a temp NodeData
    temp = curr->data; // set the current data to the temp
    curr->data = nullptr; // set the current data now to null
    *(arrayToFill + left) = temp; // then set a pointer to the temp
    temp = nullptr; // set temp to null

    int right = bstreeToArrayHelper(curr->right, arrayToFill + left + 1); // traverse right

    return left + right + 1; // returning the position of the node
} // end of bstreeToArrayHelper

// --------------------- arrayToBSTree --------------------------
// Function that converts an array to a binary search tree.
// Uses arrayToBSTree and sizeOf helper functions.
// --------------------------------------------------------------
void BinTree::arrayToBSTree(NodeData* array[])
{
    arrayToTreeHelper(array, 0, (sizeOf(array) - 1)); // calls helper function and sizeOf
} // end of arrayToBSTree

// --------------------- sizeOf ---------------------------------
// Helper function that determines the size of a array consisting of NodeDatas.
// --------------------------------------------------------------
int BinTree::sizeOf(NodeData* array[]) const
{
    int size = 0; // set a temp size 

    while (array[size] != NULL) // loop and increase the size until array empty
    {
        size++; // increment size
    }
    return size; // returns the size
} // end of sizeOf

// --------------------- arrayToBSTreeHelper --------------------
// Helper function for arrayToBSTree.
// Uses insert function and recursion calls.
// --------------------------------------------------------------
void BinTree::arrayToTreeHelper(NodeData* array[], int start, int end)
{
     if (start > end) // if the start of the array is greater then end, return nothing.
    {
        return;
    }
    
    int mid = start + ((end - start) / 2); // find a mid value
    NodeData* temp = new NodeData(*array[mid]); // set a temp NodeData with the array mid data
    insert(temp); // use the insert function to inser the temp NodeData.
    delete array[mid]; // delete this array spot
    
    arrayToTreeHelper(array, start, (mid - 1)); // filling the left of tree
    arrayToTreeHelper(array, (mid + 1), end);  // filling the right of tree
} // end of arrayToTreeHelper

// --------------------- displaySideways ------------------------
// Function that displays the binary search tree sideways.
// Uses the sideways helper function.
// --------------------------------------------------------------
void BinTree::displaySideways() const
{
    sideways(root, 0); // call to sideways helper function  
} // end of displaySideways

// --------------------- sideways -------------------------------
// Helper function that makes a binary search tree become sideways when displayed.
// --------------------------------------------------------------
void BinTree::sideways(Node* curr, int level) const
{
    if (curr != nullptr) 
    { 
        level++; 
        sideways(curr->right, level); 
        
        // for loop to create indentation
        for (int i = level; i >= 0; i--) 
        {
            cout << "    ";
        }

        cout << *curr->data << endl;  // output and display      
        sideways(curr->left, level);
    }
} // end of sideways