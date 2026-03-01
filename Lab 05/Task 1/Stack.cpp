#include <iostream>
#include "Stack.h"

using namespace std;

Stack::Stack(int size)
{
    maxSize = size;
    currentSize = 0;
    topIndex = -1;
    st = new int[maxSize];
}

Stack::~Stack()
{
    delete[] st;
}

bool Stack::isEmpty() const
{
    return currentSize == 0;
}

bool Stack::isFull() const
{
    return currentSize == maxSize;
}

void Stack::push(int value)
{
    if (!isFull())
    {
        topIndex++;
        st[topIndex] = value;
        currentSize++;
    }
}

int Stack::pop()
{
    if (!isEmpty())
    {
        int value = st[topIndex];
        topIndex--;
        currentSize--;
        return value;
    }
    return 0;
}

int Stack::top() const
{
    if (!isEmpty())
    {
        return st[topIndex];
    }
    return 0;
}

void Stack::clear()
{
    topIndex = -1;
    currentSize = 0;
}