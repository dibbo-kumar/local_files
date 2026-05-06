#include<stdio.h>

#define MAX 100
int queue[MAX];
int front =-1;
int rear =-1;

int isEMPTY()
{
   return(front==-1);

}
int isFULL()
{
    return(rear==MAX-1);
}

void enqueue(int item)
{
    if(isFULL())
    {
        printf("Queue is full\n");
        return;
    }
    if(front==-1)
    {
        front=0;
    }
    rear++;
    queue[rear]=item;
    printf("%d enqueued to queue\n",item);
}

int dequeue()
{
    int item;
    if(isEMPTY())
    {
        printf("Queue is empty\n");
        return -1;
    }
    item=queue[front];
    front++;
    if(front>rear)
    {
        front=rear=-1;
    }
    
    return item;
}

int main()
{
   enqueue(10);
   enqueue(20);
   enqueue(30);
   enqueue(40);
   enqueue(50);
   printf("%d dequeued from queue\n",dequeue());
   printf("%d dequeued from queue\n",dequeue());
}