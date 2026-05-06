#include <iostream>
using namespace std;

class Stack
{
    int arr[100];
    int top;

public:
    Stack()
    {
        top = -1;
    }

    bool isEmpty()
    {
        return top == -1;
    }

    void push(int value)
    {
        if (top == 99)
        {
            cout << "Stack Overflow" << endl;
            return;
        }
        arr[++top] = value;
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow" << endl;
            return;
        }
        top--;
    }

    int topElement()
    {
        if (isEmpty())
        {
            cout << "Stack is Empty" << endl;
            return -1;
        }
        return arr[top];
    }
};

class Queue
{
    int arr[100];
    int front;
    int rear;

public:
    Queue()
    {
        front = -1;
        rear = -1;
    }

    bool isEmpty()
    {
        return front == -1;
    }

    void enqueue(int value)
    {
        if (rear == 99)
        {
            cout << "Queue is Full" << endl;
            return;
        }
        if (isEmpty())
            front = 0;
        arr[++rear] = value;
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty" << endl;
            return;
        }
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
            front++;
    }

    int frontElement()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty" << endl;
            return -1;
        }
        return arr[front];
    }

    int size()
    {
        if (isEmpty())
            return 0;
        return rear - front + 1;
    }

    void printQueue()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty" << endl;
            return;
        }
        for (int i = front; i <= rear; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

void reverseFirstK(Queue &queue, int k)
{
    Stack stk;
    int totalSize = queue.size();
    if (k > totalSize)
        k = totalSize;


    for (int i = 0; i < k; i++)
    {
        int value = queue.frontElement();
        queue.dequeue();
        stk.push(value);
    }


    for (int i = 0; i < k; i++)
    {
        int value = stk.topElement();
        stk.pop();
        queue.enqueue(value);
    }


    for (int i = 0; i < totalSize - k; i++)
    {
        int value = queue.frontElement();
        queue.dequeue();
        queue.enqueue(value);
    }
}

int main()
{
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);

    cout << "Queue before reversing " << endl;
    q.printQueue();

    reverseFirstK(q, 4);

    cout << "Queue after reversing " << endl;
    q.printQueue();

    return 0;
}