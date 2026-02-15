#ifndef ARRAYCONVERTER_H
#define ARRAYCONVERTER_H

int** convertTo2D(int* arr1D, int n, int r, int c);
void display2DArray(int** arr2D, int r, int c);
void deallocate2DArray(int** arr2D, int r);

#endif