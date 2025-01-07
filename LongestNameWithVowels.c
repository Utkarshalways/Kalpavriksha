#include <stdio.h>
#include <string.h>
#include <ctype.h>

void matrixPrint(char arr[][100][50], int n, int m)
{

    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < m; j++)
        {

            printf("%s ", arr[i][j]);
        }
        printf("\n");
    }
}

void longestNameWithVowelsCount(char names[][100][50],int rows,int columns){


    char nameLongest[50] = "";
    int count = 0;

    for (int i = 0; i < rows; i++)
    {

        for (int j = 0; j < columns; j++)
        {

            if(strlen(names[i][j]) > strlen(nameLongest)){

                strcpy(nameLongest,names[i][j]);
            }


            char ch = tolower(names[i][j][0]);

            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
                count++;
            }
            
        }

        
    }



    printf("The longest Name is:- %s\n",nameLongest);
    printf("The Names with the vowels are :- %d",count);
}


int main()
{

    int rows = 5;
    printf("Enter the Number of Rows:-");
    scanf("%d", &rows);

    int columns = 5;
    printf("Enter the Number of Columns:-");
    scanf("%d", &columns);

    char names[10][100][50];

    for (int i = 0; i < rows; i++)
    {

        for (int j = 0; j < columns; j++)
        {
            printf("Enter the names for (%d,%d):- ", i, j);
            scanf("%s", names[i][j]);
        }
    }

    

    matrixPrint(names, rows, columns);


    longestNameWithVowelsCount(names,rows,columns);

    return 0;
}

