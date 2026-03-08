#include <iostream>
#include <cstring>
#include <fstream>
#include "PostfixEvaluator.h"
using namespace std;

void runTask1() {
    cout << "Task # 2.1" << endl;
    PostfixEvaluator evaluator;
    char expression[200];
    cout << "Enter the postfix expression: ";
    cin.getline(expression, 200);
    char expressionCopy[200];
    strcpy(expressionCopy, expression);
    evaluator.evaluatePostfixExpression(expressionCopy);
}

void runTask2() {
    cout << "Task # 2.2" << endl;
    PostfixEvaluator evaluator;
    char expression[200];
    double result;
    char errorMessage[100];
    cout << "Enter the postfix expression: ";
    cin.getline(expression, 200);
    char expressionCopy[200];
    strcpy(expressionCopy, expression);
    if (evaluator.evaluateWithErrorHandling(expressionCopy, result, errorMessage)) {
        cout << "Valid expression!" << endl;
        cout << "Result = " << result << endl;
    } else {
        cout << "Error: " << errorMessage << endl;
    }
    cout << endl;
    cout << "Testing error cases:" << endl;
    const char* testCases[] = {
        "1 3 + *",
        "3 4 5 +",
        "4 6 + 8 &"
    };
    for (int i = 0; i < 3; i++) {
        char testCopy[200];
        strcpy(testCopy, testCases[i]);
        cout << "Expression: " << testCases[i] << endl;
        if (evaluator.evaluateWithErrorHandling(testCopy, result, errorMessage)) {
            cout << "Result: " << result << endl;
        } else {
            cout << "Error: " << errorMessage << endl;
        }
        cout << endl;
    }
}

void runTask3() {
    cout << "Task # 2.3" << endl;
    PostfixEvaluator evaluator;
    ofstream sampleInput("input.txt");
    sampleInput << "12 3 ~ 1 - / 4.6 ~ *" << endl;
    sampleInput << "5 3 + 2 *" << endl;
    sampleInput << "10 2 / 3 +" << endl;
    sampleInput << "4 6 + 8 &" << endl;
    sampleInput << "1 3 + *" << endl;
    sampleInput << "3 4 5 +" << endl;
    sampleInput.close();
    cout << "Sample input file 'input.txt' created." << endl;
    evaluator.processFile("input.txt", "output.txt");
    cout << endl;
    cout << "Contents of output.txt:" << endl;
    ifstream outputFile("output.txt");
    string line;
    while (getline(outputFile, line)) {
        cout << line << endl;
    }
    outputFile.close();
}

int main() {
    int choice;
    do {
        cout << "Menu:" << endl;
        cout << "1. Task 2.1" << endl;
        cout << "2. Task 2.2" << endl;
        cout << "3. Task 2.3" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();
        if (choice == 1) {
            runTask1();
        }
        else if (choice == 2) {
            runTask2();
        }
        else if (choice == 3) {
            runTask3();
        }
        else if (choice == 4) {
            cout << "Exiting program." << endl;
        }
        else {
            cout << "Invalid choice." << endl;
        }
        cout << endl;
    } while (choice != 4);
    return 0;
}