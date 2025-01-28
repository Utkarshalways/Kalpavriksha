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


void insertionSort(int arr[],int arrSize){


    int key, secIdx;

    for(int idx = 1;idx < arrSize;idx++){

            key = arr[idx];
            secIdx = idx;

            while(secIdx > 0 && arr[secIdx-1] > key){

                arr[secIdx] = arr[secIdx-1];
                secIdx--;

            }
            arr[secIdx] = key;

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

    insertionSort(arr,arrSize);

    printArr(arrSize,arr);

    

}