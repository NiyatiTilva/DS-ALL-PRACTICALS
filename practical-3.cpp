#include <iostream>
using namespace std;

const int MAX = 5;
int arr[MAX];
int top = -1;

void push(int x)
{
    if (top == MAX - 1)
    {
        cout << "Stack is full" << endl;
    }
    else
    {
        top++;
        arr[top] = x;
        cout << x << " pushed into stack." << endl;
    }
}

void pop()
{
    if (top == -1)
    {
        cout << "Stack is empty" << endl;
    }
    else
    {
        cout << arr[top] << " popped from stack" << endl;
        top--;
    }
}

void peek()
{
    if (top == -1)
    {
        cout << "Stack is empty" << endl;
    }
    else
    {
        cout << "Top element is: " << arr[top] << endl;
    }
}

void display()
{
    if (top == -1)
    {
        cout << "Stack is empty" << endl;
    }
    else
    {
        cout << "Stack elements: ";
        for (int i = top; i >= 0; i--)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int choice, value;

    do
    {
        cout << "\n== STACK MENU ==\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                push(value);
                break;

            case 2:
                pop();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                cout << "Exiting program..." << endl;
                break;

            default:
                cout << "Invalid choice! Try again." << endl;
        }
    }
    while (choice != 5);

    return 0;
}