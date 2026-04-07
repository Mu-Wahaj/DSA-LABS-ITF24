#include "ArrayConverter.h"
#include <iostream>
using namespace std;

int** convertTo2D(int* arr1D, int n, int r, int c) {//eg if we have 1D array of size 6 and we want to convert it into 2D array of size 2*3 then we will check if the size of 1D array is equal to the product of rows and columns of 2D array if it is not equal then we will return nullptr otherwise we will create a 2D array and fill it with the elements of 1D array and return the pointer to the 2D array
    if(n != r * c) {
        return nullptr;
    }
    
    int** arr2D = new int*[r];
    for(int i = 0; i < r; i++) {
        arr2D[i] = new int[c];
        for(int j = 0; j < c; j++) {
            arr2D[i][j] = arr1D[i * c + j];
        }
    }
    return arr2D;
}

void display2DArray(int** arr2D, int r, int c) {
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cout << arr2D[i][j] << " ";
        }
        cout << endl;
    }
}

void deallocate2DArray(int** arr2D, int r) {
    for(int i = 0; i < r; i++) {
        delete[] arr2D[i];
    }
    delete[] arr2D;
}