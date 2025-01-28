#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


int printArr(int arrSize,int arr[arrSize]){

    for(int idx = 0;idx < arrSize;idx++){

        printf("%d  ",arr[idx]);

    }
    printf("\n");

}

void  swap(int *first , int* second){

        int temp = *first;
        *first = *second;
        *second = temp;

}


void bubbleSort(int arr[],int arrSize){

    bool swapped = false;

    for(int idx = 0;idx < arrSize;idx++){

        for(int j = 1;j<arrSize-idx+1;j++){

            if(arr[j-1] > arr[j]){

                swap(&arr[j-1],&arr[j]);
                swapped = true;
            }

        }
        if(swapped == false){

            break;
        }

    }

}


int main(){

    int arrSize = 0;
    printf("Enter the Array Size:-- ");
    scanf("%d",&arrSize);

    int arr[arrSize];
    printf("Enter the Elements:- ");
    for(int idx = 0;idx < arrSize;idx++){

        scanf("%d",&arr[idx]);

    }

    bubbleSort(arr,arrSize);

    printArr(arrSize,arr);

    

}