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
    DNode head; // dummy header

public:
    CDLL();
    ~CDLL();

    // Sorted insert
    bool sorted_Insert(int val);

    // Basic Operations
    void insertAtBeginning(int val);
    void insertAtEnd(int val);
    bool insertAtPosition(int position, int val);

    // Delete Operations
    bool deleteFromBeginning();
    bool deleteFromEnd();
    bool deleteFromPosition(int position);
    bool deleteValue(int val);

    // Search and Access
    bool search(int val);
    int getAtPosition(int position);
    bool isEmpty();

    // Display Operations
    void display();
    void displayBackward();
    void displayCircular();

    // Rule of Three
    CDLL(const CDLL &other);
    CDLL &operator=(const CDLL &other);

    // Additional Functions
    void split(CDLL &list1, CDLL &list2, int position);                                       // Split into two lists
    void splitList(CDLLD &leftHalf, CDLLD &rightHalf) void combine(CDLL &list1, CDLL &list2); // Combine two lists into current

    // Utility Operations
    void clear();
    void reverse();
    int count();
};

#endif