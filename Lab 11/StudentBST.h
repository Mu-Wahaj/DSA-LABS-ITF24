// Muhammad Wahaj
// BITF24M059
// StudentBST.h - Student Binary Search Tree Header

#ifndef STUDENTBST_H
#define STUDENTBST_H

#include <string>
using namespace std;

class StudentBST;

class StudentNode {
    friend class StudentBST;
private:
    int rollNo;
    string name;
    double cgpa;
    StudentNode *left;
    StudentNode *right;
};

class StudentBST {
private:
    StudentNode *root;

    void inOrder(StudentNode *s);
    void destroy(StudentNode *s);
    StudentNode* removeHelper(StudentNode *s, int rn, bool &removed);
    void displayInRange(StudentNode *s, int rollNoStart, int rollNoEnd);

public:
    StudentBST();
    ~StudentBST();

    bool insert(int rn, string n, double c);
    bool search(int rn);
    void inOrder();
    bool remove(int rn);
    void displayInRange(int rollNoStart, int rollNoEnd);
};

#endif
