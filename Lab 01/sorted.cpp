#include <iostream>
#include "sorted.h"
using namespace std;

/* Constructor */
sorted::sorted(int size)
{
    maxSize = size;
    currentSize = 0;
    arr = new int[maxSize];
}

/* Destructor */
sorted::~sorted()
{
    delete[] arr;
}

/* Check if empty */
bool sorted::isEmpty() const
{
    return currentSize == 0;
}

/* Check if full */
bool sorted::isFull() const
{
    return currentSize == maxSize;
}

/* Insert while maintaining sorted order */
bool sorted::insert(int val)
{
    if (isFull())
        return false;

    int i = currentSize - 1;

    while (i >= 0 && arr[i] > val)
    {
        arr[i + 1] = arr[i];
        i--;
    }

    arr[i + 1] = val;
    currentSize++;
    return true;
}

/* Remove element at index (order maintained) */
bool sorted::remove(int index, int &val)
{
    if (index < 0 || index >= currentSize)
        return false;

    val = arr[index];

    for (int i = index; i < currentSize - 1; i++)
        arr[i] = arr[i + 1];

    currentSize--;
    return true;
}

/* Display list */
void sorted::display() const
{
    for (int i = 0; i < currentSize; i++)
        cout << arr[i] << " ";
    cout << endl;
}

/* Replace value at index while keeping sorted order */
bool sorted::replace(int index, int newval)
{
    if (index < 0 || index >= currentSize)
        return false;

    int oldVal;
    remove(index, oldVal);   // remove old value
    insert(newval);          // insert new value correctly
    return true;
}

/* Binary Search */
bool sorted::binarySearch(int val, int &index) const
{
    int low = 0;
    int high = currentSize - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] == val)
        {
            index = mid;
            return true;
        }
        else if (arr[mid] < val)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return false;
}

/* Remove all occurrences of val */
int sorted::removeAll(int val)
{
    int count = 0;
    int i = 0;

    while (i < currentSize)
    {
        if (arr[i] == val)
        {
            for (int j = i; j < currentSize - 1; j++)
                arr[j] = arr[j + 1];

            currentSize--;
            count++;
        }
        else
            i++;
    }
    return count;
}

/* Copy constructor */
sorted::sorted(const sorted &org)
{
    maxSize = org.maxSize;
    currentSize = org.currentSize;
    arr = new int[maxSize];

    for (int i = 0; i < currentSize; i++)
        arr[i] = org.arr[i];
}

/* Assignment operator */
sorted& sorted::operator=(const sorted &rhs)
{
    if (this != &rhs)
    {
        delete[] arr;

        maxSize = rhs.maxSize;
        currentSize = rhs.currentSize;
        arr = new int[maxSize];

        for (int i = 0; i < currentSize; i++)
            arr[i] = rhs.arr[i];
    }
    return *this;
}
