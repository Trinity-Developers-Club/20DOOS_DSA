/*
 * C Program to Search for an Element in a Linked List 
 */
#include <stdio.h>
#include <stdlib.h>
 
struct node
{
    int num;
    struct node *next;
};
 
void create(struct node **);
int search(struct node *, int);
void release(struct node **);
void display(struct node *);
 
int main()
{
    struct node *p = NULL;
    int key, result;
 
    printf("Enter data into the list\n");
    create(&p);
    printf("Displaying the nodes in the list:\n");
    display(p);
    printf("Enter key to search in the list: ");
    scanf("%d", &key);
    result = search(p, key);
    if (result)
    {
        printf("%d found in the list.\n", key);
    }
    else
    {
        printf("%d not found in the list.\n", key);
    }
    release(&p);
 
    return 0;
}
 
int search(struct node *head, int key)
{
    while (head != NULL)
    {
        if (head->num == key)
        {
            return 1;
        }
        head = head->next;
    }
 
    return 0;
}
 
void create(struct node **head)
{
    int c, ch;
    struct node *temp, *rear;
 
    do
    {
        printf("Enter number: ");
        scanf("%d", &c);
        temp = (struct node *)malloc(sizeof(struct node));
        temp->num = c;
        temp->next = NULL;
        if (*head == NULL)
        {
            *head = temp;
        }
        else
        {
            rear->next = temp;
        }
        rear = temp;
        printf("Do you wish to continue [1/0]: ");
        scanf("%d", &ch);
    } while (ch != 0);
    printf("\n");
}
 
void display(struct node *p)
{
    while (p != NULL)
    {
        printf("%d\t", p->num);
        p = p->next;
    }
    printf("\n");
}
 
void release(struct node **head)
{
    struct node *temp = *head;
    *head = (*head)->next;
    while ((*head) != NULL)
    {
        free(temp);
        temp = *head;
        (*head) = (*head)->next;
    }
}
