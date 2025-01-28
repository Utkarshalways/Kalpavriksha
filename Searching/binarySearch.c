#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


int printArr(int arrSize,int arr[arrSize]){

    for(int idx = 0;idx < arrSize;idx++){

        printf("%d  ",arr[idx]);

    }
    printf("\n");

}




bool binarySearch(int arr[],int arrSize,int key){

  int start = 0;
  int end = arrSize-1;

while(start <= end){

    int mid = (start + end)/2;

    if(arr[mid] == key){

        return true;
    }
    else if(arr[mid] > key){

        end = mid-1;

    }
    else {

        start = mid+1;
    }


}

   return false;


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

    printf("Enter the key?");
    int key;
    scanf("%d",&key);

    printArr(arrSize,arr);
    
    binarySearch(arr,arrSize,key)? printf("Found"):printf("Not Found");
    

    

}
    
