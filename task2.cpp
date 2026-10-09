#include <iostream>
using namespace std;
#include "List_classes.h"

void task2()
{
	DoublyLinkedList list;

	list.AddValue(10);
	list.AddValue(20);
	list.AddValue(30);

	// Insert 15 before position 2
	list.InsertBefore(2, 15);
	list.PrintForward();
	list.PrintReverse();

	// Delete 20
	list.DeleteNode(20);
	list.PrintForward();
	list.PrintReverse();
	list.ClearList();

	// insertion before head
	list.AddValue(10);
	list.AddValue(20);
	list.InsertBefore(1, 5);
	list.PrintForward();

	// deletion of head and tail
	list.DeleteNode(5);
	list.DeleteNode(20);
	list.PrintForward();
	list.PrintReverse();
	list.ClearList();


	list.AddValue(7);
	list.DeleteNode(7);
	list.PrintForward();


	list.DeleteNode(100);
	list.InsertBefore(1, 50);
	list.ClearList();
}
