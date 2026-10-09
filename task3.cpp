#include <iostream>
using namespace std;
#include "List_classes.h"

//In a normal linked list, traversal stops when curr == nullptr because the last node points to nullptr.

//In a circular linked list, the last node points back to the head instead of nullptr
//Therefore, curr keeps moving through the nodes in a loop and never becomes nullptr
//This causes an infinite loop if we use normal while (curr != nullptr) traversal
void task3()
{
	CircularLinkedList list;

	list.PrintList();
	cout << "Count: " << list.CountNodes() << endl;

	list.AddNode(5);
	list.PrintList();
	cout << "Count: " << list.CountNodes() << endl;
	list.ClearList();

	list.AddNode(10);
	list.AddNode(20);
	list.AddNode(30);

	list.PrintList();
	cout << "Count: " << list.CountNodes() << endl;
	list.ClearList();

}
