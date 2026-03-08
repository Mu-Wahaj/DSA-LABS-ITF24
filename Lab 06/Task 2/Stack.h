#ifndef STACK_H
#define STACK_H

class Stack {
private:
    double* data;
    int capacity;
    int topIndex;
    
public:
    Stack(int size = 100);
    ~Stack();
    void push(double value);
    double pop();
    double peek() const;
    bool isEmpty() const;
    bool isFull() const;
    int size() const;
};

#endif