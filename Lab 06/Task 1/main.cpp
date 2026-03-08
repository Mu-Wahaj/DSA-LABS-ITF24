#include <iostream>
#include "Deque.h"
using namespace std;

int main() {
    int size, choice, value, removedValue;
    
    cout << "Enter the size of Deque: ";
    cin >> size;
    
    Deque dq(size);
    
    do {
        cout << "\n1. Insert value at Front" << endl;
        cout << "2. Insert value at Back" << endl;
        cout << "3. Remove value from Front" << endl;
        cout << "4. Remove value from Back" << endl;
        cout << "5. Display the Deque" << endl;
        cout << "6. Make the Deque Empty" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch(choice) {
            case 1:
                cout << "Enter value to insert at front: ";
                cin >> value;
                if (dq.insertAtFront(value)) {
                    cout << "Value inserted successfully" << endl;
                } else {
                    cout << "Deque is full. Cannot insert" << endl;
                }
                break;
                
            case 2:
                cout << "Enter value to insert at back: ";
                cin >> value;
                if (dq.insertAtBack(value)) {
                    cout << "Value inserted successfully" << endl;
                } else {
                    cout << "Deque is full. Cannot insert" << endl;
                }
                break;
                
            case 3:
                if (dq.removeFromFront(removedValue)) {
                    cout << "Removed value: " << removedValue << endl;
                } else {
                    cout << "Deque is empty. Cannot remove" << endl;
                }
                break;
                
            case 4:
                if (dq.removeFromBack(removedValue)) {
                    cout << "Removed value: " << removedValue << endl;
                } else {
                    cout << "Deque is empty. Cannot remove" << endl;
                }
                break;
                
            case 5:
                cout << "Deque elements: ";
                dq.display();
                break;
                
            case 6:
                dq.makeEmpty();
                cout << "Deque has been emptied" << endl;
                break;
                
            case 7:
                cout << "Exiting program" << endl;
                break;
                
            default:
                cout << "Invalid choice. Please try again" << endl;
        }
    } while (choice != 7);
    
    return 0;
}