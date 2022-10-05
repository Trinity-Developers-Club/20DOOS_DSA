#include<iostream>
using namespace std;
int main()
{
  system("cls");
  int n,i=1,k;
  cout<<"Enter value of n :-";
  cin>>n;
   while(i<=n)
   {
     k=0;
     while(k<n-i)
     {
       cout<<" "; 
       k++;
     }
     k=1;
     while(k<=i)
     {
       cout<<k++;
     }
     k=i-1;
     while(k>0)
     {
       cout<<k--;
     }

     cout<<endl;
     i++;
  }

}
