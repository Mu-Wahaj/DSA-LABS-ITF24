#ifndef TASK_H
#define TASK_H

class unsorted
{
public:
    int *arr;
    int maxSize;
    int currentSize;

    unsorted(int size);
    ~unsorted();
    bool isFull() const;
    bool isEmpty() const;
    bool insert(int val);
    bool remove(int index, int &val);
    void display() const;
    bool removeMax(int &maxVal);
    void reverse();
    void combine(const unsorted &rhs);
    int replaceVal(int oldVal,int newVal);
    int removeLastAcuucrence(int Val);
    int removeAll(int val);
    unsorted(const unsorted &otherList);
    unsorted &operator=(const unsorted &otherList);
  
};
#endif