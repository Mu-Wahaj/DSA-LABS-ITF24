// Name: Muhammad Wahaj
// Roll Number: BITF24M059

#include <iostream>
using namespace std;

int linearSearchUpdated(int* arr, int start, int end, int key) {
    if (start > end) {
        return 0;
    }
    if (arr[start] == key) {
        return 1 + linearSearchUpdated(arr, start + 1, end, key);
    }
    return linearSearchUpdated(arr, start + 1, end, key);
}

int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;
    int arr[size];
    cout << "Enter " << size << " elements for the array: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }   
    int key;
    cout << "Enter the key to search: ";
    cin >> key;
    int count = linearSearchUpdated(arr, 0, size - 1, key);
    cout << "The key " << key << " appears " << count << " times in the array." << endl;

    return 0;
}
