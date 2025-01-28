#include <stdio.h>
#include <stdlib.h>


int printArr(int arrSize,int arr[arrSize]){

    for(int idx = 0;idx < arrSize;idx++){

        printf("%d  ",arr[idx]);

    }
    printf("\n");

}

int partition(int arr[],int start,int end){

    int pivot = arr[start];
    int count = 0;
    for(int i = start+1;i<=end;i++){

        if(arr[i] < pivot){
            count++;
        }

    }

    int pivotIdx =  start+count;

    int temp = arr[start];
    arr[start] = arr[pivotIdx];
    arr[pivotIdx] = temp;

    pivot = arr[pivotIdx];


    int i = start;
    int j = end;

    while(i < pivotIdx && j > pivotIdx){

        while( arr[i] < pivot){
            i++;
        }
        while(arr[j] > pivot){
            j--;
        }

        if(i < pivotIdx && j > pivotIdx){

            int temp = arr[i];
            arr[i] =  arr[j];
            arr[j] = temp;

        }


    }



}


void quickSort(int arr[],int start,int end){

    
    if(start >= end){
        return;
    }

    int pivot = partition(arr,start,end);

    quickSort(arr,start,pivot -1);

    quickSort(arr,pivot+1,end);


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

    printArr(arrSize,arr);
    quickSort(arr,0,arrSize-1);
    printArr(arrSize,arr);

    

}
    
