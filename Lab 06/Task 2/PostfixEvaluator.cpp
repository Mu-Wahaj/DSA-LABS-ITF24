#include "PostfixEvaluator.h"
#include "Stack.h"
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <fstream>
using namespace std;

bool PostfixEvaluator::isValidOperator(const char* token) const {
    return (strcmp(token, "+") == 0 || 
            strcmp(token, "-") == 0 || 
            strcmp(token, "*") == 0 || 
            strcmp(token, "/") == 0 || 
            strcmp(token, "~") == 0);
}

bool PostfixEvaluator::isUnaryMinus(const char* token) const {
    return strcmp(token, "~") == 0;
}

double PostfixEvaluator::applyOperator(double operand1, double operand2, const char* op) const {
    if (strcmp(op, "+") == 0) return operand1 + operand2;
    if (strcmp(op, "-") == 0) return operand1 - operand2;
    if (strcmp(op, "*") == 0) return operand1 * operand2;
    if (strcmp(op, "/") == 0) return operand1 / operand2;
    return 0;
}

double PostfixEvaluator::applyUnaryMinus(double operand) const {
    return -operand;
}

void PostfixEvaluator::evaluatePostfixExpression(char* input) {
    Stack stack(MAX_EXPRESSION_LENGTH);
    char* token;
    cout << "Token = ";
    token = strtok(input, " ");
    while (token != nullptr) {
        cout << token << "  ";
        if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1])) || 
            (token[0] == '.' && isdigit(token[1])) || 
            (isdigit(token[0]) && token[1] == '.')) {
            double value = atof(token);
            stack.push(value);
            cout << "Push " << value << endl;
        }
        else if (isUnaryMinus(token)) {
            double operand = stack.pop();
            double result = applyUnaryMinus(operand);
            stack.push(result);
            cout << "Pop " << operand << "  Push " << result << endl;
        }
        else if (isValidOperator(token)) {
            double operand2 = stack.pop();
            double operand1 = stack.pop();
            double result = applyOperator(operand1, operand2, token);
            stack.push(result);
            cout << "Pop " << operand2 << "  Pop " << operand1 << "  Push " << result << endl;
        }
        token = strtok(nullptr, " ");
    }
    cout << "End of input" << endl << endl;
    cout << "Answer = " << stack.pop() << endl;
}

bool PostfixEvaluator::evaluateWithErrorHandling(char* input, double& result, char* errorMessage) {
    Stack stack(MAX_EXPRESSION_LENGTH);
    char* token;
    char inputCopy[MAX_EXPRESSION_LENGTH];
    strcpy(inputCopy, input);
    token = strtok(inputCopy, " ");
    while (token != nullptr) {
        if (!isdigit(token[0]) && token[0] != '.' && token[0] != '-' && 
            !isValidOperator(token)) {
            strcpy(errorMessage, "Invalid operator encountered");
            return false;
        }
        if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1])) || 
            (token[0] == '.' && isdigit(token[1])) || 
            (isdigit(token[0]) && token[1] == '.')) {
            double value = atof(token);
            stack.push(value);
        }
        else if (isUnaryMinus(token)) {
            if (stack.isEmpty()) {
                strcpy(errorMessage, "Too few operands for unary minus");
                return false;
            }
            double operand = stack.pop();
            double result2 = applyUnaryMinus(operand);
            stack.push(result2);
        }
        else if (isValidOperator(token)) {
            if (stack.size() < 2) {
                strcpy(errorMessage, "Too few operands for binary operator");
                return false;
            }
            double operand2 = stack.pop();
            double operand1 = stack.pop();
            double result2 = applyOperator(operand1, operand2, token);
            stack.push(result2);
        }
        token = strtok(nullptr, " ");
    }
    if (stack.isEmpty()) {
        strcpy(errorMessage, "Expression evaluated to empty stack");
        return false;
    }
    if (stack.size() > 1) {
        strcpy(errorMessage, "Too few operators - multiple values remain on stack");
        return false;
    }
    result = stack.pop();
    return true;
}

void PostfixEvaluator::processFile(const char* inputFilename, const char* outputFilename) {
    ifstream inputFile(inputFilename);
    ofstream outputFile(outputFilename);
    if (!inputFile.is_open()) {
        cout << "Error: Could not open input file: " << inputFilename << endl;
        return;
    }
    if (!outputFile.is_open()) {
        cout << "Error: Could not open output file: " << outputFilename << endl;
        return;
    }
    char line[MAX_EXPRESSION_LENGTH];
    int lineNumber = 1;
    while (inputFile.getline(line, MAX_EXPRESSION_LENGTH)) {
        size_t len = strlen(line);
        if (len > 0 && line[len-1] == '\n') {
            line[len-1] = '\0';
        }
        char lineCopy[MAX_EXPRESSION_LENGTH];
        strcpy(lineCopy, line);
        double result;
        char errorMessage[100] = "";
        outputFile << "Expression " << lineNumber << ": " << line << endl;
        if (evaluateWithErrorHandling(lineCopy, result, errorMessage)) {
            outputFile << "Result: " << result << endl;
        } else {
            outputFile << "Error: " << errorMessage << endl;
        }
        outputFile << "------------------------" << endl;
        lineNumber++;
    }
    inputFile.close();
    outputFile.close();
    cout << "Processing complete. Results written to " << outputFilename << endl;
}