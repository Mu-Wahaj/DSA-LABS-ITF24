// Name: Muhammad Wahaj
// Roll Number: BITF24M059

#include <iostream>
using namespace std;

int findLargestIndex(int *arr, int start, int end)
{
    if (start == end)
    {
        return start;
    }
    int restIndex = findLargestIndex(arr, start + 1, end);
    if (arr[start] > arr[restIndex])
    {
        return start;
    }
    return restIndex;
}

int main()
{
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;
    int arr1[size];
    cout << "Enter " << size << " elements for the array: ";
    for (int i = 0; i < size; i++)
    {
        cin >> arr1[i];
    }
    int idx1 = findLargestIndex(arr1, 0, size - 1);
    cout << "Largest index: " << idx1 << "  value: " << arr1[idx1] << endl;

    return 0;
}
