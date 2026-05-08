// Muhammad Wahaj
// BITF24M059
// BST.h - Integer Binary Search Tree Header

#ifndef BST_H
#define BST_H

class BSTNode {
    friend class BST;
private:
    int data;
    BSTNode *left, *right;
};

class BST {
private:
    BSTNode *root;

    int getHeight(BSTNode *b);
    int countNodes(BSTNode *b);
    bool recSearch(BSTNode *b, int key);
    int findMinRec(BSTNode *b);
    int findMaxRec(BSTNode *b);
    void preOrder(BSTNode *b);
    void inOrder(BSTNode *b);
    void postOrder(BSTNode *b);
    void destroy(BSTNode *b);
    BSTNode* removeHelper(BSTNode *b, int val, bool &removed);
    BSTNode* createBalancedTreeHelper(int *arr, int start, int end);

public:
    BST();
    ~BST();

    bool search(int val);
    bool insert(int val);
    bool remove(int val);
    void preOrder();
    void inOrder();
    void postOrder();
    int getHeight();
    int countNodes();
    bool recSearch(int key);
    int findMin();
    int findMax();
    int findMinRec();
    int findMaxRec();
    void createBalancedTree(int *arr, int start, int end);
};

#endif
