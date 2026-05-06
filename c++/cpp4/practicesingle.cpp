#include <iostream>
using namespace std;
struct node
{
public:
    int data;
    node *next;
    node(int data)
    {
        this->data = data;
        next = NULL;
    }
};
// node *head = NULL;
void insertAtHead(node *&head, int value)
{
    node *newNode = new node(value);
    newNode->next = head;
    head = newNode;
}
void insertAtEnd(node *&head, int value)
{

    node *n1 = new node(value);
    node *temp = head;
    if (head == NULL)
    {
        insertAtHead(head, value);
    }
    else
    {

        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = n1;
    }
}
void insertAtMiddle(node *&head, int data, int target)
{
    node *newnode = new node(data);
    node *temp = head;

    while (temp->data != target && temp != NULL)
    {
        temp = temp->next;
    }
    newnode->next = temp->next;
    temp->next = newnode;
}
void deleteHead(node *&head)
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
    }
}
void deleteLast(node *&head)
{
    if (head == NULL)
    {
        cout << "there is nothing to delete" << endl;
    }
    else
    {
        node *current = head;
        node *previous = NULL;
        while (current->next != NULL)
        {
            previous = current;
            current = current->next;
        }
        if (previous != NULL)
        {
            previous->next = NULL;
        }
        else
        {
            head = NULL;
        }
        delete current;

        //
        //
        //
        // node *temp = head;
        // if (temp->next == NULL)
        // {
        //     // simply delete head then return
        // }

        // while (temp->next->next != NULL)
        // {
        //     temp = temp->next;
        // }
    }
}

void deleteAnyValue(node *&head, int value)
{
    // assuming the value is presented in the linked list.
    if (head == NULL)
    {
        cout << "there is nothing to delete" << endl;
    }
    else
    {
        node *previous = NULL;
        node *current = head;
        while (current->data != value)
        {
            previous = current;
            current = current->next;
        }
        if (previous == NULL)
        {
            if (current->next != NULL)
            {
                head = head->next;
                // delete current;
            }
            else
                head = NULL;
        }
        else
        {
            previous->next = current->next;
            //  delete current;
        }
        delete current;
    }
}
void printlist(node *&head)
{
    if (head == NULL)
    {
        cout << "there is nothing to delete" << endl;
    }
    else
    {
        node *current = head;
        while (current != NULL)
        {
            cout << current->data << " ";
            current = current->next;
        }
    }
    cout << endl;
}
void reverselist(node *&head)
{
    node *temp = head;
    node *t = NULL;
    node *prev = NULL;
    if (head == NULL)
    {
        cout << "nothing in the list ";
        return;
    }

    while (temp != NULL)
    {
        t = temp;
        temp = temp->next;
        t->next = prev;
        prev = t;
    }
    head = t;
}

void mergelist(node *&head, node *&head2, node *&head3)
{
    node *temp = head;
    node *temp2 = head2;
    node *temp3 = head3;

    while (temp != NULL || temp2 != NULL)
    {
        if ((temp2 == NULL) || ((temp != NULL) && (temp->data <= temp2->data)))
        {
            temp3->data = temp->data;
            temp = temp->next;
            temp3 = temp3->next;
        }
        else
        {
            temp3->data = temp2->data;
            temp2 = temp2->next;
            temp3 = temp3->next;
        }
    }
}

int main()
{

    node *list1 = NULL;
    // node *list2 = NULL;
    // node *list3 = NULL;
    insertAtEnd(list1, 5);
    insertAtEnd(list1, 8);
    insertAtHead(list1, 4);
    insertAtEnd(list1, 15);
    insertAtMiddle(list1, 8, 8);
    insertAtHead(list1, 4);
    insertAtEnd(list1, 15);

    printlist(list1);
    // insertAtEnd(list2, 5);
    // insertAtEnd(list2, 7);
    // insertAtHead(list2, 1);
    // insertAtMiddle(list2, 9, 7);
    // insertAtEnd(list2, 11);

    // printlist(list1);
    // printlist(list2);
    // mergelist(list1, list2, list3);
    // printlist(list3);
    return 0;
}