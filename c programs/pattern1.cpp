#include<iostream>
using namespace std;
int main()
{
  system("cls");
  int n,i=1,j=1;
  cout<<"Enter value of n :-";
  cin>>n;
   while(i<=n)
   {
    j=1; 
    while (j<=n)
    {  
       if(j<i)
         cout<<" ";
        else if(j>=i)
          cout<<"*";
        j++;    
     }
     cout<<endl;
     i++;
  }

}
