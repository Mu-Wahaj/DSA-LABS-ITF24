#ifndef DEQUE_H
#define DEQUE_H

class Deque {
private:
    int* arr;
    int capacity;
    int front;
    int back;
    int count;

public:
    Deque(int n);
    ~Deque();
    
    bool isEmpty();
    bool isFull();
    void display();
    void makeEmpty();
    
    bool insertAtFront(int val);
    bool insertAtBack(int val);
    bool removeFromFront(int& val);
    bool removeFromBack(int& val);
};

#endif