#ifndef POSTFIX_EVALUATOR_H
#define POSTFIX_EVALUATOR_H

class PostfixEvaluator {
private:
    static const int MAX_EXPRESSION_LENGTH = 200;
    bool isValidOperator(const char* token) const;
    bool isUnaryMinus(const char* token) const;
    double applyOperator(double operand1, double operand2, const char* op) const;
    double applyUnaryMinus(double operand) const;
    
public:
    void evaluatePostfixExpression(char* input);
    bool evaluateWithErrorHandling(char* input, double& result, char* errorMessage);
    void processFile(const char* inputFilename, const char* outputFilename);
};

#endif