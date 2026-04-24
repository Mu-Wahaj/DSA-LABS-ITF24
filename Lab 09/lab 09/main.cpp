#include "CDLL.h"
#include <iostream>
using namespace std;

int main()
{
    cout << "Task 1.1 - Shuffle Merge" << endl;
    
    CDLL original;
    for(int i = 1; i <= 10; i++)
    {
        original.insertAtEnd(i);
    }
    
    cout << "Original list: ";
    original.display();
    
    CDLL list1, list2;
    original.shuffleMerge(list1, list2);
    
    cout << "List1 : ";
    list1.display();
    
    cout << "List2 : ";
    list2.display();
    
    cout << "\nTask 1.2 - Split List" << endl;
    
    CDLL Mlist;
    Mlist.insertAtEnd(10);
    Mlist.insertAtEnd(20);
    Mlist.insertAtEnd(30);
    Mlist.insertAtEnd(40);
    Mlist.insertAtEnd(50);
    Mlist.insertAtEnd(60);
    
    cout << "Original list: ";
    Mlist.display();
    
    CDLL leftHalf, rightHalf;
    Mlist.splitList(leftHalf, rightHalf);
    
    cout << "Left half: ";
    leftHalf.display();
    
    cout << "Right half: ";
    rightHalf.display();
    
    cout << "\nTask 1.3 - isSorted Function" << endl;
    
    CDLL sorted;
    sorted.insertAtEnd(5);
    sorted.insertAtEnd(10);
    sorted.insertAtEnd(15);
    sorted.insertAtEnd(20);
    
    cout << "Sorted list: ";
    sorted.display();
    cout << "Is sorted: " << (sorted.isSorted() ? "Yes" : "No") << endl;
    
    CDLL unsorted;
    unsorted.insertAtEnd(5);
    unsorted.insertAtEnd(20);
    unsorted.insertAtEnd(10);
    unsorted.insertAtEnd(15);
    
    cout << "Unsorted list: ";
    unsorted.display();
    cout << "Is sorted: " << (unsorted.isSorted() ? "Yes" : "No") << endl;
    
    cout << "\nTask 1.4 - Remove Functions" << endl;
    
    CDLL test;
    test.insertAtEnd(4);
    test.insertAtEnd(2);
    test.insertAtEnd(8);
    test.insertAtEnd(1);
    test.insertAtEnd(9);
    test.insertAtEnd(5);
    test.insertAtEnd(4);
    test.insertAtEnd(6);
    
    cout << "Original list: ";
    test.display();
    
    int val;
    
    if(test.removeLastNode(val))
    {
        cout << "Removed last node value: " << val << endl;
        cout << "List after removal: ";
        test.display();
    }
    
    if(test.removeSecondLastNode(val))
    {
        cout << "Removed second last node value: " << val << endl;
        cout << "List after removal: ";
        test.display();
    }
    
    CDLL kthTest;
    kthTest.insertAtEnd(4);
    kthTest.insertAtEnd(2);
    kthTest.insertAtEnd(8);
    kthTest.insertAtEnd(1);
    kthTest.insertAtEnd(9);
    kthTest.insertAtEnd(5);
    kthTest.insertAtEnd(4);
    kthTest.insertAtEnd(6);
    
    cout << "\nRemove Kth Node Test" << endl;
    cout << "Original list: ";
    kthTest.display();
    
    int k = 4;
    if(kthTest.removeKthNode(k, val))
    {
        cout << "Removed " << k << "th node with value: " << val << endl;
        cout << "List after removal: ";
        kthTest.display();
    }
    
    cout << "\nEdge Cases" << endl;
    
    CDLL single;
    single.insertAtEnd(100);
    cout << "Single node list: ";
    single.display();
    
    if(single.removeLastNode(val))
    {
        cout << "Removed: " << val << endl;
        cout << "List now: ";
        single.display();
    }
    
    CDLL twoNodes;
    twoNodes.insertAtEnd(10);
    twoNodes.insertAtEnd(20);
    cout << "Two node list: ";
    twoNodes.display();
    
    if(twoNodes.removeSecondLastNode(val))
    {
        cout << "Removed second last: " << val << endl;
        cout << "List now: ";
        twoNodes.display();
    }
    
    return 0;
}