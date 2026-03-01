#include <iostream>
#include "LetterFrequency.h"
#include <fstream>
#include "LetterFrequency.cpp"

using namespace std;

void readAndCountFrequency(const char *, LetterInfo[26]);
void insertionSort(LetterInfo[26]);
void displayFrequencies(const LetterInfo[26]);

int main()
{
    LetterInfo letters[26];
    char filename[100];

    cout << "Enter input file name: ";
    cin >> filename;

    readAndCountFrequency(filename, letters);
    insertionSort(letters);
    displayFrequencies(letters);

    return 0;
}