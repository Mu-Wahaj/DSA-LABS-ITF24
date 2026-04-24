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

// ==================== RULE OF THREE ====================

// Copy Constructor
CDLL::CDLL(const CDLL& other)
{
    head.next = &head;
    head.prev = &head;
    
    DNode *cuv = other.head.next;
    while (cuv != &other.head)
    {
        this->insertAtEnd(cuv->data);
        cuv = cuv->next;
    }
}

// Assignment Operator
CDLL& CDLL::operator=(const CDLL& other)
{
    if (this == &other)
    {
        return *this;
    }
    
    this->clear();
    
    DNode *cuv = other.head.next;
    while (cuv != &other.head)
    {
        this->insertAtEnd(cuv->data);
        cuv = cuv->next;
    }
    
    return *this;
}

// ==================== SPLIT FUNCTION ====================
// Splits current list into list1 and list2 at given position
// list1 gets nodes from position 1 to position-1
// list2 gets nodes from position to end
void CDLL::split(CDLL& list1, CDLL& list2, int position)
{
    // Clear both lists first
    list1.clear();
    list2.clear();
    
    if (position < 1 || isEmpty())
    {
        cout << "Invalid split position!" << endl;
        return;
    }
    
    // Find the node at given position
    DNode *cuv = head.next;
    int currentPos = 1;
    
    while (cuv != &head && currentPos < position)
    {
        list1.insertAtEnd(cuv->data);  // Add to first list
        cuv = cuv->next;
        currentPos++;
    }
    
    // Add remaining nodes to second list
    while (cuv != &head)
    {
        list2.insertAtEnd(cuv->data);
        cuv = cuv->next;
    }
}

// ==================== SHUFFLE FUNCTION (Zigzag) ====================
// Shuffles current list into list1 and list2 in zigzag pattern
// Example: Current: 1,2,3,4,5,6
// Result: list1: 1,3,5  list2: 2,4,6
void CDLL::shuffle(CDLL& list1, CDLL& list2)
{
    // Clear both lists
    list1.clear();
    list2.clear();
    
    if (isEmpty())
        return;
    
    DNode *cuv = head.next;
    bool turn = true;  // true for list1, false for list2
    
    while (cuv != &head)
    {
        if (turn)
        {
            list1.insertAtEnd(cuv->data);
        }
        else
        {
            list2.insertAtEnd(cuv->data);
        }
        turn = !turn;  // Alternate
        cuv = cuv->next;
    }
}

// ==================== COMBINE FUNCTION ====================
// Combines list1 and list2 into current list (this)
// Order: first all of list1, then all of list2
void CDLL::combine(CDLL& list1, CDLL& list2)
{
    // Clear current list first
    this->clear();
    
    // Add all nodes from list1
    DNode *cuv = list1.head.next;
    while (cuv != &list1.head)
    {
        this->insertAtEnd(cuv->data);
        cuv = cuv->next;
    }
    
    // Add all nodes from list2
    cuv = list2.head.next;
    while (cuv != &list2.head)
    {
        this->insertAtEnd(cuv->data);
        cuv = cuv->next;
    }
}

// ==================== SORTED INSERT ====================
bool CDLL::sorted_Insert(int val)
{
    DNode *kup = new DNode;
    kup->data = val;
    
    DNode *cuv = head.next;
    
    while (cuv != &head && cuv->data < val)
    {
        cuv = cuv->next;
    }
    
    kup->next = cuv;
    kup->prev = cuv->prev;
    cuv->prev->next = kup;
    cuv->prev = kup;
    
    return true;
}

// ==================== BASIC OPERATIONS ====================

void CDLL::insertAtBeginning(int val)
{
    DNode *kup = new DNode;
    kup->data = val;
    
    DNode *first = head.next;
    
    kup->next = first;
    kup->prev = &head;
    first->prev = kup;
    head.next = kup;
}

void CDLL::insertAtEnd(int val)
{
    DNode *kup = new DNode;
    kup->data = val;
    
    DNode *last = head.prev;
    
    kup->next = &head;
    kup->prev = last;
    last->next = kup;
    head.prev = kup;
}

bool CDLL::insertAtPosition(int position, int val)
{
    if (position < 1)
    {
        cout << "Invalid position!" << endl;
        return false;
    }
    
    if (position == 1)
    {
        insertAtBeginning(val);
        return true;
    }
    
    DNode *cuv = head.next;
    int currentPos = 1;
    
    while (cuv != &head && currentPos < position)
    {
        cuv = cuv->next;
        currentPos++;
    }
    
    if (cuv == &head)
    {
        cout << "Position out of range!" << endl;
        return false;
    }
    
    DNode *kup = new DNode;
    kup->data = val;
    
    kup->next = cuv;
    kup->prev = cuv->prev;
    cuv->prev->next = kup;
    cuv->prev = kup;
    
    return true;
}

// ==================== DELETE OPERATIONS ====================

bool CDLL::deleteFromBeginning()
{
    if (isEmpty())
    {
        cout << "List is empty!" << endl;
        return false;
    }
    
    DNode *toDelete = head.next;
    DNode *newFirst = toDelete->next;
    
    head.next = newFirst;
    newFirst->prev = &head;
    
    delete toDelete;
    return true;
}

bool CDLL::deleteFromEnd()
{
    if (isEmpty())
    {
        cout << "List is empty!" << endl;
        return false;
    }
    
    DNode *toDelete = head.prev;
    DNode *newLast = toDelete->prev;
    
    newLast->next = &head;
    head.prev = newLast;
    
    delete toDelete;
    return true;
}

bool CDLL::deleteFromPosition(int position)
{
    if (isEmpty() || position < 1)
    {
        cout << "Invalid operation!" << endl;
        return false;
    }
    
    DNode *cuv = head.next;
    int currentPos = 1;
    
    while (cuv != &head && currentPos < position)
    {
        cuv = cuv->next;
        currentPos++;
    }
    
    if (cuv == &head)
    {
        cout << "Position not found!" << endl;
        return false;
    }
    
    cuv->prev->next = cuv->next;
    cuv->next->prev = cuv->prev;
    
    delete cuv;
    return true;
}

bool CDLL::deleteValue(int val)
{
    if (isEmpty())
    {
        cout << "List is empty!" << endl;
        return false;
    }
    
    DNode *cuv = head.next;
    
    while (cuv != &head)
    {
        if (cuv->data == val)
        {
            cuv->prev->next = cuv->next;
            cuv->next->prev = cuv->prev;
            delete cuv;
            return true;
        }
        cuv = cuv->next;
    }
    
    cout << "Value " << val << " not found!" << endl;
    return false;
}

// ==================== SEARCH AND ACCESS ====================

bool CDLL::search(int val)
{
    if (isEmpty())
        return false;
    
    DNode *cuv = head.next;
    
    while (cuv != &head)
    {
        if (cuv->data == val)
            return true;
        cuv = cuv->next;
    }
    
    return false;
}

int CDLL::getAtPosition(int position)
{
    if (position < 1 || isEmpty())
    {
        cout << "Invalid position!" << endl;
        return -1;
    }
    
    DNode *cuv = head.next;
    int currentPos = 1;
    
    while (cuv != &head && currentPos < position)
    {
        cuv = cuv->next;
        currentPos++;
    }
    
    if (cuv == &head)
    {
        cout << "Position out of range!" << endl;
        return -1;
    }
    
    return cuv->data;
}

bool CDLL::isEmpty()
{
    return head.next == &head;
}

// ==================== DISPLAY OPERATIONS ====================

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

void CDLL::displayCircular()
{
    if (isEmpty())
    {
        cout << "List is empty" << endl;
        return;
    }
    
    DNode *cur = head.next;
    cout << "Circular (2 cycles): ";
    
    int count = 0;
    int totalNodes = this->count();
    
    while (count < totalNodes * 2)
    {
        cout << cur->data << " ";
        cur = cur->next;
        if (cur == &head)
            cur = cur->next;
        count++;
    }
    cout << endl;
}

// ==================== UTILITY OPERATIONS ====================

void CDLL::clear()
{
    while (!isEmpty())
    {
        deleteFromBeginning();
    }
}

void CDLL::reverse()
{
    if (isEmpty())
        return;
    
    DNode *cur = head.next;
    DNode *temp = nullptr;
    
    while (cur != &head)
    {
        temp = cur->prev;
        cur->prev = cur->next;
        cur->next = temp;
        cur = cur->prev;
    }
    
    temp = head.next;
    head.next = head.prev;
    head.prev = temp;
}

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