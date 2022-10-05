#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct node
{
  int data;
  struct node *next;
  
};

struct node* begininsert(struct node *head )
{
  struct node *ptr;
  int e;
  ptr = (struct node * )malloc(sizeof(struct node));
  printf("Enter the data :-");
  scanf("%d",&e);
  ptr->data=e;
  ptr->next=head;
  head=ptr;
  return head;
}

struct node* endinsert(struct node *head )
{ 
  struct node *ptr;
  struct node *temp;
  ptr=head;
  int e;
  
  while(ptr->next!=NULL)
  {
    ptr=ptr->next;
  }
  temp = (struct node * )malloc(sizeof(struct node));
  // printf("fgfhgfghf");
  printf("Enter the data :-");
  scanf("%d",&e);
  temp->data=e;
  temp->next=NULL;
  ptr->next=temp;
  return head;
}
void anyinsert(struct node *head ,int pos)
{
  struct node *ptr;
  struct node *temp;
  int e;
  ptr=head;
  pos--;
  while(pos!=1)
  {
    ptr=ptr->next;
    pos--;
  }
  temp = (struct node * )malloc(sizeof(struct node));
  printf("Enter the data :-");
  scanf("%d",&e);
  temp->data=e;
  temp->next=ptr->next;
  ptr->next=temp;
}
void print(struct node *head)
{
  printf("The list is :- ");
  while(head!=NULL)
  {
    printf("%d ", head->data);
    head=head->next;
  }
}

 struct node * create()
 {
  struct node *ptr;
  int e;
  ptr = (struct node * )malloc(sizeof(struct node));
  printf("Enter the data :-");
  scanf("%d",&e);
  ptr->data=e;
  ptr->next=NULL;
  return ptr;
 }

void enddelete(struct node * head)
{
  struct node *ptr;
  ptr=head;
  while(ptr->next->next!=NULL)
  {
    ptr=ptr->next;
  }
  ptr->next=NULL;
  ptr=ptr->next;
  free(ptr);

  
}
void main()
{
  struct node *head;
  int n,m;
  system("cls");
  do
  {
    printf("\n1. Insert at begin\n2. Insert at end\n3. Insert at any particular position\n4. Print the list\n5. Create linkedlist\n6. Exit\n 7. enddelete");
    printf("\nEnter your choice :-");
    scanf("%d", &n);
    switch(n)
    {
      case 1: head=begininsert(head);
              break;
      case 2: head=endinsert(head);
              break;
      case 3: printf("\nEnter the position :-");
              scanf("%d",&m);
              anyinsert(head,m);
              break;
      case 4: print(head);
              break;
      case 5: head=create();
              printf("\nNode created successfully.");
              break;
      case 7: enddelete(head);
              break;          
                               
    }
  } while(n!=6);
  
}