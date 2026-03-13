// Name: Muhammad Wahaj
// Roll Number: BITF24M059

#include <iostream>
using namespace std;

bool areArraysEqual(int* a, int aSize, int* b, int bSize) {
    if (aSize != bSize) {
        return false;
    }
    if (aSize == 0) {
        return true;
    }
    if (*a != *b) {
        return false;
    }
    return areArraysEqual(a + 1, aSize - 1, b + 1, bSize - 1);
}

int main() {
    int size1, size2;
    cout << "Enter the size of the first array: ";
    cin >> size1;
    int arr1[size1];
    cout << "Enter " << size1 << " elements for the first array: ";
    for (int i = 0; i < size1; i++) {
        cin >> arr1[i];
    }
    cout << "Enter the size of the second array: ";
    cin >> size2;
    int arr2[size2];    
    cout << "Enter " << size2 << " elements for the second array: ";
    for (int i = 0; i < size2; i++) {
        cin >> arr2[i];
    }
    if (areArraysEqual(arr1, size1, arr2, size2)) {
        cout << "The arrays are equal." << endl;
    } else {
        cout << "The arrays are not equal." << endl;
    }

    return 0;
}
