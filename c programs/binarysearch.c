#include <stdio.h>
void binarysearch(int arr[],int n,int key)
{
 int f = 0,mid,l=n-1;
 while (f <= l)
{
    mid = (f+l)/2;
    if (arr[mid] == key)
  {
    printf("Element is found at index %d.\n", mid);
    break;
  }
  else if (arr[mid] < key)
  {
    f = mid + 1;
  }
  else
  {
    l = mid - 1;
  }
}
 if (f > l)
 {
    printf("Element not found !!!!!!!!");
 }
}

int main()
{
  system("cls");
  int arr[50],n,key;
  printf("Enter the size of array : ");
  scanf("%d",&n);
  printf("Enter the elements of array : ");
  for(int i=0;i<n;i++)
  {
    scanf("%d",&arr[i]);
  }
  printf("Enter Element to Search : ");
  scanf("%d", &key);
  binarysearch(arr,n,key);
}