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
void push(struct Node** top, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *top;
    *top = newNode;
}
int pop(struct Node** top) {
    if (*top == NULL) {
        printf("Stack is empty.\n");
        return -1;
    }
    int data = (*top)->data;
    struct Node* temp = *top;
    *top = (*top)->next;
    free(temp);
    return data;
}
void enqueue(struct Node** front, struct Node** rear, int data) {
    struct Node* newNode = createNode(data);
    if (*front == NULL) {
        *front = *rear = newNode;
        return;
    }
    (*rear)->next = newNode;
    *rear = newNode;
}
int dequeue(struct Node** front, struct Node** rear) {
    if (*front == NULL) {
        printf("Queue is empty.\n");
        return -1;
    }
    int data = (*front)->data;
    struct Node* temp = *front;
    if (*front == *rear) {
        *front = *rear = NULL;
    } else {
        *front = (*front)->next;
    }
    free(temp);
    return data;
}
void display(struct Node* top, const char* label) {
    printf("%s elements: ", label);
    while (top != NULL) {
        printf("%d ", top->data);
        top = top->next;
    }
    printf("\n");
}
int main() {
    struct Node* stackTop = NULL;
    struct Node* queueFront = NULL;
    struct Node* queueRear = NULL;
    int choice, data;
    do {
        printf("\nChoose an operation:\n");
        printf("1. Push (Stack)\n");
        printf("2. Pop (Stack)\n");
        printf("3. Enqueue (Queue)\n");
        printf("4. Dequeue (Queue)\n");
        printf("5. Display\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to push onto the stack: ");
                scanf("%d", &data);
                push(&stackTop, data);
                display(stackTop, "Stack");
                break;

            case 2:
                printf("Popped element from the stack: %d\n", pop(&stackTop));
                display(stackTop, "Stack");
                break;

            case 3:
                printf("Enter the element to enqueue into the queue: ");
                scanf("%d", &data);
                enqueue(&queueFront, &queueRear, data);
                display(queueFront, "Queue");
                break;

            case 4:
                printf("Dequeued element from the queue: %d\n", dequeue(&queueFront, &queueRear));
                display(queueFront, "Queue");
                break;

            case 5:
                display(stackTop, "Stack");
                display(queueFront, "Queue");
                break;

            case 0:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 0);
    return 0;
}
