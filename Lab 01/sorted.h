#ifndef SORTED_H
#define SORTED_H

class sorted
{
private:
    int *arr;
    int maxSize;
    int currentSize;

public:
    sorted(int size);

    ~sorted();
    bool isEmpty() const;
    bool isFull() const;
    bool insert(int val);
    bool remove(int index, int &val);
    void display() const;
    bool replace(int index,int newwal);
    bool binarySearch(int val,int &index)const;
    int  removeAll(int val);
    sorted(const sorted &org);
    sorted &operator=(const sorted &rhs);

};

#endif
