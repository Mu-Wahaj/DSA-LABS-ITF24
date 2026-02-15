#include "PhraseAnalyzer.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string* readPhrasesFromFile(const char* filename, int& count) {
    ifstream file(filename);
    file >> count;
    file.ignore();
    
    string* phrases = new string[count];
    for(int i = 0; i < count; i++) {
        getline(file, phrases[i]);
    }
    file.close();
    return phrases;
}

void findLongestAndShortest(string* phrases, int count, string& longest, string& shortest) {
    longest = phrases[0];
    shortest = phrases[0];
    
    for(int i = 1; i < count; i++) {
        if(phrases[i].length() > longest.length()) {
            longest = phrases[i];
        }
        if(phrases[i].length() < shortest.length()) {
            shortest = phrases[i];
        }
    }
}

void deallocatePhrases(string* phrases) {
    delete[] phrases;
}