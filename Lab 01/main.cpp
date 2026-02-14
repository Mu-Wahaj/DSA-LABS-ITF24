#include <iostream>
#include "sorted.h"
#include "unsorted.h"
using namespace std;

int main()
{
    cout << "Unsorted List Operations" << endl;

    unsorted u(10);
    u.insert(5);
    u.insert(3);
    u.insert(9);
    u.insert(3);
    u.insert(1);

    cout << "Unsorted list elements:" << endl;
    u.display();

    int maxVal;
    if (u.removeMax(maxVal))
        cout << "Removed max value: " << maxVal << endl;

    cout << "After removing max:" << endl;
    u.display();

    u.reverse();
    cout << "After reversing:" << endl;
    u.display();

    cout << "Removed occurrences of 3: " << u.removeAll(3) << endl;
    u.display();

    cout << endl;

    cout << "Sorted List Operations" << endl;

    sorted s(10);
    s.insert(5);
    s.insert(3);
    s.insert(9);
    s.insert(1);
    s.insert(5);

    cout << "Sorted list elements:" << endl;
    s.display();

    int index;
    if (s.binarySearch(5, index))
        cout << "Value 5 found at index " << index << endl;

    int removedVal;
    s.remove(2, removedVal);
    cout << "Removed value at index 2: " << removedVal << endl;
    s.display();

    s.replace(1, 8);
    cout << "After replacing index 1 with 8:" << endl;
    s.display();

    cout << "Removed occurrences of 5: " << s.removeAll(5) << endl;
    s.display();

    return 0;
}
