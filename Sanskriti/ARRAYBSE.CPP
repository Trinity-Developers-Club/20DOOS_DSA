#include<iostream.h>
#include<conio.h>
int Bsearch(int a[20],int n,int k)
{ int b=0,m,l=n-1 ;
  while(b<=l)
  { m=(b+l)/2;
    if(a[m]==k)
     return m;
    else if (a[m]<k)
     b=m+1;
    else
     l=m-1;
   }
   return -1;
}
void main()
{ clrscr();
  int a[20],n,m,h;
  cout<<"Enter the lenght of the array :-\n";
  cin>>n;
  cout<<"Enter the array (The array must be in ascending order) :-\n";
  for(int i=0;i<n;i++)
  cin>>a[i];
  cout<<"Enter the key element :-\n";
  cin>>m;
  h=Bsearch(a,n,m);
  if(h==-1)
  cout<<"Element not found !!!!!";
  else
  cout<<"Element found at location :-\n"<<h;
  getch();
}
