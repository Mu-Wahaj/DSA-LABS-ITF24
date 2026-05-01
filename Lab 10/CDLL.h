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
    bool isSorted() const;

public:
    CDLL();
    ~CDLL();

    // Sorted insert
    bool sorted_Insert(int val);

    // Basic Operations
    void insertAtBeginning(int val);
    void insertAtEnd(int val);
    bool insertAtPosition(int position, int val);
    void clear();
    int count();
    void splitList(CDLL &leftHalf, CDLL &rightHalf);
    bool merge(CDLL &other);                    // Merge another sorted list into this
    bool merge(CDLL &list1, CDLL &list2);       // Merge two sorted lists into this (Task 1.3)
    void mergeSort();                           // Task 1.4
    void insertionSort();                       // Task 1.5
    void reverse();

    bool isEmpty();

    // Display Operations
    void display();
    void displayBackward();
    void displayCircular();
};

#endif