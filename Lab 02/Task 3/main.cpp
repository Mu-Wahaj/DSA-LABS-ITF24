#include "PhraseAnalyzer.h"
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    int count;
    string longest, shortest;
    
    string* phrases = readPhrasesFromFile("phrases.txt", count);
    
    cout << "The input file contains " << count << " phrases" << endl;
    
    findLongestAndShortest(phrases, count, longest, shortest);
    
    cout << "Longest phrase: " << longest << " (Length: " << longest.length() << ")" << endl;
    cout << "Shortest phrase: " << shortest << " (Length: " << shortest.length() << ")" << endl;
    
    deallocatePhrases(phrases);
    
    return 0;
}