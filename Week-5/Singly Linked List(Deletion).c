#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *next;
};
void insertEnd(struct Node **head, int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}
void deleteFirst(struct Node **head) {
    if (*head == NULL) {
        printf("List is empty! Nothing to delete.\n");
        return;
    }

    struct Node *temp = *head;
    *head = (*head)->next;
    printf("Deleted element: %d\n", temp->data);
    free(temp);
}
void deleteLast(struct Node **head) {
    if (*head == NULL) {
        printf("List is empty! Nothing to delete.\n");
        return;
    }

    struct Node *temp = *head;
    if (temp->next == NULL) {
        printf("Deleted element: %d\n", temp->data);
        free(temp);
        *head = NULL;
        return;
    }
    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    struct Node *lastNode = temp->next;
    printf("Deleted element: %d\n", lastNode->data);
    temp->next = NULL;
    free(lastNode);
}
void deleteSpecified(struct Node **head, int value) {
    if (*head == NULL) {
        printf("List is empty! Nothing to delete.\n");
        return;
    }

    struct Node *temp = *head;
    struct Node *prev = NULL;
    if (temp != NULL && temp->data == value) {
        *head = temp->next;
        printf("Deleted element: %d\n", temp->data);
        free(temp);
        return;
    }
    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Element %d not found in the list.\n", value);
        return;
    }
    prev->next = temp->next;
    printf("Deleted element: %d\n", temp->data);
    free(temp);
}
void display(struct Node *head) {
    struct Node *temp = head;
    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
int main() {
    struct Node *head = NULL;
    int choice, value;

    while (1) {
        printf("\n--- Linked List Deletion Menu ---\n");
        printf("1. Add Element (Insert at End)\n");
        printf("2. Delete First Element\n");
        printf("3. Delete Last Element\n");
        printf("4. Delete Specified Element (by Value)\n");
        printf("5. Display List\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to add: ");
                scanf("%d", &value);
                insertEnd(&head, value);
                display(head);
                break;
            case 2:
                deleteFirst(&head);
                display(head);
                break;
            case 3:
                deleteLast(&head);
                display(head);
                break;
            case 4:
                printf("Enter the element value to delete: ");
                scanf("%d", &value);
                deleteSpecified(&head, value);
                display(head);
                break;
            case 5:
                printf("Current Linked List: ");
                display(head);
                break;
            case 6:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please select a valid option.\n");
        }
    }
    return 0;
}
