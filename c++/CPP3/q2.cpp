#include <iostream>
using namespace std;

class Queue {
    int arr[100];
    int front;
    int rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return rear == 99;
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is Full" << endl;
            return;
        }

        if (isEmpty()) {
            front++;
        }

        rear++;
        arr[rear] = value;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is Empty" << endl;
            return;
        }

        if (front == rear) { // Only one element present
            front = -1;
            rear = -1;
        } else {
            front++;
        }
    }

    int peek() {
        if (isEmpty()) {
            cout << "Queue is Empty" << endl;
            return -1;
        }

        return arr[front];
    }

    int size() {
        return isEmpty() ? 0 : (rear - front + 1);
    }
};

class StackUsingQueues {
    Queue q1, q2;

public:
    void push(int value) {
        q1.enqueue(value); // Push the element into q1
    }

    void pop() {
        if (q1.isEmpty()) {
            cout << "Stack is Empty" << endl;
            return;
        }

        // Move all elements except the last one from q1 to q2
        while (q1.size() > 1) {
            q2.enqueue(q1.peek());
            q1.dequeue();
        }

        // Remove the last element
        q1.dequeue();

        // Swap q1 and q2
        swap(q1, q2);
    }

    int peek() {
        if (q1.isEmpty()) {
            cout << "Stack is Empty" << endl;
            return -1;
        }

        while (q1.size() > 1) {
            q2.enqueue(q1.peek());
            q1.dequeue();
        }

        int result = q1.peek();
        q2.enqueue(result); 
        q1.dequeue();

        
        swap(q1, q2);

        return result;
    }

    void print_stack() {
        if (q1.isEmpty()) {
            cout << "Stack is Empty" << endl;
            return;
        }

        int size = q1.size();
        for (int i = 0; i < size; i++) {
            int val = q1.peek();
            cout << val << endl;
            q1.enqueue(val); 
            q1.dequeue();
        }
    }
};

int main() {
    StackUsingQueues stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);

    cout << "Top of stack: " << stack.peek() << endl; 

    stack.pop();
    cout << "After one pop, top element: " << stack.peek() << endl; 

    stack.pop();
    cout << "After another pop, top element: " << stack.peek() << endl; 

    stack.pop();
    cout << "After another pop:" << endl;
    stack.print_stack(); 

    return 0;
}