#include<stdio.h>
#include<conio.h>
void quicksort(int a[], int l,int h)
{ 
  int pivot;
  if(l<h)
  {
    pivot = partition(a,l,h);
  
  quicksort(a, l,pivot-1);
  quicksort(a,pivot+1,h);
  }
}

int partition(int a[],int l,int h)
{
  int i=l,j=h,pivot=l,t;
  while(i<j)
  {
    while(a[i]>=a[pivot])
      i++;
    while(a[j]<a[pivot])
      j--;
    if(i<j)
    {
      t=a[i];
      a[i]=a[j];
      a[j]=t;  
    }          
  }
  t=a[pivot];
  a[j]=a[pivot];
  a[j]=t;
  return j;
}

void main()
{
  int a[100],n,i;
  system("cls");
  printf("\nEnter the length array :-");
  scanf("%d",&n);
  printf("\nEnter the array:- ");
  for(i=0;i<n;i++)
  {
    scanf("%d",&a[i]);
  }
  quicksort(a,0,n-1);
  printf("\nAfter sorting:- ");
  for(i=0;i<n;i++)
  {
    printf("%d ",a[i]);
  }

}