// Muhammad Wahaj
// BITF24M059
// StudentBST.cpp - Student Binary Search Tree Implementation

#include "StudentBST.h"
#include <iostream>
using namespace std;

// -------------------------------------------------------
// Constructor & Destructor
// -------------------------------------------------------

StudentBST::StudentBST() {
    root = nullptr;
}

StudentBST::~StudentBST() {
    destroy(root);
}

// -------------------------------------------------------
// Private Helper: destroy (post-order deletion)
// Visits left and right subtrees before deleting the node
// itself, so no dangling pointers are left behind.
// -------------------------------------------------------

void StudentBST::destroy(StudentNode *s) {
    if (s == nullptr)
        return;
    destroy(s->left);
    destroy(s->right);
    delete s;
}

// -------------------------------------------------------
// Public: insert
// BST ordering is based on rollNo (must be unique).
// Iterates to find the correct position without recursion.
// Returns false without modifying the tree if rollNo exists.
// Does NOT print anything (as required by the lab sheet).
// -------------------------------------------------------

bool StudentBST::insert(int rn, string n, double c) {
    StudentNode *curr   = root;
    StudentNode *parent = nullptr;

    while (curr != nullptr) {
        if (curr->rollNo == rn)
            return false;
        parent = curr;
        if (rn < curr->rollNo)
            curr = curr->left;
        else
            curr = curr->right;
    }

    StudentNode *newNode = new StudentNode();
    newNode->rollNo = rn;
    newNode->name   = n;
    newNode->cgpa   = c;
    newNode->left   = nullptr;
    newNode->right  = nullptr;

    if (parent == nullptr) {
        root = newNode;
    } else if (rn < parent->rollNo) {
        parent->left = newNode;
    } else {
        parent->right = newNode;
    }

    return true;
}

// -------------------------------------------------------
// Public: search
// Iterative search by rollNo.
// Prints full student details if found, error if not found.
// -------------------------------------------------------

bool StudentBST::search(int rn) {
    StudentNode *curr = root;
    while (curr != nullptr) {
        if (curr->rollNo == rn) {
            cout << "Student found!" << endl;
            cout << "Roll No : " << curr->rollNo << endl;
            cout << "Name    : " << curr->name   << endl;
            cout << "CGPA    : " << curr->cgpa   << endl;
            return true;
        }
        if (rn < curr->rollNo)
            curr = curr->left;
        else
            curr = curr->right;
    }
    cout << "Student with roll number " << rn << " not found." << endl;
    return false;
}

// -------------------------------------------------------
// Private Helper: inOrder (recursive)
// Left -> Root -> Right gives ascending rollNo order
// because BST ordering is based on rollNo.
// -------------------------------------------------------

void StudentBST::inOrder(StudentNode *s) {
    if (s == nullptr)
        return;
    inOrder(s->left);
    cout << "Roll No : " << s->rollNo
         << "  |  Name : " << s->name
         << "  |  CGPA : " << s->cgpa << endl;
    inOrder(s->right);
}

// -------------------------------------------------------
// Public: inOrder driver
// -------------------------------------------------------

void StudentBST::inOrder() {
    if (root == nullptr) {
        cout << "No students in the tree." << endl;
        return;
    }
    cout << "\n--- Student List (Sorted by Roll No.) ---" << endl;
    inOrder(root);
}

// -------------------------------------------------------
// Private Helper: removeHelper (recursive)
// Three deletion cases:
//   Case 1 - node has no children     -> delete and return nullptr
//   Case 2 - node has one child       -> replace node with that child
//   Case 3 - node has two children    -> copy in-order successor
//             data into this node, then delete the successor
//             from the right subtree
// Does NOT print anything (as required by the lab sheet).
// -------------------------------------------------------

StudentNode* StudentBST::removeHelper(StudentNode *s, int rn, bool &removed) {
    if (s == nullptr) {
        removed = false;
        return nullptr;
    }

    if (rn < s->rollNo) {
        s->left = removeHelper(s->left, rn, removed);

    } else if (rn > s->rollNo) {
        s->right = removeHelper(s->right, rn, removed);

    } else {
        removed = true;

        if (s->left == nullptr && s->right == nullptr) {
            delete s;
            return nullptr;

        } else if (s->left == nullptr) {
            StudentNode *temp = s->right;
            delete s;
            return temp;

        } else if (s->right == nullptr) {
            StudentNode *temp = s->left;
            delete s;
            return temp;

        } else {
            StudentNode *successor = s->right;
            while (successor->left != nullptr)
                successor = successor->left;

            s->rollNo = successor->rollNo;
            s->name   = successor->name;
            s->cgpa   = successor->cgpa;

            bool dummy = true;
            s->right = removeHelper(s->right, successor->rollNo, dummy);
        }
    }
    return s;
}

// -------------------------------------------------------
// Public: remove driver
// -------------------------------------------------------

bool StudentBST::remove(int rn) {
    bool removed = true;
    root = removeHelper(root, rn, removed);
    return removed;
}

// -------------------------------------------------------
// Private Helper: displayInRange (recursive)
// Efficiency trick:
//   - If current node's rollNo > rollNoStart, there may
//     still be valid nodes in the LEFT subtree, so recurse left.
//   - Print this node only if it falls inside [start, end].
//   - If current node's rollNo < rollNoEnd, there may still
//     be valid nodes in the RIGHT subtree, so recurse right.
// This prunes unnecessary branches and avoids a full traversal.
// -------------------------------------------------------

void StudentBST::displayInRange(StudentNode *s, int rollNoStart, int rollNoEnd) {
    if (s == nullptr)
        return;
    if (s->rollNo > rollNoStart)
        displayInRange(s->left, rollNoStart, rollNoEnd);
    if (s->rollNo >= rollNoStart && s->rollNo <= rollNoEnd)
        cout << "Roll No : " << s->rollNo
             << "  |  Name : " << s->name
             << "  |  CGPA : " << s->cgpa << endl;
    if (s->rollNo < rollNoEnd)
        displayInRange(s->right, rollNoStart, rollNoEnd);
}

// -------------------------------------------------------
// Public: displayInRange driver
// -------------------------------------------------------

void StudentBST::displayInRange(int rollNoStart, int rollNoEnd) {
    cout << "\n--- Students with Roll No. "
         << rollNoStart << " to " << rollNoEnd << " ---" << endl;
    displayInRange(root, rollNoStart, rollNoEnd);
}
