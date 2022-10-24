/*
 * C program to illustrate the operations of singly linked list
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 30
 
struct emp_data
{
    int  empno;
    char empName[MAX];
    char designation[MAX];
    struct emp_data *next;
};
 
/* ********************************************************************/
/*  Function to insert a node at the front of the linked list.        */
/*  front: front pointer, id: employee ID, name: employee name        */
/*  desg: Employee designation                                        */
/*  Returns the new front pointer.                                    */
/* ********************************************************************/
struct emp_data *insert(struct emp_data *front, int id, char name[],
char desg[])
{
    struct emp_data *newnode;
 
    newnode = (struct emp_data*)malloc(sizeof(struct emp_data));
 
    if (newnode == NULL)
    {
        printf("\n Allocation failed \n");
        exit(2);
    }
    newnode->empno = id;
    strcpy(newnode->empName, name);
    strcpy(newnode->designation, desg);
    newnode->next = front;
    front = newnode;
    return(front);
}
/*  End of insert() */
 
/*  Function to display a node in a linked list */
void printNode(struct emp_data *p)
{
    printf("\n Employee Details...\n");
    printf("\n Emp No       : %d", p->empno);
    printf("\n Name           : %s", p->empName);
    printf("\n Designation    : %s\n", p->designation);
    printf("-------------------------------------\n");
}
/*  End of printNode() */
 
/*  ********************************************************/
/*  Function to deleteNode a node based on employee number */
/*  front: front pointer, id: Key value                    */
/*  Returns: the modified list.                            */
/*  ********************************************************/
struct emp_data* deleteNode(struct emp_data *front, int id)
{
    struct emp_data *ptr;
    struct emp_data *bptr;
 
    if (front->empno == id)
    {
        ptr = front;
        printf("\n Node deleted:");
        printNode(front);
        front = front->next;
        free(ptr);
        return(front);
    }
    for (ptr = front->next, bptr = front; ptr != NULL; ptr = ptr->next,
bptr = bptr->next)
    {
        if (ptr->empno == id)
        {
            printf("\n Node deleted:");
            printNode(ptr);
            bptr->next = ptr->next;
            free(ptr);
            return(front);
        }
    }
    printf("\n Employee Number %d not found ", id);
    return(front);
}
/*  End of deleteNode() */
 
/* ****************************************************************/
/*  Function to search the nodes in a linear fashion based emp ID */
/*  front: front pointer, key: key ID.                            */
/* ****************************************************************/
void search(struct emp_data *front, int key)
{
    struct emp_data *ptr;
 
    for (ptr = front; ptr != NULL; ptr = ptr -> next)
    {
        if (ptr->empno == key)
        {
            printf("\n Key found:");
            printNode(ptr);
            return;
        }
    }
    printf("\n Employee Number %d not found ", key);
}
/*  End of search() */
 
/*  Function to display the linked list */
void display(struct emp_data  *front)
{
    struct emp_data *ptr;
 
    for (ptr = front; ptr != NULL; ptr = ptr->next)
    {
        printNode(ptr);
    }
}
/*  End of display() */
 
/*  Function to display the menu of operations on a linked list */
void menu()
{
    printf("---------------------------------------------\n");
    printf("Press 1 to INSERT a node into the list       \n");
    printf("Press 2 to DELETE a node from the list       \n");
    printf("Press 3 to DISPLAY the list                 \n");
    printf("Press 4 to SEARCH the list                   \n");
    printf("Press 5 to EXIT                              \n");
    printf("---------------------------------------------\n");
}
/*  End of menu() */
 
/*  Function to select the option */
char option()
{
    char choice;
 
    printf("\n\n>> Enter your choice: ");
    switch(choice=getche())
    {
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':   return(choice);
        default :   printf("\n Invalid choice.");
    }
    return choice;
}
/*  End of option() */
 
/*  The main() program begins */
void main()
{
    struct emp_data *linkList;
    char name[21], desig[51];
    char choice;
    int eno;
 
    linkList = NULL;
    printf("\n Welcome to demonstration of singly linked list \n");
    menu();
    do
    {
        /*  choose oeration to be performed */
        choice = option();
        switch(choice)
        {
        case '1':
            printf("\n Enter the Employee Number      : ");
            scanf("%d", &eno);
            printf("Enter the Employee name        : ");
            fflush(stdin);
            gets(name);
            printf("Enter the Employee Designation : ");
            gets(desig);
            linkList = insert(linkList, eno, name, desig);
            break;
        case '2':
            printf("\n\n Enter the employee number to be deleted: ");
            scanf("%d", &eno);
            linkList = deleteNode(linkList, eno);
            break;
        case '3':
            if (linkList == NULL)
            {
                printf("\n List empty.");
                break;
            }
            display(linkList);
            break;
        case '4':
            printf("\n\n Enter the employee number to be searched: ");
            scanf("%d", &eno);
            search(linkList, eno);
            break;
        case '5': break;
        }
    } while (choice != '5');
}
