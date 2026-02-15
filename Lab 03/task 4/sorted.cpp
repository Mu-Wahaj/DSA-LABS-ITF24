#include <iostream>
#include "sorted.h"
using namespace std;

sorted::sorted(int s)
{
    maxSize = s;
    arr = new int[maxSize];
    currentSize = 0;
}

sorted::~sorted()
{
    delete[] arr;
    arr = nullptr;
}
void sorted::display() const
{
    for (int i = 0; i < currentSize; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

bool sorted::isFull() const
{

    if (currentSize == maxSize)
    {
        return true;
    }
    return false;
}
bool sorted::isFull() const
{

    if (currentSize == 0)
    {
        return true;
    }
    return false;
}

int sorted::getLength() const
{
    return currentSize;
}

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

bool sorted::deleteItem(int index, int &val)
{
    if (index < 0 || index >= currentSize)
        return false;

    val = arr[index];

    for (int i = index; i < currentSize - 1; i++)
        arr[i] = arr[i + 1];

    currentSize--;
    return true;
}
bool sorted::deleteItem2(int index, int &val)
{
    return deleteItem(index, val);
}

// home work rule of three

sorted::sorted(const sorted &otherList)
{
    maxSize = otherList.maxSize;
    currentSize = otherList.currentSize;

    arr = new int[maxSize];
    for (int i = 0; i < currentSize; i++)
        arr[i] = otherList.arr[i];
}

sorted &sorted::operator=(const sorted &otherList)
{
    if (this != &otherList)
    {
        if (arr != nullptr)
        {
            delete[] arr;
            arr = nullptr;
        }

        else
        {
            maxSize = otherList.maxSize;
            currentSize = otherList.currentSize;

            arr = new int[maxSize];
            for (int i = 0; i < currentSize; i++)
                arr[i] = otherList.arr[i];
        }
    }
    return *this;
}

bool sorted::operator==(const sorted &otherList) const
{
    if (currentSize != otherList.currentSize)
        return false;

    for (int i = 0; i < currentSize; i++)
        if (arr[i] != otherList.arr[i])
            return false;

    return true;
}

// dosent matter wer the element is
bool sorted::operator==(const sorted &otherList) const
{
    if (currentSize != otherList.currentSize)
        return false;

    bool matched[currentSize] = {false};

    for (int i = 0; i < currentSize; i++)
    {
        bool found = false;

        for (int j = 0; j < currentSize; j++)
        {
            if (!matched[j] && arr[i] == otherList.arr[j] && !found)
            {
                matched[j] = true;
                found = true;
            }
        }

        if (!found)
            return false;
    }
    return true;
}

int sorted::removeAll(int val)
{
    int count = 0;
    int i = 0;

    while (i < currentSize)
    {
        if (arr[i] == val)
        {
            // shift elements left
            for (int j = i; j < currentSize - 1; j++)
            {
                arr[j] = arr[j + 1];
            }

            currentSize--; // one element removed
            count++;
            // do NOT increment i → recheck same index
        }
        else
        {
            i++; // move forward only if no deletion
        }
    }

    return count;
}
int sorted::removeAll3(int val)
{
    int i = 0;
    int j = 0;
    int count = 0;

    while (i < currentSize)
    {
        if (arr[i] != val)
        {
            arr[j] = arr[i];
            j++;
        }
        else
        {
            count++;
        }
        i++;
    }

    currentSize = j;
    return count;
}

int sorted::removeAll4(int val)
{
    int *newArr = new int[maxSize];
    int i = 0, j = 0;
    int count = 0;

    while (i < currentSize)
    {
        if (arr[i] != val)
        {
            newArr[j++] = arr[i];
        }
        else
        {
            count++;
        }
        i++;
    }

    delete[] arr;
    arr = newArr;
    currentSize = j;

    return count;
}

int sorted::removeAll4(int val)
{
    int *newArr = new int[maxSize];
    int i = 0, j = 0;
    int count = 0;

    while (i < currentSize)
    {
        if (arr[i] != val)
        {
            newArr[j++] = arr[i];
        }
        else
        {
            count++;
        }
        i++;
    }

    delete[] arr;
    arr = newArr;
    currentSize = j;

    return count;
}
bool sorted::search(int val, int &index) const
{
    int i = 0;
    while (i < currentSize)
    {
        if (arr[i] == val)
        {
            index = i;
            return true;
        }
        i++;
    }
    return false;
}

// binary search
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
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return false;
}

// lab 03 tasks
sorted sorted::intersection(const sorted &list2) const
{
    sorted result(maxSize);

    int i = 0;
    int j = 0;

    while (i < currentSize && j < list2.currentSize)
    {
        if (arr[i] == list2.arr[j])
        {
            result.arr[result.currentSize] = arr[i];
            result.currentSize++;

            i++;
            j++;
        }
        else if (arr[i] < list2.arr[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }

    return result;
}

bool sorted::isSubset(const sorted& list2) const
{
    if (currentSize == 0)
        return true;

    int i = 0;
    int j = 0;

    while (i < currentSize && j < list2.currentSize)
    {
        if (arr[i] == list2.arr[j])
        {
            i++;
            j++;
        }
        else if (arr[i] > list2.arr[j])
        {
            j++;
        }
        else
        {
            return false;
        }
    }

    if (i == currentSize)
        return true;
    else
        return false;
}

