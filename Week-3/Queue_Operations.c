#include<stdio.h>
#define MAX 5
int queue[MAX];
int front = -1, rear = -1;
void enqueue()
{
    if(rear==MAX-1)
        printf("Overflow\n");
    else
    {
        int item;
        printf("Enter the element to be inserted:");
        scanf("%d",&item);
        if(front==-1)
            front = 0;
        rear++;
        queue[rear] = item;
        printf("%d inserted into queue\n",item);
    }
}
int dequeue()
{
    int item;
    if(front==-1 || front>rear)
        printf("Underflow\n");
    else
    {
        item = queue[front];
        front++;
        printf("%d deleted from queue\n",item);
    }
    return item;
}
void display()
{
    if(front==-1 || front>rear)
        printf("Queue is empty.\n");
    else
    {
        printf("Queue elements are: ");
        for(int i=front;i<=rear;i++)
            printf("%d ",queue[i]);
        printf("\n");
    }
}
int main()
{
    int ele,ch;
    while(1)
    {
        printf("\n=====QUEUE OPERATIONS=====\n");
        printf("1. Insertion\n");
        printf("2. Deletion\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Exiting the program.\n");
            return 0;
        default:
            printf("Invalid choice.\n");

        }
    }
    return 0;
}
