#include "CDLL.h"
#include <iostream>
using namespace std;

int main()
{
    cout << "========== Task 1.1 & 1.2 - Sorted Insert & Split ==========" << endl;
    
    // Test sorted insert
    CDLL list;
    cout << "Sorted Insert (5, 3, 8, 1, 7):" << endl;
    list.sorted_Insert(5);
    list.sorted_Insert(3);
    list.sorted_Insert(8);
    list.sorted_Insert(1);
    list.sorted_Insert(7);
    list.display(); // Expected: 1 3 5 7 8
    cout << "Count: " << list.count() << endl;

    // Test splitList
    CDLL list1, list2, list3;
    list1.insertAtEnd(8);
    list1.insertAtEnd(4);
    list1.insertAtEnd(2);
    list1.insertAtEnd(9);
    list1.insertAtEnd(1);
    list1.insertAtEnd(5);
    list1.insertAtEnd(3);

    cout << "\nOriginal list1: ";
    list1.display();
    list1.splitList(list2, list3);
    cout << "After split, list1: ";
    list1.display();
    cout << "Left half (list2): ";
    list2.display();
    cout << "Right half (list3): ";
    list3.display();

    cout << "\n========== Task 1.3 - Merge Two Sorted Lists ==========" << endl;
    
    CDLL sortedA, sortedB, merged;
    sortedA.sorted_Insert(4);
    sortedA.sorted_Insert(7);
    sortedA.sorted_Insert(10);
    sortedA.sorted_Insert(12);
    sortedB.sorted_Insert(1);
    sortedB.sorted_Insert(3);
    sortedB.sorted_Insert(6);
    sortedB.sorted_Insert(8);
    sortedB.sorted_Insert(9);
    sortedB.sorted_Insert(15);

    cout << "Sorted A: ";
    sortedA.display();
    cout << "Sorted B: ";
    sortedB.display();

    if (merged.merge(sortedA, sortedB))
    {
        cout << "Merged result: ";
        merged.display();
        cout << "Sorted A after merge: ";
        sortedA.display();
        cout << "Sorted B after merge: ";
        sortedB.display();
    }
    else
    {
        cout << "Merge failed." << endl;
    }

    cout << "\n========== Task 1.4 - Recursive Merge Sort ==========" << endl;
    
    CDLL unsorted;
    unsorted.insertAtEnd(7);
    unsorted.insertAtEnd(2);
    unsorted.insertAtEnd(11);
    unsorted.insertAtEnd(4);
    unsorted.insertAtEnd(9);
    unsorted.insertAtEnd(1);

    cout << "Before mergeSort: ";
    unsorted.display();
    unsorted.mergeSort();
    cout << "After mergeSort: ";
    unsorted.display();

    cout << "\n========== Task 1.5 - Insertion Sort ==========" << endl;
    
    CDLL unsorted2;
    unsorted2.insertAtEnd(5);
    unsorted2.insertAtEnd(2);
    unsorted2.insertAtEnd(8);
    unsorted2.insertAtEnd(3);
    unsorted2.insertAtEnd(1);
    unsorted2.insertAtEnd(6);

    cout << "Before insertionSort: ";
    unsorted2.display();
    unsorted2.insertionSort();
    cout << "After insertionSort: ";
    unsorted2.display();

    cout << "\n========== Display Methods Test ==========" << endl;
    
    CDLL testList;
    testList.insertAtEnd(10);
    testList.insertAtEnd(20);
    testList.insertAtEnd(30);
    testList.insertAtEnd(40);
    
    cout << "Forward display: ";
    testList.display();
    cout << "Backward display: ";
    testList.displayBackward();
    cout << "Circular display: ";
    testList.displayCircular();
    
    cout << "\nReverse test: ";
    testList.reverse();
    cout << "After reverse: ";
    testList.display();

    return 0;
}