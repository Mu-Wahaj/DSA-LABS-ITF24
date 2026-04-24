
#ifndef CDLL_H
#define CDLL_H

#include <iostream>
    using namespace std;

class DNode
{
    friend class CDLL;

private:
    int data;
    DNode *next, *prev;
};

class CDLL
{
private:
    DNode head;

public:
    CDLL();
    ~CDLL();
    void insertAtBeginning(int val);
    bool deleteFromBeginning();
    void insertAtEnd(int val);
    bool isEmpty();
    void display();
    void clear();
    int count();

    // task 1.1
    void shuffleMerge(CDLL &list1, CDLL &list2);
    // task 1.2
    void splitList(CDLL &leftHalf, CDLL &rightHalf);

    // task 1.3
    bool isSorted();

    // 1.4
    bool removeLastNode(int &val);
    bool removeSecondLastNode(int &val);
    bool removeKthNode(int k, int &val);
   
};

#endif