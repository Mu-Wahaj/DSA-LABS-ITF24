#include "CDLL.h"
#include <iostream>
using namespace std;

// Constructor
CDLL::CDLL()
{
    head.next = &head;
    head.prev = &head;
}

// Destructor
CDLL::~CDLL()
{
    clear();
}

// Clear list
void CDLL::clear()
{
    DNode *cur = head.next;
    while (cur != &head)
    {
        DNode *nextNode = cur->next;
        delete cur;
        cur = nextNode;
    }

    head.next = &head;
    head.prev = &head;
}

// Sorted Insert
bool CDLL::sorted_Insert(int val)
{
    DNode *newNode = new DNode;
    newNode->data = val;

    DNode *curr = head.next;

    // Find insertion position
    while (curr != &head && curr->data < val)
    {
        curr = curr->next;
    }

    // Insert before curr
    newNode->next = curr;
    newNode->prev = curr->prev;
    curr->prev->next = newNode;
    curr->prev = newNode;

    return true;
}

bool CDLL::isSorted() const
{
    if (head.next == &head || head.next->next == &head)
        return true;

    DNode *cur = head.next;
    while (cur->next != &head)
    {
        if (cur->data > cur->next->data)
            return false;
        cur = cur->next;
    }

    return true;
}

// Task 1.2 - Split list into two halves
void CDLL::splitList(CDLL &leftHalf, CDLL &rightHalf)
{
    // Clear the output lists
    leftHalf.clear();
    rightHalf.clear();

    if (isEmpty())
        return;

    int total = count();
    int leftSize = (total + 1) / 2;  // Extra element goes to left half

    // Find the last node of left half
    DNode *leftLast = head.next;
    for (int i = 1; i < leftSize; ++i)
        leftLast = leftLast->next;

    DNode *leftFirst = head.next;
    DNode *rightFirst = leftLast->next;
    DNode *rightLast = head.prev;

    // Setup leftHalf
    leftHalf.head.next = leftFirst;
    leftHalf.head.prev = leftLast;
    leftFirst->prev = &leftHalf.head;
    leftLast->next = &leftHalf.head;

    // Setup rightHalf (if it exists)
    if (rightFirst != &head)
    {
        rightHalf.head.next = rightFirst;
        rightHalf.head.prev = rightLast;
        rightFirst->prev = &rightHalf.head;
        rightLast->next = &rightHalf.head;
    }

    // Make current list empty
    head.next = &head;
    head.prev = &head;
}

// Task 1.3 - Merge two sorted lists into this (this must be empty)
bool CDLL::merge(CDLL &list1, CDLL &list2)
{
    // This list must be empty
    if (!isEmpty())
        return false;

    // Both lists must be sorted
    if (!list1.isSorted() || !list2.isSorted())
        return false;

    // If both are empty, nothing to do
    if (list1.isEmpty() && list2.isEmpty())
        return true;

    DNode *p = list1.head.next;
    DNode *q = list2.head.next;
    DNode *tail = &head;

    // Merge while both lists have nodes
    while (p != &list1.head && q != &list2.head)
    {
        if (p->data <= q->data)
        {
            DNode *nextP = p->next;
            tail->next = p;
            p->prev = tail;
            tail = p;
            p = nextP;
        }
        else
        {
            DNode *nextQ = q->next;
            tail->next = q;
            q->prev = tail;
            tail = q;
            q = nextQ;
        }
    }

    // Append remaining nodes from list1
    while (p != &list1.head)
    {
        DNode *nextP = p->next;
        tail->next = p;
        p->prev = tail;
        tail = p;
        p = nextP;
    }

    // Append remaining nodes from list2
    while (q != &list2.head)
    {
        DNode *nextQ = q->next;
        tail->next = q;
        q->prev = tail;
        tail = q;
        q = nextQ;
    }

    // Complete the circle
    tail->next = &head;
    head.prev = tail;

    // Empty list1 and list2
    list1.head.next = &list1.head;
    list1.head.prev = &list1.head;
    list2.head.next = &list2.head;
    list2.head.prev = &list2.head;

    return true;
}

// Task 1.4 - Recursive Merge Sort
void CDLL::mergeSort()
{
    if (isEmpty() || head.next->next == &head)
        return;  // Empty or single node is already sorted

    CDLL left;
    CDLL right;
    splitList(left, right);
    
    left.mergeSort();
    right.mergeSort();
    
    // Merge the sorted halves into this list
    merge(left, right);
}

// Task 1.5 - Insertion Sort (modifying links only)
void CDLL::insertionSort()
{
    if (isEmpty() || head.next->next == &head)
        return;  // Empty or single node is already sorted

    // Create a new empty list for the sorted result
    CDLL sorted;
    
    while (!isEmpty())
    {
        // Remove first node from original list
        DNode *current = head.next;
        
        // Remove current from original list
        head.next = current->next;
        current->next->prev = &head;
        
        // Insert current into sorted list at correct position
        DNode *pos = sorted.head.next;
        while (pos != &sorted.head && pos->data < current->data)
        {
            pos = pos->next;
        }
        
        // Insert before pos
        current->next = pos;
        current->prev = pos->prev;
        pos->prev->next = current;
        pos->prev = current;
    }
    
    // Move the sorted list back to this
    if (!sorted.isEmpty())
    {
        head.next = sorted.head.next;
        head.prev = sorted.head.prev;
        head.next->prev = &head;
        head.prev->next = &head;
        
        sorted.head.next = &sorted.head;
        sorted.head.prev = &sorted.head;
    }
}

// Insert at beginning
void CDLL::insertAtBeginning(int val)
{
    DNode *newNode = new DNode;
    newNode->data = val;

    DNode *first = head.next;

    newNode->next = first;
    newNode->prev = &head;
    first->prev = newNode;
    head.next = newNode;
}

// Insert at end
void CDLL::insertAtEnd(int val)
{
    DNode *newNode = new DNode;
    newNode->data = val;

    DNode *last = head.prev;

    newNode->next = &head;
    newNode->prev = last;
    last->next = newNode;
    head.prev = newNode;
}

// Insert at position (1-based index)
bool CDLL::insertAtPosition(int position, int val)
{
    if (position < 1)
        return false;

    if (position == 1)
    {
        insertAtBeginning(val);
        return true;
    }

    DNode *curr = head.next;
    int index = 1;
    
    while (curr != &head && index < position - 1)
    {
        curr = curr->next;
        index++;
    }

    if (curr == &head)
        return false;  // Position out of range

    DNode *newNode = new DNode;
    newNode->data = val;
    
    newNode->next = curr->next;
    newNode->prev = curr;
    curr->next->prev = newNode;
    curr->next = newNode;
    
    return true;
}

// Reverse the list
void CDLL::reverse()
{
    if (isEmpty() || head.next->next == &head)
        return;

    DNode *curr = head.next;
    DNode *temp = nullptr;
    
    do
    {
        temp = curr->next;
        curr->next = curr->prev;
        curr->prev = temp;
        curr = temp;
    } while (curr != &head);
    
    // Adjust head pointers
    temp = head.next;
    head.next = head.prev;
    head.prev = temp;
}

// Count nodes
int CDLL::count()
{
    if (isEmpty())
        return 0;

    DNode *cur = head.next;
    int counter = 0;

    while (cur != &head)
    {
        counter++;
        cur = cur->next;
    }

    return counter;
}

// Check if empty
bool CDLL::isEmpty()
{
    return head.next == &head;
}

// Display forward
void CDLL::display()
{
    if (isEmpty())
    {
        cout << "List is empty" << endl;
        return;
    }

    DNode *cur = head.next;
    while (cur != &head)
    {
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << endl;
}

// Display backward
void CDLL::displayBackward()
{
    if (isEmpty())
    {
        cout << "List is empty" << endl;
        return;
    }

    DNode *cur = head.prev;
    while (cur != &head)
    {
        cout << cur->data << " ";
        cur = cur->prev;
    }
    cout << endl;
}

// Display circular (shows that it loops back)
void CDLL::displayCircular()
{
    if (isEmpty())
    {
        cout << "List is empty" << endl;
        return;
    }

    DNode *cur = head.next;
    cout << "HEAD <-> ";
    while (cur != &head)
    {
        cout << cur->data << " <-> ";
        cur = cur->next;
    }
    cout << "HEAD (circular)" << endl;
}

// Merge another sorted CDLL into this list (overload for merging into existing)
bool CDLL::merge(CDLL &other)
{
    if (other.isEmpty())
        return false;

    if (isEmpty())
    {
        // Transfer all nodes from other to this
        head.next = other.head.next;
        head.prev = other.head.prev;
        head.next->prev = &head;
        head.prev->next = &head;

        other.head.next = &other.head;
        other.head.prev = &other.head;
        return true;
    }

    // Merge two non-empty sorted lists
    if (!isSorted() || !other.isSorted())
        return false;

    CDLL temp;
    if (!temp.merge(*this, other))
        return false;
    
    // Transfer temp to this
    clear();
    head.next = temp.head.next;
    head.prev = temp.head.prev;
    head.next->prev = &head;
    head.prev->next = &head;
    
    temp.head.next = &temp.head;
    temp.head.prev = &temp.head;
    
    return true;
}