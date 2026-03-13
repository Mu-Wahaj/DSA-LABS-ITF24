// Name: Muhammad Wahaj
// Roll Number: BITF24M059

#include <iostream>
using namespace std;

int sumDigits(int num)
{
    int sum = 0;
    if (num < 0)
    {
        num = -num;
    }
    if (num == 0)
    {
        return 0;
    }
    sum = num % 10 + sumDigits(num / 10);
    return sum;
}

int main()
{
    int n;
    cout << "Enter a number you want to find the sum of digits for: ";
    cin >> n;
    cout << "Sum of digits: " << sumDigits(n) << endl;
    return 0;
}
