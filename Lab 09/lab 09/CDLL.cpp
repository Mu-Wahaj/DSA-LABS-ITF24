#include "CDLL.h"
#include <iostream>
using namespace std;

CDLL::CDLL()
{
    head.next = &head;
    head.prev = &head;
}

CDLL::~CDLL()
{
    clear();
}

void CDLL::insertAtBeginning(int val)
{
    DNode *temp= new DNode;
    temp->data = val;
    
    DNode *first = head.next;
    
    temp->next = first;
    temp->prev = &head;
    first->prev = temp;
    head.next = temp;
}

bool CDLL::deleteFromBeginning()
{
    if (isEmpty())
    {
        return false;
    }
    
    DNode *toDelete = head.next;
    DNode *newFirst = toDelete->next;
    
    head.next = newFirst;
    newFirst->prev = &head;
    
    delete toDelete;
    return true;
}

void CDLL::insertAtEnd(int val)
{
    DNode *temp= new DNode;
    temp->data = val;
    
    DNode *last = head.prev;
    
    temp->next = &head;
    temp->prev = last;
    last->next = temp;
    head.prev = temp;
}

bool CDLL::isEmpty()
{
    return head.next == &head;
}

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

void CDLL::clear()
{
    while (!isEmpty())
    {
        deleteFromBeginning();
    }
}

int CDLL::count()
{
    if (isEmpty())
    {
        return 0;
    }
    
    DNode *cur = head.next;
    int counter = 0;
    
    while (cur != &head)
    {
        counter++;
        cur = cur->next;
    }
    
    return counter;
}

void CDLL::shuffleMerge(CDLL &list1, CDLL &list2)
{
    list1.clear();
    list2.clear();
    
    if (isEmpty())
    {
        return;
    }
    
    DNode *curr1 = list1.head.next;
    DNode *curr2 = list2.head.next;
    DNode *curr = head.next;
    bool turn = true;
    
    while (curr != &head)
    {
        if (turn)
        {
            list1.insertAtEnd(curr->data);
        }
        else
        {
            list2.insertAtEnd(curr->data);
        }
        turn = !turn;
        curr = curr->next;
    }
}

void CDLL::splitList(CDLL &leftHalf, CDLL &rightHalf)
{
    leftHalf.clear();
    rightHalf.clear();
    
    if (isEmpty())
    {
        return;
    }
    
    int total = count();
    int mid = total / 2;
    
    DNode *curr = head.next;
    int currentPos = 1;
    
    while (curr != &head && currentPos <= mid)
    {
        leftHalf.insertAtEnd(curr->data);
        curr = curr->next;
        currentPos++;
    }
    
    while (curr != &head)
    {
        rightHalf.insertAtEnd(curr->data);
        curr = curr->next;
    }
}

bool CDLL::isSorted()
{
    if (isEmpty() || count() == 1)
    {
        return true;
    }
    
    DNode *curr = head.next;
    
    while (curr->next != &head)
    {
        if (curr->data > curr->next->data)
        {
            return false;
        }
        curr = curr->next;
    }
    
    return true;
}

bool CDLL::removeLastNode(int &val)
{
    if (isEmpty())
    {
        return false;
    }
    
    DNode *toDelete = head.prev;
    val = toDelete->data;
    DNode *newLast = toDelete->prev;
    
    newLast->next = &head;
    head.prev = newLast;
    
    delete toDelete;
    return true;
}

bool CDLL::removeSecondLastNode(int &val)
{
    if (count() < 2)
    {
        return false;
    }
    
    DNode *last = head.prev;
    DNode *secondLast = last->prev;
    val = secondLast->data;
    
    secondLast->prev->next = last;
    last->prev = secondLast->prev;
    
    delete secondLast;
    return true;
}

bool CDLL::removeKthNode(int k, int &val)
{
    if (k < 1 || k > count())
    {
        return false;
    }
    
    DNode *curr = head.next;
    
    for (int i = 1; i < k; i++)
    {
        curr = curr->next;
    }
    
    val = curr->data;
    
    curr->prev->next = curr->next;
    curr->next->prev = curr->prev;
    
    delete curr;
    return true;
}