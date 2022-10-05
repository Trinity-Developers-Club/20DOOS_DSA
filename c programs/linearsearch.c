#include<stdio.h>

int main()
{
  system("cls");
  int a[100],n,k,f=0,i;
  printf("Enter the size of the array :- ");
  scanf("%d",&n);
  printf("Enter the array :- ");
  for(i=0;i<n;i++)
  {
    scanf("%d",&a[i]);
  }
  printf("Enter the element to be searched :-");
  scanf("%d",&k);
  for(i=0;i<n;i++)
  {
    if(a[i]==k)
    {
       f++;
       break;
       
    }  
  }
  if(f==0)
  {
    printf("Element not found !!!!!!!!");
    
  }
  else
  {
    printf("Element found at location :- %d",i);
  } 
}
