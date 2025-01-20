#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct
        Node *next;
};

struct Node *createNode(int value)
{

    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    return newNode;
}

struct Node *head = NULL;

int PrintLinkedList()
{
    struct Node *temp = head;
    int length = 1;
    while (temp != NULL)
    {
        length++;
        printf("%d ", temp->data);
        temp = temp->next;
    }
    // printf("NULL");

    printf("\n");

    return length;
}


int getLength(){

    
    struct Node *temp = head;
    int length = 0;
    while (temp != NULL)
    {
        length++;
        temp = temp->next;
    }


    return length;
}




void addAtBeginning(int value)
{

    if (head == NULL)
    {
        struct Node *newNode = createNode(value);
        head = newNode;
        return;
    }

    struct Node *newNode = createNode(value);
    newNode->next = head;
    head = newNode;
}

void addAtEnd(int value)
{

    if (head == NULL)
    {
        struct Node *newNode = createNode(value);
        head = newNode;
        return;
    }

    struct Node *newNode = createNode(value);
    struct Node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
}

void addAtPosition(int position, int value)
{

    if (position == 1 || head == NULL)
    {
        addAtBeginning(value);
    }

    
    if(position == getLength()+1){

        addAtEnd(value);  
        return;      

    }

    else if( position > getLength()){

        printf("Invaild Position\n");
        return;
    }

    int length = 1;
    struct Node *temp = head;

    while (length < position - 1)
    {
        temp = temp->next;
        length++;
    }

    struct Node *newNode = createNode(value);
    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteAtBeginning()
{

    if (head == NULL)
    {

        exit(0);
    }
    if(head -> next == NULL){

        free(head);
        head = NULL;
        return;
    }

    struct Node *temp = head;
    head = temp->next;
    free(temp); 
}

void deleteAtEnd()
{

    if (head == NULL)
    {
       exit(0);
    }
    struct Node *temp = head;

    while (temp->next->next != NULL)
    {

        temp = temp->next;
    }
    free(temp->next->next);
    temp->next = NULL;
}

void deleteAtPosition(int position)
{

    if (head == NULL)
    {   

        exit(0);

    }


    if(position > getLength()){

        printf("Invaild Position\n");
        return;

    }

    if (position == 1)
    {

        return deleteAtBeginning(head);
    }

    struct Node *temp = head;
    int length = 1;

    while (length < position - 1)
    {
        length++;
        temp = temp->next;
    }

    struct Node *nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    free(nodeToDelete);
}

void updateAtStarting(int updatedValue)
{

    if (head == NULL)
    {
       exit(0);
    }

    head->data = updatedValue;
}

void updateAtEnd(int updatedValue)
{

    if (head == NULL)
    {
       exit(0);
    }

    struct Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->data = updatedValue;
}

void updateAtPosition(int position, int updatedValue)
{

    if (head == NULL)
    {
        exit(0);
    }


     if(position == 0){

        printf("Invaild Position\n");
        return;

    }
    

    
    if(position > getLength()){

        printf("Invaild Position\n");
        return;

    }

    if (position == 1)
    {

        return updateAtStarting(updatedValue);
    }

    int length = 1;
    struct Node *temp = head;
    while (length < position - 1)
    {

        temp = temp->next;
        length++;
    }

    temp->next->data = updatedValue;
}

int main()
{
    int operations;
    scanf("%d",&operations);

    while (operations > 0)
    {

        // printf("Enter the Choice:--\n");
        // printf("1.Insert at End\n");
        // printf("2.Insert at Beginning\n");
        // printf("3.Insert at Position\n");
        // printf("4.Display\n");
        // printf("5.Update The Element on the position\n");
        // printf("6.Delete At Beginning\n");
        // printf("7.Delete At End\n");
        // printf("8.Delete At Position\n");
        int choice = 0;
        scanf("%d", &choice);
        int value = 0;
        int position = 0;

        switch (choice)
        {

        case 1:
            value = 0;
            // printf("Enter the Value you want to insert:-- ");
            scanf("%d", &value);
            addAtEnd(value);
            break;

        case 2:
            // printf("Enter the Value you want to insert:-- ");
            scanf("%d", &value);
            addAtBeginning(value);
            break;

        case 3:
            value = 0;
            // printf("Enter the position:--");
            scanf("%d", &position);
            // printf("Enter the Value you want to insert:-- ");
            scanf("%d", &value);
            addAtPosition(position, value);
            break;

        case 4:
            PrintLinkedList();
            break;

        case 5:
            value = 0;
            // printf("Enter the position:--");
            scanf("%d", &position);
            // printf("Enter the Value you want to insert:-- ");
            scanf("%d", &value);
            updateAtPosition(position, value);
            break;

        case 6:
            deleteAtBeginning();
            break;

        case 7:
            deleteAtEnd();
            break;

        case 8:
            value = 0;
            // printf("Enter the position:--");
            scanf("%d", &position);
            deleteAtPosition(position);
            break;

        default:
            exit(0);
            
        }

        operations--;
    }

}