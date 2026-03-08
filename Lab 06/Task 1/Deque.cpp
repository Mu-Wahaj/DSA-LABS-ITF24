#include "Deque.h"
#include <iostream>
using namespace std;

Deque::Deque(int n) {
    arr = new int[n];
    capacity = n;
    front = -1;
    back = -1;
    count = 0;
}

Deque::~Deque() {
    delete[] arr;
}

bool Deque::isEmpty() {
    return count == 0;
}

bool Deque::isFull() {
    return count == capacity;
}

void Deque::display() {
    if (isEmpty()) {
        cout << "Deque is empty" << endl;
        return;
    }
    
    int index = front;
    for (int i = 0; i < count; i++) {
        cout << arr[index] << " ";
        index = (index + 1) % capacity;
    }
    cout << endl;
}

void Deque::makeEmpty() {
    front = -1;
    back = -1;
    count = 0;
}

bool Deque::insertAtFront(int val) {
    if (isFull()) {
        return false;
    }
    
    if (isEmpty()) {
        front = 0;
        back = 0;
    } else {
        front = (front - 1 + capacity) % capacity;
    }
    
    arr[front] = val;
    count++;
    return true;
}

bool Deque::insertAtBack(int val) {
    if (isFull()) {
        return false;
    }
    
    if (isEmpty()) {
        front = 0;
        back = 0;
    } else {
        back = (back + 1) % capacity;
    }
    
    arr[back] = val;
    count++;
    return true;
}

bool Deque::removeFromFront(int& val) {
    if (isEmpty()) {
        return false;
    }
    
    val = arr[front];
    
    if (count == 1) {
        front = -1;
        back = -1;
    } else {
        front = (front + 1) % capacity;
    }
    
    count--;
    return true;
}

bool Deque::removeFromBack(int& val) {
    if (isEmpty()) {
        return false;
    }
    
    val = arr[back];
    
    if (count == 1) {
        front = -1;
        back = -1;
    } else {
        back = (back - 1 + capacity) % capacity;
    }
    
    count--;
    return true;
}