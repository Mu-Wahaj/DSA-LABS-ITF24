#ifndef STACK_H
#define STACK_H

class Stack
{
private:
    int maxSize;
    int currentSize;
    int topIndex;
    int *st;

public:
    Stack(int size);
    ~Stack();

    bool isEmpty() const;
    bool isFull() const;

    void push(int value);
    int pop();
    int top() const;

    void clear();
};

#endif