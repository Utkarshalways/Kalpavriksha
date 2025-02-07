#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct Node
{
    int key;
    int value;
    struct Node *next;

} Node;

typedef struct
{
    Node **map;
    int size;

} Hashmap;

Node *createNode(int key, int value)
{

    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        free(newNode);
        return NULL;
    }
    newNode->key = key;
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

Hashmap *createMap(int size)
{

    Hashmap *hashmap = (Hashmap *)malloc(sizeof(Hashmap));
    if (hashmap == NULL)
    {
        free(hashmap);
        return NULL;
    }
    hashmap->map = (Node **)malloc(sizeof(Node *) * size);
    hashmap->size = size;

    for (int idx = 0; idx < size; idx++)
    {
        hashmap->map[idx] = NULL;
    }
    return hashmap;
}

int hash(int key, int size)
{
    int res = key % size;
    return res;
}

void insertIntoHashmap(Hashmap *hashmap, int key, int value)
{
    int idx = hash(key, hashmap->size);
    Node *newNode = createNode(key, value);
    if (hashmap->map[idx] == NULL)
    {
        hashmap->map[idx] = newNode;
    }
    else
    {
        Node *temp = hashmap->map[idx];
        while (temp != NULL)
        {

            if (temp->key == key)
            {
                temp->value = value;
                free(newNode);
                return;
            }
            temp = temp->next;
        }
        newNode->next = hashmap->map[idx];
        hashmap->map[idx] = newNode;
    }
}

int search(Hashmap *hashmap, int key)
{

    int idx = hash(key, hashmap->size);
    Node *temp = hashmap->map[idx];
    while (temp != NULL)
    {
        if (temp->key == key)
        {
            return temp->value;
        }
        temp = temp->next;
    }
    return -1;
}

void display(Hashmap *hashmap)
{

    for (int idx = 0; idx < hashmap->size; idx++)
    {
        printf("Index:- %d", idx + 1);
        Node *temp = hashmap->map[idx];
        while (temp != NULL)
        {
            printf("(%d, %d) -> ", temp->key, temp->value);
            temp = temp->next;
        }
        printf(" NULL\n");
    }
}

void delete(Hashmap *hashmap, int key)
{
    int idx = hash(key, hashmap->size);
    Node *temp = hashmap->map[idx];
    Node *prev = NULL;
    while (temp != NULL && temp->key != key)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Key Not Found\n");
        return;
    }
    if (prev == NULL)
    {
        hashmap->map[idx] = temp->next;
    }
    else
    {
        prev->next = temp->next;
    }
    printf("Key %d Deleted!!\n", key);
}

int main()
{
    int mapSize = 20;
    Hashmap *hashmap = createMap(mapSize);
    int choice = 0;
    int key, value;

    while (1)
    {
        printf("Enter the Choice:- \n1. Insert\n2. Search\n3. Delete\n4. Display\n5. Exit\n>");
        if (scanf("%d", &choice) != 1)
        {
            return 0;
        }
        switch (choice)
        {
        case 1:
        {
            printf("Enter Key: ");
            scanf("%d", &key);
            printf("Enter Value: ");
            scanf("%d", &value);
            insertIntoHashmap(hashmap, key, value);
            break;
        }

        case 2:
        {
            printf("Enter Key: ");
            scanf("%d", &key);
            value = search(hashmap, key);
            if (value == -1)
            {
                printf("Key Not Found\n");
            }
            else
            {
                printf("Value is %d.\n", value);
            }
            break;
        }
        case 3:
        {

            printf("Enter Key: ");
            scanf("%d", &key);
            delete (hashmap, key);
            break;
        }

        case 4:
        {
            printf("HashMap:- \n");
            display(hashmap);
            break;
        }
        case 5:
        {
            printf("Exiting Program.\n");
            exit(0);
        }
        default:
            printf("Invalid Choice\n");
        }
    }

    return 0;
}