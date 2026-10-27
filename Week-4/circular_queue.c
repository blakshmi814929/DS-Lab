#include<stdio.h>
#include<stdlib.h>
#define MAX 4
int queue[MAX],front = -1, rear = -1,i,ele;
void enqueue(int ele)
{
    if((front == 0 && rear == MAX-1) ||(front == rear+1))
    {
        printf("Overflow!\n");
        return;
    }
    if(front==-1 && rear==-1)
        front = 0;
    rear = (rear+1)%MAX;
    queue[rear] = ele;
    printf("Element %d added.\n",ele);
}
void dequeue()
{
    if(front==-1 && rear==-1)
    {
        printf("Underflow!\n");
        return;
    }
    int value = queue[front];
    if(front==rear)
    {
        rear = -1;
        front = -1;
    }
    else
        front = (front+1)%MAX;
    printf("Element %d removed.\n",value);
}
void display()
{
    if(front==-1 && rear==-1)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Front : %d\n",front);
    for(int i = front; i!=rear; i=(i+1)%MAX)
        printf("%d ",queue[i]);
    printf("%d\n",queue[rear]);
    printf("Rear : %d\n",rear);
}
int main()
{   int ch;
    while(1)
    {
        printf("CIRCULAR QUEUE:-\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display queue\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4):\n");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            printf("Enter the element to be inserted:\n");
            scanf("%d",&ele);
            enqueue(ele);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Exiting the program.\n");
            exit(0);
            break;
        default:
            printf("Please enter valid choice.\n");
        }
    }
}

