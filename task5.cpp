#include <iostream>
using namespace std;

class ArrayStack
{
private:
    int items[5];
    int top;

public:
    ArrayStack()
    {
        top = -1;
    }

    bool IsEmpty()
    {
        return top == -1;
    }

    bool IsFull()
    {
        return top == 4;
    }

    void Push(int value)
    {
        if (IsFull())
        {
            cout << "Stack Overflow! Stack is full.\n";
            return;
        }

        top++;
        items[top] = value;
    }

    void Pop()
    {
        if (IsEmpty())
        {
            cout << "Stack Underflow! Stack is empty.\n";
            return;
        }

        cout << "Removed: " << items[top] << endl;
        top--;
    }

    void Peek()
    {
        if (IsEmpty())
        {
            cout << "Stack is empty. Nothing to peek.\n";
            return;
        }

        cout << "Top element: " << items[top] << endl;
    }

    void Display()
    {
        if (IsEmpty())
        {
            cout << "Stack is empty.\n";
            return;
        }

        cout << "Stack (top to bottom): ";

        for (int i = top; i >= 0; i--)
        {
            cout << items[i] << " ";
        }

        cout << endl;
    }
};

void task5()
{
    ArrayStack stack;
    stack.Push(10);
    stack.Push(20);
    stack.Push(30);
    stack.Push(40);
    stack.Push(50);

    stack.Display();

    // Test overflow
    stack.Push(60);

    stack.Pop();
    stack.Peek();
    stack.Display();

    // Empty the stack
    while (!stack.IsEmpty())
    {
        stack.Pop();
    }

    stack.Display();

    // Test underflow
    stack.Pop();
}