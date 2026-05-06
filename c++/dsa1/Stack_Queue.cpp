#include<iostream>

using namespace std;

class Stack
{
    int arr[100];
    int top;

   public:

    Stack()
    {
        top=-1;
    }

    bool isFull()
    {
        if(top==99)
        {
            return true;
        }

        else
             return false;
    }

    bool isEmpty()
    {
        if(top==-1)
        {
            return true;
        }
        else
            return false;
    }

    void push(int value)
    {
        if(isFull())
        {
            cout<<"Stack is Full"<<endl;
            return;
        }

        top++;
        arr[top]=value;
    }

    void pop()
    {
        if(isEmpty())
        {
            cout<<"Stack is Empty"<<endl;
            return;
        }

        top--;
    }

    int peek()
    {
        if(isEmpty())
        {
            cout<<"Stack is Empty"<<endl;
            return -1;
        }

        return arr[top];
    }

    void print_stack()
    {
        if(isEmpty())
        {
            cout<<"Stack is Empty"<<endl;
            return;
        }

        for(int i=top; i>=0; i--)
        {
            cout<<arr[i]<<endl;
        }
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
        front=-1;
        rear=-1;
    }

    bool isEmpty()
    {
        if(front==-1)
        {
            return true;
        }
        else
            return false;
    }

    bool isFull()
    {
        if(rear==99)
        {
            return true;
        }

        else return false;
    }

    void enqueue(int value)
    {
        if(isFull())
        {
            cout<<"Queue is Full"<<endl;
            return;
        }

        if(isEmpty())
        {
            front++;
        }

        rear++;
        arr[rear]=value;
    }

    void dequeue()
    {
        if(isEmpty())
        {
            cout<<"Queue is Empty"<<endl;
            return;
        }

        if(front==rear)//only one element is present in the queue
        {
            front=-1;
            rear=-1;
        }
        else
        {
          front++;
        }

    }

    int peek()
    {
        if(isEmpty())
        {
            cout<<"Queue is Empty"<<endl;
            return -1;
        }

        return arr[front];
    }

    void print_queue()
    {
        if(isEmpty())
        {
            cout<<"Queue is Empty"<<endl;
            return;
        }

        for(int i=front; i<=rear; i++)
        {
            cout<<arr[i]<<endl;
        }
    }

};


int main()
{
//    Stack st;
//    st.push(12);
//    st.push(5);
//    st.push(9);
//
//    //st.print_stack();
//
//    st.pop();
//    st.pop();
//    st.pop();
//    st.pop();
//    st.print_stack();


    Queue q;
    q.enqueue(5);
    q.enqueue(9);
    q.enqueue(12);
    q.dequeue();
    q.dequeue();
    q.dequeue();

    q.print_queue();
}
