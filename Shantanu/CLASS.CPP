#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>
class Applicant
{
	long ANo ;
	char Name[25] ;
	float Agg ;
	char Grade ;
	char GradeMe()
	{       char G ;
		if(Agg>=80)
		{
			G='A' ;
		}
		else if(Agg<80 && Agg>=65)
		{
			G='B' ;
		}
		else if(Agg<65 && Agg>=50)
		{
			G='C' ;
		}
		else
		{
			G='D' ;
		}
		return G ;
	}
public :
	void ENTER()
	{
		cout<<"Enter your name : "<<"\t" ;
		gets(Name) ;
		cout<<endl ;
		cout<<"Enter your Admission number : "<<"\t" ;
		cin>>ANo ;
		cout<<endl ;
		cout<<"Enter your Aggregate marks : "<<"\t" ;
		cin>>Agg ;
		cout<<endl ;
		cout<<endl<<endl<<"\t"<<"\t" ;
		Grade= GradeMe() ;
	}
	void RESULT()
	{
		cout<<"RESULT"<<"\n"<<"\n" ;
		cout<<Name<<"\n" ;
		cout<<ANo<<"\n" ;
		cout<<"Grade --------- "<<Grade<<"\n"<<"\n" ;
		cout<<"\t"<<"\t"<<"BEST OF LUCK FOR YOUR FUTURE" ;
		getch() ;
	}

} ;
void main()
{
	clrscr() ;
	Applicant y ;
	y.ENTER() ;
	y.RESULT() ;
	getch() ;
}
