#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int printArr(int arrSize, int arr[arrSize])
{

    for (int idx = 0; idx < arrSize; idx++)
    {

        printf("%d  ", arr[idx]);
    }
    printf("\n");
}

int twoPointer(int arr[], int arrSize, int key)
{   
    int start = 0;
    int end = arrSize-1;

    while(start <= end){

        if(arr[start] == key){

            return start;
        }
        if(arr[end] == key){

            return end;
        }

        start++;
        end--;

    }
    return -1;
}

int main()
{

    int arrSize = 0;
    printf("Enter the Array Size:-- ");
    scanf("%d", &arrSize);

    int arr[arrSize];
    printf("Enter the Elements:- ");
    for (int idx = 0; idx < arrSize; idx++)
    {
        scanf("%d", &arr[idx]);
    }
    printf("Enter the key?");
    int key;
    scanf("%d", &key);
    printArr(arrSize, arr);
    printf("Present at Index:- %d",twoPointer(arr, arrSize, key));

}
