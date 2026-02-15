#ifndef STUDENT_H
#define STUDENT_H
#include <fstream>
using namespace std;
const int MAX_NAME_LENGTH = 40;

class Student {
private:
    int rollNumber;
    char name[MAX_NAME_LENGTH + 1];
    int numberOfQuizzes;
    int* marks;
    int* totalMarks;
    void inputMarks();

public:
    Student();
    Student(int roll, const char* studentName, int quizzes);
    Student(const Student& other);
    ~Student();
    void getInputFromUser();
    void display() const;
    void storeInFile(ofstream& outFile) const;
    void readFromFile(ifstream& inFile);
    Student& operator=(const Student& other);
};
#endif