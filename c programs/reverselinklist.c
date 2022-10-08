// revesrse linked list only for gaurav sir.

#include<stdio.h>
#include<stdlib.h>
 typedef struct start
{
  int data;
  struct start * next;
}Node;
Node *start;
void createsll()
{
  start = NULL; 
  printf("List created");
}

void revlist()
{
  struct start *cur=start;
  struct start *prev=NULL;
  struct start *temp;
  int i=1;
  while(cur!=NULL)
  {
     temp=cur->next;
     cur->next=prev;
     prev=cur;
     cur=temp;
  } 
   start=prev;

}

void insert_start()
{
  Node *ptr;
  int e;
  ptr = (Node * )malloc(sizeof(Node));
  printf("Enter the data :-");
  scanf("%d",&e);
  ptr->data=e;
  ptr->next=start;
  start=ptr;
}

void print()
{
  Node *ptr1;
  ptr1=start;
  printf("The list is :- ");
  while(ptr1!=NULL)
  {
    printf("%d ", ptr1->data);
    ptr1=ptr1->next;
  }
}

void main()
{
  struct start *start;
  int n,m;
  char ch;
  do
  {
    system("cls");
    printf("\n1. Create a linked list\n2. Insert element\n3. Display\n4. Reverse the list");
    printf("\nEnter your choice :-");
    scanf("%d", &n);
    switch(n)
    {
      case 1: createsll();
              break;
      case 4: revlist();
              printf("link is reversed");
              break;
      case 2: insert_start();
              break;
      case 3: print();
              break;   
    }                
      printf("\nDo you want to continue?");
      getchar();
      scanf("%c", &ch);                         
    
  } while (ch == 'y' || ch=='Y');
  
}