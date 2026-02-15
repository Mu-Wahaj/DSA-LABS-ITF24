#include <iostream>
#include "sorted.h"
using namespace std;

int main()
{
    


    sorted sList(10);

    cout << " Inserting elements ";
    sList.insert(5);
    sList.insert(2);
    sList.insert(8);
    sList.insert(1);
    sList.insert(6);

    cout << "Sorted list elements after insertions:";
    sList.display();

    cout << " Searching elements ";
    int index;

    if (sList.search(5, index))
        cout << "Linear search: 5 found at index " << index << endl;
    else
        cout << "5 not found" << endl;

    if (sList.binarySearch(6, index))
        cout << "Binary search: 6 found at index " << index << endl;
    else
        cout << "6 not found" << endl;

    if (sList.binarySearch(10, index))
        cout << "Binary search: 10 found at index " << index << endl;
    else
        cout << "10 not found" << endl;

    cout << " Removing all occurrences of 5 ";
    int removed = sList.removeAll3(5);
    cout << "Removed " << removed << " element(s)";
    sList.display();

    cout << " Copying list to another object ";
    sorted copyList = sList;
    copyList.display();

    cout << " Testing equality operator ";
    if (sList == copyList)
        cout << "Lists are equal";
    else
        cout << "Lists are NOT equal";

    cout << " Deleting element at index 2 ";
    int val;
    if (sList.deleteItem(2, val))
        cout << "Deleted value: " << val << endl;
    else
        cout << "Invalid index" << endl;
    sList.display();
    // ===============================
    // Test intersection
    // ===============================
    cout << "Intersection of List 1 and List 2:" << endl;
    sorted sList1(10);
    sorted sList2(10);
    sList1.insert(5);
    sList1.insert(2);
    sList1.insert(8);
    sList2.insert(5);
    sList2.insert(8);
    sList2.insert(9);
    sorted intersectList = sList1.intersection(sList2);
    intersectList.display();
    cout << endl;

    cout << "Checking if List 1 is subset of List 2:" << endl;
    if (sList1.isSubset(sList2))
        cout << "List 1 is a subset of List 2" << endl;
    else
        cout << "List 1 is NOT a subset of List 2" << endl;
    cout << endl;

    cout << "Checking if Intersection is subset of List 1:" << endl;
    if (intersectList.isSubset(sList1))
        cout << "Intersection is a subset of List 1" << endl;
    else
        cout << "Intersection is NOT a subset of List 1" << endl;
    cout << endl;

    cout << "Searching elements:" << endl;

    if (sList1.search(5, index))
        cout << "Linear search: 5 found at index " << index << endl;
    else
        cout << "5 not found" << endl;

    if (sList1.binarySearch(6, index))
        cout << "Binary search: 6 found at index " << index << endl;
    else
        cout << "6 not found" << endl;

    if (sList1.binarySearch(10, index))
        cout << "Binary search: 10 found at index " << index << endl;
    else
        cout << "10 not found" << endl;

    cout << "Removing all occurrences of 5:" << endl;
    removed = sList1.removeAll3(5);
    cout << "Removed " << removed << " element(s)" << endl;
    sList1.display();
    cout << endl;

    cout << "Copying list to another object:" << endl;
    copyList = sList1;
    copyList.display();
    cout << endl;

    cout << "Testing equality operator:" << endl;
    if (sList1 == copyList)
        cout << "Lists are equal" << endl;
    else
        cout << "Lists are NOT equal" << endl;
    cout << endl;

    cout << "Deleting element at index 2:" << endl;
    if (sList1.deleteItem(2, val))
        cout << "Deleted value: " << val << endl;
    else
        cout << "Invalid index" << endl;
    sList1.display();
    cout << endl;

    return 0;
}
