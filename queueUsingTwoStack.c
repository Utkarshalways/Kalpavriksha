#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Stack {
    int size;
    int *arr;
    int top;
} Stack;

Stack* createStack(int size) {
    Stack* s = (Stack*) malloc(sizeof(Stack));
    if (s == NULL) {
        printf("Memory Not Allocated!!");
        return NULL;
    }
    s->size = size;
    s->top = -1;
    s->arr = (int*) malloc(sizeof(int) * size);
    if (s->arr == NULL) {
        printf("Memory not allocated to stack array!!\n");
        free(s);
        return NULL;
    }
    return s;
}

bool isEmpty(Stack* s) {
    return s->top == -1;
}

bool isFull(Stack* s) {
    return s->top == s->size - 1;
}

void push(Stack* s, int data) {
    if (isFull(s)) {
        printf("Stack Overflow!!\n");
        return;
    }
    s->arr[++s->top] = data;
}

int pop(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack Underflow!!\n");
        return -1;
    }
    return s->arr[s->top--];
}

typedef struct Queue {
    Stack* stack1;
    Stack* stack2;
} Queue;

Queue* createQueue(int size) {
    Queue* q = (Queue*) malloc(sizeof(Queue));
    q->stack1 = createStack(size);
    q->stack2 = createStack(size);
    return q;
}

void enqueue(Queue* q, int data) {
    push(q->stack1, data);
    printf("Enqueued: %d\n", data);
}

int dequeue(Queue* q) {
    if (isEmpty(q->stack2)) {
        while (!isEmpty(q->stack1)) {
            push(q->stack2, pop(q->stack1));
        }
    }
    int data = pop(q->stack2);
    if (data != -1) {
        printf("Dequeued: %d\n", data);
    }
    return data;
}

int main() {
    int size, choice, value;
    printf("Enter the size of the queue: ");
    scanf("%d", &size);
    Queue* q = createQueue(size);

    while (1) {
        printf("Enter the Choice:- \n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Exit\n");
        printf("You Entered: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Value? ");
                scanf("%d", &value);
                enqueue(q, value);
                break;

            case 2:
                dequeue(q);
                break;

            case 3:
                printf("--EXIT--\n");
                return 0;

            default:
                printf("Invalid choice! Please enter again.\n");
                break;
        }
    }
    return 0;
}
