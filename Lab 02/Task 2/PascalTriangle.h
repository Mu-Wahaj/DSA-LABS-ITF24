#ifndef PASCALTRIANGLE_H
#define PASCALTRIANGLE_H

int** createPascalTriangle(int n);
void displayPascalTriangle(int** pt, int n);
void deallocatePascalTriangle(int** pt, int n);
//updated deallocatePascalTriangle to match the header file signature
void deallocatePascalTriangleupdated(int**& pt, int n);

#endif