
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node* head = NULL;

// Insert at beginning
void insertB(int x)
{
    Node* newNode = new Node;
    newNode->data = x;
    newNode->next = head;
    head = newNode;
}

// Insert at end
void insertE(int x)
{
    Node* newNode = new Node;
    newNode->data = x;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    Node* temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
}

// Insert after a given node
void insertAfter(int key, int x)
{
    Node* temp = head;

    while (temp != NULL && temp->data != key)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        cout << "Node not found";
        return;
    }

    Node* newNode = new Node;
    newNode->data = x;
    newNode->next = temp->next;
    temp->next = newNode;
}

// Delete first node
void deleteB()
{
    if (head == NULL)
    {
        cout << "List is empty";
        return;
    }

    Node* temp = head;
    head = head->next;
    delete temp;
}

// Delete last node
void deleteE()
{
    if (head == NULL)
    {
        cout << "List is empty";
        return;
    }

    if (head->next == NULL)
    {
        delete head;
        head = NULL;
        return;
    }

    Node* temp = head;

    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }

    delete temp->next;
    temp->next = NULL;
}

// Delete node after a given node
void deleteAfter(int key)
{
    Node* temp = head;

    while (temp != NULL && temp->data != key)
    {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL)
    {
        cout << "Node not found or no next node";
        return;
    }

    Node* del = temp->next;
    temp->next = del->next;
    delete del;
}

// Display all nodes
void display()
{
    Node* temp = head;

    if (head == NULL)
    {
        cout << "List is empty";
        return;
    }

    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL";
}

int main()
{
    int ch, x, key;

    do
    {
        cout << "\n\n1. Insert at Beginning";
        cout << "\n2. Insert at End";
        cout << "\n3. Insert After Given Node";
        cout << "\n4. Delete First Node";
        cout << "\n5. Delete Last Node";
        cout << "\n6. Delete After Given Node";
        cout << "\n7. Display";
        cout << "\n8. Exit";

        cout << "\nEnter your choice: ";
        cin >> ch;

        switch (ch)
        {
            case 1:
                cout << "Enter value: ";
                cin >> x;
                insertB(x);
                break;

            case 2:
                cout << "Enter value: ";
                cin >> x;
                insertE(x);
                break;

            case 3:
                cout << "Enter node value: ";
                cin >> key;
                cout << "Enter new value: ";
                cin >> x;
                insertAfter(key, x);
                break;

            case 4:
                deleteB();
                break;

            case 5:
                deleteE();
                break;

            case 6:
                cout << "Enter node value: ";
                cin >> key;
                deleteAfter(key);
                break;

            case 7:
                display();
                break;

            case 8:
                cout << "Exiting...";
                break;

            default:
                cout << "Invalid choice";
        }

    } while (ch != 8);

    return 0;
}
