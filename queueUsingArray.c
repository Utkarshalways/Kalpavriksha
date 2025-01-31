#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


struct Queue{

    int front;
    int rear;
    int size;
    int *arr;

};


struct Queue* createQueue(int Size){

    struct Queue* q = (struct Queue*) malloc(sizeof(struct Queue));
    if(q == NULL){

        printf("Memory Can't Allocate");
        return NULL;
    }
    q->front = -1;
    q->rear = -1;
    q->size = Size;
    q->arr = (int *) malloc (sizeof(int) * Size);

    if(q->arr == NULL){
        printf("Memory Can't Allocate");
        return NULL;
    }
    return q;



}

bool isEmpty(struct Queue* q){

    if(q->front == -1 || q->front > q->rear){

        return true;
    }

    if(q->front == q->rear){

        return true;
    }
    return false;

}


bool isFull(struct Queue* q){

    if(q->rear >= q->size-1){

        printf("OverFlow!!\n");
        return true;
    }

    if(q->front > q->rear){

        printf("OverFlow!!\n");
        return true;
    }
    return false;

}

struct Queue* push(struct Queue* q,int data){


    if(isFull(q)){

        return q;
    }

    if(q->front == -1){
        q->arr[++q->front] = data;
        q->rear = q->front;
        return q;
    }

    if(q->front > q->rear){
        return q;
    }


    q->arr[++q->rear] = data;
    return q;

}

struct Queue* pop(struct Queue* q){


    if(isEmpty(q)){

        return NULL;
    }

    q->front += 1;

    return q;

}

int peek(struct Queue* q){

    printf("%d",q->arr[q->front]);
    return  q->arr[q->front];

}



int main(){ 

    
    printf("Size of the Stack?");
    int size;
    scanf("%d",&size);
    struct Queue* q = createQueue(size);

    

    int val = 0;
    

    while(1){
        printf("Enter the Choice:- \n");
        printf("1.Push\n");
        printf("2.Pop\n");
        printf("3.Peek\n");
        printf("4.isEmpty\n");
        printf("5.isFull\n");
        printf("6.Size\n");
        printf("Default \n");
        printf("You Entered >");

        int choice;
        scanf("%d",&choice);

        switch(choice){

            case 1: printf("Value? ");
                    scanf("%d",&val);
                    q = push(q,val);
                    break;

            case 2: q = pop(q);    
                    break;

            case 3: peek(q);
                    break;

            case 4: isEmpty(q)? printf("True\n"):printf("False\n");
                    break;

            case 5: isFull(q)? printf("True\n"):printf("False\n");
                    break;

            case 6: printf("%d\n",q->rear);        
                    break;

            default: printf("--EXIT--\n");
                    return 0;


        }


    }

    
    return 0;
}