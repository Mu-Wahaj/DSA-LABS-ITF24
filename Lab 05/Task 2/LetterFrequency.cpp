// Muhammad Wahaj
// Roll No: bitf24059
// secton: Morning

#include <iostream>
#include <fstream>
#include "LetterFrequency.h"

using namespace std;

void readAndCountFrequency(const char *filename, LetterInfo letters[26])
{
    for (int i = 0; i < 26; i++)
    {
        letters[i].letter = 'A' + i;
        letters[i].freq = 0;
    }

    ifstream in(filename);
    if (!in)
    {
        cout << "Cannot open file." << endl;
        return;
    }
    char ch;
    while (in.get(ch))
    {
        if (ch >= 'a' && ch <= 'z')
        {
            letters[ch - 'a'].freq++;
        }
        else if (ch >= 'A' && ch <= 'Z')
        {
            letters[ch - 'A'].freq++;
        }
    }

    in.close();
}

void insertionSort(LetterInfo letters[26])
{
    for (int i = 1; i < 26; i++)
    {
        LetterInfo key = letters[i];
        int j = i - 1;
        while (j >= 0 && letters[j].freq < key.freq)
        {
            letters[j + 1] = letters[j];
            j--;
        }
        letters[j + 1] = key;
    }
}

void displayFrequencies(const LetterInfo letters[26])
{
    cout << "Letter\tFrequency" << endl;
    for (int i = 0; i < 26; i++)
    {
        if (letters[i].freq > 0)
        {
            cout << letters[i].letter << "\t" << letters[i].freq << endl;
        }
    }
}