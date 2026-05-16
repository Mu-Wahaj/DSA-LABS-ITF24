// Name: Muhammad Wahaj
// Roll Number: BITF24M059
// Section: Morning

#include <iostream>
using namespace std;

class LinkedList;

class Node
{
	friend class LinkedList;

private:
	int data;
	Node *next;
};

class LinkedList
{
private:
	Node *head;

public:
	LinkedList();
	~LinkedList();

	bool insertAtStart(int val);
	bool insertAtEnd(int val);
	void display();

	bool removeKthNode(int k, int &val);
	void combine(LinkedList &list1, LinkedList &list2);
	void shuffleMerge(LinkedList &list1, LinkedList &list2);
	bool removeLastNode(int &val);
	bool removeSecondLastNode(int &val);
	int countNodes();
	int findMin();
	int findMax();
};

LinkedList::LinkedList()
{
	head = nullptr;
}

LinkedList::~LinkedList()
{
	Node *current = head;
	while (current != nullptr)
	{
		Node *temp = current;
		current = current->next;
		delete temp;
	}
	head = nullptr;
}

bool LinkedList::insertAtStart(int val)
{
	Node *newNode = new Node();
	if (newNode == nullptr)
		return false;
	newNode->data = val;
	newNode->next = head;
	head = newNode;
	return true;
}

bool LinkedList::insertAtEnd(int val)
{
	Node *newNode = new Node();
	if (newNode == nullptr)
		return false;
	newNode->data = val;
	newNode->next = nullptr;
	if (head == nullptr)
	{
		head = newNode;
	}
	else
	{
		Node *current = head;
		while (current->next != nullptr)
		{
			current = current->next;
		}
		current->next = newNode;
	}
	return true;
}

void LinkedList::display()
{
	Node *current = head;
	while (current != nullptr)
	{
		cout << current->data;
		if (current->next != nullptr)
			cout << " ";
		current = current->next;
	}
}

bool LinkedList::removeKthNode(int k, int &val)
{

	if (head == nullptr || k <= 0) //this check means either the list is empty or the position k is invalid (non-positive)
		return false;

	if (k == 1) //if k osition is one  then we need to remove the head node of the list. We store the value of the head node in val, update the head pointer to point to the next node, delete the old head node, and return true to indicate successful removal.
	{
		Node *temp = head;
		val = temp->data;
		head = head->next;
		delete temp;
		return true;
	}
	Node *current = head;
	for (int i = 1; i < k - 1; i++)  // This loop iterates through the list to find the (k-1)th node, which is the node just before the one we want to remove. If we reach the end of the list before finding the (k-1)th node, it means that the position k does not exist in the list, and we return false.
	{
		if (current->next == nullptr) // If current->next is nullptr, it means we have reached the end of the list before finding the (k-1)th node. This indicates that the position k does not exist in the list, so we return false.
			return false;
		current = current->next; // If we successfully find the (k-1)th node, we move the current pointer to the next node in each iteration of the loop until we reach the (k-1)th node. After the loop, current will point to the (k-1)th node, which is the node just before the one we want to remove.
	}
	if (current->next == nullptr) //we can check this coditions onnce outside the loop because if current->next is nullptr, it means that there is no node at position k to remove, and we should return false.
		return false;
	Node *toDelete = current->next;
	val = toDelete->data;
	current->next = toDelete->next;
	delete toDelete;
	return true;
}

void LinkedList::combine(LinkedList &list1, LinkedList &list2)
{
	if (list1.head == nullptr && list2.head == nullptr) //if both list1 and list2 are empty (i.e., their head pointers are nullptr), there are no nodes to combine, so we simply return without doing anything. This check prevents unnecessary operations when both lists are empty.
	{
		return;
	}
	else if (list1.head == nullptr) //if list1 is empty (i.e., its head pointer is nullptr), we can directly set the head of the combined list to the head of list2. After that, we set the head of list2 to nullptr to indicate that list2 is now empty, as its nodes have been transferred to the combined list.
	{
		head = list2.head;
		list2.head = nullptr;
	}
	else if (list2.head == nullptr) // if list2 is empty (i.e., its head pointer is nullptr), we can directly set the head of the combined list to the head of list1. After that, we set the head of list1 to nullptr to indicate that list1 is now empty, as its nodes have been transferred to the combined list.
	{
		head = list1.head;
		list1.head = nullptr;
	}
	else
	{
		head = list1.head; // If both lists are non-empty, we set the head of the combined list to the head of list1. Then, we traverse to the end of list1 to find the last node (tail). Once we find the tail, we set its next pointer to the head of list2, effectively linking the two lists together. Finally, we set the head of list1 and list2 to nullptr to indicate that both lists are now empty, as their nodes have been transferred to the combined list.
		list1.head = nullptr; //ths line is for safety to make sure that list1 is empty after combining, even though we have already set head to list1.head. This ensures that list1 does not retain any references to its original nodes, preventing potential issues with memory management or unintended modifications to the combined list through list1.
		Node *tail = head; // for te traversal after setting head to list1.head, we initialize a tail pointer to the head of the combined list (which is now pointing to the head of list1). We will use this tail pointer to traverse through list1 until we reach the last node (the tail of list1).
		while (tail->next != nullptr) //it finds the end of the lined list by checking if tail->next is not nullptr. If tail->next is not nullptr, it means there are more nodes in the list, and we move the tail pointer to the next node (tail = tail->next) until we reach the last node where tail->next is nullptr.
		{
			tail = tail->next;
		}
		tail->next = list2.head;
		list2.head = nullptr;
	}
}

void LinkedList::shuffleMerge(LinkedList &list1, LinkedList &list2)  // The shuffleMerge function takes two linked lists (list1 and list2) as input and merges them by alternating nodes from each list. The resulting merged list is stored in the current object (the one on which the function is called). After the merge, both input lists are emptied (their head pointers are set to nullptr).
{
	if (list1.head == nullptr && list2.head == nullptr)
		return;
	Node *curr1 = list1.head;
	Node *curr2 = list2.head;
	Node *tail = nullptr;
	while (curr1 != nullptr && curr2 != nullptr) // chaeck lists are empty 
	{
		Node *next1 = curr1->next; // createpointers for each list to move in front so that 
		Node *next2 = curr2->next;
		curr1->next = nullptr;// we set the next pointer of the current nodes (curr1 and curr2) to nullptr to detach them from their original lists. This is important because we will be re-linking these nodes in the merged list, and we want to ensure that they do not retain any connections to their original lists. By setting curr1->next and curr2->next to nullptr, we effectively isolate these nodes, allowing us to safely merge them into the new list without any unintended side effects from their previous connections.
		curr2->next = nullptr;
		if (head == nullptr)  // If the head of the merged list is nullptr, it means this is the first node being added to the merged list. In this case, we set the head to curr1 (the current node from list1) and then link curr1 to curr2 (the current node from list2). We also update the tail pointer to point to curr2, which is now the last node in the merged list.
		{
			head = curr1;
			head->next = curr2;
			tail = curr2;
		}
		else
		{
			tail->next = curr1;
			curr1->next = curr2;
			tail = curr2;
		}
		curr1 = next1;
		curr2 = next2;
	}
	list1.head = nullptr;
	list2.head = nullptr;
}

bool LinkedList::removeLastNode(int &val)
{
	if (head == nullptr)
		return false;
	if (head->next == nullptr)
	{
		val = head->data;
		delete head;
		head = nullptr;
		return true;
	}
	Node *current = head;
	while (current->next->next != nullptr)
	{
		current = current->next;
	}
	val = current->next->data;
	delete current->next;
	current->next = nullptr;
	return true;
}

bool LinkedList::removeSecondLastNode(int &val)
{
	if (head == nullptr || head->next == nullptr)
		return false;
	if (head->next->next == nullptr)
	{
		val = head->data;
		Node *temp = head;
		head = head->next;
		delete temp;
		return true;
	}
	Node *current = head;
	while (current->next->next->next != nullptr)
	{
		current = current->next;
	}
	val = current->next->data;
	Node *temp = current->next;
	current->next = current->next->next;
	delete temp;
	return true;
}

int LinkedList::countNodes()
{
	int count = 0;
	Node *current = head;
	while (current != nullptr)
	{
		count++;
		current = current->next;
	}
	return count;
}

int LinkedList::findMin()
{
	if (head == nullptr)
		return 999;
	int minVal = head->data;
	Node *current = head->next;
	while (current != nullptr)
	{
		if (current->data < minVal)
			minVal = current->data;
		current = current->next;
	}
	return minVal;
}

int LinkedList::findMax()
{
	if (head == nullptr)
		return -999;
	int maxVal = head->data;
	Node *current = head->next;
	while (current != nullptr)
	{
		if (current->data > maxVal)
			maxVal = current->data;
		current = current->next;
	}
	return maxVal;
}

void driverTask1()
{
	cout << "Task 1 - removeKthNode" << endl;

	LinkedList list1;
	list1.insertAtEnd(4);
	list1.insertAtEnd(2);
	list1.insertAtEnd(8);
	list1.insertAtEnd(1);
	list1.insertAtEnd(9);
	list1.insertAtEnd(5);
	list1.insertAtEnd(4);
	list1.insertAtEnd(6);
	cout << "List: ";
	list1.display();
	int val = 0;
	if (list1.removeKthNode(4, val))
		cout << "Removed node at position 4, value was: " << val << endl;
	cout << "List after removal: ";
	list1.display();

	cout << endl;

	LinkedList list2;
	list2.insertAtEnd(10);
	list2.insertAtEnd(20);
	list2.insertAtEnd(30);
	cout << "List: ";
	list2.display();
	if (list2.removeKthNode(1, val))
		cout << "Removed node at position 1, value was: " << val << endl;
	cout << "List after removal: ";
	list2.display();

	cout << endl;

	LinkedList list3;
	list3.insertAtEnd(5);
	list3.insertAtEnd(10);
	cout << "List: ";
	list3.display();
	if (!list3.removeKthNode(5, val))
		cout << "Position 5 does not exist in the list." << endl;
}

void driverTask2()
{
	cout << "\nTask 2 - combine" << endl;

	LinkedList list1, list2, list3;
	list1.insertAtEnd(7);
	list1.insertAtEnd(3);
	list1.insertAtEnd(4);
	list1.insertAtEnd(2);
	list2.insertAtEnd(5);
	list2.insertAtEnd(9);
	cout << "list1: ";
	list1.display();
	cout << "list2: ";
	list2.display();
	list3.combine(list1, list2);
	cout << "Combined list: ";
	list3.display();
	cout << "list1 after combine: ";
	list1.display();
	cout << "list2 after combine: ";
	list2.display();

	cout << endl;

	LinkedList list4, list5, list6;
	list5.insertAtEnd(1);
	list5.insertAtEnd(2);
	list5.insertAtEnd(3);
	cout << "list4 (empty) and list5: ";
	list5.display();
	list6.combine(list4, list5);
	cout << "Combined list: ";
	list6.display();
}

void driverTask3()
{
	cout << "\nTask 3 - shuffleMerge" << endl;

	LinkedList list1, list2, list3;
	list1.insertAtEnd(2);
	list1.insertAtEnd(6);
	list1.insertAtEnd(4);
	list2.insertAtEnd(8);
	list2.insertAtEnd(1);
	list2.insertAtEnd(3);
	cout << "list1: ";
	list1.display();
	cout << "list2: ";
	list2.display();
	list3.shuffleMerge(list1, list2);
	cout << "Shuffle merged list: ";
	list3.display();
	cout << "list1 after merge: ";
	list1.display();
	cout << "list2 after merge: ";
	list2.display();

	cout << endl;

	LinkedList list4, list5, list6;
	list4.insertAtEnd(10);
	list4.insertAtEnd(20);
	list5.insertAtEnd(30);
	list5.insertAtEnd(40);
	cout << "list4: ";
	list4.display();
	cout << "list5: ";
	list5.display();
	list6.shuffleMerge(list4, list5);
	cout << "Shuffle merged list: ";
	list6.display();
}

void driverTask4()
{
	cout << "\nTask 4 - removeLastNode and removeSecondLastNode" << endl;

	LinkedList list1;
	list1.insertAtEnd(1);
	list1.insertAtEnd(2);
	list1.insertAtEnd(3);
	list1.insertAtEnd(4);
	int val = 0;
	cout << "List: ";
	list1.display();
	list1.removeLastNode(val);
	cout << "Removed last node, value: " << val << endl;
	cout << "List after removal: ";
	list1.display();

	cout << endl;

	LinkedList list2;
	list2.insertAtEnd(99);
	cout << "List: ";
	list2.display();
	list2.removeLastNode(val);
	cout << "Removed last node, value: " << val << endl;
	cout << "List after removal: ";
	list2.display();

	cout << endl;

	LinkedList list3;
	list3.insertAtEnd(10);
	list3.insertAtEnd(20);
	list3.insertAtEnd(30);
	list3.insertAtEnd(40);
	cout << "List: ";
	list3.display();
	list3.removeSecondLastNode(val);
	cout << "Removed second last node, value: " << val << endl;
	cout << "List after removal: ";
	list3.display();

	cout << endl;

	LinkedList list4;
	list4.insertAtEnd(5);
	list4.insertAtEnd(15);
	cout << "List: ";
	list4.display();
	list4.removeSecondLastNode(val);
	cout << "Removed second last node, value: " << val << endl;
	cout << "List after removal: ";
	list4.display();

	cout << endl;

	LinkedList list5;
	list5.insertAtEnd(7);
	cout << "List: ";
	list5.display();
	if (!list5.removeSecondLastNode(val))
		cout << "Cannot remove second last node, list has fewer than 2 nodes." << endl;
}

void driverTask5()
{
	cout << "\nTask 5 - countNodes, findMin, findMax" << endl;

	LinkedList list1;
	list1.insertAtEnd(3);
	list1.insertAtEnd(7);
	list1.insertAtEnd(1);
	list1.insertAtEnd(9);
	list1.insertAtEnd(4);
	cout << "List: ";
	list1.display();
	cout << "Number of nodes: " << list1.countNodes() << endl;
	cout << "Minimum value: " << list1.findMin() << endl;
	cout << "Maximum value: " << list1.findMax() << endl;

	cout << endl;

	LinkedList list2;
	list2.insertAtEnd(100);
	list2.insertAtEnd(50);
	list2.insertAtEnd(200);
	cout << "List: ";
	list2.display();
	cout << "Number of nodes: " << list2.countNodes() << endl;
	cout << "Minimum value: " << list2.findMin() << endl;
	cout << "Maximum value: " << list2.findMax() << endl;

	cout << endl;

	LinkedList list3;
	cout << "Empty list: ";
	list3.display();
	cout << "Number of nodes: " << list3.countNodes() << endl;
	cout << "findMin on empty list returns: " << list3.findMin() << endl;
	cout << "findMax on empty list returns: " << list3.findMax() << endl;
}

int main()
{
	driverTask1();
	driverTask2();
	driverTask3();
	driverTask4();
	driverTask5();
	return 0;
}
