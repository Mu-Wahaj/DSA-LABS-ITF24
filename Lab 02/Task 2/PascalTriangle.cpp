#include "PascalTriangle.h"
#include <iostream>
using namespace std;

int** createPascalTriangle(int n) {
    int** triangle = new int*[n];
    for(int i = 0; i < n; i++) {
        triangle[i] = new int[i + 1];
        triangle[i][0] = 1;
        triangle[i][i] = 1;
        for(int j = 1; j < i; j++) {
            triangle[i][j] = triangle[i-1][j-1] + triangle[i-1][j];
        }
    }
    return triangle;
}

void displayPascalTriangle(int** pt, int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= i; j++) {
            cout << pt[i][j] << " ";
        }
        cout << endl;
    }
}

void deallocatePascalTriangle(int** pt, int n) {
    for(int i = 0; i < n; i++) {
        delete[] pt[i];
    }
    delete[] pt;
}

//updated  deallocatePascalTriangle to match the header file signature
void deallocatePascalTriangleupdated(int**& pt, int n) {
    if(pt != nullptr) {
        for(int i = 0; i < n; i++) {
            delete[] pt[i];
            pt[i] = nullptr;
        }
        delete[] pt;
        pt = nullptr;
    }
}