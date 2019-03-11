#include<iostream>
#include<conio.h>
#include<dos.h>
#include<stdio.h>
#include<fstream.h>
#include<process.h>
#include<string.h>
using namespace std;
struct data
{private: char name[20];
	  char start[20];
	  char dest[20];
	  int seats;
	  int code;
public: void getinfo();
	void showinfo();
	int a;
	int generator()
	{       a=a+1;
		code=a;
		return code;
	}
	int tcode()
	{
		return code;
	}
}d;
void data::getinfo()
{	cout<<"\n\n\n\n\t\t\t Enter Applicant Name:";
	gets(name);
	cout<<"\n\n\t\t\t Enter No. of Seats Required:";
	cin>>seats;
	cout<<"\n\n\t\t\t Enter Starting Location:";
	gets(start);
	cout<<"\n\n\t\t\t Enter Destination:";
	gets(dest);
	generator();
	cout<<"\n\n\t Your Ticket No. is:"<<tcode()<<". Thanks for Entering Your Details!.";
	getch();
}
void data::showinfo()
{
	cout<<"\n\n\t\tTicket No:"<<"  "<<code;
	cout<<"\n\n\t\tApplicants Name:"<<"  "<<name;
	cout<<"\n\n\t\tNo of Seats Booked:"<<"  "<<seats;
	cout<<"\n\n\t\tStarting Location:"<<"  "<<start;
	cout<<"\n\n\t\tDestination:"<<"  "<<dest;
	getch();
}
void reservation()
{	ofstream f;
	f.open("d.dat",ios::out|ios::app|ios::binary);
	d.getinfo();
	cout<<"\n\n\t You have entered the following Details.";
	d.showinfo();
	f.write((char*)&d,sizeof(d));
	f.close();
}
void verification()
{       clrscr();
	ifstream f3;
	int flag=0;
	int vcode;
	cout<<"\n\n\n\n\t\t\tEnter Ticket No. to be Verified:";
	cin>> vcode;
	f3.open("d.dat",ios::in|ios::binary);
	if(!f3)
		cout<<"\n\n\n\t\t\t ERROR!!.. File doesn't exists.";
	while(f3.read((char*)&d, sizeof(d)))
	{
		if(d.tcode()==vcode)
		{	cout<<"\n\n\n\t\t\t\t\t Details Found!";
			d.showinfo();
			flag=1;
		}
	}
	if(flag==0)
	{
		cout<<"\n\n\t\t\t Sorry! Record doesn't exist.";
		getch();
	}
	f3.close();
}

void cancellation(int vcode)
{       clrscr();
	char found='f',confirm='n';
	ifstream f1("d.dat",ios::in|ios::binary);
	ofstream f2("t.dat",ios::out|ios::app|ios::binary);
	while(f1.read((char*)&d,sizeof(d)))
	{
		if(d.tcode()==vcode)
		{
			cout<<"\n\n\t\t\t\t Record Found.";
			d.showinfo();
			found='t';
			cout<<"\n\n\t\t\tAre u sure to delete? (y/n)..";
			cin>>confirm;
			if ((confirm=='y'||confirm=='Y'))
			{
				cout<<"\n\n\n\t\t\t Record Deleted.";
			}
			else
			{

				f2.write((char*)&d,sizeof(d));
				cout<<"\n\n\t\t\tDelete operation Aborted by user.";
			}
		}
		else
		{
			f2.write((char*)&d,sizeof(d));
		}
	}
	if(found=='f')
	cout<<"\n\n\t Sorry! Record not found. Please check your Ticket Code and Try again.";
	getch();
	f1.close();
	f2.close();
	remove("d.dat");
	rename("t.dat","d.dat");
}


void main()
{       d.a=1800;
	clrscr();
	char ip[8];
	int atm=0;
pcheck: if(atm<3)
	{
	clrscr();
	cout<<"\n\n\n\n\n\n\n\n\t\t\t    Enter Password:";
	gets(ip);
	if((strcmp(ip,"password"))==0)
		goto start;
	else
	{
		cout<<"\n\n\t\t You have entered wrong Password. Please try Again.";
		getch(); atm++;
		goto pcheck;
	}}
	else
	{
	cout<<"\n\n\n\n\t   You have entered wrong password for consecutive three times.\n\n\t\t    Now the program is terminated. Thank You!";
	getch();
	exit(0);
	}
start:	clrscr();
			cout<<"\n\n\n\n\n\n\n\n";
			cout<<"#################################################################################";
			cout<<"\n################################################################################";
			cout<<"\n\n\n\n";
			cout<<"\t\t     ##### AIRLINE MANAGEMENT SYSTEM #####";
			cout<<"\n\t\t  ____________________________________________";
			cout<<"\n\t\t  --------------------------------------------";
			cout<<"\n\n\n\n";
			cout<<"\t\t           ##### DEVELOPED BY:- #####";
			cout<<"\n\t\t\t   --------------------------";
			cout<<"\n\n\t\t  ### SIDHARTH, DHEERAJ, SUBHASH AND HIMANSHU ###";
			cout<<"\n\n\t\t      ### KENDRIYA VIDYALAYA LAKHANPUR ###";
			cout<<"\n\n\n\n";
			cout<<"\t\t\t ##### SUBJECT TEACHER::-- #####";
			cout<<"\n\t\t\t  -----------------------------";
			cout<<"\n\n\t\t\t       ### MR. RAMESH ###";
			cout<<"\n\n\n\n################################################################################";
			cout<<"\n################################################################################";
			getch();
			clrscr();
	cout<<"\n\n\n\n:";
label:
	clrscr();
	cout<<"    ***********************************************************************\n\n";
	cout<<"      $$    $$     $$     $$$$$ $$    $     $$    $$ $$$$$ $$    $ $    $\n";
	cout<<"      $ $  $ $    $  $      $   $ $   $     $ $  $ $ $     $ $   $ $    $\n";
	cout<<"      $  $$  $   $$$$$$     $   $  $  $     $  $$  $ $$$   $  $  $ $    $\n";
	cout<<"      $      $  $      $    $   $   $ $     $      $ $     $   $ $ $    $\n";
	cout<<"      $      $ $        $ $$$$$ $    $$     $      $ $$$$$ $    $$ $$$$$$\n\n";
	cout<<"    ***********************************************************************\n\n";
	int choice;
	char d;
	cout<<"\n\n\n\t\t\t1.RESERVATION CUM TICKET CORNER";
	cout<<"\n\n\n\t\t\t2.VERIFICATON OF TICKETS";
	cout<<"\n\n\n\t\t\t3.CANCELLATION OF TICKETS";
	cout<<"\n\n\n\t\t\t4.EXIT\n\n";
	delay(500);
	cout<<"\n\n\t\t\tEnter your choice---->>>";
	cin>>choice;
	switch(choice)
	{
		case 1: clrscr();
			cout<<"\t\t\t*******PROCESSING.";delay(500);cout<<".";delay(500);
			cout<<".";delay(500);cout<<".\n\n\n";
			do
			{
				reservation();
				cout<<"\n\n\t\tWant to continue(y/n)?..";
				cin>>d;
				clrscr();
			}while(d=='y'||d=='Y');
			goto label;
		case 2: clrscr();
			cout<<"\t\t\t*******PROCESSING.";delay(500);cout<<".";delay(500);
			cout<<".";delay(500);cout<<".\n\n\n";
			do
			{
				verification();
				cout<<"\n\n\t\tWant to continue(y/n)?..";
				cin>>d;
			}while(d=='y'||d=='Y');
			goto label;
		case 3: clrscr();
			cout<<"\t\t\t*******PROCESSING.";delay(500);cout<<".";delay(500);
			cout<<".";delay(500);cout<<".\n\n\n";
			int c_ticket;
			do
			{
				cout<<"\n\n\tEnter Ticket No. to be Cancelled:";
				cin>>c_ticket;
				cancellation(c_ticket);
				cout<<"\n\n\t\tWant to continue(y/n)?..";
				cin>>d;
			}while(d=='y'||d=='Y');
			goto label;
		case 4: clrscr();
			cout<<"\n\n\n\n\n\n\n\n\n\t\t Thank You for using Airlines Management System!";
			getch();
			exit(0);
			break;
		default: cout<<"\n\t\tYou have entered wrong choice!!!!!.. Please Try Again.";
			getch();
			goto label;
	}
	getch();
}
