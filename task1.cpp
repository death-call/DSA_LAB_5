#include <iostream>
using namespace std;
#include "List_classes.h"


void task1()
{
	DoublyLinkedList list;

	// Test empty list
	list.PrintForward();
	list.PrintReverse();

	// Test one node
	list.AddValue(5);
	list.PrintForward();
	list.PrintReverse();
	list.ClearList();

	// Test multiple nodes
	list.AddValue(10);
	list.AddValue(20);
	list.AddValue(30);

	list.PrintForward();
	list.PrintReverse();
	list.ClearList();

	// Take input from user
	int n, value;
	cout << "Enter number of nodes: ";
	cin >> n;

	if (n < 0)
	{
		cout << "Invalid number of nodes.\n";
		return;
	}

	for (int i = 0; i < n; i++)
	{
		cout << "Enter value: ";
		cin >> value;
		list.AddValue(value);
	}

	list.PrintForward();
	list.PrintReverse();
	list.ClearList();
}
