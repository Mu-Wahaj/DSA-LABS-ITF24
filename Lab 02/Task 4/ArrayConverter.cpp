#include "ArrayConverter.h"
#include <iostream>
using namespace std;

int** convertTo2D(int* arr1D, int n, int r, int c) {
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