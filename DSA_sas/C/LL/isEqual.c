/*
 * C Program to Check whether 2 Lists are Same 
 */
#include <stdio.h>
#include <stdlib.h>
 
struct node
{
    int num;
    struct node *next;
};
 
void feedmember(struct node **);
int compare (struct node *, struct node *);
void release(struct node **);
 
int main()
{
    struct node *p = NULL;
    struct node *q = NULL;
    int result;
 
    printf("Enter data into first list\n");
    feedmember(&p);
    printf("Enter data into second list\n");
    feedmember(&q);
    result = compare(p, q);
    if (result == 1)
    {
        printf("The 2 list are equal.\n");
    }
    else
    {
        printf("The 2 lists are unequal.\n");
    }
    release (&p);
    release (&q);
 
    return 0;
}
 
int compare (struct node *p, struct node *q)
{
    while (p != NULL && q != NULL)
    {
        if (p->num != q-> num)
        {
            return 0;
        }
        else
        {
            p = p->next;
            q = q->next;
        }
    }
    if (p != NULL || q != NULL)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
 
void feedmember (struct node **head)
{
    int c, ch;
    struct node *temp;
 
    do
    {
        printf("Enter number: ");
        scanf("%d", &c);
        temp = (struct node *)malloc(sizeof(struct node));
        temp->num = c;
        temp->next = *head;
        *head = temp;
        printf("Do you wish to continue [1/0]: ");
        scanf("%d", &ch);
    }while (ch != 0);
    printf("\n");
}
 
void release (struct node **head)
{
    struct node *temp = *head;
 
    while ((*head) != NULL)
    {
        (*head) = (*head)->next;
        free(temp);
        temp = *head;
    }
}