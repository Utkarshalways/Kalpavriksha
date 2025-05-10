#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int isbn;
    char* name;
    int quantity;
    struct Node *next;
};

struct Node* head = NULL;

struct Node *createNode(int isbn, int quantity, char *name)
{
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->name = name;
    newNode->isbn = isbn;
    newNode->quantity = quantity;
    newNode->next = NULL;
    return newNode;

}

void printNode(struct Node* start){

    struct Node* temp = start;
    
    printf("\n");
    while(temp != NULL){

        printf("%d - %s - Quantity(%d)\n",temp->isbn,temp->name,temp->quantity);
        temp = temp->next;

    }
    printf("\n----END----\n\n");
    

}

int getTotalBooks(){

    struct Node* temp = head;
    int length = 0;
    while(temp != NULL){

     length += temp->quantity;
        temp = temp->next;

    }

    return length;
}

int isBookPresent(int isbn){

    struct Node* temp = head;
    int count = 0;

    while(temp != NULL){
        count++;
        if(temp->isbn == isbn){
            return count;
        }
        temp = temp->next;
    }

    return -1;

}

struct Node* insertAtEnd(int isbn,int quantity,char* name){

    if(head == NULL){
        struct Node* newNode = createNode(isbn,quantity,name);
        head = newNode;
        return head;
    }


    if(isBookPresent(isbn) > 0){

        // printf("Book Already Present!!\n");

        struct Node* temp = head;
        int count = isBookPresent(isbn);
        // printf("%d",count);
        int start = 1;
        int len = getTotalBooks();
        // printf("%d\n",len);
        while(start < count && temp->next != NULL){
            // printf("%d\n",temp->isbn);
            start++;
            temp = temp->next;
        }

        temp->quantity += quantity;
        // printf("%s %d",temp->name,temp->quantity);
        return head;

    }

    struct Node* temp = head;

    while(temp->next != NULL){

        temp = temp->next;

    }

    temp->next = createNode(isbn,quantity,name);

    return head;

}


void purchaseABook(int isbn){

    struct Node* temp = head;

    while(temp != NULL){

        if(temp->isbn == isbn && temp->isbn > 0){

            temp->quantity -= 1;
            return;

        }

        temp = temp->next;

    }

    printNode(head);

}


struct Node* find_middle(struct Node* head){
    struct Node* slow = head;
    struct Node* fast = head->next;
 
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
 

 struct Node* merge_recursive(struct Node* left, struct Node* right){
    if(left == NULL) return right;
    if(right == NULL) return left;
 
    if(left->quantity > right->quantity){
        left->next = merge_recursive(left->next, right);
        return left;
    }
    else{
        right->next = merge_recursive(left, right->next);
        return right;
    }
}

 
struct Node* merge_sort(struct Node* head) {
    if(head == NULL || head->next == NULL) return head;
 
    struct Node* middle = find_middle(head);
    struct Node* left = head;
    struct Node* right = middle->next;
    middle->next = NULL;
 
    left = merge_sort(left);
    right = merge_sort(right);
    head = merge_recursive(left, right);
    return head;
}




int main(){


    head = createNode(1,10,"Creating Abundance");
    head = insertAtEnd(2,1,"Create an impact");
    head = insertAtEnd(3,4,"The Wings of Fire");
   
    
    int isbn;
    int quantity;
    char name[50];
    //  printf("%d",getTotalBooks());

    while(1){

        printf("Choose The Options:-- \n");
        printf("1.Add Book\n");
        printf("2.Sort By Quantity\n");
        printf("3.Purchase A Book\n");
        printf("4.Display Books\n");
        printf("5.Total Books Count\n");
        printf("Default: EXIT....\n");
        printf("You Choose >");

        int choice;
        scanf("%d",&choice);

        switch(choice){

            case 1:
                    printf("Enter ISBN:- ");
                    scanf("%d",&isbn);
                    getchar();
                    printf("Enter Quantity:- ");
                    scanf("%d",&quantity);
                    getchar();
                    printf("Enter Name:- ");
                    scanf("%[^\n]%*c",name);
                    head = insertAtEnd(isbn,quantity,name);
                    break;

            case 2: head = merge_sort(head);
                    printNode(head);
                    break;

            case 3: printf("Enter ISBN:- ");
                    scanf("%d",&isbn);
                    purchaseABook(isbn);
                    break;

            case 4: printNode(head);
                    break;

            // case 3:
            case 5: printf("%d\n",getTotalBooks());
                    break;


            default: 
                    return 0;

        }

 
    }

    return 0;



}
