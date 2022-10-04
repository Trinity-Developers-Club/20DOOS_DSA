/*-----Student  Report card  Maker
	Made by               : DHRUV VARSHNEY
	Session               : 2019-20
	School Name           : Hans Raj Smarak SR. SEC. School ,Dilshad Garden ,Delhi
*/
#include<fstream.h>
#include<conio.h>
#include<string.h>
#include<process.h>
#include<stdio.h>

class report
{

    private :
		 int 		admno;
		 char		name[30];
		 char		fname[30];
		 int		std;
		 char		section;
		 int		phy;
		 int		chem;
		 int		math;
		 int 		comp;
		 int		eng;
		 int		total;
		 float		per;
		 char		grade[3];

    public	:
	void main_menu()    //function to display main menu
	{
	  int choice;
	  while(1)
		{
		  clrscr();
		  cout<<"\n\n\n\t\t R e p o r t  C a r d  M e n u\n\n";
		  cout<<"\n\n\t\t1. Add New Student ";
		  cout<<"\n\n\t\t2. Delete Menu";
		  cout<<"\n\n\t\t3. Modify Student";
		  cout<<"\n\n\t\t4. Search Menu";
		  cout<<"\n\n\t\t5. Report Menu ";
		  cout<<"\n\n\t\t6. Exit ";
		  cout<<"\n\n\t\t   Enter your choice (1..6) : ";
		  cin>>choice;
		  switch(choice)
			 {
			   case 1:    add_record();// function to call add record
				      break;
			   case 2:    del_record();// function to call delete record
				      break;
			   case 3:    modify_record();// function to call modify record
				      break;
			   case 4:    search_menu();
				      break;
			   case 5:    report_menu();
				      break;
			   case 6:    exit(0);
			   default :  cout<<"\n\t\t\t\tWrong Choice.... Try again !!!!";
				      getch();
			 }  // end of switch
		}
	}
    void search_menu()  // function to display search menu
	{
	 int choice;
	 do
	  {
	   clrscr();
	   cout<<"\n\n\n\t\t S e a r c h   M e n u \n\n";
	   cout<<"\n\n\t\t1. Admno Student";
	   cout<<"\n\n\t\t2. Student Name";
	   cout<<"\n\n\t\t3. Class wise";
	   cout<<"\n\n\t\t4. Exit ";
	   cout<<"\n\n\n\n\t\t   Enter your choice (1..4) : ";
	    cin>>choice;
	   switch(choice)
		{
		   case 1:    // function to call search_admno
			     search_admno( );
			     getch();
			     break;
		   case 2:    // function to call search_name
			     search_name();
			     getch();
			     break;

		   case 3:   // function to call
			     search_class();
			     getch();
			     break;
		   case 4:   break;
		 default :   cout<<"\n\t\t\tWrong Choice.... Try again !!!!";
			     getch();
		}  // end of switch
	  }while(choice!=4);
	}
    void report_menu()      // function to  display report menu
	{
	 int choice;
	 do
	  {
	   clrscr();
	   cout<<"\n\n\n\t\t R e p o r t   M e n u\n\n";
	   cout<<"\n\n\t\t1. Single Student";
	   cout<<"\n\n\t\t2. Single class";
	   cout<<"\n\n\t\t3. Whole School";
	   cout<<"\n\n\t\t4. Exit ";
	   cout<<"\n\n\t\t   Enter your choice (1..4) : ";
	   cin>>choice;
	   switch(choice)
		{
		   case 1:  // function to call single student
			    report_single();
			    break;
		   case 2:  // function to display class report
			    report_class();
			    break;
		   case 3:  // function to display whole school report card
			    report_school();
			    break;
		   case 4:  break;
		 default :  cout<<"\n\t\t\t Wrong Choice.... Try again !!!!";
			    getch();
	   }  // end of switch
	 }while(choice!=4);
	}
    void read_data()	  // function to read all the data members from the keyboard
	{
	  clrscr();
	  cout<<"\n Enter Adm No :";
	   cin>>admno;
	  cout<<"\n Enter Name : ";
	   cin>>name;
	  cout<<"\n Enter Father Name : ";
	   cin>>fname;
	  cout<<"\n Enter class : ";
	   cin>>std;
	  cout<<"\n Enter Section :";
	   cin>>section;
	  cout<<"\n Enter marks obtained in Phyics : ";
	   cin>>phy;
	  cout<<"\n Enter marks obtained in Chemistry : ";
	   cin>>chem;
	  cout<<"\n Enter marks obtained in Maths  : ";
	   cin>>math;
	  cout<<"\n Enter marks obtained in Computer : ";
	   cin>>comp;
	  cout<<"\n enter marks obtained in English : ";
	   cin>>eng;
	}
    void calculate()      // function to calculate total marks, per and grade
	{
	  total = phy+chem+math+comp+eng;
	  per = total/5.0;

	  if(per>=95)
	    strcpy(grade,"A+");

	  if(per<95 &&  per>=90)
	    strcpy(grade,"A");

	  if(per<90 &&  per>=80)
	    strcpy(grade,"B+");

	  if(per<80 &&  per>=70)
	    strcpy(grade,"B");

	  if(per<70 &&  per>=60)
	    strcpy(grade,"C+");
	  if(per<60)
	    strcpy(grade,"C");
	}
    void disp_data()	  // function to display data members on the screen
	{
	  cout<<"\n\t\t\t Admno               : "<<admno;
	  cout<<"\n\t\t\t Student Name        : "<<name;
	  cout<<"\n\t\t\t Father Name         : "<<fname;
	  cout<<"\n\t\t\t Class & Section     : "<<std<<"-"<<section;
	  cout<<"\n\t\tMarks obtained in ";
	  cout<<"\n\t\t\t Physics             : "<<phy;
	  cout<<"\n\t\t\t Chemistry           : "<<chem;
	  cout<<"\n\t\t\t Maths               : "<<math;
	  cout<<"\n\t\t\t Computer            : "<<comp;
	  cout<<"\n\t\t\t English             : "<<eng;
	  cout<<"\n\n\t\t\t Total Marks         : "<<total;
	  cout<<"\n\t\t\t Percentage          : "<<per;
	  cout<<"\n\t\t\t Grade               : "<<grade;
	}
    void add_record ()  // function to add student record in a data file
	{
	  clrscr();
	  int t,j=0;
	  fstream fout("report.dat",ios::app|ios::binary);
	  read_data();
	  calculate();
	  fout.write((char*)this, sizeof(report));
	  fout.close();
	}
    void del_record ()  //function to delete a record from the data file
	{
	 int n;
	 clrscr();
	 do
	    {
	      clrscr();
	      cout<<"\n\n\n\t\t\t D e l e t e   M e n u ";
	      cout<<"\n\n\t\t1. Delete All Records";
	      cout<<"\n\n\t\t2. Delete Student";
	      cout<<"\n\n\t\t3. Exit";
	      cout<<"\n\n\n\t\t\tEnter your choice (1..3):  ";
	      cin>>n;
	      switch(n)
		 {
		   case 1: //funtion to delete all records
			   ifstream fin("report.dat",ios::binary);
			   ofstream fout("p.dat",ios::binary);
			   remove("report.dat");  // function from stdio.h header file
			   rename("p.dat","report.dat"); // function from stdio.h header file
			   fin.close();
			   fout.close();
			   clrscr();
			   cout<<"\n\n Records Successfully removed ";
			   getch();
			   break;
		   case 2: //function to delete student
			   ifstream f("report.dat",ios::binary);
			   ofstream u("t.dat",ios::binary);
			   int tadmno;
			   int flag=0;
			   clrscr();
			   cout<<"\n Enter admission number to delete :";
			    cin>>tadmno;
			   while(f.read((char*)this, sizeof(report)))
				{
				  if(tadmno!=admno)
				   u.write((char*)this,sizeof(report));
				  else
				   flag=1;
				}
			   f.close();
			   u.close();
			   remove("report.dat");  // function from stdio.h header file
			   rename("t.dat","report.dat"); // function from stdio.h header file

			   if(flag==1)
			      cout<<"\n\n Record Successfully removed ";
			   else
			    cout<<"\n Admission No :"<<tadmno <<" \nDoes not exist...Try again !!!!";
			    getch();
			   break;
		   case 3: break;
		   default :  cout<<"\t\t\t\tWrong Choice......Try Again !!!!";
			      getch();
		 }  //end of switch
	    }while(n!=3);
       }
   void modify_record()  //Function to modify a record in a data file
       {
	 clrscr();
	 long pos;
	 fstream fin("report.dat",ios::in|ios::out|ios::binary);
	 int tadmno,y;
	 int flag=0;
	 cout<<"\n Enter Admission number to Modify :";
	 cin>>tadmno;
	 while(!fin.eof())
	    {
	       pos=fin.tellg();
	       fin.read((char*)this, sizeof(report));
	       if(tadmno == admno)
		{
		   clrscr();
		   do
		    {
		      clrscr();
		      cout<<"\n\t\t\tWhich field you have to modify ";
		      cout<<"\n\t\t1. Student's Name";
		      cout<<"\n\t\t2. Father's Name";
		      cout<<"\n\t\t3. Marks Obtained";
		      cout<<"\n\t\t4. Admission No.";
		      cout<<"\n\t\t5. Exit ";
		      cout<<"\n\n\t\t\tEnter your Choice :";
		       cin>>y;
		      switch(y)
		       {
			 case 1: clrscr();
				 cout<<"Enter the correct name :";
				  gets(name);
				 flag=1;
				 cout<<"\n\n Record Successfully modified ";
				 getch();
				 break;
			 case 2: clrscr();
				 cout<<"Enter the correct name :";
				  gets(fname);
				 flag=1;
				 cout<<"\n\n Record Successfully modified ";
				 getch();
				 break;
			 case 3: clrscr();
				 cout<<"Enter the correct marks obtained in:-";
				 cout<<"\n\tPhysics :";
				  cin>>phy;
				 cout<<"\n\tChemistry :";
				  cin>>chem;
				 cout<<"\n\tMathematics :";
				  cin>>math;
				 cout<<"\n\tComputer :";
				  cin>>comp;
				 cout<<"\n\tEnglish :";
				  cin>>eng;
				 flag=1;
				 cout<<"\n\n Record Successfully modified ";
				 getch();
				 break;
			 case 4: clrscr();
				 cout<<"Enter the correct admission no. :";
				  cin>>admno;
				 flag=1;
				 cout<<"\n\n Record Successfully modified ";
				 getch();
				 break;
			 case 5: flag=1;
				 break;
			default: cout<<"\n\t\t\t\tWrong choice.....Try again !!!!";
				 getch();
		    }
		   }while(y!=5);
		   calculate();
		   fin.seekp(pos);
		   fin.write((char*)this,sizeof(report));
		}
	     }
	 fin.close();
	if(flag==0)
	 {
		cout<<"\n Admission No :"<<tadmno <<" \nDoes not exist...Try again !!!!";
		getch();
	 }
       }
  void search_name( )   //function to read student name and search the information in the given database file, if it is
			      // available then display student information
      {
	ifstream fin("report.dat",ios::binary);
	char tname[30];
	int flag=0;
	clrscr();
	cout<<"\n Enter Name to search :";
	 cin>>tname;
	 clrscr();
	 cout<<"\n\t\t Hans Raj Smarak SR. SEC. School, Dilshad Garden";
	 cout<<"\n\t\t Session : 2019-20";
	 cout<<"\n-------------------------------------------------------------------------------"<<endl;
	 cout<<"Admno\tName\tFname\t Phy \t Chem\t Math \t Comp \t Eng \t Total \t per\n";
	 cout<<"-------------------------------------------------------------------------------"<<endl;
	 while(fin.read((char*)this,sizeof(report)))
		{
		  if(strcmp(tname,name)==0)
		    {
		      cout<<admno<<"\t"<<name<<"\t"<<fname<<"\t"<<phy<<"\t"<<chem<<"\t"<<math<<"\t"<<comp<<"\t"<<eng<<"\t"<<total<<"\t"<<per<<"%"<<endl;
		      flag=1;
		    }
		}
	 cout<<"-------------------------------------------------------------------------------"<<endl;
	 fin.close();
	if(flag==0)
	 cout<<"\n No such name : "<<strupr(tname)<<"\nDoes not exist in our record... Try again !!!!";
	getch();
      }
  void search_admno( ) // function to read student admno and search the 					  Information in the given database file, if it is
		      // available then display student information 					   otherwise display “ Name does not exist”
	{
	  clrscr();
	  ifstream f("report.dat",ios::binary);
	  int tadmno;
	  int flag=0;
	  cout<<"\n Enter Admission Number to search : ";
	   cin>>tadmno;
	  clrscr();
	  while(f.read((char*)this,sizeof(report)))
	       {
		 if(tadmno==admno)
		   {
		     cout<<"\n-------------------------------------------------------------------------------"<<endl;
		     cout<<"\t\t\t\tStudent Information ";
		     cout<<"\n-------------------------------------------------------------------------------"<<endl;
		     disp_data();
		     cout<<"\n-------------------------------------------------------------------------------"<<endl;
		     flag = 1;
		   }
	       }
	  f.close();

	  if(flag==0)
	   cout<<"\n\n Admission No : "<<tadmno <<" \nDoes not exist.... Try again";
	}
    void search_class() // function to read student admno and search the 					  Information in the given database file, if it is
					  // available then display student information 					   otherwise display “ Name does not exist”
	{
	  ifstream fin("report.dat",ios::binary);
	  char tsect;
	  int tstd;
	  int flag=0;
	  clrscr();
	  cout<<"\n Enter student Class to search :";
	   cin>>tstd;
	  cout<<"\n Enter student section to search :";
	   cin>>tsect;
	  clrscr();
	  cout<<"\n Class :"<<tstd<<" - "<<tsect<<endl;
	  cout<<"-------------------------------------------------------------------------------"<<endl;
	  cout<<"Admno\tName\tFname\t Phy \t Chem\t Math \t Comp \t Eng \t Total \t per\n";
	  cout<<"-------------------------------------------------------------------------------"<<endl;
	  while(fin.read((char*)this,sizeof(report)))
		{
		  if(tsect==section && tstd == std)
		    {
		      cout<<admno<<"\t"<<name<<"\t"<<fname<<"\t"<<phy<<"\t"<<chem<<"\t"<<math<<"\t"<<comp<<"\t"<<eng<<"\t"<<total<<"\t"<<per<<"%"<<endl;
		      flag=1;
		    }
		}
	  cout<<"-------------------------------------------------------------------------------"<<endl;
	  fin.close();
	  if(flag==0)
	    cout<<"\n\n Information not available for class :"<<tstd <<" - "<<tsect;
	}
    void single_report_card()
	{
	  clrscr();
	  cout<<"\n\t\t Hans Raj Smarak SR. SEC. School, Dilshad Garden";
	  cout<<"\n\t\t Session : 2019-20";
	  cout<<"\n-------------------------------------------------------------------------------";
	  cout<<"\n\n Admno :"<<admno;
	  cout<<"\n\n Name  :"<<name <<"\t\t Father Name :"<<fname<<"\t\t class :"<<std<<"-"<<section;
	  cout<<"\n\n-------------------------------------------------------------------------------";
	  cout<<"\n Subject\tMax Mark\tMin Mark\t Marks Obtained";
	  cout<<"\n-------------------------------------------------------------------------------";
	  cout<<"\n Physics\t100\t\t33\t\t\t"<<phy;
	  cout<<"\n\n Chemistry\t100\t\t33\t\t\t"<<chem;
	  cout<<"\n\n Maths\t\t100\t\t33\t\t\t"<<math;
	  cout<<"\n\n Computer\t100\t\t33\t\t\t"<<comp;
	  cout<<"\n\n English\t100\t\t33\t\t\t"<<eng;
	  cout<<"\n\n-------------------------------------------------------------------------------";
	  cout<<"\n Total Marks :\t\t"<<total<<"\t\tPercentage : "<<per<<"%\tGrade :"<<grade;
	  cout<<"\n-------------------------------------------------------------------------------";
	}
    void report_single()  // function to show single student report card
	{
	  int tadmno;
	  int flag=0;
	  ifstream fin("report.dat",ios::binary);
	  clrscr();
	  cout<<"\n Enter admission No : ";
	   cin>>tadmno;
	  while(fin.read((char*)this, sizeof(report)))  // read record and check eof
	       {
		 if(tadmno == admno)
		  {
		   single_report_card();  // function to display single report card
		   flag=1;
		  }
	       }
	  fin.close();
	  if(flag==0)
	    cout<<"\n\n Admission No :"<<tadmno <<" \nDoes not exist.... Try again !!!!";
	  getch();
	}
    void report_class()     // function to show class report of a single class
	{
	  int tstd,f=0;
	  char tsect;
	  int row=6;
	  int no=0;
	  ifstream  fin("report.dat",ios::binary);
	  clrscr();
	  cout<<"n\n Enter Class (1..12)  :";
	   cin>>tstd;
	  cout<<"\n Enter section :";
	   cin>>tsect;
	  clrscr();
	  cout<<"\n\t\t Hans Raj Smarak SR. SEC. School, Dilshad Garden";
	  cout<<"\n\t\t Class :"<<tstd<<"-"<<tsect<<"\t\t Session : 2019-20"<<endl;
	  cout<<"-------------------------------------------------------------------------------"<<endl;
	  cout<<"Admno\tName\tFname\t Phy \t Chem\t Math \t Comp \t Eng \t Total \t per\n";
	  cout<<"-------------------------------------------------------------------------------"<<endl;
	  while(fin.read((char*)this, sizeof(report)))
	       {
		if(tstd==std && tsect== section )
		  {
		    row= row+1;
		    no++;
		    f=1;
		    if(row>=30)
		      {
			cout<<"\n\n  Press any key to continue ................";
			getch();
			cout<<"\n\t\t Hans Raj Smarak SR. SEC. School, Dilshad Garden";
			cout<<"\n\t\t Class :"<<tstd<<"-"<<tsect<<"\t\t Session : 2012-13"<<endl;
			cout<<"-------------------------------------------------------------------------------"<<endl;
			cout<<"Admno\tName\tFname\t Phy \t Chem\t Math \t Comp \t Eng \t Total \t per\n";
			cout<<"-------------------------------------------------------------------------------"<<endl;
			row =6;
		      }
		    cout<<admno<<"\t"<<name<<"\t"<<fname<<"\t"<<phy<<"\t"<<chem<<"\t"<<math<<"\t"<<comp<<"\t"<<eng<<"\t"<<total<<"\t"<<per<<"%"<<endl;
		  }
	       }
	  fin.close();

	  if(f==0)
	    {
	      cout<<"\n\t\t\t    No Record Available !!!!\n\n";
	    }
	  cout<<"-------------------------------------------------------------------------------"<<endl;
	  cout<<"\n Total Student : "<<no<<"\t\t\tReport prepared By  :  Dhruv Varshney";
	  getch();
	}
    void report_school()   // fucntion to show class wise report of whole school
	{
	 int row =6;
	 int no =0;
	 ifstream  fin("report.dat",ios::binary);
	 clrscr();
	 cout<<"\n\t\t Hans Raj Smarak SR. SEC. School, Dilshad Garden";
	 cout<<"\n\t\t\t Session : 2019-20"<<endl;
	 cout<<"-------------------------------------------------------------------------------"<<endl;
	 cout<<"Admno\tName\tFname\t Phy \t Chem\t Math \t Comp \t Eng \t Total \t per\n";
	 cout<<"-------------------------------------------------------------------------------"<<endl;
	 while(fin.read((char*)this, sizeof(report)))
	      {
		row= row+1;
		no++;
		if(row>=30)
		  {
		    cout<<"\n\n  Press any key to continue ................";
		    getch();
		    cout<<"\n\t\t Hans Raj Smarak SR. SEC. School, Dilshad Garden";
		    cout<<"\n\t\t Class :"<<std<<"-"<<section<<"\t\t Session : 2012-13"<<endl;
		    cout<<"-------------------------------------------------------------------------------"<<endl;
		    cout<<"Admno\tName\tFname\t Phy \t Chem\t Math \t Comp \t Eng \t Total \t per\n";
		    cout<<"-------------------------------------------------------------------------------"<<endl;
		    row =6;
		  }
		cout<<admno<<"\t"<<name<<"\t"<<fname<<"\t"<<phy<<"\t"<<chem<<"\t"<<math<<"\t"<<comp<<"\t"<<eng<<"\t"<<total<<"\t"<<per<<"%"<<endl;
	      }
	 fin.close();
	 cout<<"-------------------------------------------------------------------------------"<<endl;
	 cout<<"\n Total Student : "<<no<<"\t\t\t\Report prepared By  :  Dhruv varshney ";
	 getch();
	}
};

/*-----------main function to implement report class ------------*/

void main()
    {
      clrscr();
      report r;
      r.main_menu();
      getch();
    }