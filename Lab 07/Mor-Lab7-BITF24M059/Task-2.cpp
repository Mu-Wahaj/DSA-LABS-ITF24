// Name: Muhammad Wahaj
// Roll Number: BITF24M059

#include <iostream>
using namespace std;

void printZigZag(int* arr, int start, int end) {
    if (start > end) {
        return;
    }
    if (start == end) {
        cout << arr[start] << " ";
        return;
    }
    cout << arr[start] << " " << arr[end] << " ";
    printZigZag(arr, start + 1, end - 1);
}

void printZigZagUpdated(int* pStart, int* pEnd) {
    if (pStart > pEnd) {
        return;
    }
    if (pStart == pEnd) {
        cout << *pStart << " ";
        return;
    }
    cout << *pStart << " " << *pEnd << " ";
    printZigZagUpdated(pStart + 1, pEnd - 1);
}

int main() {
    cout << "Enter the size of the first array: ";
    int size1;
    cin >> size1;
    int arr1[size1];
    cout << "Enter " << size1 << " elements for the  array: ";
    for (int i = 0; i < size1; i++) {
        cin >> arr1[i];
    }

    cout << endl;
    cout << "ZIGZAG ORDER:" << endl;
    printZigZag(arr1, 0, size1 - 1);
    cout << endl;

        
    int SIZE2 ;
    cout << "Enter the size of the second array: ";
    cin >> SIZE2;
    int arr2[SIZE2];
    cout << "Enter " << SIZE2 << " elements for the second array: ";
    for (int i = 0; i < SIZE2; i++) {
        cin >> arr2[i];
    }
    cout << endl;
    cout << "ZIGZAG ORDER (Updated):" << endl;
    printZigZagUpdated(arr2, arr2 + SIZE2 - 1);
    cout << endl;

    return 0;
}
