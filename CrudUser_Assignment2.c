#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "user.txt"

void createFile();
void addUser();
void displayUsers();
void updateUser();
void deleteUser();

// This is main Function
int main()
{
    // Automatically create file at startup
    createFile();

    int choice;

    do
    {
        printf("\n---- User Management By Utkarsh ----\n");
        printf("1. Add User\n");
        printf("2. Display Users\n");
        printf("3. Update User\n");
        printf("4. Delete User\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");

        // Check for valid input
        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n')
                ; // clear input buffer
            continue;
        }

        switch (choice)
        {
        case 1:
            addUser();
            break;
        case 2:
            displayUsers();
            break;
        case 3:
            updateUser();
            break;
        case 4:
            deleteUser();
            break;
        case 5:
            printf("Exiting program\n");
            break;
        default:
            printf("Please enter a valid choice\n");
        }
    } while (choice != 5);

    return 0;
}

void createFile()
{
    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL)
    {
        // File doesn't exist, create it
        file = fopen(FILE_NAME, "w");
        if (file)
        {
            printf("File created successfully.\n");
        }
        else
        {
            perror("Error creating file"); // More descriptive error message
            exit(1);                       // Exit if we can't create the file
        }
    }
    fclose(file);
}

void addUser()
{
    FILE *file = fopen(FILE_NAME, "a+"); // Open for reading and appending
    if (!file)
    {
        perror("Error opening file"); // Proper error message
        return;
    }

    int id, age;
    char name[50];

    printf("Enter ID: ");
    if (scanf("%d", &id) != 1)
    {
        printf("Invalid input! ID must be an integer.\n");
        fclose(file);
        return;
    }

    // Check for duplicate user ID
    int existingId, found = 0;
    while (fscanf(file, "%d %s %d", &existingId, name, &age) != EOF)
    {
        if (existingId == id)
        {
            found = 1;
            break;
        }
    }

    if (found)
    {
        printf("User with ID %d already exists! Please use a different ID.\n", id);
        fclose(file);
        return;
    }

    printf("Enter Name: ");
    scanf("%s", name);

    printf("Enter Age: ");
    if (scanf("%d", &age) != 1)
    {
        printf("Invalid input! Age must be an integer.\n");
        fclose(file);
        return;
    }

    fprintf(file, "%d %s %d\n", id, name, age);
    fclose(file);
    printf("User added successfully!\n");
}

void displayUsers()
{
    FILE *file = fopen(FILE_NAME, "r");
    if (!file)
    {
        perror("Error opening file"); // Proper error message
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
        perror("Error opening file"); // Proper error message
        if (file)
            fclose(file);
        if (temp)
            fclose(temp);
        return;
    }

    int id, found = 0, age;
    char name[50];

    int searchId;

    printf("Enter ID to update: ");

    if (scanf("%d", &searchId) != 1)
    {
        printf("Invalid input! ID must be an integer.\n");
        fclose(file);
        fclose(temp);
        return;
    }

    while (fscanf(file, "%d %s %d", &id, name, &age) != EOF)
    {
        if (id == searchId)
        {
            found = 1;
            printf("Enter new Name: ");
            scanf("%s", name);

            printf("Enter new Age: ");
            if (scanf("%d", &age) != 1)
            {
                printf("Invalid input! Age must be an integer.\n");
                fclose(file);
                fclose(temp);
                return;
            }
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

void deleteUser()
{
    FILE *file = fopen(FILE_NAME, "r");
    FILE *temp = fopen("temp.txt", "w");

    if (!file || !temp)
    {
        perror("Error opening file"); // Proper error message
        if (file)
            fclose(file);
        if (temp)
            fclose(temp);
        return;
    }

    int id, age, searchId, found = 0;
    char name[50];

    printf("Enter ID to delete: ");

    if (scanf("%d", &searchId) != 1)
    {
        printf("Invalid input! ID must be an integer.\n");
        fclose(file);
        fclose(temp);
        return;
    }

    while (fscanf(file, "%d %s %d", &id, name, &age) != EOF)
    {
        if (id == searchId)
        {
            found = 1; // Mark as found but do not write to temp file
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
