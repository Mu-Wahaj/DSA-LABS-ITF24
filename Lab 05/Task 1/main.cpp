// Muhammad Wahaj
// Roll No: bitf24059
// secton: Morning

#include <iostream>
#include <cstring>
#include "Stack.h"

using namespace std;

void addingLargeNumbers(char *num1, char *num2)
{
    Stack stack1(40);
    Stack stack2(40);
    Stack resultStack(41);

    int len1 = strlen(num1);
    int len2 = strlen(num2);

    for (int i = 0; i < strlen(num1); i++)
    {
        stack1.push(num1[i] - '0');
    }

    for (int i = 0; i < len2; i++)
    {
        stack2.push(num2[i] - '0');
    }

    int carry = 0;

    while (!stack1.isEmpty() || !stack2.isEmpty())
    {
        int sum = carry;

        if (!stack1.isEmpty())
        {
            sum += stack1.pop();
        }

        if (!stack2.isEmpty())
        {
            sum += stack2.pop();
        }

        resultStack.push(sum % 10);
        carry = sum / 10;
    }

    if (carry != 0)
    {
        resultStack.push(carry);
    }

    cout << "Sum of the two numbers is: ";

    while (!resultStack.isEmpty())
    {
        cout << resultStack.pop();
    }

    cout << endl;
}

int main()
{
    const int MAX_DIGITS = 40;

    char num1[MAX_DIGITS + 1];
    char num2[MAX_DIGITS + 1];

    cout << "Enter 1st number: ";
    cin >> num1;

    cout << "Enter 2nd number: ";
    cin >> num2;

    addingLargeNumbers(num1, num2);

    return 0;
}