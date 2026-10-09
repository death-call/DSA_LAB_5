#include <iostream>
using namespace std;

//LIFO principle means the value added at the last will be the first to be deleted.
//This task differs from array stack as arrays have fixed sizes and linked lists have dynamic memory allocation.
class LinkedStack
{
private:
    struct node
    {
        int data;
        node* next;
    };

    node* top;

public:
    LinkedStack()
    {
        top = nullptr;
    }

    bool IsEmpty()
    {
        return top == nullptr;
    }

    void Push(int value)
    {
        node* n = new node;
        n->data = value;
        n->next = top;
        top = n;
    }

    void Pop()
    {
        if (IsEmpty())
        {
            cout << "Stack Underflow! Stack is empty.\n";
            return;
        }

        node* temp = top;
        cout << "Removed: " << temp->data << endl;

        top = top->next;
        delete temp;
    }

    void Peek()
    {
        if (IsEmpty())
        {
            cout << "Stack is empty. Nothing to peek.\n";
            return;
        }

        cout << "Top element: " << top->data << endl;
    }

    void Display()
    {
        if (IsEmpty())
        {
            cout << "Stack is empty.\n";
            return;
        }

        node* curr = top;

        cout << "Stack (top to bottom): ";

        while (curr != nullptr)
        {
            cout << curr->data << " ";
            curr = curr->next;
        }

        cout << endl;
    }

    void ClearStack()
    {
        while (!IsEmpty())
        {
            node* temp = top;
            top = top->next;
            delete temp;
        }
    }

};
void task6()
{
    LinkedStack stack;
    int choice, value;

    // Required tests
    stack.Push(10);
    stack.Push(20);
    stack.Push(30);

    stack.Display();  // 30 20 10

    stack.Pop();      // Removes 30
    stack.Peek();     // Displays 20

    // Delete until empty
    while (!stack.IsEmpty())
    {
        stack.Pop();
    }

    stack.Pop();      // Test underflow

    // Repeating menu
    do
    {
        cout << "\n--- Linked Stack Menu ---\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            stack.Push(value);
            break;

        case 2:
            stack.Pop();
            break;

        case 3:
            stack.Peek();
            break;

        case 4:
            stack.Display();
            break;

        case 5:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 5);

    // Release remaining nodes before exit
    stack.ClearStack();
}