#include <iostream>
using namespace std;

#define SIZE 5

int q[SIZE];
int front = -1, rear = -1;

void enqueue()
{
    int value;

    if ((rear + 1) % SIZE == front)
    {
        cout << "Queue is Full!" << endl;
    }
    else
    {
        cout << "Enter value: ";
        cin >> value;

        if (front == -1)
        {
            front = 0;
        }

        rear = (rear + 1) % SIZE;
        q[rear] = value;

        cout << "Element inserted." << endl;
    }
}

void dequeue()
{
    if (front == -1)
    {
        cout << "Queue is Empty!" << endl;
    }
    else
    {
        cout << "Deleted element: " << q[front] << endl;

        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % SIZE;
        }
    }
}

void display()
{
    if (front == -1)
    {
        cout << "Queue is Empty!" << endl;
    }
    else
    {
        cout << "Queue elements: ";

        int i = front;

        while (true)
        {
            cout << q[i] << " ";

            if (i == rear)
            {
                break;
            }

            i = (i + 1) % SIZE;
        }

        cout << endl;
    }
}

int main()
{
    int choice;

    do
    {
        cout << "\n1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Display" << endl;
        cout << "4. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                enqueue();
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                cout << "Exiting..." << endl;
                break;

            default:
                cout << "Invalid choice!" << endl;
        }

    } while (choice != 4);

    return 0;
}