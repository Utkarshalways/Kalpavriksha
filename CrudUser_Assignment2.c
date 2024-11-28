#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "user.txt"

void createFile();
void addUser();
void displayUsers();
void updateUser();
void deleteUser();

int main()
{
    int choice;

    do
    {
        printf("\n---- User Management By Utkarsh ----\n");
        printf("1. Create File\n");
        printf("2. Add User\n");
        printf("3. Display Users\n");
        printf("4. Update User\n");
        printf("5. Delete User\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1)
            createFile();
        else if (choice == 2)
            addUser();
        else if (choice == 3)
            displayUsers();
        else if (choice == 4)
            updateUser();
        else if (choice == 5)
            deleteUser();
        else if (choice == 6)
            printf("Exiting program\n");
        else
            printf("Please enter a vaild Choice\n");
    } while (choice != 6);

    return 0;
}

void createFile()
{
    FILE *file = fopen(FILE_NAME, "a");
    if (file)
    {
        fclose(file);
        printf("File created successfully (or already exists).\n");
    }
    else
    {
        printf("Error creating file!\n");
    }
}

void deleteUser()
{
    FILE *file = fopen(FILE_NAME, "r");
    FILE *temp = fopen("temp.txt", "w");
    if (!file || !temp)
    {
        printf("Error opening file!\n");
        return;
    }

    int id, age, searchId, found = 0;
    char name[50];

    printf("Enter ID to delete: ");
    scanf("%d", &searchId);

    while (fscanf(file, "%d %s %d", &id, name, &age) != EOF)
    {
        if (id == searchId)
        {
            found = 1;
            continue;
        }
        fprintf(temp, "%d %s %d\n", id, name, age); 
    }

    fclose(file);
    fclose(temp);

    remove(FILE_NAME);
    rename("temp.txt", FILE_NAME);

    if (found)
        printf("User deleted successfully!\n");
    else
        printf("User with ID %d not found!\n", searchId);
}

void addUser()
{
    FILE *file = fopen(FILE_NAME, "a");
    if (!file)
    {
        printf("Error opening file!\n");
        return;
    }

    int id, age;
    char name[50];
    printf("Enter ID: ");
    scanf("%d", &id);
    printf("Enter Name: ");
    scanf("%s", name);
    printf("Enter Age: ");
    scanf("%d", &age);

    fprintf(file, "%d %s %d\n", id, name, age);
    fclose(file);
    printf("User added successfully!\n");
}

void displayUsers()
{
    FILE *file = fopen(FILE_NAME, "r");
    if (!file)
    {
        printf("Error opening file!\n");
        return;
    }

    int id, age;
    char name[50];
    printf("\n--- Users List ---\n");
    while (fscanf(file, "%d %s %d", &id, name, &age) != EOF)
    {
        printf("ID: %d, Name: %s, Age: %d\n", id, name, age);
    }
    fclose(file);
}

void updateUser()
{
    FILE *file = fopen(FILE_NAME, "r");
    FILE *temp = fopen("temp.txt", "w");
    if (!file || !temp)
    {
        printf("Error opening file!\n");
        return;
    }

    int id, found = 0, age;
    char name[50];
    int searchId;

    printf("Enter ID to update: ");
    scanf("%d", &searchId);

    while (fscanf(file, "%d %s %d", &id, name, &age) != EOF)
    //EOF is end of file
    {
        if (id == searchId)
        {
            found = 1;
            printf("Enter new Name: ");
            scanf("%s", name);
            printf("Enter new Age: ");
            scanf("%d", &age);
        }
        fprintf(temp, "%d %s %d\n", id, name, age);
    }

    fclose(file);
    fclose(temp);

    remove(FILE_NAME);
    rename("temp.txt", FILE_NAME);

    if (found)
        printf("User updated successfully!\n");
    else
        printf("User with ID %d not found!\n", searchId);
}


// in this we have to first create a file which is by default will be named as user.txt then can perform operation on it 