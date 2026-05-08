// Muhammad Wahaj
// BITF24M059
// BST.cpp - Integer Binary Search Tree Implementation

#include "BST.h"
#include <iostream>
using namespace std;

// -------------------------------------------------------
// Constructor & Destructor
// -------------------------------------------------------

BST::BST() {
    root = nullptr;
}

BST::~BST() {
    destroy(root);
}

// -------------------------------------------------------
// Private Helper: destroy (post-order deletion)
// -------------------------------------------------------

void BST::destroy(BSTNode *b) {
    if (b == nullptr)
        return;
    destroy(b->left);
    destroy(b->right);
    delete b;
}

// -------------------------------------------------------
// Public: insert
// Iteratively inserts val. Returns false if duplicate.
// -------------------------------------------------------

bool BST::insert(int val) {
    BSTNode *newNode = new BSTNode();
    newNode->data  = val;
    newNode->left  = nullptr;
    newNode->right = nullptr;

    if (root == nullptr) {
        root = newNode;
        return true;
    }

    BSTNode *curr = root;
    while (true) {
        if (val == curr->data) {
            delete newNode;
            return false;
        }
        if (val < curr->data) {
            if (curr->left == nullptr) {
                curr->left = newNode;
                return true;
            }
            curr = curr->left;
        } else {
            if (curr->right == nullptr) {
                curr->right = newNode;
                return true;
            }
            curr = curr->right;
        }
    }
}

// -------------------------------------------------------
// Public: search (iterative)
// -------------------------------------------------------

bool BST::search(int val) {
    BSTNode *curr = root;
    while (curr != nullptr) {
        if (curr->data == val)
            return true;
        if (val < curr->data)
            curr = curr->left;
        else
            curr = curr->right;
    }
    return false;
}

// -------------------------------------------------------
// Private Helper: removeHelper (recursive)
// Handles all 3 BST deletion cases:
//   Case 1 - leaf node
//   Case 2 - one child
//   Case 3 - two children (replace with in-order successor)
// -------------------------------------------------------

BSTNode* BST::removeHelper(BSTNode *b, int val, bool &removed) {
    if (b == nullptr) {
        removed = false;
        return nullptr;
    }

    if (val < b->data) {
        b->left = removeHelper(b->left, val, removed);

    } else if (val > b->data) {
        b->right = removeHelper(b->right, val, removed);

    } else {
        removed = true;

        if (b->left == nullptr && b->right == nullptr) {
            delete b;
            return nullptr;

        } else if (b->left == nullptr) {
            BSTNode *temp = b->right;
            delete b;
            return temp;

        } else if (b->right == nullptr) {
            BSTNode *temp = b->left;
            delete b;
            return temp;

        } else {
            BSTNode *successor = b->right;
            while (successor->left != nullptr)
                successor = successor->left;
            b->data = successor->data;
            bool dummy = true;
            b->right = removeHelper(b->right, successor->data, dummy);
        }
    }
    return b;
}

// -------------------------------------------------------
// Public: remove
// -------------------------------------------------------

bool BST::remove(int val) {
    bool removed = true;
    root = removeHelper(root, val, removed);
    return removed;
}

// -------------------------------------------------------
// Private Helpers: traversals (recursive)
// Pre-order  : Root -> Left -> Right
// In-order   : Left -> Root -> Right  (gives sorted output)
// Post-order : Left -> Right -> Root
// -------------------------------------------------------

void BST::preOrder(BSTNode *b) {
    if (b == nullptr)
        return;
    cout << b->data << " ";
    preOrder(b->left);
    preOrder(b->right);
}

void BST::inOrder(BSTNode *b) {
    if (b == nullptr)
        return;
    inOrder(b->left);
    cout << b->data << " ";
    inOrder(b->right);
}

void BST::postOrder(BSTNode *b) {
    if (b == nullptr)
        return;
    postOrder(b->left);
    postOrder(b->right);
    cout << b->data << " ";
}

// -------------------------------------------------------
// Public: traversal drivers
// -------------------------------------------------------

void BST::preOrder() {
    preOrder(root);
    cout << endl;
}

void BST::inOrder() {
    inOrder(root);
    cout << endl;
}

void BST::postOrder() {
    postOrder(root);
    cout << endl;
}

// -------------------------------------------------------
// Private Helper: getHeight (recursive)
// Height = number of edges on the longest root-to-leaf path.
// Empty tree returns -1. Single node returns 0.
// -------------------------------------------------------

int BST::getHeight(BSTNode *b) {
    if (b == nullptr)
        return -1;
    int leftHeight  = getHeight(b->left);
    int rightHeight = getHeight(b->right);
    if (leftHeight > rightHeight)
        return leftHeight + 1;
    return rightHeight + 1;
}

// -------------------------------------------------------
// Public: getHeight driver
// -------------------------------------------------------

int BST::getHeight() {
    return getHeight(root);
}

// -------------------------------------------------------
// Private Helper: countNodes (recursive)
// Counts every node in the tree by visiting all subtrees.
// -------------------------------------------------------

int BST::countNodes(BSTNode *b) {
    if (b == nullptr)
        return 0;
    return 1 + countNodes(b->left) + countNodes(b->right);
}

// -------------------------------------------------------
// Public: countNodes driver
// -------------------------------------------------------

int BST::countNodes() {
    return countNodes(root);
}

// -------------------------------------------------------
// Private Helper: recSearch (recursive)
// Uses BST property to go left/right instead of checking
// every node, so it is O(h) not O(n).
// -------------------------------------------------------

bool BST::recSearch(BSTNode *b, int key) {
    if (b == nullptr)
        return false;
    if (b->data == key)
        return true;
    if (key < b->data)
        return recSearch(b->left, key);
    return recSearch(b->right, key);
}

// -------------------------------------------------------
// Public: recSearch driver
// -------------------------------------------------------

bool BST::recSearch(int key) {
    return recSearch(root, key);
}

// -------------------------------------------------------
// Public: findMin / findMax (iterative)
// Minimum is always the leftmost node.
// Maximum is always the rightmost node.
// -------------------------------------------------------

int BST::findMin() {
    if (root == nullptr) {
        cout << "Tree is empty." << endl;
        return -1;
    }
    BSTNode *curr = root;
    while (curr->left != nullptr)
        curr = curr->left;
    return curr->data;
}

int BST::findMax() {
    if (root == nullptr) {
        cout << "Tree is empty." << endl;
        return -1;
    }
    BSTNode *curr = root;
    while (curr->right != nullptr)
        curr = curr->right;
    return curr->data;
}

// -------------------------------------------------------
// Private Helpers: findMinRec / findMaxRec (recursive)
// Same logic as iterative but expressed recursively.
// -------------------------------------------------------

int BST::findMinRec(BSTNode *b) {
    if (b->left == nullptr)
        return b->data;
    return findMinRec(b->left);
}

int BST::findMaxRec(BSTNode *b) {
    if (b->right == nullptr)
        return b->data;
    return findMaxRec(b->right);
}

// -------------------------------------------------------
// Public: findMinRec / findMaxRec drivers
// -------------------------------------------------------

int BST::findMinRec() {
    if (root == nullptr) {
        cout << "Tree is empty." << endl;
        return -1;
    }
    return findMinRec(root);
}

int BST::findMaxRec() {
    if (root == nullptr) {
        cout << "Tree is empty." << endl;
        return -1;
    }
    return findMaxRec(root);
}

// -------------------------------------------------------
// Private Helper: createBalancedTreeHelper (recursive)
// Algorithm:
//   1. Find the middle index of the current subarray.
//   2. Make arr[mid] the root of this subtree.
//   3. Recurse on the left half  -> left subtree.
//   4. Recurse on the right half -> right subtree.
// This guarantees a height-balanced BST from a sorted array.
// -------------------------------------------------------

BSTNode* BST::createBalancedTreeHelper(int *arr, int start, int end) {
    if (start > end)
        return nullptr;
    int mid = (start + end) / 2;
    BSTNode *node = new BSTNode();
    node->data  = arr[mid];
    node->left  = createBalancedTreeHelper(arr, start, mid - 1);
    node->right = createBalancedTreeHelper(arr, mid + 1, end);
    return node;
}

// -------------------------------------------------------
// Public: createBalancedTree
// Clears any existing tree first, then builds balanced BST.
// -------------------------------------------------------

void BST::createBalancedTree(int *arr, int start, int end) {
    destroy(root);
    root = createBalancedTreeHelper(arr, start, end);
}
