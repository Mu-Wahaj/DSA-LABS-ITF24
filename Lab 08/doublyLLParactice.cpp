#include <iostream>
using namespace std;

class DoublyLinkedList {
public:
    class Node {
    public:
        int data;
        Node* next;
        Node* prev;
        Node(int val) : data(val), next(nullptr), prev(nullptr) {}
    };
    
private:
    Node* head;
    Node* tail;
    
public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}
    ~DoublyLinkedList();
    
    // ========== INSERTION ==========
    void insertAtStart(int val);           // Iterative O(1)
    void insertAtEnd(int val);             // Iterative O(1)
    bool insertAtPosition(int pos, int val);  // Iterative
    
    // ========== DELETION ==========
    bool deleteAtStart(int& val);          // Iterative O(1)
    bool deleteAtEnd(int& val);            // Iterative O(1)
    bool deleteAtPosition(int pos, int& val);  // Iterative
    int deleteAllOccurrences(int val);     // Iterative
    
    // ========== TRAVERSAL ==========
    void displayForward();                 // Iterative
    void displayBackward();                // Iterative
    void displayForwardRecursive();        // Recursive
    void displayBackwardRecursive();       // Recursive
    void printReverse();                   // Iterative (backward traversal)
    
    // ========== RECURSIVE OPERATIONS ==========
    int countNodesRecursive();             // Recursive
    int sumNodesRecursive();               // Recursive
    int findMaxRecursive();                // Recursive
    int findMinRecursive();                // Recursive
    bool searchRecursive(int val);         // Recursive
    
    // ========== SEARCH & GET ==========
    bool search(int val);                  // Iterative
    int getMiddleNode();                   // Iterative
    int getNthNode(int pos);               // Iterative
    
    // ========== LIST MODIFICATION ==========
    void reverseList();                    // Iterative (swap prev/next)
    void reverseListRecursive();           // Recursive
    void removeDuplicates();               // Iterative (sorted list)
    
    // ========== HELPER ==========
    bool isEmpty() { return head == nullptr; }
    int countNodes();                      // Iterative
};

// ==================== DESTRUCTOR ====================
DoublyLinkedList::~DoublyLinkedList() {
    Node* current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
    head = tail = nullptr;
}

// ==================== INSERTION ====================

void DoublyLinkedList::insertAtStart(int val) {
    Node* newNode = new Node(val);
    if (head == nullptr) {
        head = tail = newNode;
        return;
    }
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

void DoublyLinkedList::insertAtEnd(int val) {
    Node* newNode = new Node(val);
    if (tail == nullptr) {
        head = tail = newNode;
        return;
    }
    newNode->prev = tail;
    tail->next = newNode;
    tail = newNode;
}

bool DoublyLinkedList::insertAtPosition(int pos, int val) {
    if (pos < 1) return false;
    
    if (pos == 1) {
        insertAtStart(val);
        return true;
    }
    
    Node* temp = head;
    for (int i = 1; i < pos; i++) {
        if (temp == nullptr) return false;
        temp = temp->next;
    }
    
    if (temp == nullptr) return false;
    
    Node* newNode = new Node(val);
    newNode->prev = temp->prev;
    newNode->next = temp;
    
    if (temp->prev != nullptr) {
        temp->prev->next = newNode;
    }
    temp->prev = newNode;
    
    return true;
}

// ==================== DELETION ====================

bool DoublyLinkedList::deleteAtStart(int& val) {
    if (head == nullptr) return false;
    
    Node* toDelete = head;
    val = toDelete->data;
    head = head->next;
    
    if (head != nullptr) {
        head->prev = nullptr;
    } else {
        tail = nullptr;
    }
    
    delete toDelete;
    return true;
}

bool DoublyLinkedList::deleteAtEnd(int& val) {
    if (tail == nullptr) return false;
    
    Node* toDelete = tail;
    val = toDelete->data;
    tail = tail->prev;
    
    if (tail != nullptr) {
        tail->next = nullptr;
    } else {
        head = nullptr;
    }
    
    delete toDelete;
    return true;
}

bool DoublyLinkedList::deleteAtPosition(int pos, int& val) {
    if (head == nullptr || pos < 1) return false;
    
    if (pos == 1) {
        return deleteAtStart(val);
    }
    
    Node* temp = head;
    for (int i = 1; i < pos; i++) {
        if (temp == nullptr) return false;
        temp = temp->next;
    }
    
    if (temp == nullptr) return false;
    
    val = temp->data;
    temp->prev->next = temp->next;
    
    if (temp->next != nullptr) {
        temp->next->prev = temp->prev;
    } else {
        tail = temp->prev;
    }
    
    delete temp;
    return true;
}

int DoublyLinkedList::deleteAllOccurrences(int val) {
    int count = 0;
    Node* current = head;
    
    while (current != nullptr) {
        if (current->data == val) {
            Node* toDelete = current;
            if (current->prev != nullptr) {
                current->prev->next = current->next;
            } else {
                head = current->next;
            }
            
            if (current->next != nullptr) {
                current->next->prev = current->prev;
            } else {
                tail = current->prev;
            }
            
            current = current->next;
            delete toDelete;
            count++;
        } else {
            current = current->next;
        }
    }
    return count;
}

// ==================== TRAVERSAL ====================

void DoublyLinkedList::displayForward() {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void DoublyLinkedList::displayBackward() {
    Node* temp = tail;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->prev;
    }
    cout << endl;
}

// Recursive forward display
void displayForwardRecursiveHelper(DoublyLinkedList::Node* node) {
    if (node == nullptr) return;
    cout << node->data << " ";
    displayForwardRecursiveHelper(node->next);
}

void DoublyLinkedList::displayForwardRecursive() {
    displayForwardRecursiveHelper(head);
    cout << endl;
}

// Recursive backward display
void displayBackwardRecursiveHelper(DoublyLinkedList::Node* node) {
    if (node == nullptr) return;
    cout << node->data << " ";
    displayBackwardRecursiveHelper(node->prev);
}

void DoublyLinkedList::displayBackwardRecursive() {
    displayBackwardRecursiveHelper(tail);
    cout << endl;
}

void DoublyLinkedList::printReverse() {
    displayBackward();  // Same as backward traversal
}

// ==================== RECURSIVE OPERATIONS ====================

int countRecursiveHelper(DoublyLinkedList::Node* node) {
    if (node == nullptr) return 0;
    return 1 + countRecursiveHelper(node->next);
}

int DoublyLinkedList::countNodesRecursive() {
    return countRecursiveHelper(head);
}

int sumRecursiveHelper(DoublyLinkedList::Node* node) {
    if (node == nullptr) return 0;
    return node->data + sumRecursiveHelper(node->next);
}

int DoublyLinkedList::sumNodesRecursive() {
    return sumRecursiveHelper(head);
}

int maxRecursiveHelper(DoublyLinkedList::Node* node) {
    if (node == nullptr) return -999;
    int restMax = maxRecursiveHelper(node->next);
    return (node->data > restMax) ? node->data : restMax;
}

int DoublyLinkedList::findMaxRecursive() {
    if (head == nullptr) return -999;
    return maxRecursiveHelper(head);
}

int minRecursiveHelper(DoublyLinkedList::Node* node) {
    if (node == nullptr) return 999;
    int restMin = minRecursiveHelper(node->next);
    return (node->data < restMin) ? node->data : restMin;
}

int DoublyLinkedList::findMinRecursive() {
    if (head == nullptr) return 999;
    return minRecursiveHelper(head);
}

bool searchRecursiveHelper(DoublyLinkedList::Node* node, int val) {
    if (node == nullptr) return false;
    if (node->data == val) return true;
    return searchRecursiveHelper(node->next, val);
}

bool DoublyLinkedList::searchRecursive(int val) {
    return searchRecursiveHelper(head, val);
}

// ==================== SEARCH & GET ====================

bool DoublyLinkedList::search(int val) {
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->data == val) return true;
        temp = temp->next;
    }
    return false;
}

int DoublyLinkedList::getMiddleNode() {
    if (head == nullptr) return -1;
    
    Node* slow = head;
    Node* fast = head;
    
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    return slow->data;
}

int DoublyLinkedList::getNthNode(int pos) {
    if (pos < 1) return -1;
    
    Node* temp = head;
    for (int i = 1; i < pos; i++) {
        if (temp == nullptr) return -1;
        temp = temp->next;
    }
    
    if (temp == nullptr) return -1;
    return temp->data;
}

int DoublyLinkedList::countNodes() {
    int count = 0;
    Node* temp = head;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}

// ==================== LIST MODIFICATION ====================

void DoublyLinkedList::reverseList() {
    if (head == nullptr) return;
    
    Node* current = head;
    Node* temp = nullptr;
    
    while (current != nullptr) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    
    if (temp != nullptr) {
        head = temp->prev;
    }
    
    // Update tail
    tail = head;
    while (tail != nullptr && tail->next != nullptr) {
        tail = tail->next;
    }
}

void reverseRecursiveHelper(DoublyLinkedList::Node* node, DoublyLinkedList::Node*& newHead) {
    if (node == nullptr) return;
    
    DoublyLinkedList::Node* temp = node->prev;
    node->prev = node->next;
    node->next = temp;
    
    if (node->prev == nullptr) {
        newHead = node;
    }
    
    reverseRecursiveHelper(node->prev, newHead);
}

void DoublyLinkedList::reverseListRecursive() {
    if (head == nullptr) return;
    reverseRecursiveHelper(head, head);
    
    // Update tail
    tail = head;
    while (tail != nullptr && tail->next != nullptr) {
        tail = tail->next;
    }
}

void DoublyLinkedList::removeDuplicates() {
    if (head == nullptr) return;
    
    Node* current = head;
    while (current->next != nullptr) {
        if (current->data == current->next->data) {
            Node* toDelete = current->next;
            current->next = toDelete->next;
            if (toDelete->next != nullptr) {
                toDelete->next->prev = current;
            } else {
                tail = current;
            }
            delete toDelete;
        } else {
            current = current->next;
        }
    }
}