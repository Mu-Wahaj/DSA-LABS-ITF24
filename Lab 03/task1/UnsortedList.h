#ifndef TASK_H
#define TASK_H

class UnsortedList
{
public:
    int *arr;
    int maxSize;
    int currentSize;

    UnsortedList(int size);
    ~UnsortedList();
    void display() const;
    bool isEmpty() const;
    bool isFull() const;
    bool insert(int val);
    int getLength() const;
    bool deleteItem(int index, int &val);
    bool deleteItem2(int index, int &val);
    UnsortedList(const UnsortedList &otherList);
    UnsortedList &operator=(const UnsortedList &otherList);
    bool operator==(const UnsortedList &otherList) const;
    int removeAll(int val);
    int removeAll2(int val);
    int removeAll3(int val);
    int removeAll4(int val);
    bool search(int key) const;
    bool getval(int index, int &val) const;
    // LAB 03 TASKS
    UnsortedList intersection(const UnsortedList &list2) const;
    bool isSubset(const UnsortedList &list2) const;
    UnsortedList difference(const UnsortedList& list2) const;
};
#endif