#ifndef _H
#define _H
class  sorted
{
private:
 int *arr ; 
 int msxSze;

public:
    int *arr;
    int maxSize;
    int currentSize;

    sorted(int size);
    ~sorted();
    void display() const;
    bool isEmpty() const;
    bool isFull() const;
    bool insert(int val);
    int getLength() const;
    bool deleteItem(int index, int &val);
    bool deleteItem2(int index, int &val);
    // homework functions
    sorted(const sorted &otherList);
    sorted &operator=(const sorted &otherList);
    bool operator==(const sorted &otherList) const;
    bool operator==(const sorted &otherList) const;
    int removeAll(int val);
    int removeAll2(int val);
    int removeAll3(int val);
    int removeAll4(int val);
    bool search(int val,int &index)const;
    bool binarySearch(int val,int &index)const;


    // lab 03 tasks
    sorted intersection(const sorted &list2) const;
    bool isSubset(const sorted &list2) const;
};
#endif
