#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void displayList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

struct Node* insertAtFront(struct Node* head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;
    return newNode;
}

struct Node* deleteAtFront(struct Node* head) {
    if (head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return head;
    }

    struct Node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

struct Node* deleteAtLast(struct Node* head) {
    if (head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return head;
    }

    if (head->next == NULL) {
        free(head);
        return NULL;
    }

    struct Node* current = head;
    struct Node* prev = NULL;

    while (current->next != NULL) {
        prev = current;
        current = current->next;
    }

    free(current);
    prev->next = NULL;
    return head;
}

struct Node* deleteAtPosition(struct Node* head, int position) {
    if (head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return head;
    }

    if (position < 1) {
        printf("Invalid position. Position should be >= 1.\n");
        return head;
    }

    struct Node* current = head;
    struct Node* prev = NULL;

    if (position == 1) {
        head = head->next;
        free(current);
        return head;
    }

    for (int i = 1; i < position && current != NULL; i++) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Invalid position. Position exceeds the length of the list.\n");
        return head;
    }

    prev->next = current->next;
    free(current);

    return head;
}

int main() {
    struct Node* head = NULL;
    int choice, value, position;

    do {
        printf("\n1. Insert at Front\n");
        printf("2. Delete at Front\n");
        printf("3. Delete at Last\n");
        printf("4. Delete at Position\n");
        printf("5. Display List\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert at front: ");
                scanf("%d", &value);
                head = insertAtFront(head, value);
                displayList(head);
                break;
            case 2:
                head = deleteAtFront(head);
                displayList(head);
                break;
            case 3:
                head = deleteAtLast(head);
                displayList(head);
                break;
            case 4:
                printf("Enter the position to delete: ");
                scanf("%d", &position);
                head = deleteAtPosition(head, position);
                displayList(head);
                break;
            case 5:
                displayList(head);
                break;
            case 6:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 6);

    struct Node* current = head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
