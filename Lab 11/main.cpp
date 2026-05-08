// Muhammad Wahaj
// BITF24M059
// main.cpp - Lab 11 Driver (BST + StudentBST)

#include <iostream>
#include <string>
#include "BST.h"
#include "StudentBST.h"
using namespace std;

// -------------------------------------------------------
// bstMenu
// Menu-driven driver for the integer BST (Tasks 1.1 - 1.8)
// -------------------------------------------------------

void bstMenu() {
    BST tree;
    int choice, val;

    do {
        cout << "\n========== Integer BST Menu ==========" << endl;
        cout << " 1.  Insert a value" << endl;
        cout << " 2.  Search a value (iterative)" << endl;
        cout << " 3.  Remove a value" << endl;
        cout << " 4.  Display values - Pre-order" << endl;
        cout << " 5.  Display values - In-order" << endl;
        cout << " 6.  Display values - Post-order" << endl;
        cout << " 7.  Get height of BST" << endl;
        cout << " 8.  Count total nodes" << endl;
        cout << " 9.  Search a value (recursive)" << endl;
        cout << " 10. Find minimum value (iterative)" << endl;
        cout << " 11. Find maximum value (iterative)" << endl;
        cout << " 12. Find minimum value (recursive)" << endl;
        cout << " 13. Find maximum value (recursive)" << endl;
        cout << " 14. Build balanced BST from sorted array" << endl;
        cout << " 15. Back to main menu" << endl;
        cout << "=======================================" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter value to insert: ";
            cin >> val;
            if (tree.insert(val))
                cout << val << " inserted successfully." << endl;
            else
                cout << val << " already exists. Duplicate not allowed." << endl;

        } else if (choice == 2) {
            cout << "Enter value to search: ";
            cin >> val;
            if (tree.search(val))
                cout << val << " was found in the tree." << endl;
            else
                cout << val << " was not found in the tree." << endl;

        } else if (choice == 3) {
            cout << "Enter value to remove: ";
            cin >> val;
            if (tree.remove(val))
                cout << val << " removed successfully." << endl;
            else
                cout << val << " was not found. Nothing removed." << endl;

        } else if (choice == 4) {
            cout << "Pre-order traversal  : ";
            tree.preOrder();

        } else if (choice == 5) {
            cout << "In-order traversal   : ";
            tree.inOrder();

        } else if (choice == 6) {
            cout << "Post-order traversal : ";
            tree.postOrder();

        } else if (choice == 7) {
            cout << "Height of the BST    : " << tree.getHeight() << endl;

        } else if (choice == 8) {
            cout << "Total nodes in BST   : " << tree.countNodes() << endl;

        } else if (choice == 9) {
            cout << "Enter value to search (recursive): ";
            cin >> val;
            if (tree.recSearch(val))
                cout << val << " was found in the tree." << endl;
            else
                cout << val << " was not found in the tree." << endl;

        } else if (choice == 10) {
            int minVal = tree.findMin();
            if (minVal != -1)
                cout << "Minimum value (iterative) : " << minVal << endl;

        } else if (choice == 11) {
            int maxVal = tree.findMax();
            if (maxVal != -1)
                cout << "Maximum value (iterative) : " << maxVal << endl;

        } else if (choice == 12) {
            int minVal = tree.findMinRec();
            if (minVal != -1)
                cout << "Minimum value (recursive) : " << minVal << endl;

        } else if (choice == 13) {
            int maxVal = tree.findMaxRec();
            if (maxVal != -1)
                cout << "Maximum value (recursive) : " << maxVal << endl;

        } else if (choice == 14) {
            int arr[] = {7, 10, 14, 20, 36, 47, 55, 63, 72, 86, 92};
            int size  = 11;
            tree.createBalancedTree(arr, 0, size - 1);
            cout << "Balanced BST created from array { 7 10 14 20 36 47 55 63 72 86 92 }." << endl;
            cout << "Pre-order  : ";
            tree.preOrder();
            cout << "In-order   : ";
            tree.inOrder();
            cout << "Post-order : ";
            tree.postOrder();

        } else if (choice != 15) {
            cout << "Invalid choice. Please enter a number between 1 and 15." << endl;
        }

    } while (choice != 15);
}

// -------------------------------------------------------
// studentBSTMenu
// Menu-driven driver for StudentBST (Tasks 2.1 - 2.7)
// -------------------------------------------------------

void studentBSTMenu() {
    StudentBST tree;
    int choice, rn, rStart, rEnd;
    string name;
    double cgpa;

    do {
        cout << "\n========== Student BST Menu ==========" << endl;
        cout << " 1. Insert a new student" << endl;
        cout << " 2. Search for a student by Roll No." << endl;
        cout << " 3. Remove a student by Roll No." << endl;
        cout << " 4. Display all students (sorted by Roll No.)" << endl;
        cout << " 5. Display students in a Roll No. range" << endl;
        cout << " 6. Back to main menu" << endl;
        cout << "=======================================" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter roll number : ";
            cin >> rn;
            cout << "Enter name        : ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter CGPA        : ";
            cin >> cgpa;
            if (tree.insert(rn, name, cgpa))
                cout << "Student inserted successfully." << endl;
            else
                cout << "Roll number " << rn << " already exists. Insert failed." << endl;

        } else if (choice == 2) {
            cout << "Enter roll number to search: ";
            cin >> rn;
            tree.search(rn);

        } else if (choice == 3) {
            cout << "Enter roll number to remove: ";
            cin >> rn;
            if (tree.remove(rn))
                cout << "Student with roll number " << rn << " removed successfully." << endl;
            else
                cout << "Student with roll number " << rn << " not found. Nothing removed." << endl;

        } else if (choice == 4) {
            tree.inOrder();

        } else if (choice == 5) {
            cout << "Enter starting roll number : ";
            cin >> rStart;
            cout << "Enter ending roll number   : ";
            cin >> rEnd;
            tree.displayInRange(rStart, rEnd);

        } else if (choice != 6) {
            cout << "Invalid choice. Please enter a number between 1 and 6." << endl;
        }

    } while (choice != 6);
}

// -------------------------------------------------------
// main
// Top-level menu to choose between the two BST types
// -------------------------------------------------------

int main() {
    int choice;

    do {
        cout << "\n===== Lab 11 - Binary Search Trees =====" << endl;
        cout << " 1. Integer BST  (Tasks 1.1 to 1.8)" << endl;
        cout << " 2. Student BST  (Tasks 2.1 to 2.7)" << endl;
        cout << " 3. Exit" << endl;
        cout << "=========================================" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
            bstMenu();
        else if (choice == 2)
            studentBSTMenu();
        else if (choice != 3)
            cout << "Invalid choice. Please enter 1, 2, or 3." << endl;

    } while (choice != 3);

    cout << "Goodbye!" << endl;
    return 0;
}
