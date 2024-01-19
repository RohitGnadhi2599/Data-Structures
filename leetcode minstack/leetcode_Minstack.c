#include <stdio.h>
#include <stdlib.h>


typedef struct {
    int value;
    int min;
} Node;


typedef struct {
    Node *array;
    int top;
    int size;
} MinStack;


MinStack* minStackCreate() {
    MinStack* stack = (MinStack*)malloc(sizeof(MinStack));
    stack->array = (Node*)malloc(10000 * sizeof(Node)); 
    stack->top = -1;
    stack->size = 10000;
    return stack;
}


void minStackPush(MinStack* obj, int val) {
    if (obj->top == -1) {
        obj->array[0].value = val;
        obj->array[0].min = val;
        obj->top = 0;
    } else {
        int newMin = (val < obj->array[obj->top].min) ? val : obj->array[obj->top].min;
        obj->top++;
        obj->array[obj->top].value = val;
        obj->array[obj->top].min = newMin;
    }
}


void minStackPop(MinStack* obj) {
    if (obj->top != -1) {
        obj->top--;
    }
}


int minStackTop(MinStack* obj) {
    if (obj->top != -1) {
        return obj->array[obj->top].value;
    }
    return -1;
}


int minStackGetMin(MinStack* obj) {
    if (obj->top != -1) {
        return obj->array[obj->top].min;
    }
    return -1; 
}

void minStackFree(MinStack* obj) {
    free(obj->array);
    free(obj);
}

int solution() {
    MinStack* obj = minStackCreate();

    minStackPush(obj, -2);
    minStackPush(obj, 0);
    minStackPush(obj, -3);

    printf("Minimum element: %d\n", minStackGetMin(obj)); 

    minStackPop(obj);

    printf("Top element: %d\n", minStackTop(obj));

    printf("Minimum element: %d\n", minStackGetMin(obj)); 

    minStackFree(obj);

    return 0;
}