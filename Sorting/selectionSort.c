#include <stdio.h>
#include <stdlib.h>


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


void selectionSort(int arr[],int arrSize){


    

    for(int idx = 0;idx < arrSize-1;idx++){

           int minIdx = idx;
           for(int secIdx = idx+1;secIdx < arrSize ;secIdx++){

                    if(arr[minIdx] > arr[secIdx]){

                            minIdx = secIdx;

                    }

           }
           int temp = arr[minIdx];
           arr[minIdx] = arr[idx];
           arr[idx] = temp;
        
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

    selectionSort(arr,arrSize);

    printArr(arrSize,arr);

    

}