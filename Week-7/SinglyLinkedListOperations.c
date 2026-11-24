#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *create()
{
    struct node *newnode, *head = NULL, *temp;
    int n, i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        newnode = (struct node*)malloc(sizeof(struct node));

        printf("Enter data: ");
        scanf("%d", &newnode->data);

        newnode->next = NULL;

        if(head == NULL)
        {
            head = newnode;
            temp = head;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
    }

    return head;
}

void display(struct node *head)
{
    struct node *temp = head;

    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    while(temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

struct node* sort(struct node *head)
{
    struct node *i, *j;
    int temp;

    for(i = head; i != NULL; i = i->next)
    {
        for(j = i->next; j != NULL; j = j->next)
        {
            if(i->data > j->data)
            {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }

    return head;
}

struct node* reverse(struct node *head)
{
    struct node *prev = NULL;
    struct node *current = head;
    struct node *nextnode;

    while(current != NULL)
    {
        nextnode = current->next;
        current->next = prev;
        prev = current;
        current = nextnode;
    }

    return prev;
}

struct node* concatenate(struct node *head1, struct node *head2)
{
    struct node *temp;

    if(head1 == NULL)
        return head2;

    temp = head1;

    while(temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = head2;

    return head1;
}

int main()
{
    struct node *head1 = NULL, *head2 = NULL;
    int choice;

    printf("Create First Linked List\n");
    head1 = create();

    do
    {
        printf("\n1. Sort Linked List");
        printf("\n2. Reverse Linked List");
        printf("\n3. Concatenate Two Linked Lists");
        printf("\n4. Display Linked List");
        printf("\n5. Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                head1 = sort(head1);
                printf("Sorted List:\n");
                display(head1);
                break;

            case 2:
                head1 = reverse(head1);
                printf("Reversed List:\n");
                display(head1);
                break;

            case 3:
                printf("Create Second Linked List\n");
                head2 = create();

                head1 = concatenate(head1, head2);

                printf("Concatenated List:\n");
                display(head1);
                break;

            case 4:
                display(head1);
                break;

            case 5:
                printf("Exiting...");
                break;

            default:
                printf("Invalid choice\n");
        }

    } while(choice != 5);

    return 0;
}
