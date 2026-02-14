#include <iostream>
#include "unsorted.h"
using namespace std;

/* Constructor */
unsorted::unsorted(int size)
{
    maxSize = size;
    currentSize = 0;
    arr = new int[maxSize];
}

/* Destructor */
unsorted::~unsorted()
{
    delete[] arr;
}

/* Check if full */
bool unsorted::isFull() const
{
    return currentSize == maxSize;
}

/* Check if empty */
bool unsorted::isEmpty() const
{
    return currentSize == 0;
}

/* Insert at end */
bool unsorted::insert(int val)
{
    if (isFull())
        return false;

    arr[currentSize++] = val;
    return true;
}

/* Remove element at index (overwrite method) */
bool unsorted::remove(int index, int &val)
{
    if (index < 0 || index >= currentSize)
        return false;

    val = arr[index];
    arr[index] = arr[currentSize - 1];
    currentSize--;
    return true;
}

/* Display list */
void unsorted::display() const
{
    for (int i = 0; i < currentSize; i++)
        cout << arr[i] << " ";
    cout << endl;
}

/* Remove maximum element */
bool unsorted::removeMax(int &maxVal)
{
    if (isEmpty())
        return false;

    int maxIndex = 0;
    for (int i = 1; i < currentSize; i++)
    {
        if (arr[i] > arr[maxIndex])
            maxIndex = i;
    }

    maxVal = arr[maxIndex];
    arr[maxIndex] = arr[currentSize - 1];
    currentSize--;
    return true;
}

/* Reverse the list */
void unsorted::reverse()
{
    int i = 0;
    int j = currentSize - 1;

    while (i < j)
    {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i++;
        j--;
    }
}

/* Combine another unsorted list into this one */
void unsorted::combine(const unsorted &rhs)
{
    for (int i = 0; i < rhs.currentSize && currentSize < maxSize; i++)
    {
        arr[currentSize++] = rhs.arr[i];
    }
}

int unsorted::replaceVal(int oldVal, int newVal)
{
    int count = 0;
    for (int i = 0; i < currentSize; i++)
    {
        if (arr[i] == oldVal)
        {
            arr[i] = newVal;
            count++;
        }
    }
    return count;
}
int unsorted::removeLastAcuucrence(int val)
{
    if (isEmpty())
    {
        return false;
    }

    for (int i = currentSize - 1; i >= 0; i--)
    {
        if (arr[i] == val)
        {
            arr[i] = arr[currentSize - 1];
            currentSize--;
            return true;
        }
    }
    return false;
}

/* Remove all occurrences of val (overwrite technique) */
int unsorted::removeAll(int val)
{
    int count = 0;
    int i = 0;

    while (i < currentSize)
    {
        if (arr[i] == val)
        {
            arr[i] = arr[currentSize - 1];
            currentSize--;
            count++;
        }
        else
            i++;
    }
    return count;
}

/* Copy constructor */
unsorted::unsorted(const unsorted &otherList)
{
    maxSize = otherList.maxSize;
    currentSize = otherList.currentSize;
    arr = new int[maxSize];

    for (int i = 0; i < currentSize; i++)
        arr[i] = otherList.arr[i];
}

/* Assignment operator */
unsorted &unsorted::operator=(const unsorted &otherList)
{
    if (this != &otherList)
    {
        delete[] arr;

        maxSize = otherList.maxSize;
        currentSize = otherList.currentSize;
        arr = new int[maxSize];

        for (int i = 0; i < currentSize; i++)
            arr[i] = otherList.arr[i];
    }
    return *this;
}
