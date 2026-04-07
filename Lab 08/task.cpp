// linked list class

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    friend class LinkedList;
};

class LinkedList
{
private:
    Node *head;

public:
    LinkedList()
    {
        head = nullptr;
    }

    void insertAtStart(int value)
    {
        Node *newNode = new Node();
        newNode->data = value;
        newNode->next = head;
        head = newNode;
    }

    void insertAtEnd(int value)
    {
        Node *newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;

        if (head == nullptr)
        {
            head = newNode;
            return;
        }

        Node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void display()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
