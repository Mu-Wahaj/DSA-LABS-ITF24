#include "CDLL.h"
#include <iostream>
using namespace std;

int main()
{
    cout << "=== CDLL with Split, Shuffle, Combine ===\n\n";
    
    cout << "1. SPLIT FUNCTION:" << endl;
    CDLL original;
    original.insertAtEnd(10);
    original.insertAtEnd(20);
    original.insertAtEnd(30);
    original.insertAtEnd(40);
    original.insertAtEnd(50);
    
    cout << "Original list: ";
    original.display();
    
    CDLL firstPart, secondPart;
    original.split(firstPart, secondPart, 3);  // Split at position 3
    
    cout << "First part (positions 1-2): ";
    firstPart.display();   // 10 20
    cout << "Second part (positions 3-5): ";
    secondPart.display();  // 30 40 50
    cout << "Original after split (unchanged): ";
    original.display();    // Still 10 20 30 40 50
    
    cout << "\n2. SHUFFLE FUNCTION (Zigzag):" << endl;
    CDLL zigzagList;
    zigzagList.insertAtEnd(1);
    zigzagList.insertAtEnd(2);
    zigzagList.insertAtEnd(3);
    zigzagList.insertAtEnd(4);
    zigzagList.insertAtEnd(5);
    zigzagList.insertAtEnd(6);
    
    cout << "Original list for shuffle: ";
    zigzagList.display();  // 1 2 3 4 5 6
    
    CDLL oddPositions, evenPositions;
    zigzagList.shuffle(oddPositions, evenPositions);
    
    cout << "Odd positions (1,3,5): ";
    oddPositions.display();    // 1 3 5
    cout << "Even positions (2,4,6): ";
    evenPositions.display();   // 2 4 6
    
    cout << "\n3. COMBINE FUNCTION:" << endl;
    CDLL listA, listB, combined;
    
    listA.insertAtEnd(100);
    listA.insertAtEnd(200);
    listA.insertAtEnd(300);
    
    listB.insertAtEnd(400);
    listB.insertAtEnd(500);
    
    cout << "List A: ";
    listA.display();
    cout << "List B: ";
    listB.display();
    
    combined.combine(listA, listB);
    cout << "Combined (A then B): ";
    combined.display();  // 100 200 300 400 500
    
    // ========== COMPLEX EXAMPLE ==========
    cout << "\n4. COMPLEX EXAMPLE - Split then Shuffle:" << endl;
    CDLL master;
    for(int i = 1; i <= 10; i++)
    {
        master.insertAtEnd(i);
    }
    cout << "Master list: ";
    master.display();  // 1 2 3 4 5 6 7 8 9 10
    
    CDLL left, right;
    master.split(left, right, 6);  // Split at position 6
    cout << "Left part (1-5): ";
    left.display();    // 1 2 3 4 5
    cout << "Right part (6-10): ";
    right.display();   // 6 7 8 9 10
    
    CDLL odd, even;
    left.shuffle(odd, even);  // Shuffle left part
    cout << "Left shuffled - Odd positions: ";
    odd.display();     // 1 3 5
    cout << "Left shuffled - Even positions: ";
    even.display();    // 2 4
    
    return 0;
}