#include "Student.h"
#include <iostream>
#include <fstream>
using namespace std;

void printStudent(Student s) {
    s.display();
}

int main() {
    int numStudents;
    cout << "Enter number of students: ";
    cin >> numStudents;
    
    Student* students = new Student[numStudents];
    
    for(int i = 0; i < numStudents; i++) {
        cout << "Enter details for student " << (i + 1) << ":" << endl;
        students[i].getInputFromUser();
    }
    
    ofstream outFile("students.txt");
    for(int i = 0; i < numStudents; i++) {
        students[i].storeInFile(outFile);
    }
    outFile.close();
    
    delete[] students;
    
    ifstream inFile("students.txt");
    Student* loadedStudents = new Student[numStudents];
    for(int i = 0; i < numStudents; i++) {
        loadedStudents[i].readFromFile(inFile);
    }
    inFile.close();
    
    cout << "Student details from file:" << endl;
    for(int i = 0; i < numStudents; i++) {
        loadedStudents[i].display();
    }
    
    delete[] loadedStudents;
    
    cout << "Testing copy constructor:" << endl;
    Student testStudent(101, "Test", 2);
    printStudent(testStudent);
    
    cout << "Testing assignment operator:" << endl;
    Student s1(102, "Original", 2);
    Student s2;
    s2 = s1;
    s2.display();
    
    return 0;
}