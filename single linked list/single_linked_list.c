#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};


struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}


void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}


void insertAtPosition(struct Node** head, int data, int position) {
    if (position <= 0) {
        printf("Invalid position. Please enter a position greater than 0.\n");
        return;
    }

    struct Node* newNode = createNode(data);

    if (position == 1) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    struct Node* current = *head;
    for (int i = 1; i < position - 1 && current != NULL; i++) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Invalid position. Please enter a valid position.\n");
        return;
    }

    newNode->next = current->next;
    current->next = newNode;
}


void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newNode;
}


void display(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;


    int n, element;


    printf("Enter the number of elements: ");
    scanf("%d", &n);


    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &element);
        insertAtEnd(&head, element);
    }


    printf("Linked List: ");
    display(head);


    int newData;
    printf("Enter a new element to insert at the beginning: ");
    scanf("%d", &newData);
    insertAtBeginning(&head, newData);
    printf("Linked List after insertion at the beginning: ");
    display(head);


    int position;
    printf("Enter the position to insert a new element: ");
    scanf("%d", &position);
    printf("Enter a new element to insert at position %d: ", position);
    scanf("%d", &newData);
    insertAtPosition(&head, newData, position);
    printf("Linked List after insertion at position %d: ", position);
    display(head);


    printf("Enter a new element to insert at the end: ");
    scanf("%d", &newData);
    insertAtEnd(&head, newData);
    printf("Linked List after insertion at the end: ");
    display(head);

    return 0;
}
