#include<stdio.h>

int b[100];

void mergesort(int a[],int l,int h)
{
  int mid;
  if(l<h)
  {
    mid = (l+h)/2;
    mergesort(a,l,mid);
    mergesort(a,mid+1,h);
    merge(a,l,mid,h);
  }
}

void merge(int a[],int l,int mid,int h)
{
   int i=l,k=0,j=mid+1;
   while(i<=mid && j<=h)
   {
      if(a[i]<a[j])
        b[k++] = a[i++];
      else
        b[k++] = a[j++];  
   }
  while(j<h)
        b[k++] = a[j++]; 
  while(i<mid)
        b[k++] = a[i++];
   
   i=0;
   for(i=0;i<h;i++)
   {
      a[i]=b[i];
   }
}

void main()
{
  system("cls");
  int n,a[100];
  printf("\nEnter the size of the array :-");
  scanf("%d",&n);
  for(int i=0;i<n;i++)
  {
    scanf("%d",&a[i]);
  }
  mergesort(a,0,n);
  printf("After sorting array will be :- ");
  for(int i=0;i<n;i++)
  {
    printf("%d",a[i]);
  }

}