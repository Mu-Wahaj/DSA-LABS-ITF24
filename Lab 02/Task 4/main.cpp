#include "ArrayConverter.h"
#include <iostream>
using namespace std;

int main() {
    int n, r, c;
    
    cout << "Enter the size of 1D array: ";
    cin >> n;
    
    int* arr1D = new int[n];
    cout << "Enter " << n << " elements: ";
    for(int i = 0; i < n; i++) {
        cin >> arr1D[i];
    }
    
    cout << "Enter number of rows and columns: ";
    cin >> r >> c;
    
    int** arr2D = convertTo2D(arr1D, n, r, c);
    
    if(arr2D == nullptr) {
        cout << "Conversion failed: n != r * c" << endl;
    } else {
        cout << "2D Array created successfully:" << endl;
        display2DArray(arr2D, r, c);
        deallocate2DArray(arr2D, r);
    }
    
    delete[] arr1D;
    return 0;
}