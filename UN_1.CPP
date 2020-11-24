//START
#include<iostream.h>		//input/output objects c++
#include<stdio.h>		//standard input/output c
#include<stdlib.h>		//standard library
#include<conio.h>		//getch function
#include<dos.h>			//delay function
#include<windows.h>		//Sleep,gotoxy coordinate functions
#include<iomanip>		//output manipulatons
#include<fstream>		//file handling
#include<string.h>		//string abstract datatype
#include<math.h>		//mathematical operations
#include<time.h>		//system current time and date
#include"MMSystem.h"	//plays audio track
using namespace std;
void delr1();			//delete file
void delr2();			//rename file
void gotoxy (int x, int y);	//handle output on screen
void frame ();			//frame for every dialog box
void frame_fix();
void scroll_note();
void flow(char *ch);
void main_menu();		// main part of the program
void sub_menu();
COORD coord = {0, 0};
FILE *ff,*fs,*fp,*fg;
class machine			// class for entire program
{
	private:
	int mbno,pcode,amt,prev;
	int adl;
	char  fname[10],p_name[20],city[15],email[20],dob[15],type;
	char acno[7],pin[5];

	public:

	void create_account();
	void help();
	void main_menu();
	void sub_menu();

	void cash_deposit(machine);
	void fund_transfer(machine);
	void change_pin(machine);

	void cash_withdraw(machine);
	void balance_enquiry(machine);
	void mini_statement(machine);

	void admin();		//admin login for verification of user accounts

	void note();
	machine login_check();

};
void gotoxy (int x, int y)	//defining/initializing to predefined objects
{
    coord.X = x;
    coord.Y = y; // X and Y coordinates
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void frame()
{
	int i,j=79;
	for(i = 0;i<80,j>=0;i++,j--)
	{
		gotoxy(i,3);
		Sleep(10);
		cout<<"-";
		gotoxy(j,20);
		Sleep(10);
		cout<<"-";
	}
}
void frame_fix()	//instead of flow line fixing the frame
{
	int i,j=79;
	for(i = 0;i<80,j>=0;i++,j--)
	{
		gotoxy(i,3);
		cout<<"-";
		gotoxy(j,20);
		cout<<"-";
	}
}
void flow(char *ch)	//flow of instructions
{
	char *str=ch;
	for(int i=0;i<strlen(str);i++)
	{
		Sleep(20);
		cout<<str[i];
	}
}
void scroll_note()	//welcome note
{
    system("color FC");
	int j,i,x,y;
	for(i=0;i<27;i++)
	{
		gotoxy(i,13);cout<<" ";
		cout<<"LPS ATM SERVICES";
		Sleep(40);
	}

	for(j=67;j>44;j--)
	{
		gotoxy(j,13);
		cout<<"WELCOMES YOU";cout<<"            ";
		Sleep(40);
	}

	gotoxy(27,13);cout<<"LPS ATM SERVICES";
	gotoxy(45,13);cout<<"WELCOMES YOU";
	for(int j=78;j>=0;j--)
	{
		gotoxy(j,20);cout<<"|";
		gotoxy(j,4);cout<<"|";
		Sleep(30);
	}
	Sleep(2000);
}
void machine:: main_menu()	//main menu for all functions included
{
	system("cls");
	system("COLOR 2F");
	frame();
	gotoxy(33,10);
	cout<<"CREATE ACCOUNT";
	gotoxy(20,14);
	cout<<"ALREADY HAVE ACCOUNT PRESS P TO PROCEED ";
	gotoxy(74,19);
	cout<<"HELP";
	char op;
	gotoxy(1,21);
	cout<<"C : Create account H : Help P : Proceed to account ";
	gotoxy(5,2);
	cout<<"ADMIN ";
	gotoxy(1,22);
	cout<<"E : Exit ";
	gotoxy(54,21);cout<<"";
	op=getch();

	if(op=='c'||op=='C')
	{
		create_account();
	}
	else if(op=='h'||op=='H')
	{
		cout<<"h";
		help();
	}
	else if(op=='p'||op=='P')
	{
		sub_menu();
	}
	else if(op=='a'||op=='A')
	{
		admin();
	}
	else if(op=='e'||op=='E')
	{
		system("cls");
		exit(0);
	}
	else
	{
		cout<<" \a\a\aINVALID OPTION ";
		Sleep(1000);
		main_menu();
	}

}

void machine::sub_menu()	//after user login the following functions are displayed
{
	system("cls");

	int cpin;
	machine r;
	r=login_check();
	fclose(fg);
		while(1)
		{
			int i;
			system("cls");
			system("COLOR 1F");
			frame();
			gotoxy(1,6);
			cout<<"CASH DEPOSIT";
			gotoxy(1,10);
			cout<<"FUND TRANSFER";
			gotoxy(1,14);
			cout<<"PIN CHANGE";

			gotoxy(64,6);
			cout<<"CASH WITHDRAWL";
			gotoxy(64,10);
			cout<<"BALANCE ENQUIRY";
			gotoxy(64,14);
			cout<<"MINI STATEMENT";

			gotoxy(28,4);
			char* s="Select your transaction";
			for(int i=0;i<24;i++)
			{
				cout<<s[i];
				Sleep(100);
			}
			int op;
			gotoxy(38,24);
			cout<<" ";
			cin>>op;
			switch(op)
			{
				case 1:
					{
						cash_deposit(r);
						break;
					}
				case 2:
					{
						fund_transfer(r);
						break;
					}
				case 3:
					{
						change_pin(r);
						break;
					}
				case 4:
					{
						cash_withdraw(r);
						break;
					}
				case 5:
					{
						balance_enquiry(r);
						break;
					}
				case 6:
					{
						mini_statement(r);
						break;
					}
				default:
					{
						gotoxy(64,24);
						cout<<"Invalid Input ";
						cout<<"\a\a\a";		//terminating to mainmenu
						Sleep(1000);
						main_menu();
					}

			}
		}

}
void machine::help()		//initial help notice in mainmenu on opening account
{
	system("cls");
	system("COLOR 70");
    for(int i=0;i<25;i++)
	{
		gotoxy(2,i);
		cout<<"|";
		gotoxy(77,i);
		cout<<"|";
	}
	gotoxy(3,0);
	cout<<"Inorder to use our ATM services be sure that,";
	gotoxy(3,2);
	cout<<"you might have already opened an account previously. ";
	gotoxy(3,22);
	cout<<"For more information, contact:";
	gotoxy(3,23);
	cout<<"Call our 24x7 helpline through 8750968921.";
	gotoxy(3,24);
	cout<<"Contact at lakshyaprateek87@gmail.com";
	gotoxy(3,5);
	flow("ATM Services");
	gotoxy(3,8);
	flow("Cash Withdrawal : Use this service to withdraw amount (40,000/-per day).");
	gotoxy(3,10);
	flow("Pin Change : Use this service to change your ATM password.");
	gotoxy(3,12);
	flow("Balance Enquiry : To check the current balance in your account.");
	gotoxy(3,14);
	flow("Ministatement : Keep track of the transactions in your account.");
	gotoxy(3,16);
	flow("Fund Transfer : Transfers amount instantly to your loved ones.");
	getch();
	main_menu();
}
void machine::create_account()		//create account on selecting the option on main menu
{
	machine a;
	system("cls");
	system("COLOR F5");
	for(int i=0;i<25;i++)
	{
		gotoxy(5,i);
		cout<<"|";
		gotoxy(75,i);
		cout<<"|";
	}
	gotoxy(34,2);
	cout<<"APPLICATION FORM";
	gotoxy(10,5);
	cout<<"Enter Full Name : ";
	cin>>a.fname;
	gotoxy(10,7);
	cout<<"Father/Guardian : ";
	cin>>a.p_name;
	gotoxy(10,9);
	cout<<"Date Of Birth (dd/mm/yyyy) : ";
	cin>>a.dob;
	gotoxy(10,11);
	cout<<"Account Type (S/C): ";
	cin>>a.type;
	gotoxy(10,13);
	cout<<"City : ";
	cin>>a.city;
	gotoxy(10,15);
	cout<<"PINCODE : ";
	cin>>a.pcode;
	gotoxy(10,17);
	cout<<"Email Id : ";
	cin>>a.email;
	gotoxy(10,19);
	cout<<"Enter initial amount( >= 500) ";
	cin>>a.amt;

	strcpy(a.pin,"6235");
	fs=fopen("accounts.txt","rb+");
	machine b;
        while(fscanf(fs,"%s %s %s %d \n",b.acno,b.pin,b.fname,&b.amt)!=EOF);
		strcpy(a.acno,b.acno);
		if(a.acno[5]!='9')
            a.acno[5]=a.acno[5]+1;
		else
		{
			if(a.acno[4]!='9')
				a.acno[4]=a.acno[4]+1;
				a.acno[5]='0';
			}
		}
		fprintf(fs,"%s %s %s %d \n",a.acno,a.pin,a.fname,a.amt);
	fclose(fs);

	//initial account details posting to atm_users file
	ff=fopen("atm_users.txt","a");
	fprintf(ff,"%s %s %s %s %s %s %c %s %d %s %d \n",a.acno,a.pin,a.fname,a.p_name,a.dob,a.type,a.city,a.pcode,a.email,a.amt);
	fclose(ff);

	a.adl=a.amt;	//adl = additional amount either deposit/credit
	a.prev=0;		//prev = available balance before transaction

	//to transactions file
	fp=fopen("transactions.txt","a");
	fprintf(fp,"%s %s %d %d %d \n",a.acno,a.fname,a.prev,a.adl,a.amt);
	fclose(fp);

	gotoxy(35,21);
	cout<<" SUBMIT";
	char c;
	c=getche();
	gotoxy(10,23);
	cout<<"Loading";
	Sleep(400);
	cout<<".";
	Sleep(400);
	cout<<".";
	Sleep(400);
	cout<<".";
	Sleep(400);

	system("cls");
	system("COLOR B0");
	frame_fix();
	gotoxy(22,5);
	cout<<"YOUR ACCOUNT HAS SUCCESSFULLY CREATED ";
	gotoxy(29,8);		//giving account details on that particular user
	cout<<"ACCOUNT NUMBER  : "<<a.acno;
	gotoxy(29,12);
	cout<<"ATM PIN	      : "<<a.pin;
	gotoxy(8,19);
	cout<<"NOTE : THESE ARE THE ACCOUNT CREDENTIALS FOR USING ATM SERVICES.";
	gotoxy(28,23);
	cout<<"MAIN MENU : PRESS ENTER";
	char op;
	op=getche();
	main_menu();
}


void machine:: balance_enquiry(machine r)	//argument object received from login_check function
{
	system("cls");
	frame_fix();
	gotoxy(22,10);
	cout<<"ACCOUNT HOLDER NAME  : "<<r.fname;
	gotoxy(22,13);
	cout<<"CURRENT BALANCE      : "<<r.amt;
	Sleep(3000);

    system("cls");
	gotoxy(18,13);
	cout<<"YOUR TRANSACTION IS BEING PROCESSED PLEASE WAIT ";
	Sleep(1000);
	system("cls");
	gotoxy(18,13);
	cout<<"       TRANSACTION COMPLETED SUCCESSFULLY       \a\a";
	Sleep(1000);
	main_menu();
}


void machine:: cash_deposit(machine r)	//argument object received from login_check function
{
	FILE *f1,*f2,*f3;		//declaring pointers in C style
	system("cls");
	int cash;
	frame_fix();
	gotoxy(22,6);
	cout<<"PLEASE ENTER AMOUNT : ";
	cin>>cash;
	machine g;
	g.prev=r.amt;		//holding available balance before transaction which equals to present previous amount
	g.amt=r.amt+cash;	//present amount equals to amount sum of current transaction + previous available balance
	strcpy(g.acno,r.acno);
	strcpy(g.fname,r.fname);
	strcpy(g.pin,r.pin);
	g.adl=cash;			// additional amount will be currents transaction amount

	//transacton APPENDING to transactions file
	machine a;
	f1=fopen("transactions.txt","a");
	fprintf(f1,"%s %s %d %d %d \n",g.acno,g.fname,g.prev,g.adl,g.amt);
	fclose(f1);

	f2=fopen("accounts.txt","r");		//finding current account details to accounts file for changing amount
    f3=fopen("temp.txt","w");
    while(fscanf(f2,"%s %s %s %d \n",a.acno,a.pin,a.fname,&a.amt)!=EOF)
    {
    	if(strcmp(g.acno,a.acno)==0)
            a.amt=g.amt;
            fprintf(f3,"%s %s %s %d \n",a.acno,a.pin,a.fname,a.amt);
    }
	fclose(f3);
	fclose(f2);

    system("cls");
    frame_fix();
    gotoxy(18,12);
	cout<<"AMOUNT DEPOSITED  : "<<g.adl<<" FINAL BALANCE : "<<g.amt;
	Sleep(3000);
    system("cls");
	gotoxy(18,13);
	cout<<"	      PLEASE WAIT VALIDATING THE CASH		";
	Sleep(1000);
	system("cls");
	gotoxy(18,13);
	cout<<"       TRANSACTION COMPLETED SUCCESSFULLY       \a\a";
	Sleep(1000);
    delr1();	//calling file delete function
    main_menu();
}

void machine:: cash_withdraw(machine r)	//argument object received from login_check function
{
	FILE *f1,*f2,*f3;		//declaring pointers in C style
	system("cls");
	int cash;
	frame_fix();
	gotoxy(22,6);
	cout<<"PLEASE ENTER AMOUNT : ";
	cin>>cash;
	if(cash>r.amt)
	{
		gotoxy(15,13);
		cout<<"WITHDRAWAL AMOUNT IS GREATER THAN THE AVAILABLE BALANCE \a\a\a";
		Sleep(1000);
		main_menu();
	}

	machine g;
	g.prev=r.amt;
	g.amt=r.amt-cash;		//present amount equals to amount sum of current transaction - previous available balance
	strcpy(g.acno,r.acno);
	strcpy(g.fname,r.fname);
	strcpy(g.pin,r.pin);
	g.adl=cash;

    //transaction APPENDING to transactions file
	machine a;
	f1=fopen("transactions.txt","a");
	fprintf(f1,"%s %s %d %d %d  \n",g.acno,g.fname,g.prev,g.adl,g.amt);
	fclose(f1);

	f2=fopen("accounts.txt","r");	//finding current account details to accounts file for changing amount
    f3=fopen("temp.txt","w");
    while(fscanf(f2,"%s %s %s %d \n",a.acno,a.pin,a.fname,&a.amt)!=EOF)
    {
    	if(strcmp(g.acno,a.acno)==0)
    	a.amt=g.amt;
    	fprintf(f3,"%s %s %s %s %d \n",a.acno,a.pin,a.fname,a.amt);
    }
	fclose(f3);
	fclose(f2);

    system("cls");
    frame_fix();
    gotoxy(18,12);
	cout<<"AMOUNT WITHDRAWN  : "<<g.adl<<" FINAL BALANCE : "<<g.amt;
	Sleep(3000);
    system("cls");
	gotoxy(18,13);
	cout<<"YOUR TRANSACTION IS BEING PROCESSED PLEASE WAIT ";
	Sleep(1000);
	system("cls");
	gotoxy(18,13);
	cout<<"       TRANSACTION COMPLETED SUCCESSFULLY       ";
	Sleep(100);
	cout<<"PLEASE COLLECT CASH \a\a";
	Sleep(1000);
	delr1();	//calling file delete function bottom section of the code
    main_menu();getch();
}


void machine:: mini_statement(machine r)	//argument object received from login_check function
{
	system("cls");
	FILE *fm;		//declaring pointer in C style
	int l;
    system("COLOR E0");
	for(int i=0;i<24;i++)
	{
		gotoxy(2,i);
		cout<<"|";
		gotoxy(77,i);
		cout<<"|";
	}
	gotoxy(6,1);
    cout<<"TRANSACTION  TYPE";
	gotoxy(17,1);
	cout<<"AMOUNT";
	gotoxy(27,1);
    cout<<"FINAL BALANCE";
	machine n;
	fm=fopen("transactions.txt","r");
	l=3;
	while(fscanf(fm,"%s %s %d %d %d \n",n.acno,n.fname,&n.prev,&n.adl,&n.amt)!=EOF)
	{
		if(strcmp(r.acno,n.acno)==0)
		{
			gotoxy(3,l);
			if(n.amt>n.prev && n.prev!=0)	//for first , to the user previous amt = 0
			{
			cout<<setw(18)<<"CASH DEPOSITED"<<setw(15)<<n.adl<<setw(18)<<n.amt;
			}
			else if(n.amt<n.prev)
			{
			cout<<setw(19)<<"CASH WITHDRAWAL"<<setw(14)<<n.adl<<setw(18)<<n.amt;
			}
			else if(n.amt>n.prev && n.prev==0)	//for first , to the user previous amt = 0
			{
			cout<<setw(18)<<"ACCOUNT OPENED"<<setw(15)<<n.adl<<setw(18)<<n.amt;
			}
			l=l+2;
		}
	}
	fclose(fm);
	getch();
	system("cls");
	frame_fix();
	gotoxy(18,13);
	cout<<"YOUR TRANSACTION IS BEING PROCESSED PLEASE WAIT";
	Sleep(1000);
	system("cls");
	gotoxy(18,13);
	cout<<"      TRANSACTION COMPLETED SUCCESSFULLY       \a\a";
	Sleep(1000);
	main_menu();

}
void machine::fund_transfer(machine r)	//argument object received from login_check function
{
	system("cls");
	frame_fix();

	FILE *fk,*fl,*fm,*fn;		//declaring pointers in C style
	char racno[7],rracno[7];
	int famt;
	gotoxy(22,6);
	cout<<"ENTER RECEPIENT'S ACCOUNT NUMBER : ";
	cin>>racno;
	gotoxy(22,8);
	cout<<"CONFIRM ACCOUNT NUMBER           : ";
	cin>>rracno;
	if(strcmp(racno,rracno)!=0)
	{
		system("cls");
		gotoxy(24,14);
		cout<<"GIVEN ACCOUNT NUMBER DOES NOT MATCH \a\a\a";
		Sleep(1000);
		main_menu();
	}
	gotoxy(22,11);
	cout<<"PLEASE ENTER AMOUNT              : ";
	cin>>famt;
	if(famt>r.amt)
	{
		gotoxy(15,13);
		cout<<"WITHDRAWAL AMOUNT IS GREATER THAN THE AVAILABLE BALANCE \a\a\a";
		Sleep(1000);
		main_menu();
	}

	machine g;
	g.prev=r.amt;
	g.amt=r.amt-famt;
	g.adl=famt;
	strcpy(g.acno,r.acno);
	strcpy(g.fname,r.fname);
	strcpy(g.pin,r.pin);

    //transaction APPENDING to transactions file
	machine a,b;
	fl=fopen("transactions.txt","a");
	fprintf(fl,"%s %s %d %d %d \n",g.acno,g.fname,g.prev,g.adl,g.amt);
	fclose(fl);
    //finding current account details to accounts file for changing amount and also transfer account
	fm=fopen("accounts.txt","r");
    fn=fopen("temp.txt","w");
    while(fscanf(fm,"%s %s %s %d \n",a.acno,a.pin,a.fname,&a.amt)!=EOF)
    {
    	if(strcmp(g.acno,a.acno)==0)		//transfer account
            a.amt=g.amt;
    	else if(strcmp(racno,a.acno)==0)	//current account
    	{
    		b=a;
    		b.prev=a.amt;
    		b.amt=a.amt+famt;
    		b.adl=famt;	//transaction APPENDING to transactions file
            fk=fopen("transactions.txt","a");
            fprintf(fk,"%s %s %d %d %d \n",b.acno,b.fname,b.prev,b.adl,b.amt);
            fclose(fk);
            a.amt=a.amt+famt;
    	}

    	fprintf(fn,"%s %s %s %d \n",a.acno,a.pin,a.fname,a.amt);
    }
	fclose(fn);
	fclose(fm);

	system("cls");
	frame_fix();
	gotoxy(18,13);
	cout<<"AMOUNT TRANSFERRED : "<<famt<<" FINAL BALANCE : "<<g.amt;
    Sleep(3000);
	system("cls");
	gotoxy(18,13);
	cout<<"YOUR TRANSACTION IS BEING PROCESSED PLEASE WAIT ";
	Sleep(1000);
	system("cls");
	gotoxy(18,13);
	cout<<"       TRANSACTION COMPLETED SUCCESSFULLY       \a\a";
	Sleep(1000);
    delr1();	//calling file delete function bottom section of the code
    main_menu();
}

void machine::change_pin(machine g)	//argument object recieved from login_check function
{

	system("cls");
	frame_fix();

	FILE *fk,*fl;
	char npin1[5],npin2[5];
	gotoxy(2,11);
	cout<<"YOUR PIN IS CONFIDENTIAL";
	gotoxy(2,13);
	cout<<"NOBODY SHOULD SEE THE PIN";
	gotoxy(2,15);
	cout<<"WHILE YOU ARE ENTERING IT.";
	gotoxy(2,17);
	cout<<"MAKE YOUR PIN MORE SECURE BY";
	gotoxy(2,19);
	cout<<"CHANGING IT FREQUENTLY.";
	gotoxy(30,6);
	cout<<"ENTER NEW PIN : ";
	cin>>npin1;
	gotoxy(30,8);
	cout<<"CONFIRM PIN   : ";
	cin>>npin2;
	machine a;
	if(strcmp(npin1,npin2)==0)
	{
		fk=fopen("accounts.txt","r");
    	fl=fopen("temp.txt","w");	//finding current account details to accounts file for changing pin
  		while(fscanf(fk,"%s %s %s %d \n",a.acno,a.pin,a.fname,&a.amt)!=EOF)
 	  	{
  	  		if(strcmp(g.acno,a.acno)==0)
    		strcpy(a.pin,npin1);
    		fprintf(fl,"%s %s %s %s %d \n",a.acno,a.pin,a.fname,a.sname,a.amt);
  	  	}
		fclose(fl);
		fclose(fk);

	}
	else
	{
		gotoxy(40,16);
		cout<<"Password do not match try after some time \a\a\a";
		Sleep(1000);
		main_menu();
	}
	system("cls");
	frame_fix();
	gotoxy(18,13);
	cout<<"YOUR TRANSACTION IS BEING PROCESSED PLEASE WAIT";
	Sleep(1000);
	system("cls");
	gotoxy(18,13);
	cout<<"      TRANSACTION COMPLETED SUCCESSFULLY       \a\a";
	Sleep(1000);
	delr1();	//calling file delete function bottom section of the code
	main_menu();

}
//different function than all functions till
//access of all details of every user account
void machine :: admin()
{
	char addname[15],pass[8];
	char adname[]="lakshyaprateek";
	char password[]="lps87";
	system("cls");
	gotoxy(25,13);
	cout<<"Enter name of the admin : ";
	cin>>addname;
	if(strcmp(adname,addname)==0)
	{
		gotoxy(25,15);
		cout<<"Enter password : ";
		cin>>pass;
		if(strcmp(password,pass)==0)
		{
			while(1)
			{
				system("cls");
				int op;gotoxy(10,9);
				cout<<"1.ACCOUNT MEMBERS ";
				gotoxy(10,11);
				cout<<"2.MAIN MENU ";
				gotoxy(10,16);
				cout<<"Select : ";
				cin>>op;
				if(op==1)
				{
					system("cls");
					FILE *fy;
					machine b;
					int i=3;
					fy=fopen("accounts.txt","r");//all information from accounts file
					gotoxy(0,1);
					cout<<"ACCOUNT NUMBER		PIN NUMBER	FULL NAME	AVAILABLE BALANCE";
			  		while(fscanf(fy,"%s %s %s %d \n",b.acno,b.pin,b.fname,&b.amt)!=EOF)
 		  			{
 		  				gotoxy(2,i);
    					cout<<b.acno<<"		"<<b.pin<<"		"<<b.fname<<" "<<b.sname<<"	"<<b.amt;
    					i=i+2;
  	  				}
  	  				fclose(fy);
  	  				Sleep(1000);
  	  				main_menu();
				}
				else if(op==2)
                {
                   main_menu();
                }
				else
				{
					system("cls");
					gotoxy(35,13);
					cout<<"INVALID OPTION \a\a\a";
					main_menu();
				}
			}
		}
		else
		{
			system("cls");
			gotoxy(25,17);
			cout<<"INVALID USERNAME OR PASSWORD \a\a\a";
			Sleep(1000);
			main_menu();
		}
	}
}
machine machine::login_check()
{
	system("cls");
	system("COLOR 1F");
	frame();
	char apin[5]={0},aacno[7]={0};
	int cnt,e=0;
	char x,y;
	char p1=0,p2=0,p3=0,p4=0;
	char ans;
	gotoxy(24,12);
	cout<<" PLEASE ENTER YOUR ACCOUNT NUMBER ";
	gotoxy(37,16);
	cin>>aacno;
	system("cls");
	frame();
	gotoxy(34,2);
	cout<<"LPS BANK";
	gotoxy(56,2);
	cout<<"                        ";
	gotoxy(32,5);
	cout<<"PLEASE ENTER YOUR PIN";
	gotoxy(2,11);
	cout<<"YOUR PIN IS CONFIDENTIAL";
	gotoxy(2,13);
	cout<<"NOBODY SHOULD SEE THE PIN";
	gotoxy(2,15);
	cout<<"WHILE YOU ARE ENTERING IT.";
	gotoxy(2,17);
	cout<<"MAKE YOUR PIN MORE SECURE BY";
	gotoxy(2,19);
	cout<<"CHANGING IT FREQUENTLY.";
	gotoxy(38,22);
	apin[0]=getche();
	gotoxy(36,22);
	cout<<"        ";
	gotoxy(39,9);
	cout<<"X"<<"\a";
	gotoxy(38,22);
	apin[1]=getche();
	gotoxy(36,22);
	cout<<"       ";
	gotoxy(40,9);
	cout<<"X"<<"\a";
	gotoxy(38,22);
	apin[2]=getche();
	gotoxy(36,22);
	cout<<"        ";
	gotoxy(41,9);
	cout<<"X"<<"\a";
	gotoxy(38,22);
	apin[3]=getche();
	gotoxy(36,22);
	cout<<"        ";
	gotoxy(42,9);
	cout<<"X"<<"\a";
   	fg=fopen("accounts.txt","rb+");
	machine b,q;
    while(fscanf(fg,"%s %s %s %d \n",b.acno,b.pin,b.fname,&b.amt)!=EOF)
	{
    	if(strcmp(aacno,b.acno)==0)
    	{
			q=b;
			if(strcmp(apin,b.pin)==0)
			{
				gotoxy(2,8);

				cout<<"HELLO__MR."<<strupr(b.fname);
				Sleep(1000);
				return q;
			}
			else
			{
				Sleep(1000);
				cout<<"\a\a\aINCORRECT PIN";
				login_check();
			}

		}
		cnt++;
		e++;
	}
	if(cnt==0&&e<3)
	{
		gotoxy(30,24);
		cout<<"No account  exits of given data. ";
		sub_menu();
	}
		else if(cnt==0 && e==3)
		{
			gotoxy(30,24);
			cout<<"\nThe service for respective account is temporarily stopped. Please try again later.";
			main_menu();
		}

	fclose(fg);
}
void delr1()
{
	char ac[]="accounts.txt";
	int aaa;
		//system function (remove) in stdio.h header
	aaa=remove(ac);
	cout<<"\n\ndel "<<aaa;
	delr2();
}
void delr2()
{
	char acc[]="accounts.txt";
	char tmp[]="temp.txt";
	int bbc;
		//system function (rename) in stdio.h header
	bbc=rename(tmp,acc);
	cout<<" ren"<<bbc;
}
int main()
{
	scroll_note();		//welcome note
	machine m;			//object of machine class
	m.main_menu();		//calling menu function for making simple for our program MAIN
	return 0;
}
