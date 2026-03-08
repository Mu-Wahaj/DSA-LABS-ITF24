#include "Stack.h"
#include <iostream>
using namespace std;

Stack::Stack(int size) {
    capacity = size;
    data = new double[capacity];
    topIndex = -1;
}

Stack::~Stack() {
    delete[] data;
}

void Stack::push(double value) {
    if (isFull()) {
        cout << "Stack overflow!" << endl;
        return;
    }
    data[++topIndex] = value;
}

double Stack::pop() {
    if (isEmpty()) {
        cout << "Stack underflow!" << endl;
        return 0;
    }
    return data[topIndex--];
}

double Stack::peek() const {
    if (isEmpty()) {
        cout << "Stack is empty!" << endl;
        return 0;
    }
    return data[topIndex];
}

bool Stack::isEmpty() const {
    return topIndex == -1;
}

bool Stack::isFull() const {
    return topIndex == capacity - 1;
}

int Stack::size() const {
    return topIndex + 1;
}