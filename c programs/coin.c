#include<stdio.h>

void main()
{
  system("cls");
  int a,b,c,d,t,i=0,k=0;
  char s[100];
  scanf("%d",&t);
  for(i=0;i<t;i++)
  {
     scanf("%d %d %d %d",&a,&b,&c,&d);
     if(a<b)
     {
       a=a+c;
     }
     else if(b<a)
     {
       b=b+c;
     }
     if(a<b)
     {
       a=a+d;
     }
     else if(b<a)
     {
       b=b+d;
     }
     if(a<b)
     {
       s[k++]='S';
     }
     else if(b<a)
     {
       s[k++]='N';
     }
  }
  s[k]='\0';
  k=0;
  while(s[k]!='\0')
  {
    printf("%c",&s[k++]);
    printf("\n");
  }

}