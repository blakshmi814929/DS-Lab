#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *top = NULL;
struct node *front = NULL;
struct node *rear = NULL;

// STACK OPERATIONS

void push()
{
    struct node *newnode;

    newnode = (struct node*)malloc(sizeof(struct node));

    printf("Enter element: ");
    scanf("%d", &newnode->data);

    newnode->next = top;
    top = newnode;

    printf("Element pushed successfully\n");
}

void pop()
{
    struct node *temp;

    if(top == NULL)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        temp = top;
        printf("Deleted element: %d\n", temp->data);

        top = top->next;
        free(temp);
    }
}

void displayStack()
{
    struct node *temp = top;

    if(top == NULL)
    {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack elements:\n");

    while(temp != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

// QUEUE OPERATIONS

void enqueue()
{
    struct node *newnode;

    newnode = (struct node*)malloc(sizeof(struct node));

    printf("Enter element: ");
    scanf("%d", &newnode->data);

    newnode->next = NULL;

    if(front == NULL)
    {
        front = rear = newnode;
    }
    else
    {
        rear->next = newnode;
        rear = newnode;
    }

    printf("Element inserted successfully\n");
}

void dequeue()
{
    struct node *temp;

    if(front == NULL)
    {
        printf("Queue Underflow\n");
    }
    else
    {
        temp = front;

        printf("Deleted element: %d\n", temp->data);

        front = front->next;

        if(front == NULL)
        {
            rear = NULL;
        }

        free(temp);
    }
}

void displayQueue()
{
    struct node *temp = front;

    if(front == NULL)
    {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements:\n");

    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

// MAIN FUNCTION

int main()
{
    int choice;

    do
    {
        printf("\n--- MAIN MENU ---");
        printf("\n1. Stack Push");
        printf("\n2. Stack Pop");
        printf("\n3. Display Stack");
        printf("\n4. Queue Enqueue");
        printf("\n5. Queue Dequeue");
        printf("\n6. Display Queue");
        printf("\n7. Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                push();
                break;

            case 2:
                pop();
                break;

            case 3:
                displayStack();
                break;

            case 4:
                enqueue();
                break;

            case 5:
                dequeue();
                break;

            case 6:
                displayQueue();
                break;

            case 7:
                printf("Exiting...");
                break;

            default:
                printf("Invalid choice\n");
        }

    } while(choice != 7);

    return 0;
}
