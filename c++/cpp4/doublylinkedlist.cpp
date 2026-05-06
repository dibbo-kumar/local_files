#include <iostream>
using namespace std;
struct node
{
public:
    int data;
    node *next;
    node *prev;
    node(int data)
    {
        this->data = data;
        next = NULL;
        prev = NULL;
    }
};
node *head = NULL;
node *tail = NULL;

void insertAtHead(int value)
{
    node *newNode = new node(value);
    newNode->next = head;
    if (head != NULL)
    {

        head->prev = newNode;
    }
    else
        tail = head;

    head = newNode;
}

void insertAtEnd(int value)
{

    node *n1 = new node(value);
    node *temp = head;
    // while (temp->next != NULL)
    // {
    //     temp = temp->next;
    // }
    // if (head != NULL)
    // {
    //     temp->next = n1;
    //     n1->prev = temp;
    //     tail = n1;
    // }
    // else
    // insertAtHead(value);
    if (head != NULL)
    {
        tail->next = n1;
        n1->prev = tail;
        tail = n1;
    }
    else
    {
        head = n1;
        tail = n1;
    }
}

void insertAtMiddle(int data, int target)
{
    node *newnode = new node(data);
    node *temp = head;

    while (temp->data != target && temp != NULL)
    {
        temp = temp->next;
    }
    newnode->next = temp->next;
    newnode->prev = temp;
    if (temp->next != NULL)
    {
        temp->next->prev = newnode;
    }
    else
        tail = newnode;
    temp->next = newnode;
}

void deleteHead()
{
    if (head == NULL)
    {
        cout << "There is nothing to delete" << endl;
    }
    else
    {
        node *current = head;
        head = head->next;
        delete current;
        if (head != NULL)
        {
            head->prev = NULL;
        }
        else
            tail = NULL;
    }
}

void deletetail()
{
    if (tail == NULL)
    {
        cout << "nothing to delete ";
    }
    else
    {
        node *temp = tail;
        if (tail->prev != NULL)
        {
            tail = tail->prev;
            tail->next = NULL;
        }
        else
        {
            head = NULL;
            tail = NULL;
        }
        delete temp;
    }
}

void deleteAnyValue(int value)
{
    // assuming the value is presented in the linked list.
    if (head == NULL)
    {
        cout << "there is nothing to delete" << endl;
    }
    else
    {
        // node *previous = NULL;
        node *current = head;
        while (current->data != value)
        {
            // previous = current;
            current = current->next;
        }

        if (current == head)
        {
            deleteHead();
        }
        else if (current == tail)
        {
            deletetail();
        }
        else
        {
            current->prev->next = current->next;
            current->next->prev = current->prev;
        }

        // if (previous == NULL)
        // {
        //     if (current->next != NULL)
        //     {
        //         head = head->next;
        //         // delete current;
        //     }
        //     else
        //         head = NULL;
        // }
        // else
        // {
        //     previous->next = current->next;
        //     //  delete current;
        // }
        delete current;
    }
}

int main()
{
    return 0;
}
