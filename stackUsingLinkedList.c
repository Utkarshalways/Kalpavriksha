#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Node{
    int data;
    struct Node* next;
};


struct Node* createNode(int data){

    struct Node* newNode = (struct Node* ) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}


int getLength(struct Node* head){

    struct Node* temp = head;
    int count = 0;

    while(temp != NULL){
        count++;
        temp = temp->next;  
    }

    return count;

}

bool isEmpty(struct Node* head){

    if(head == NULL){
        printf("Empty!! \n");
        return true;
    }

    return false;

}

struct Node* insertAtBeginning(struct Node* head,int data){

    if(head == NULL){

        head = createNode(data);
        return head;

    }

    struct Node* newNode = createNode(data);

    newNode->next = head;
    head = newNode;
    return head;

}


struct Node* push(struct Node* head,int data){

    return insertAtBeginning(head,data);


}

struct Node* pop(struct Node* head){

    if(head == NULL || head->next == NULL){
        head = NULL;
        return head;
    }

    struct Node* temp = head->next;
    head = temp;
    return head;

}

int peek(struct Node* head){

    if(isEmpty(head)){
        return -1;
    }

    printf("%d\n",head->data);

    return head->data;

}


int main(){


    struct Node* head = NULL;

   
    int val;

     while(1){
        printf("Enter the Choice:- \n");
        printf("1.Push\n");
        printf("2.Pop\n");
        printf("3.Peek\n");
        printf("4.isEmpty\n");
        printf("5.Length Of Stack\n");
        printf("Default \n");
        printf("You Entered >");

        int choice;
        scanf("%d",&choice);

        switch(choice){

            case 1: printf("Value? ");
                    scanf("%d",&val);
                    head = push(head,val);
                    break;

            case 2: head = pop(head);    
                    break;

            case 3: peek(head);
                    break;

            case 4: isEmpty(head)? printf("True\n"):printf("False\n");
                    break;

            case 5: printf("%d\n",getLength(head));        
                    break;

            default: printf("--EXIT--\n");
                    return 0;


        }


    }
    return 0;


}
