
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node* head = NULL;

void insertB(int x)
{
    Node* newNode = new Node;
    newNode->data = x;

    if (head == NULL)
    {
        head = newNode;
        newNode->next = head;
    }
    else
    {
        Node* temp = head;

        while (temp->next != head)
        {
            temp = temp->next;
        }

        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }
}

void insertE(int x)
{
    Node* newNode = new Node;
    newNode->data = x;

    if (head == NULL)
    {
        head = newNode;
        newNode->next = head;
    }
    else
    {
        Node* temp = head;

        while (temp->next != head)
        {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->next = head;
    }
}

void insertAfter(int key, int x)
{
    if (head == NULL)
    {
        cout << "List is empty";
        return;
    }

    Node* temp = head;

    do
    {
        if (temp->data == key)
        {
            Node* newNode = new Node;
            newNode->data = x;

            newNode->next = temp->next;
            temp->next = newNode;

            cout << "Node inserted";
            return;
        }

        temp = temp->next;

    } while (temp != head);

    cout << "Given node not found";
}

void deleteB()
{
    if (head == NULL)
    {
        cout << "List is empty";
        return;
    }

    Node* temp = head;

    if (head->next == head)
    {
        head = NULL;
        delete temp;
    }
    else
    {
        Node* last = head;

        while (last->next != head)
        {
            last = last->next;
        }

        head = head->next;
        last->next = head;

        delete temp;
    }

    cout << "First node deleted";
}

void deleteE()
{
    if (head == NULL)
    {
        cout << "List is empty";
        return;
    }

    if (head->next == head)
    {
        delete head;
        head = NULL;
    }
    else
    {
        Node* temp = head;

        while (temp->next->next != head)
        {
            temp = temp->next;
        }

        Node* last = temp->next;
        temp->next = head;

        delete last;
    }

    cout << "Last node deleted";
}

void deleteAfter(int key)
{
    if (head == NULL)
    {
        cout << "List is empty";
        return;
    }

    Node* temp = head;

    do
    {
        if (temp->data == key)
        {
            Node* del = temp->next;

            if (del == head && del == temp)
            {
                head = NULL;
                delete del;
            }
            else
            {
                temp->next = del->next;

                if (del == head)
                {
                    head = del->next;
                }

                delete del;
            }

            cout << "Node after given node deleted";
            return;
        }

        temp = temp->next;

    } while (temp != head);

    cout << "Given node not found";
}

void display()
{
    if (head == NULL)
    {
        cout << "List is empty";
        return;
    }

    Node* temp = head;

    cout << "Circular linked list: ";

    do
    {
        cout << temp->data << " ";
        temp = temp->next;

    } while (temp != head);

    cout << "(back to head)";
}

int main()
{
    int ch, x, key;

    do
    {
        cout << "\n1. Insert at beginning";
        cout << "\n2. Insert at end";
        cout << "\n3. Insert after given node";
        cout << "\n4. Delete first node";
        cout << "\n5. Delete last node";
        cout << "\n6. Delete node after given node";
        cout << "\n7. Display";
        cout << "\n8. Exit";

        cout << "\nEnter your choice: ";
        cin >> ch;

        switch (ch)
        {
            case 1:
                cout << "Enter data: ";
                cin >> x;
                insertB(x);
                break;

            case 2:
                cout << "Enter data: ";
                cin >> x;
                insertE(x);
                break;

            case 3:
                cout << "Enter given node value: ";
                cin >> key;

                cout << "Enter new data: ";
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
                cout << "Enter given node value: ";
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
