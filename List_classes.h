#include <iostream>
using namespace std;

class DoublyLinkedList {
	struct node {
		int data;
		node* next;
		node* prev;
	};
	node* head;

public:
	DoublyLinkedList()
	{
		head = nullptr;
	}
	void AddValue(int value)
	{
		node* curr = head;
		node* n = new node;
		n->data = value;
		n->next = nullptr;
		n->prev = nullptr;
		if (curr == nullptr)
		{
			head = n;
		}
		else {

			while (curr->next != nullptr) {
				curr = curr->next;
			}

			curr->next = n;
			n->prev = curr;
		}

	}
	void PrintForward()
	{
		node* curr = head;
		if (curr == nullptr)
		{
			cout << "List is empty" << endl;
		}
		else {
			cout << "\nList:" << endl;
			while (curr != nullptr)
			{
				cout << curr->data << " ";
				curr = curr->next;
			}
		}
	}
	void PrintReverse()
	{
		node* curr = head;
		if (curr == nullptr)
		{
			cout << "List is empty" << endl;
		}
		else {
			while (curr->next != nullptr) {
				curr = curr->next;
			}
			while (curr != nullptr)
			{
				cout << curr->data << endl;
				curr = curr->prev;
			}
		}
	}
	void ClearList()
	{
		node* curr = head;
		if (curr == nullptr)
		{
			cout << "List is already empty" << endl;
		}
		else {
			while (curr != nullptr)
			{
				node* temp = curr;
				curr = curr->next;
				delete temp;
			}
			head = nullptr;
		}
	}
	void InsertBefore(int pos, int value)
	{
		if (pos < 1)
		{
			cout << "Invalid position" << endl;
			return;
		}

		node* curr = head;
		if (curr == nullptr)
		{
			if (pos == 1)
			{
				AddValue(value);
			}
			else
			{
				cout << "Position not found" << endl;
			}
			return;
		}
		int index = 1;

		while (curr != nullptr && index < pos)
		{
			curr = curr->next;
			index++;
		}

		if (curr == nullptr)
		{
			cout << "Position not found" << endl;
			return;
		}

		node* n = new node;
		n->data = value;
		n->prev = curr->prev;
		n->next = curr;

		if (curr->prev != nullptr)
		{
			curr->prev->next = n;
		}
		else
		{
			head = n;
		}

		curr->prev = n;
	}
	void DeleteNode(int value)
	{
		node* curr = head;
		while (curr != nullptr && curr->data != value)
		{
			curr = curr->next;
		}
		if (curr == nullptr)
		{
			cout << "Value not found" << endl;
			return;
		}
		if (curr->prev != nullptr)
		{
			curr->prev->next = curr->next;
		}
		else
		{
			head = curr->next;
		}
		if (curr->next != nullptr)
		{
			curr->next->prev = curr->prev;
		}
		delete curr;
	}
};
class CircularLinkedList {

	//TASK 3 and 4

	struct node {
		int data;
		node* next;
	};
	node* head;
	node* tail;
public:
	//Functions for TASK 3
	CircularLinkedList()
	{
		head = nullptr;
		tail->next = head;
	}
	void AddNode(int value) {
		node* n = new node;
		n->next = head;
		n->data = value;

		if (head == nullptr)
		{
			head = n;
			tail = n;
			n->next = head;
		}
		else
		{
			tail->next = n;
			n->next = head;
			tail = n;
		}
	}
	void PrintList() {
		node* curr = head;
		if (head == nullptr)
		{
			cout << "List is empty" << endl;
		}
		else {
			do {
				cout << curr->data << endl;
				curr = curr->next;
			} while (curr != head);

		}
	}
	int CountNodes() {
		node* curr = head;
		int count = 1;

		if (curr == nullptr)
			return 0;
		else
		{
			while (curr->next != head)
			{
				count++;
				curr = curr->next;
			}
			return count;
		}
	}
	void ClearList()
	{
		node* curr = head->next;

		if (head == nullptr)
			cout << "List is empty" << endl;
		else {
			while (curr != head)
			{
				node* temp = curr;
				curr = curr->next;
				delete temp;
			}

			delete head;
			head = nullptr;
		}

	}
	//Function TASK 4
	void DeleteNode(int value)
	{
		if (head == nullptr)
		{
			cout << "List is empty" << endl;
			return;
		}

		node* curr = head;
		node* prev = tail;

		do
		{
			if (curr->data == value)
			{
				if (head == tail)
				{
					delete curr;
					head = nullptr;
					tail = nullptr;
				}
				else
				{
					prev->next = curr->next;

					if (curr == head)
						head = curr->next;

					if (curr == tail)
						tail = prev;

					tail->next = head;

					delete curr;
				}

				return;
			}

			prev = curr;
			curr = curr->next;

		} while (curr != head);

		cout << "Value not found" << endl;
	}
};