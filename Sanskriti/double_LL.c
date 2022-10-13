#include <stdio.h>
#include <stdlib.h>

typedef struct DLL
{
    int data;
    struct DLL *Llink;
    struct DLL *Rlink;
}node;

node *getnode()
{
    node * new;
    new=(node *)malloc(sizeof(node));
    new->Llink=NULL;
    new->Rlink=NULL;
    return new;
}

node *create( )
{
    node *start,*new,*ptr;
    int element;
    printf("enter first  element : ");
    scanf("%d",&element);
    new=getnode();
    new->Llink=NULL;
    new->Rlink=NULL;
    start=new;
    new->data=element;
    return start;

}

node *insert_front(node *start)
{
    node *new,*ptr;
    int element;
    new=getnode();
    if (new==NULL)
    {
        printf("overflow\n");
        return NULL;
    }
    
    printf("enter element to be inserted at front : ");
    scanf("%d",&element);
    ptr=start;
    ptr->Llink=new;
    new->Rlink=start;
    start=new;
    new->Llink=NULL;
    new->data=element;
    return start;
}

node *insert_last(node *start)
{
    node *new,*ptr,*ptr1;
    int element;
    new=getnode();
    if (new==NULL)
    {
        printf("overflow\n");
        return NULL;
    }
    
    printf("enter element to be inserted at last : ");
    scanf("%d",&element);
    ptr=start;
    while(ptr->Rlink!=NULL)
    {
        ptr=ptr->Rlink;
    }
    ptr->Rlink=new;
    new->Llink=ptr;
    new->Rlink=NULL;
    new->data=element;
    return start;
    
}

node *insert_key(node *start)
{
    node *new,*ptr,*ptr1;
    int element,key;
    new=getnode();
    if (new==NULL)
    {
        printf("overflow\n");
        return NULL;
    }
    printf("enter key value after which you want to insert : ");
    scanf("%d",&key);
    printf("enter element to be inserted : ");
    scanf("%d",&element);
    ptr=start;
    while(ptr->data!=key && ptr->Rlink!=NULL)
    {
        ptr=ptr->Rlink;
    }
    if(ptr->data!=key)
    {
        printf("key not found\n");
        return  NULL;
    }
    ptr1=ptr->Rlink;
    new->Llink=ptr;
    new->Rlink=ptr1;
    ptr->Rlink=new;
    ptr1->Llink=new;
    new->data=element;
    return start;
}

node *delete_first(node *start)
{
    node *ptr,*ptr1;
    if (start==NULL)
    {
        printf("underflow\n");
        return NULL;
    }
    ptr=start;
    ptr1=ptr->Rlink;
    start=ptr1;
    ptr->Rlink=NULL;
    ptr1->Llink=NULL;
    free(ptr);
    return start;
    

}

node *delete_last(node *start)
{
    node *ptr,*ptr1;
    if (start==NULL)
    {
        printf("underflow\n");
        return NULL;
    }
    ptr=start;
    while(ptr->Rlink!=NULL)
    {
        ptr=ptr->Rlink;
    }
    ptr1=ptr->Llink;
    ptr1->Rlink=NULL;
    ptr->Llink=NULL;
    free(ptr);
    return start;
    
}

node *delete_key(node *start)
{
    node *ptr,*ptr1,*ptr2;
    int key;
    if (start==NULL)
    {
        printf("underflow\n");
        return NULL;
    }
    printf("enter key : ");
    scanf("%d",&key);
    ptr1=start;
    while(ptr1->data!=key  && ptr1->Rlink!=NULL)
    {
        ptr1=ptr1->Rlink;
    }
    if (ptr1->data!=key)
    {
        printf("key not found\n");
        return NULL;
    }
    ptr=ptr1->Llink;
    ptr2=ptr1->Rlink;
    ptr->Rlink=ptr2;
    ptr2->Llink=ptr;
    ptr1->Llink=NULL;
    ptr1->Rlink=NULL;
    free(ptr1);
    return start;
}

void display(node *start)
{
    node *ptr;
    ptr=start;
    printf("%d ",start->data);
    while(ptr->Rlink!=NULL)
    {        
        ptr=ptr->Rlink;
        printf("%d ",ptr->data);

    }
    printf("\n");
}

int main()
{
    node *start,*res;
    int choice;
    start=create();
    while(1)
    {
        printf("1 . To insert a node at first position\n ");
        printf("2 . To insert a node at last position\n");
        printf("3 . To insert a node after a given value\n");
        printf("4 . To delete a node at the first position\n");
        printf("5 . To delete a node at the last position\n");
        printf("6 . To delete a node containing a given key value\n");
        printf("7 . To display the linked list\n");
        printf("8  exit\n");

        printf("enter your choice : ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1 :
            {
               res= insert_front(start);
               if (res==NULL)
               break;
               else{
                   printf("element is inserted at front\n");
                   start=res;
               }
            }break;
            
            case 2:
            {
                res=insert_last(start);
                if (res==NULL)
                break;
                else{
                    start=res;
                    printf("element is inserted at last\n");
                }
            }break;

            case 3:
            {
                res=insert_key(start);
                if (res==NULL)
                break;
                else{
                    printf("element is inserted after a given key value\n");
                    start=res;
                }
            }break;

            case 4:
            {
                res=delete_first(start);
                if (res==NULL)
                break;
                else
                {
                    printf("first node is deleted\n");
                    start=res;

                }
            }break;

            case 5: 
            {
                res=delete_last(start);
                if (res==NULL)
                break;
                else{
                    printf("last node is deleted\n");
                    start=res;

                }
            }break;

            case 6:
            {
                res=delete_key(start);
                if (res==NULL)
                break;
                else{
                    start=res;
                    printf("node containing a given key value is deleted\n");

                }
            }break;

            case 7:
            {
                display(start);
            }break;

            case 8 :
            {
                return 0;
            }break;

            default:{
            printf("wrong choice\n");}
            break;
        }
    }
    return 0;

}