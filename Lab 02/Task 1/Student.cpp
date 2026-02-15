#include "Student.h"
#include <iostream>
#include <cstring>
using namespace std;

Student::Student() {
    rollNumber = 0;
    name[0] = '\0';
    numberOfQuizzes = 0;
    marks = nullptr;
    totalMarks = nullptr;
}

Student::Student(int roll, const char* studentName, int quizzes) {
    rollNumber = roll;
    numberOfQuizzes = quizzes;
    strcpy(name, studentName);
    marks = new int[numberOfQuizzes]();
    totalMarks = new int[numberOfQuizzes]();
}

Student::Student(const Student& other) {
    rollNumber = other.rollNumber;
    numberOfQuizzes = other.numberOfQuizzes;
    strcpy(name, other.name);
    marks = new int[numberOfQuizzes];
    totalMarks = new int[numberOfQuizzes];
    for(int i = 0; i < numberOfQuizzes; i++) {
        marks[i] = other.marks[i];
        totalMarks[i] = other.totalMarks[i];
    }
}

Student::~Student() {
    delete[] marks;
    delete[] totalMarks;
}

void Student::inputMarks() {
    for(int i = 0; i < numberOfQuizzes; i++) {
        do {
            cout << "Enter total marks for quiz " << (i + 1) << ": ";
            cin >> totalMarks[i];
            cout << "Enter obtained marks for quiz " << (i + 1) << ": ";
            cin >> marks[i];
            if(marks[i] < 0 || marks[i] > totalMarks[i]) {
                cout << "Invalid marks. Please enter again." << endl;
            }
        } while(marks[i] < 0 || marks[i] > totalMarks[i]);
    }
}

void Student::getInputFromUser() {
    cout << "Enter Roll Number: ";
    cin >> rollNumber;
    cout << "Enter Name: ";
    cin.ignore();
    cin.getline(name, MAX_NAME_LENGTH);
    cout << "Enter Number of Quizzes: ";
    cin >> numberOfQuizzes;
    delete[] marks;
    delete[] totalMarks;
    marks = new int[numberOfQuizzes]();
    totalMarks = new int[numberOfQuizzes]();
    inputMarks();
}

void Student::display() const {
    cout << "Roll Number: " << rollNumber << endl;
    cout << "Name: " << name << endl;
    cout << "Quiz Results:" << endl;
    double highestPercentage = 0;
    double lowestPercentage = 100;
    for(int i = 0; i < numberOfQuizzes; i++) {
        double percentage = (marks[i] * 100.0) / totalMarks[i];
        cout << "Quiz " << (i + 1) << ": " << marks[i] << "/" << totalMarks[i];
        cout << " (" << percentage << "%)" << endl;
        if(percentage > highestPercentage) highestPercentage = percentage;
        if(percentage < lowestPercentage) lowestPercentage = percentage;
    }
    cout << "Highest Percentage: " << highestPercentage << "%" << endl;
    cout << "Lowest Percentage: " << lowestPercentage << "%" << endl;
}

void Student::storeInFile(ofstream& outFile) const {
    outFile << rollNumber << endl;
    outFile << name << endl;
    outFile << numberOfQuizzes << endl;
    for(int i = 0; i < numberOfQuizzes; i++) {
        outFile << marks[i] << " " << totalMarks[i] << endl;
    }
}

void Student::readFromFile(ifstream& inFile) {
    inFile >> rollNumber;
    inFile.ignore();
    inFile.getline(name, MAX_NAME_LENGTH);
    inFile >> numberOfQuizzes;
    delete[] marks;
    delete[] totalMarks;
    marks = new int[numberOfQuizzes];
    totalMarks = new int[numberOfQuizzes];
    for(int i = 0; i < numberOfQuizzes; i++) {
        inFile >> marks[i] >> totalMarks[i];
    }
}

Student& Student::operator=(const Student& other) {
    if(this != &other) {
        delete[] marks;
        delete[] totalMarks;
        rollNumber = other.rollNumber;
        numberOfQuizzes = other.numberOfQuizzes;
        strcpy(name, other.name);
        marks = new int[numberOfQuizzes];
        totalMarks = new int[numberOfQuizzes];
        for(int i = 0; i < numberOfQuizzes; i++) {
            marks[i] = other.marks[i];
            totalMarks[i] = other.totalMarks[i];
        }
    }
    return *this;
}