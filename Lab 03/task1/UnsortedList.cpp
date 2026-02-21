
#include "UnsortedList.h"
#include <iostream>
#include <string>
using namespace std;

UnsortedList::UnsortedList(int size)
{
    maxSize = size;
    arr = new int[maxSize];
    currentSize = 0;
}
UnsortedList::~UnsortedList()
{
    delete[] arr;
    arr = nullptr;
}
bool UnsortedList::isEmpty() const
{
    if (currentSize == 0)
        return true;
    else
        return false;
}
bool UnsortedList::isFull() const
{
    if (currentSize == maxSize)
        return true;
    else
        return false;
}
bool UnsortedList::insert(int val)
{
    if (!isFull())
    {
        arr[currentSize] = val;
        currentSize++;
        return true;
    }
    return false;
}

bool UnsortedList::deleteItem(int index, int &val)
{
    if (index < 0 || index >= currentSize)
        return false;
    else
    {
        val = arr[index];
        arr[index] = arr[currentSize - 1];
        currentSize--;
        return true;
    }
}
bool UnsortedList::deleteItem2(int index, int &val)
{
    if (index < 0 || index >= currentSize)
    {
        return false;
    }
    else
    {
        val = arr[index];
        for (int i = index; i < currentSize; i++)
        {
            arr[i] = arr[i + 1];
        }
        currentSize--;
        return true;
    }
}

int UnsortedList::getLength() const
{
    return currentSize;
}

UnsortedList::UnsortedList(const UnsortedList &otherList)
{

    maxSize = otherList.maxSize;
    currentSize = otherList.currentSize;
    arr = new int[maxSize];
    for (int i = 0; i < currentSize; i++)
    {
        arr[i] = otherList.arr[i];
    }
}
UnsortedList &UnsortedList::operator=(const UnsortedList &otherList)
{
    if (this != &otherList)
    {
        delete[] arr;
        arr = nullptr;
        maxSize = otherList.maxSize;
        currentSize = otherList.currentSize;
        arr = new int[maxSize];
        for (int i = 0; i < currentSize; i++)
        {
            arr[i] = otherList.arr[i];
        }
    }
    return *this;
}
bool UnsortedList::operator==(const UnsortedList &otherList) const
{
    if (currentSize != otherList.currentSize)
    {
        return false;
    }
    for (int i = 0; i < currentSize; i++)
    {
        if (arr[i] != otherList.arr[i])
        {
            return false;
        }
    }
    return true;
}

// order is not preserved; last element is swapped into the current index
int UnsortedList::removeAll(int val)
{
    int count = 0;

    for (int i = 0; i < currentSize; i++)
    {
        if (arr[i] == val)
        {
            arr[i] = arr[currentSize - 1];
            currentSize--;
            count++;
            i--;
        }
    }
    return count;
}
int UnsortedList::removeAll2(int val)
{
    int count = 0;

    for (int i = 0; i < currentSize; i++)
    {
        if (arr[i] == val)
        {
            for (int j = i; j < currentSize; j++)
            {
                arr[j] = arr[j + 1];
            }
            count++;
            i--;
        }
        currentSize--;
    }
    return count;
}
int UnsortedList::removeAll3(int val)
{
    int count = 0;
    int writeIndex = 0;

    for (int readIndex = 0; readIndex < currentSize; readIndex++)
    {
        if (arr[readIndex] != val)
        {
            arr[writeIndex] = arr[readIndex];
            writeIndex++;
        }
        else
        {
            count++;
        }
    }
    currentSize = writeIndex;
    return count;
}
void UnsortedList::display() const
{
    for (int i = 0; i < currentSize; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int UnsortedList::removeAll4(int val)
{
    int *arrNew = new int[maxSize];
    int count = 0;
    int j = 0;

    for (int i = 0; i < currentSize; i++)
    {
        if (arr[i] != val)
        {
            arrNew[j] = arr[i];
            j++;
            count++;
        }
    }
    delete[] arr;
    arr = arrNew;
    currentSize = j;
    return count;
}

bool UnsortedList::search(int key) const
{

    bool flag = false;
    int i = 0;
    while (i < currentSize && flag == false)
    {
        if (arr[i] == key)
        {
            flag = true;
        }
        i++;
    }
    return flag;
}

bool UnsortedList::getval(int index, int &val) const
{
    if (index < 0 || index >= currentSize)
    {
        return false;
    }

    val = arr[index];
    return true;
}

// lab 03 tasks
UnsortedList UnsortedList::intersection(const UnsortedList &list2) const
{
    UnsortedList result(maxSize);

    for (int i = 0; i < currentSize; i++)
    {
        bool found = false;

        for (int j = 0; j < list2.currentSize; j++)
        {
            if (arr[i] == list2.arr[j])
            {
                found = true;
            }
        }

        if (found == true)
        {
            result.arr[result.currentSize] = arr[i];
            result.currentSize++;
        }
    }

    return result;
}

bool UnsortedList::isSubset(const UnsortedList &list2) const
{
    for (int i = 0; i < currentSize; i++)
    {
        bool found = false;
        int j = 0;
        
        // Using while loop with compound condition
        while (j < list2.currentSize && !found)
        {
            found = (arr[i] == list2.arr[j]);
            j++;
        }
        
        if (!found)
        {
            return false;
        }
    }
    
    return true;
}

UnsortedList UnsortedList::difference(const UnsortedList& list2) const
{
    UnsortedList result(maxSize);
    
    for (int i = 0; i < currentSize; i++)
    {
        bool foundInList2 = false;
        int j = 0;
        
        // Continue searching until found OR end of list
        while (j < list2.currentSize && !foundInList2)
        {
            if (arr[i] == list2.arr[j])
            {
                foundInList2 = true;
            }
            j++;
        }
        
        if (!foundInList2)
        {
            result.arr[result.currentSize] = arr[i];
            result.currentSize++;
        }
    }
    
    return result;
}