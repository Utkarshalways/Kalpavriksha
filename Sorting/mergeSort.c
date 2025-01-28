#include <stdio.h>
#include <stdlib.h>


int printArr(int arrSize,int arr[arrSize]){

    for(int idx = 0;idx < arrSize;idx++){

        printf("%d  ",arr[idx]);

    }
    printf("\n");

}

void merge(int arr[],int start,int end){

    int mid = (start+end)/2;

    int len1 = mid-start+1;
    int len2 = end-mid;

    int* first = (int *) malloc(sizeof(int)* len1);
    int* second = (int *) malloc(sizeof(int)* len2);
    int idx = start;
    for(int i = 0;i<len1;i++){

        first[i] = arr[idx++];

    }

    idx = mid+1;
    for(int i = 0;i<len2;i++){

        second[i] = arr[idx++];

    }
    
    
    int firstIdx = 0;
    int secondIdx = 0;
    int mainIdx = start;


    while(firstIdx < len1  && secondIdx < len2){

        if(first[firstIdx] > second[secondIdx]){

            arr[mainIdx++] = second[secondIdx++];

        }

        else{

            arr[mainIdx++] = first[firstIdx++];
        }

    }

    while(firstIdx < len1){

         arr[mainIdx++] = first[firstIdx++];
    }
    while(secondIdx < len2){

        arr[mainIdx++] = second[secondIdx++];
    }

}


void mergeSort(int arr[],int start,int end){


    if(start >= end ){

        return;
    }

    int mid = (start + end)/2;
    
    mergeSort(arr,start,mid);

    mergeSort(arr,mid+1,end);

    merge(arr,start,end);

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
    mergeSort(arr,0,arrSize-1);
    printArr(arrSize,arr);

    

}
    
