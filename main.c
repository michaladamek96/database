#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define TOP_BORDER 205
#define LEFT_TOP_BORDER 201
#define RIGHT_TOP_BORDER 187
#define LEFT_BOTTOM_BORDER 200
#define RIGHT_BOTTOM_BORDER 188
#define SIDE_BORDER 186
#define INNER_LINE 196

#define TABLE_WIDTH 73

typedef struct Person
{
    char firstName[20];
    char lastName[20];
    int age;
    double height;
    bool isMember;
} Person;

typedef struct List
{
    int ID;
    struct Person value;
    struct List* next;
} List;

void showLabel()
{
    printf("%c",LEFT_TOP_BORDER);
    for (int i = 0; i<TABLE_WIDTH; i++)
        printf("%c", TOP_BORDER);
    printf("%c",RIGHT_TOP_BORDER);
    printf("\n");

    printf("%c", SIDE_BORDER);
    printf(" %-5s", "ID");
    printf(" %-20s", "First Name");
    printf(" %-20s", "Last Name");
    printf("%-5s \t", "Age");
    printf("%s \t", "Height");
    printf("%-10s", "Member");
    printf("%c\n", SIDE_BORDER);

    printf("%c", SIDE_BORDER);
    for (int i = 0; i<TABLE_WIDTH; i++)
        printf("%c", INNER_LINE);
    printf("%c\n", SIDE_BORDER);
}

void showBottomLine()
{
    printf("%c",LEFT_BOTTOM_BORDER);
    for (int i = 0; i<TABLE_WIDTH; i++)
        printf("%c", TOP_BORDER);
    printf("%c",RIGHT_BOTTOM_BORDER);
    printf("\n");   
}


Person createPerson(char *firstName, char *lastName, int age, double height, bool isMember)
{
    Person newPerson;

    strcpy(newPerson.firstName, firstName);
    strcpy(newPerson.lastName, lastName);
    newPerson.age = age;
    newPerson.height = height;
    newPerson.isMember = isMember;

    return newPerson;
}

List* createNewValue(Person newPerson, int id)
{
    List* newValue = (List*)malloc(sizeof(List));
    if (newValue != NULL)
    {
        newValue->value = newPerson;
        newValue->ID = id;
        newValue->next = NULL;
    }
    return newValue;
}

void addToList(List** head, char *firstName, char *lastName, int age, double height, bool isMember)
{
    Person newPerson = createPerson(firstName, lastName, age, height, isMember);
    int id=0;
    if(*head != NULL)
    {
        List *temp = *head;
        id++;
        while (temp->next != NULL)
        {
            id++;
            temp = temp->next;
        }
        List* newNode = createNewValue(newPerson, id);
        temp->next = newNode;
    }
    else
        *head = createNewValue(newPerson, 0);
}


void showPerson(Person person, int id)
{
    printf("%c", SIDE_BORDER);
    printf(" %-5d", id);
    printf(" %-20s", person.firstName);
    printf(" %-20s", person.lastName);
    printf("%-5d \t", person.age);
    printf("%0.2f \t", person.height);
    printf("%-10s", person.isMember ? "YES" : "NO");
    printf("%c\n", SIDE_BORDER);
}

void showList(List* head)
{
    while(head != NULL)
    {
        showPerson(head->value,head->ID);
        head = head->next;
    }
}

int main()
{
    List* personList = NULL;

    addToList(&personList, "Michal", "Adamek", 27, 1.70, true);
    addToList(&personList, "Ada", "Madrzynska", 15, 1.60, false);
    addToList(&personList, "Andrzej", "Kus", 45, 1.95, true);
    addToList(&personList, "Kasia", "Kostrzycka", 19, 1.72, true);
    addToList(&personList, "Barbara", "Kolodziej", 24, 1.50, false);
    addToList(&personList, "Mariusz", "Kreslinski", 68, 1.75, true);

    showLabel();;
    showList(personList);
    showBottomLine();

    return 0;
}