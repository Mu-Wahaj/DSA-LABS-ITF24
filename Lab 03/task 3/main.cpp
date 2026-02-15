#include <iostream>
#include "UnsortedList.h"
using namespace std;

int main()
{
    UnsortedList list1(10);  

    cout << "Inserting elements into Unsorted List:";
    cout << endl;
    list1.insert(5);
    list1.insert(3);
    list1.insert(7);
    list1.insert(3);
    list1.insert(9);

    cout << "Unsorted List elements:";
        cout << endl;

    list1.display();

    cout << "Removing all occurrences of 3 :";
        cout << endl;

    int removed = list1.removeAll(3);
    cout << "Removed count: " << removed << endl;

    cout << "Updated Unsorted List:";
    list1.display();

    cout << "Inserting elements into List 2:" << endl;
    UnsortedList list2(10);
    list2.insert(3);
    list2.insert(4);
    list2.insert(7);
    list2.insert(10);

    cout << "List 2 elements:" << endl;
    list2.display();

    cout << endl;

  
    cout << "Intersection of List 1 and List 2:" << endl;

    UnsortedList result = list1.intersection(list2);
    result.display();

    cout << endl;

   
    cout << "Checking if List 1 is subset of List 2:" << endl;

    if (list1.isSubset(list2))
        cout << "List 1 is a subset of List 2" << endl;
    else
        cout << "List 1 is NOT a subset of List 2" << endl;

    cout << endl;

    cout << "Checking if Intersection is subset of List 1:" << endl;

    if (result.isSubset(list1))
        cout << "Intersection is a subset of List 1" << endl;
    else
        cout << "Intersection is NOT a subset of List 1" << endl;

    return 0;
}


