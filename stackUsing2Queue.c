#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Queue {
    int front;
    int rear;
    int size;
    int *arr;
};

struct Queue* createQueue(int Size) {
    struct Queue* q = (struct Queue*) malloc(sizeof(struct Queue));
    if(q == NULL) {
        printf("Memory Can't Allocate\n");
        return NULL;
    }
    q->front = -1;
    q->rear = -1;
    q->size = Size;
    q->arr = (int *) malloc(sizeof(int) * Size);
    if(q->arr == NULL) {
        free(q);
        printf("Memory Can't Allocate\n");
        return NULL;
    }
    return q;
}

bool isEmpty(struct Queue* q) {
    return (q->front == -1);
}

bool isFull(struct Queue* q) {
    return (q->rear == q->size - 1);
}

void enqueue(struct Queue* q, int data) {
    if(isFull(q)) {
        printf("OverFlow!!\n");
        return;
    }
    if(q->front == -1) {
        q->front = 0; 
    }
    q->arr[++q->rear] = data;
}

void dequeue(struct Queue* q) {
    if(isEmpty(q)) {
        printf("Underflow!!\n");
        return;
    }
    q->front++;
    
    if(q->front > q->rear) {
        q->front = q->rear = -1;
    }
}

int front(struct Queue* q) {
    if(isEmpty(q)) {
        printf("Queue is empty.\n");
        return -1;
    }
    return q->arr[q->front];
}

struct Stack {
    struct Queue* q1;
    struct Queue* q2;
};

struct Stack* createStack(int size) {
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
    stack->q1 = createQueue(size);
    stack->q2 = createQueue(size);
    
    return stack;
}

void push(struct Stack* stack, int data) {

    enqueue(stack->q1, data);
}

int pop(struct Stack* stack) {
    if(isEmpty(stack->q1)) {
        printf("Stack is empty.\n");
        return -1; 
    }

    
    while(stack->q1->front != stack->q1->rear) {
        enqueue(stack->q2, front(stack->q1));
        dequeue(stack->q1);
    }

    int poppedElement = front(stack->q1);
    
    dequeue(stack->q1);

    
    struct Queue* temp = stack->q1;
    stack->q1 = stack->q2;
    stack->q2 = temp;

    return poppedElement; 
}

bool isStackEmpty(struct Stack* stack) {
    return isEmpty(stack->q1);
}

int main() {
    printf("Size of the Stack? ");
    
    int size;
    scanf("%d", &size);
    
    struct Stack* stack = createStack(size);
    
    int val; 

    while(1) {
        printf("Enter your choice:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Is Empty\n");
        printf("Default to Exit\n");

        int choice;
        printf("You Entered > ");
        
        scanf("%d", &choice);

        switch(choice) {
            case 1: 
                printf("Value? ");
                scanf("%d", &val);
                push(stack, val);
                break;

            case 2: 
                val = pop(stack);
                if (val != -1) { 
                    printf("Popped: %d\n", val);
                }
                break;

            case 3: 
                isStackEmpty(stack) ? printf("Stack is Empty\n") : printf("Stack is Not Empty\n");
                break;

            default: 
                printf("--EXIT--\n");
                free(stack->q1->arr); 
                free(stack->q2->arr); 
                free(stack->q1);      
                free(stack->q2);      
                free(stack);          
                return 0;
        }
        
        if (!isEmpty(stack->q1)) {
            printf("Current Stack (from bottom to top): ");
            for (int i = stack->q1->front; i <= stack->q1->rear; i++) {
                printf("%d ", stack->q1->arr[i]);
            }
            printf("\n");
        }
        
        printf("\n");
   }

   return 0;
}
