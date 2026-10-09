#include <iostream>
using namespace std;
#include "List_classes.h"

void task4()
{
	CircularLinkedList list;

	list.AddNode(10);
	list.AddNode(20);
	list.AddNode(30);

	// Delete head
	list.DeleteNode(10);
	list.PrintList();
	cout << "Count: " << list.CountNodes() << endl;

	// Delete tail
	list.DeleteNode(30);
	list.PrintList();
	cout << "Count: " << list.CountNodes() << endl;

	// Delete last remaining node
	list.DeleteNode(20);
	list.PrintList();
	cout << "Count: " << list.CountNodes() << endl;

	// Deletion from an empty list
	list.DeleteNode(10);

	// Test a value that does not exist
	list.AddNode(10);
	list.AddNode(20);
	list.AddNode(30);
	list.DeleteNode(50);
	list.PrintList();
	list.ClearList();

	// Test duplicate values
	list.AddNode(10);
	list.AddNode(20);
	list.AddNode(20);
	list.AddNode(30);

	list.DeleteNode(20);
	list.PrintList();
	cout << "Count: " << list.CountNodes() << endl;
	list.ClearList();
}