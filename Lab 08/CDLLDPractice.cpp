#include <iostream>
using namespace std;

class CDLLD {
private:
    class DNode {
    public:
        int data;
        DNode* next;
        DNode* prev;
        DNode(int val = 0) : data(val), next(this), prev(this) {}
    };
    
    DNode head;  // Dummy header node (data not used)
    
public:
    CDLLD();
    ~CDLLD();
    
    // ========== INSERTION ==========
    void insertAtStart(int val);        // O(1)
    void insertAtEnd(int val);          // O(1)
    bool insertAtPosition(int pos, int val);
    
    // ========== DELETION ==========
    bool deleteAtStart(int& val);       // O(1)
    bool deleteAtEnd(int& val);         // O(1)
    bool deleteAtPosition(int pos, int& val);
    int deleteAllOccurrences(int val);
    bool removeLastNode(int& val);      // O(1)
    bool removeSecondLastNode(int& val); // O(1)
    bool removeKthNode(int k, int& val);
    
    // ========== TRAVERSAL ==========
    void displayForward();
    void displayBackward();
    void displayForwardRecursive();
    void displayBackwardRecursive();
    
    // ========== RECURSIVE OPERATIONS ==========
    int countNodesRecursive();
    int sumNodesRecursive();
    int findMaxRecursive();
    int findMinRecursive();
    bool searchRecursive(int val);
    
    // ========== SEARCH & GET ==========
    bool search(int val);
    int getMiddleNode();
    int getNthNode(int pos);
    int countNodes();
    bool isEmpty();
    bool isSorted();
    
    // ========== LIST MODIFICATION ==========
    void reverseList();
    void removeDuplicates();
    void combine(CDLLD& list1, CDLLD& list2);        // O(1)
    void shuffleMerge(CDLLD& list1, CDLLD& list2);
    void splitList(CDLLD& leftHalf, CDLLD& rightHalf);
    bool merge(CDLLD& list1, CDLLD& list2);          // Merge two sorted lists
    void mergeSort();                                 // Recursive merge sort
    void insertionSort();
    
private:
    // Recursive helpers
    void displayForwardRecursiveHelper(DNode* node);
    void displayBackwardRecursiveHelper(DNode* node);
    int countRecursiveHelper(DNode* node);
    int sumRecursiveHelper(DNode* node);
    int maxRecursiveHelper(DNode* node);
    int minRecursiveHelper(DNode* node);
    bool searchRecursiveHelper(DNode* node, int val);
    DNode* mergeSortedLists(DNode* list1Head, DNode* list2Head);
    DNode* mergeSortRecursive(DNode* node);
    void splitListHelper(DNode* source, DNode*& front, DNode*& back);
};

// ==================== CONSTRUCTOR ====================
CDLLD::CDLLD() {
    head.next = &head;
    head.prev = &head;
}

// ==================== DESTRUCTOR ====================
CDLLD::~CDLLD() {
    DNode* current = head.next;
    while (current != &head) {
        DNode* temp = current;
        current = current->next;
        delete temp;
    }
    head.next = &head;
    head.prev = &head;
}

// ==================== HELPER ====================
bool CDLLD::isEmpty() {
    return head.next == &head;
}

int CDLLD::countNodes() {
    int count = 0;
    DNode* temp = head.next;
    while (temp != &head) {
        count++;
        temp = temp->next;
    }
    return count;
}

// ==================== INSERTION ====================

void CDLLD::insertAtStart(int val) {
    DNode* newNode = new DNode(val);
    newNode->next = head.next;
    newNode->prev = &head;
    head.next->prev = newNode;
    head.next = newNode;
}

void CDLLD::insertAtEnd(int val) {
    DNode* newNode = new DNode(val);
    newNode->next = &head;
    newNode->prev = head.prev;
    head.prev->next = newNode;
    head.prev = newNode;
}

bool CDLLD::insertAtPosition(int pos, int val) {
    if (pos < 1) return false;
    
    if (pos == 1) {
        insertAtStart(val);
        return true;
    }
    
    DNode* temp = head.next;
    for (int i = 1; i < pos - 1; i++) {
        if (temp == &head) return false;
        temp = temp->next;
    }
    
    if (temp == &head) return false;
    
    DNode* newNode = new DNode(val);
    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;
    
    return true;
}

// ==================== DELETION ====================

bool CDLLD::deleteAtStart(int& val) {
    if (isEmpty()) return false;
    
    DNode* toDelete = head.next;
    val = toDelete->data;
    
    head.next = toDelete->next;
    toDelete->next->prev = &head;
    
    delete toDelete;
    return true;
}

bool CDLLD::deleteAtEnd(int& val) {
    if (isEmpty()) return false;
    
    DNode* toDelete = head.prev;
    val = toDelete->data;
    
    head.prev = toDelete->prev;
    toDelete->prev->next = &head;
    
    delete toDelete;
    return true;
}

bool CDLLD::removeLastNode(int& val) {
    return deleteAtEnd(val);
}

bool CDLLD::removeSecondLastNode(int& val) {
    if (countNodes() < 2) return false;
    
    DNode* secondLast = head.prev->prev;
    val = secondLast->data;
    
    secondLast->prev->next = secondLast->next;
    secondLast->next->prev = secondLast->prev;
    
    delete secondLast;
    return true;
}

bool CDLLD::removeKthNode(int k, int& val) {
    if (k < 1 || isEmpty()) return false;
    
    DNode* temp = head.next;
    for (int i = 1; i < k; i++) {
        if (temp == &head) return false;
        temp = temp->next;
    }
    
    if (temp == &head) return false;
    
    val = temp->data;
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    
    delete temp;
    return true;
}

bool CDLLD::deleteAtPosition(int pos, int& val) {
    return removeKthNode(pos, val);
}

int CDLLD::deleteAllOccurrences(int val) {
    int count = 0;
    DNode* current = head.next;
    
    while (current != &head) {
        if (current->data == val) {
            DNode* toDelete = current;
            current = current->next;
            toDelete->prev->next = toDelete->next;
            toDelete->next->prev = toDelete->prev;
            delete toDelete;
            count++;
        } else {
            current = current->next;
        }
    }
    return count;
}

// ==================== TRAVERSAL ====================

void CDLLD::displayForward() {
    if (isEmpty()) {
        cout << "List is empty" << endl;
        return;
    }
    
    DNode* temp = head.next;
    while (temp != &head) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void CDLLD::displayBackward() {
    if (isEmpty()) {
        cout << "List is empty" << endl;
        return;
    }
    
    DNode* temp = head.prev;
    while (temp != &head) {
        cout << temp->data << " ";
        temp = temp->prev;
    }
    cout << endl;
}

void CDLLD::displayForwardRecursiveHelper(DNode* node) {
    if (node == &head) return;
    cout << node->data << " ";
    displayForwardRecursiveHelper(node->next);
}

void CDLLD::displayForwardRecursive() {
    if (isEmpty()) {
        cout << "List is empty" << endl;
        return;
    }
    displayForwardRecursiveHelper(head.next);
    cout << endl;
}

void CDLLD::displayBackwardRecursiveHelper(DNode* node) {
    if (node == &head) return;
    cout << node->data << " ";
    displayBackwardRecursiveHelper(node->prev);
}

void CDLLD::displayBackwardRecursive() {
    if (isEmpty()) {
        cout << "List is empty" << endl;
        return;
    }
    displayBackwardRecursiveHelper(head.prev);
    cout << endl;
}

// ==================== RECURSIVE OPERATIONS ====================

int CDLLD::countRecursiveHelper(DNode* node) {
    if (node == &head) return 0;
    return 1 + countRecursiveHelper(node->next);
}

int CDLLD::countNodesRecursive() {
    return countRecursiveHelper(head.next);
}

int CDLLD::sumRecursiveHelper(DNode* node) {
    if (node == &head) return 0;
    return node->data + sumRecursiveHelper(node->next);
}

int CDLLD::sumNodesRecursive() {
    return sumRecursiveHelper(head.next);
}

int CDLLD::maxRecursiveHelper(DNode* node) {
    if (node == &head) return -999;
    int restMax = maxRecursiveHelper(node->next);
    return (node->data > restMax) ? node->data : restMax;
}

int CDLLD::findMaxRecursive() {
    if (isEmpty()) return -999;
    return maxRecursiveHelper(head.next);
}

int CDLLD::minRecursiveHelper(DNode* node) {
    if (node == &head) return 999;
    int restMin = minRecursiveHelper(node->next);
    return (node->data < restMin) ? node->data : restMin;
}

int CDLLD::findMinRecursive() {
    if (isEmpty()) return 999;
    return minRecursiveHelper(head.next);
}

bool CDLLD::searchRecursiveHelper(DNode* node, int val) {
    if (node == &head) return false;
    if (node->data == val) return true;
    return searchRecursiveHelper(node->next, val);
}

bool CDLLD::searchRecursive(int val) {
    return searchRecursiveHelper(head.next, val);
}

// ==================== SEARCH & GET ====================

bool CDLLD::search(int val) {
    DNode* temp = head.next;
    while (temp != &head) {
        if (temp->data == val) return true;
        temp = temp->next;
    }
    return false;
}

int CDLLD::getMiddleNode() {
    if (isEmpty()) return -1;
    
    DNode* slow = head.next;
    DNode* fast = head.next;
    
    while (fast != &head && fast->next != &head) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    return slow->data;
}

int CDLLD::getNthNode(int pos) {
    if (pos < 1) return -1;
    
    DNode* temp = head.next;
    for (int i = 1; i < pos; i++) {
        if (temp == &head) return -1;
        temp = temp->next;
    }
    
    if (temp == &head) return -1;
    return temp->data;
}

bool CDLLD::isSorted() {
    if (isEmpty() || head.next->next == &head) return true;
    
    DNode* temp = head.next;
    while (temp->next != &head) {
        if (temp->data > temp->next->data) return false;
        temp = temp->next;
    }
    return true;
}

// ==================== LIST MODIFICATION ====================

void CDLLD::reverseList() {
    if (isEmpty()) return;
    
    DNode* current = head.next;
    DNode* start = current;
    DNode* temp = nullptr;
    
    do {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    } while (current != start);
    
    // Update head connections
    temp = head.next;
    head.next = head.prev;
    head.prev = temp;
}

void CDLLD::removeDuplicates() {
    if (isEmpty()) return;
    
    DNode* current = head.next;
    while (current != &head && current->next != &head) {
        if (current->data == current->next->data) {
            DNode* toDelete = current->next;
            current->next = toDelete->next;
            toDelete->next->prev = current;
            delete toDelete;
        } else {
            current = current->next;
        }
    }
}

void CDLLD::combine(CDLLD& list1, CDLLD& list2) {
    if (list1.isEmpty() && list2.isEmpty()) {
        return;
    }
    
    if (list1.isEmpty()) {
        head.next = list2.head.next;
        head.prev = list2.head.prev;
        list2.head.next->prev = &head;
        list2.head.prev->next = &head;
        list2.head.next = &list2.head;
        list2.head.prev = &list2.head;
        return;
    }
    
    if (list2.isEmpty()) {
        head.next = list1.head.next;
        head.prev = list1.head.prev;
        list1.head.next->prev = &head;
        list1.head.prev->next = &head;
        list1.head.next = &list1.head;
        list1.head.prev = &list1.head;
        return;
    }
    
    // Connect list1's end to list2's start
    list1.head.prev->next = list2.head.next;
    list2.head.next->prev = list1.head.prev;
    
    // Connect list2's end to head
    list2.head.prev->next = &head;
    head.prev = list2.head.prev;
    
    // Connect head to list1's start
    head.next = list1.head.next;
    list1.head.next->prev = &head;
    
    // Empty both lists
    list1.head.next = &list1.head;
    list1.head.prev = &list1.head;
    list2.head.next = &list2.head;
    list2.head.prev = &list2.head;
}

void CDLLD::shuffleMerge(CDLLD& list1, CDLLD& list2) {
    if (list1.isEmpty() && list2.isEmpty()) return;
    if (list1.isEmpty()) {
        combine(list1, list2);
        return;
    }
    if (list2.isEmpty()) {
        combine(list1, list2);
        return;
    }
    
    DNode* p1 = list1.head.next;
    DNode* p2 = list2.head.next;
    DNode* last = &head;
    
    while (p1 != &list1.head && p2 != &list2.head) {
        DNode* next1 = p1->next;
        DNode* next2 = p2->next;
        
        last->next = p1;
        p1->prev = last;
        last = p1;
        
        last->next = p2;
        p2->prev = last;
        last = p2;
        
        p1 = next1;
        p2 = next2;
    }
    
    while (p1 != &list1.head) {
        DNode* next1 = p1->next;
        last->next = p1;
        p1->prev = last;
        last = p1;
        p1 = next1;
    }
    
    while (p2 != &list2.head) {
        DNode* next2 = p2->next;
        last->next = p2;
        p2->prev = last;
        last = p2;
        p2 = next2;
    }
    
    last->next = &head;
    head.prev = last;
    
    list1.head.next = &list1.head;
    list1.head.prev = &list1.head;
    list2.head.next = &list2.head;
    list2.head.prev = &list2.head;
}

void CDLLD::splitListHelper(DNode* source, DNode*& front, DNode*& back) {
    if (source == nullptr || source->next == nullptr) {
        front = source;
        back = nullptr;
        return;
    }
    
    DNode* slow = source;
    DNode* fast = source->next;
    
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    front = source;
    back = slow->next;
    slow->next = nullptr;
    
    if (back != nullptr) {
        back->prev = nullptr;
    }
    if (front != nullptr) {
        front->prev = nullptr;
    }
}

CDLLD::DNode* CDLLD::mergeSortedLists(DNode* list1Head, DNode* list2Head) {
    if (list1Head == nullptr) return list2Head;
    if (list2Head == nullptr) return list1Head;
    
    DNode* result = nullptr;
    
    if (list1Head->data <= list2Head->data) {
        result = list1Head;
        result->next = mergeSortedLists(list1Head->next, list2Head);
        if (result->next != nullptr) {
            result->next->prev = result;
        }
    } else {
        result = list2Head;
        result->next = mergeSortedLists(list1Head, list2Head->next);
        if (result->next != nullptr) {
            result->next->prev = result;
        }
    }
    
    return result;
}

CDLLD::DNode* CDLLD::mergeSortRecursive(DNode* node) {
    if (node == nullptr || node->next == nullptr) return node;
    
    DNode* front = nullptr;
    DNode* back = nullptr;
    splitListHelper(node, front, back);
    
    front = mergeSortRecursive(front);
    back = mergeSortRecursive(back);
    
    return mergeSortedLists(front, back);
}

void CDLLD::mergeSort() {
    if (isEmpty() || head.next->next == &head) return;
    
    // Detach from dummy header
    DNode* first = head.next;
    first->prev = nullptr;
    head.prev->next = nullptr;
    
    // Sort
    first = mergeSortRecursive(first);
    
    // Reattach to dummy header
    head.next = first;
    if (first != nullptr) {
        first->prev = &head;
        DNode* temp = first;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = &head;
        head.prev = temp;
    } else {
        head.next = &head;
        head.prev = &head;
    }
}

bool CDLLD::merge(CDLLD& list1, CDLLD& list2) {
    if (!list1.isSorted() || !list2.isSorted()) return false;
    
    CDLLD temp;
    DNode* p1 = list1.head.next;
    DNode* p2 = list2.head.next;
    DNode* last = &temp.head;
    
    while (p1 != &list1.head && p2 != &list2.head) {
        if (p1->data <= p2->data) {
            last->next = p1;
            p1->prev = last;
            last = p1;
            p1 = p1->next;
        } else {
            last->next = p2;
            p2->prev = last;
            last = p2;
            p2 = p2->next;
        }
    }
    
    while (p1 != &list1.head) {
        last->next = p1;
        p1->prev = last;
        last = p1;
        p1 = p1->next;
    }
    
    while (p2 != &list2.head) {
        last->next = p2;
        p2->prev = last;
        last = p2;
        p2 = p2->next;
    }
    
    last->next = &temp.head;
    temp.head.prev = last;
    
    // Transfer to this list
    head.next = temp.head.next;
    head.prev = temp.head.prev;
    head.next->prev = &head;
    head.prev->next = &head;
    
    list1.head.next = &list1.head;
    list1.head.prev = &list1.head;
    list2.head.next = &list2.head;
    list2.head.prev = &list2.head;
    
    return true;
}

void CDLLD::insertionSort() {
    if (isEmpty() || head.next->next == &head) return;
    
    DNode* sorted = nullptr;
    DNode* current = head.next;
    DNode* nextNode = nullptr;
    
    while (current != &head) {
        nextNode = current->next;
        
        if (sorted == nullptr || sorted->data >= current->data) {
            current->next = sorted;
            if (sorted != nullptr) {
                sorted->prev = current;
            }
            current->prev = nullptr;
            sorted = current;
        } else {
            DNode* temp = sorted;
            while (temp->next != nullptr && temp->next->data < current->data) {
                temp = temp->next;
            }
            current->next = temp->next;
            if (temp->next != nullptr) {
                temp->next->prev = current;
            }
            temp->next = current;
            current->prev = temp;
        }
        current = nextNode;
    }
    
    // Reattach to dummy header
    head.next = sorted;
    if (sorted != nullptr) {
        sorted->prev = &head;
        DNode* temp = sorted;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = &head;
        head.prev = temp;
    } else {
        head.next = &head;
        head.prev = &head;
    }
}

void CDLLD::splitList(CDLLD& leftHalf, CDLLD& rightHalf) {
    if (isEmpty()) return;
    
    int n = countNodes();
    int mid = (n + 1) / 2;
    
    DNode* current = head.next;
    for (int i = 1; i < mid; i++) {
        current = current->next;
    }
    
    DNode* rightStart = current->next;
    
    // Detach right half
    current->next = &head;
    head.prev = current;
    
    rightStart->prev = &rightHalf.head;
    head.prev->next = &rightHalf.head;
    
    // Setup left half
    leftHalf.head.next = head.next;
    leftHalf.head.prev = head.prev;
    leftHalf.head.next->prev = &leftHalf.head;
    leftHalf.head.prev->next = &leftHalf.head;
    
    // Setup right half
    rightHalf.head.next = rightStart;
    rightHalf.head.prev = head.prev;
    rightHalf.head.next->prev = &rightHalf.head;
    rightHalf.head.prev->next = &rightHalf.head;
    
    // Empty this list
    head.next = &head;
    head.prev = &head;
}