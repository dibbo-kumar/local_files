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

    bool isFull()
    {
        if (top == 99)
        {
            return true;
        }
        else
            return false;
    }

    bool isEmpty()
    {
        if (top == -1)
        {
            return true;
        }
        else
            return false;
    }

    void push(int value)
    {
        if (isFull()) 
        {
            cout << "Stack is Full" << endl;
            return;
        }
        top++;
        arr[top] = value;
    }

    void pop()
    {
        if (isEmpty()) 
        {
            cout << "Stack is Empty" << endl;
            return;
        }
        top--;
    }

    int peek()
    {
        if (isEmpty()) 
        {
            cout << "Stack is Empty" << endl;
            return -1;
        }
        return arr[top];
    }
};

void nextGreater(int arr[], int n)
{
    Stack s;

    for(int i = 0; i < n; i++) 
    {
        while (!s.isEmpty() && arr[i] > s.peek()) 
        {
            cout << s.peek() << " -> " << arr[i] << endl;
            s.pop();
        }
        s.push(arr[i]);
    }
    while (!s.isEmpty()) 
    {
        cout << s.peek() << " -> " << -1 << endl;
        s.pop();
    }
}
int main()
{
    int arr[] = {4, 5, 6, 10};

    int n = sizeof(arr) / sizeof(arr[0]);
    nextGreater(arr, n);
    return 0;
}
