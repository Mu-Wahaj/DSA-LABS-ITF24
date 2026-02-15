#include "PascalTriangle.h"
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the size of Pascal Triangle: ";
    cin >> n;
    
    int** triangle = createPascalTriangle(n);
    displayPascalTriangle(triangle, n);
    deallocatePascalTriangle(triangle, n);
    
    return 0;
}