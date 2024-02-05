#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    int id;
    char name[50], position[50], email[100];
    long phone, alternatePhone;
} employee;

void login();
void add();
void view();
void search();
void mainmenu();
void title();

int main()
{
    login();
    return 0;
}

void title()
{
    printf("\n\t -------------");
    printf("\n\t EMPLOYEE RECORD MANAGEMENT SYSTEM");
    printf("\n\t -------------");
}
void login()
{
    title();
    char user[50], pass[40];

    printf("\n\t Enter Your Username:");

    scanf("%s", user);

    printf("\n\t Enter Password:");

    scanf("%s", pass);

    if (strcmp(user, "admin") == 0 && strcmp(pass, "admin123") == 0)
    {
        printf("\n\t You have been successfully logged in.");
        mainmenu();
    }
    else
    {
        printf("\n\t Invalid username or password. Try again.");
    }
}

void add()
{
    employee e1;
    FILE *fp;

    FILE *ft;
    char fname[20];
    title();

    printf("\n\t -------------");
    printf("\nEnter the ID of the employee: ");
    printf("\n\t -------------");
    scanf("%d", &e1.id);
    sprintf(fname, "%d.txt", e1.id);
    fp = fopen(fname, "w");

    printf("\n\t -------------");
    printf("Enter the name of the employee: ");
    printf("\n\t -------------");
    scanf("%s", e1.name);

    fflush(stdin);
    printf("\n\t -------------");
    printf("Enter the Email of the employee: ");
    printf("\n\t -------------");
    scanf("%s", e1.email);
    fflush(stdin);
    printf("\n\t -------------");
    printf("Enter the Position of the employee: ");
    printf("\n\t -------------");
    scanf("%s", e1.position);
    fflush(stdin);

    printf("\n\t -------------");
    printf("Enter the number of the employee: ");
    printf("\n\t -------------");
    scanf("%ld", &e1.phone);

    printf("\n\t -------------");
    printf("Enter the alternate number of the employee: ");
    printf("\n\t -------------");
    scanf("%ld", &e1.alternatePhone);

    ft = fopen("database.txt", "a");
    fprintf(fp, "\n\t ID: %d", e1.id);
    fprintf(ft, "\n\t ID: %d", e1.id);
    fprintf(fp, "\n\t Name: %s", e1.name);
    fprintf(fp, "\n\t Email: %s", e1.email);
    fprintf(fp, "\n\t Position: %s", e1.position);
    fprintf(fp, "\n\t Phone Number: %ld", e1.phone);
    fprintf(fp, "\n\t Alternate Phone Number: %ld", e1.alternatePhone);

    printf("\t \n Your data has been saved successfully!");
    fclose(fp);
}

void view()
{

    title();
    printf("\n\t -------------");
    printf("\n\t List of Employees In Our System");
    printf("\n\t -------------");
    employee e1;
    FILE *fs = fopen("database.txt", "r");

    if (fs == NULL)
    {
        printf("\n\t Error 404");
    }
    else
    {
        while (fscanf(fs, "\n\t %d") != EOF)
        {
            printf("%d\n");
        }
    }

    fclose(fs);
}

void search()
{
    char fname[50];
    title();
    char ch, choice;
    do
    {
        printf("\n\t Enter the ID you want to look for (Write .txt at the end): ");
        scanf("%s", fname);
        
        FILE *fx = fopen(fname, "r");

        if (fx == NULL)
        {
            printf("\n\t The ID is not available");
        }
        else
        {
            printf("\n\t Your ID exists");
        }

        fclose(fx);

        printf("\n\t Choose Y or y to search again and N or n to end: ");
        scanf(" %c", &choice);
        fflush(stdin);

    } while (choice == 'Y' || choice == 'y');
}


void mainmenu()
{
    int option;

    while (1)
    {
        title();

        printf("\n\t 1. Add New Employee");
        printf("\n\t 2. View All Employee ID");
        printf("\n\t 3. Search Employee Details");
        printf("\n\t 4. Log Out");
        printf("\n\t Choose an option: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            add();
            break;

        case 2:
            view();
            break;

        case 3:
            search();
            break;

        case 4:
            printf("\n\t Thank you for using EMS!");
            return;

        default:
            printf("Invalid option. Please choose a valid option.\n");
        }
    }
}
