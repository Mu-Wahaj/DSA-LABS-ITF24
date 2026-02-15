#ifndef PHRASEANALYZER_H
#define PHRASEANALYZER_H
#include <string>
using namespace std;

string* readPhrasesFromFile(const char* filename, int& count);
void findLongestAndShortest(string* phrases, int count, string& longest, string& shortest);
void deallocatePhrases(string* phrases);

#endif