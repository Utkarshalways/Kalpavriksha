#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Stack
{

    int size;
    int *arr;
    int top;

} Stack;

Stack *createStack(int size)
{

    Stack *s = (Stack *)malloc(sizeof(Stack));
    if (s == NULL)
    {
        printf("Memory Not Allocated!!");
        free(s);
        return NULL;
    }

    s->size = size;
    s->top = -1;
    s->arr = (int *)malloc(sizeof(int) * size);

    if (s->arr == NULL)
    {

        printf("Memory not allocated to stack Array!!\n");
        free(s);
        return NULL;
    }

    return s;
}

bool isEmpty(Stack *s)
{

    if (s->top == -1)
    {
        printf("Empty!!\n");
        return true;
    }
    return false;
}

bool isFull(Stack *s)
{

    if ((s->size - 1) <= s->top)
    {
        printf("Stack OverFlow!!\n");
        return true;
    }

    return false;
}

int peek(Stack *s)
{

    if (isEmpty(s))
    {
        return -1;
    }

    printf("Top Element-> %d\n", s->arr[s->top]);
    return s->arr[s->top];
}

void push(Stack *s, int data)
{
    if (isFull(s))
    {

        return;
    }
    s->arr[++s->top] = data;
}

int pop(Stack *s)
{

    if (isEmpty(s))
    {

        return -1;
    }

    int res = s->arr[s->top];
    s->top -= 1;
    printf("Pop Element is -> %d\n", res);
    return res;
}

int main()
{

    printf("Size of the Stack?");
    int size;
    scanf("%d", &size);
    Stack *s = createStack(size);

    int val = 0;

    while (1)
    {
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
        scanf("%d", &choice);

        switch (choice)
        {

        case 1:
            printf("Value? ");
            scanf("%d", &val);
            push(s, val);
            break;

        case 2:
            pop(s);
            break;

        case 3:
            peek(s);
            break;

        case 4:
            isEmpty(s) ? printf("True\n") : printf("False\n");
            break;

        case 5:
            isFull(s) ? printf("True\n") : printf("False\n");
            break;

        case 6:
            printf("%d\n", s->top + 1);
            break;

        default:
            printf("--EXIT--\n");
            return 0;
        }
    }
    return 0;
}