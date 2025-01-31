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

void printQueue(struct Queue* q) {
    if(isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }
    for(int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
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

int peek(struct Queue* q) {
    if(isEmpty(q)) {
        printf("Queue is empty.\n");
        return -1;
    }
    printf("Peek Element -> %d\n", q->arr[q->front]);
    return q->arr[q->front];
}

void push(struct Queue* q, int data) {
    if(isFull(q)) {
        printf("Queue is full, cannot push %d\n", data);
        return;
    }
    
    enqueue(q, data);
    
    // Move all elements behind the newly added element
    int size = q->rear - q->front + 1;
    
    for(int i = 0; i < size - 1; i++) {
        int temp = q->arr[q->front];
        dequeue(q);
        enqueue(q, temp);
    }
}

int main() {
    printf("Size of the Queue? ");
    
    int size;
    scanf("%d", &size);
    
    struct Queue* q = createQueue(size);
    
    if (q == NULL) return 1;
    int val; 

    while(1) {
        printf("Enter the Choice:- \n");
        printf("1. enqueue\n");
        printf("2. dequeue\n");
        printf("3. Peek\n");
        printf("4. isEmpty\n");
        printf("5. isFull\n");
        printf("6. Size\n");
        printf("Default \n");
        
        int choice;
        printf("You Entered > ");
        
        scanf("%d", &choice);

        switch(choice) {
            case 1: 
                printf("Value? ");
                scanf("%d", &val);
                push(q, val);
                break;

            case 2: 
                dequeue(q);    
                break;

            case 3: 
                peek(q);
                break;

            case 4: 
                isEmpty(q) ? printf("True\n") : printf("False\n");
                break;

            case 5: 
                isFull(q) ? printf("True\n") : printf("False\n");
                break;

            case 6: 
                if (isEmpty(q)) {
                    printf("Size: 0\n");
                } else {
                    printf("Size: %d\n", (q->rear - q->front + 1));
                }
                break;

            default: 
                printf("--EXIT--\n");
                free(q->arr);
                free(q);      
                return 0;
        }
        
        printQueue(q); 
    }

    return 0;
}
