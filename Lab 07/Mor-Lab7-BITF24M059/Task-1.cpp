// Name: Muhammad Wahaj
// Roll Number: BITF24M059

#include <iostream>
using namespace std;

void printVertical(int val) {
    if (val < 10) {
        cout << val << endl;
        return;
    }
    printVertical(val / 10);
    cout << val % 10 << endl;
}

int main() {
   int n ;
    cout << "Enter a number: ";
    cin >> n;
    cout << "Digits in vertical order:" << endl;
    printVertical(n);

    return 0;
}
