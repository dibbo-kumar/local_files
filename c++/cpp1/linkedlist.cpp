// #include <iostream>
// using namespace std;

// class node
// {
// public:
//     int data;
//     node *next;
//     node(int data)
//     {
//         this->data = data;
//         this->next = NULL;
//     }
//     ~node()
//     {
//         int value = this->data;
//         // memory free
//         if (this->next != NULL)
//         {
//             delete next;
//             this->next = NULL;
//         }
//         cout << "memory cleared for value " << value << endl;
//     }
// };

// void insert(node *&Heaad, int d)
// {
//     node *temp = new node(d);
//     temp->next = Heaad;
//     Heaad = temp;
// }

// void insert2(node *&tail, int a)
// {
//     node *temp = new node(a);
//     tail = tail->next = temp;
//     // tail = temp;
// }

// void insert3(node *&headd, int position, int d)
// {
//     if (position == 1)
//     {
//         insert(headd, d);
//         return;
//     }
//     node *temp = headd;

//     // cout  << temp  << endl;
//     // cout << headd<< endl;
//     // cout << temp->next << endl;
//     //  cout << temp << " before loop " << temp->data << " " << temp->next << endl;
//     int count = 1;
//     while (count < position - 1)
//     {
//         temp = temp->next;
//         //  cout << temp << " in loop" << endl;
//         // cout << temp->next << endl;
//         // cout << temp->data << endl;
//         count++;
//     }
//     if (temp->next == NULL)
//     {
//         insert2(temp, d);
//         return;
//     }
//     // cout << temp << " after loop " << endl;
//     node *nodeToInsert = new node(d);
//     nodeToInsert->next = temp->next;
//     temp->next = nodeToInsert;
//     // cout<< nodeToInsert->next << endl;
// }

// void deleteNode(node *&head, int position)
// {
//     // deleting first node
//     if (position == 1)
//     {
//         node *temp = head;
//         head = head->next;
//         temp->next = NULL;
//         delete temp;
//     }
//     else
//     {
//         // deleting any middle node or last node
//         node *current = head;
//         node *previous = NULL;
//         int count = 1;
//         while (count < position)
//         {
//             previous = current;
//             current = current->next;
//             count++;
//             previous->next = current->next;
//             current->next = NULL;
//             delete current;
//         }

//     }
// }

// void print(node *&Heead)
// {
//     node *temp = Heead;
//     while (temp != NULL)
//     {
//         cout << temp->data << " ";
//         temp = temp->next;
//     }
//     cout << endl;
// }

// int main()
// {
//     node *node1 = new node(55);
//     // cout << node1->data << endl;
//     // cout << node1->next << endl;
//     node *head = node1;
//     node *tail = node1;
//     insert2(tail, 5);
//     print(head);
//     insert2(tail, 0);
//     insert2(tail, 9);
//     insert2(tail, 8);
//     insert2(tail, 8);
//     insert2(tail, 8);
//     insert2(tail, 8);
//     insert2(tail, 8);
//     insert2(tail, 8);
//     insert2(tail, 8);
//     insert2(tail, 8);
//     print(head);
//     insert3(head, 6, 10);
//     print(head);

//     return 0;
// }
// doubly linked list is starting from here
// #include <iostream>
// using namespace std;

// class Node
// {
// public:
//     int data;
//     Node *prev;
//     Node *next;
//     Node(int d)
//     {
//         data = d;
//         prev = NULL;
//         next = NULL;
//     }
//     ~Node()
//     {
//         int value = this->data;
//         if (next != NULL)
//         {
//             delete next;
//             next = NULL;
//         }
//         cout << "memory cleared for value " << value << endl;
//     }
// };
// void print(Node *head)
// {
//     Node *temp = head;
//     while (temp != NULL)
//     {
//         cout << temp->data << " ";
//         temp = temp->next;
//     }
//     cout << endl;
// }
// int getLength(Node *head)
// {
//     Node *temp = head;
//     int count = 0;
//     while (temp != NULL)
//     {
//         count++;
//         temp = temp->next;
//     }
//     return count;
// }

// void insertAtHead(Node *&head, int data)
// {
//     Node *newNode = new Node(data);
//     head->prev = newNode;
//     newNode->next = head;
//     head = newNode;
// }

// void insertAtTail(Node *&tail, int data)
// {
//     Node *newNode = new Node(data);
//     newNode->prev = tail;
//     tail->next = newNode;
//     tail = newNode;
// }
// void insertAtPosition(Node *head, int data, int position)
// {
//     if (position == 1)
//     {
//         insertAtHead(head, data);
//         return;
//     }
//     Node *temp = head;
//     int count = 1;
//     while (count < position - 1)
//     {
//         temp = temp->next;
//         count++;
//     }
//     if (temp->next == NULL)
//     {
//         insertAtTail(temp, data);
//         return;
//     }
//     Node *newNode = new Node(data);
//     newNode->next = temp->next;
//     temp->next->prev = newNode;
//     temp->next = newNode;
//     newNode->prev = temp;
// }

// void deleteNode(Node *&head, int position)
// {
//     // deleting first node
//     if (position == 1)
//     {
//         Node *temp = head;
//         temp->next->prev = NULL;
//         head = temp->next;
//         temp->next = NULL;
//         delete temp;
//     }
//     else
//     {
//         // deleting any middle node or last node
//         Node *current = head;
//         Node *previous = NULL;
//         int count = 1;
//         while (count < position)
//         {
//             previous = current;
//             current = current->next;
//             count++;
//         }
//         current->prev = NULL;
//         previous->next = current->next;
//         current->next = NULL;
//         delete current;
//     }
// }
// int main()
// {
//     Node *node1 = new Node(8);
//     Node *head = node1;
//     Node *tail = node1;
//     print(head);
//     // cout << getLength(head) << endl;
//     insertAtHead(head, 10);
//     print(head);
//     insertAtPosition(head, 5, 2);
//     print(head);
//     insertAtHead(head, 4);
//     print(head);
//     deleteNode(head, 2);
//     print(head);
//     deleteNode(head, 3);
//     print(head);
// }
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    ~Node()
    {
        int value = this->data;
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << "value deleted for vale " << value << endl;
    }
};
void insertNode(Node *tail, int element, int data)
{
    if (tail == NULL)
    {
        Node *newNode = new Node(data);
        tail = newNode;
        newNode->next = newNode;
    }
    else
    {
        Node *current = tail;
        while (current->data != element)
        {
            current = current->next;
        }
        // element found
        Node *temp = new Node(data);
        temp->next = current->next;
        current->next = temp;
    }
}
void print(Node *tail)
{
    Node *temp = tail;
    do
    {
        cout << tail->data << " ";
        tail = tail->next;
    } while (tail != temp);
}
int main()
{
    Node *tail = NULL;
    insertNode(tail, 5, 3);
    // insertNode(tail, 10, 20);
    // insertNode(tail, 20, 30);
    print(tail);
    return 0;
}