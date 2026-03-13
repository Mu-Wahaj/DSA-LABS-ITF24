// Name: Muhammad Wahaj
// Roll Number: BITF24M059

#include <iostream>
using namespace std;

void printChar(char ch, int n)
{
    if (n == 0)
    {
        return;
    }
    cout << ch;
    printChar(ch, n - 1);
}

void printPattern1(char ch, int n)
{
    if (n == 0)
    {
        return;
    }
    printChar(ch, n);
    cout << endl;
    printPattern1(ch, n - 1);
}

void printPattern2(char ch, int n)
{
    if (n == 0)
    {
        return;
    }
    printPattern2(ch, n - 1);
    printChar(ch, n);
    cout << endl;
}

int main()
{
    int n;
    cout << "Enter the number of characters to print: ";
    cin >> n;
    cout << "print Z" << endl;
    printChar('Z', n);
    cout << endl;

    cout << endl;
    cout << "Print #" << endl;
    printPattern2('#', 6);

    cout << endl;
    cout << "Print *" << endl;
    printPattern2('*', 4);

    return 0;
}
