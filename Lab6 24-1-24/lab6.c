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

void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void sortList(struct Node* head) {
    struct Node* current = head;
    int temp;

    while (current != NULL) {
        struct Node* next = current->next;
        while (next != NULL) {
            if (current->data > next->data) {
                temp = current->data;
                current->data = next->data;
                next->data = temp;
            }
            next = next->next;
        }
        current = current->next;
    }
}

void reverseList(struct Node** head) {
    struct Node *prev, *current, *next;
    prev = NULL;
    current = *head;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

void concatenateLists(struct Node** first, struct Node* second) {
    if (*first == NULL) {
        *first = second;
        return;
    }
    struct Node* temp = *first;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = second;
}

int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;
    int n, data;

    printf("Enter the number of elements for List 1: ");
    scanf("%d", &n);
    printf("Enter the elements for List 1:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        insertEnd(&list1, data);
    }

    printf("Enter the number of elements for List 2: ");
    scanf("%d", &n);
    printf("Enter the elements for List 2:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        insertEnd(&list2, data);
    }

    printf("Original List 1: ");
    printList(list1);
    printf("Original List 2: ");
    printList(list2);

    sortList(list1);
    printf("Sorted List 1: ");
    printList(list1);

    reverseList(&list2);
    printf("Reversed List 2: ");
    printList(list2);

    concatenateLists(&list1, list2);
    printf("Concatenated List: ");
    printList(list1);

    return 0;
}

