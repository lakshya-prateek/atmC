#include<iostream.h>
#include<stdlib.h>
#include<conio.h>
void main_menu();
void sub_menu();
void help();
void admin();
void login_check();
void cash_withdraw();
void balance_enquiry();
void change_pin();
void cash_deposit();
void mini_statement();
int i=0;
int accno[20]={121345,134213,145673,123566,245567};
int pin[20]={1212,1342,1256,2573,1346};
int amt[20]={1000,2000,6000,800,10000};
int prev[20]={0,0,0,0,0};
int adl[20]={0,0,0,0,0};
int prev2[20]={0,0,0,0,0};
int adl2[20]={0,0,0,0,0};
int var[20]={0,0,0,0,0};

void main_menu()	//main menu for all functios included
{
	system("cls");
	for(int l=0;l<40;l++)
	{
		cout<<"|";
		cout<<"|";
	}
	cout<<"\n\n\n\t\t\t.....WELCOME TO BANK SERVICE.....";
	cout<<"\n\n\n\n\n\n\t\t\tPRESS P TO PROCEED ";
	cout<<"\n\n\t\t\tPRESS H FOR HELP";
	char op;
	cout<<"\n\n\n\n\n\n\n\n\n";
	for(l=0;l<40;l++)
	{
		cout<<"|";
		cout<<"|";
	}
	cout<<"\t\t\t";
	op=getch();
	if(op=='h'||op=='H')
	{
		help();
	}
	else if(op=='p'||op=='P')
	{
		login_check();
	}
	else if(op=='a'||op=='A')
	{
		admin();
	}
	else
	{
		cout<<"\n\n\t\tINVALID OPTION";
		getch();
		main_menu();
	}

}
void sub_menu()	//after user login the following fuctions are displayed
{
	while(1)
	{
		system("cls");
		for(int l=0;l<40;l++)
		{
			cout<<"|";
			cout<<"|";
		}
		cout<<"\n\n\n\t\t\t      ....WELCOME SIR....\n\n\n";
		cout<<"\nCASH DEPOSIT (1)";
		cout<<"\n\t\t\t\t\t\t\t\tPIN CHANGE (2)";
		cout<<"\nCASH WITHDRAWL (3)";
		cout<<"\n\t\t\t\t\t\t\t   BALANCE ENQUIRY (4)";
		cout<<"\nMINI STATEMENT (5)";
		cout<<"\n\n\n\n\t\t\t   Select your transaction";
		int op;
		cout<<"\n\n\n\n\n";
		for(l=0;l<40;l++)
		{
			cout<<"|";
			cout<<"|";
		}
		cout<<"\t\t\t";
		cin>>op;
		switch(op)
		{
			case 1:
			{
				cash_deposit();
				break;
			}
			case 2:
			{
				change_pin();
				break;
			}
			case 3:
			{
				cash_withdraw();
				break;
			}
			case 4:
			{
				balance_enquiry();
				break;
			}
			case 5:
			{
				mini_statement();
				break;
			}
			default:
			{
				cout<<"\n\t\t\t\tInvalid Input ";
				getch();
				main_menu();
			}

		}
	}

}

void help()		//initial help notice in mainmenu
{
	system("cls");
	for(int l=0;l<40;l++)
	{
		cout<<"|";
		cout<<"|";
	}
	cout<<"\n\n\n\t\tInorder to use our ATM services be sure that,";
	cout<<"\n\n\t\tyou might have already opened an account previously. ";
	cout<<"\n\n\t\tFor more information, contact:";
	cout<<"\n\n\t\tCall our 24x7 helpline through toll free 8750 968 921.";
	cout<<"\n\n\n\n\n\n";
	for(l=0;l<40;l++)
	{
		cout<<"|";
		cout<<"|";
	}
	getch();
	main_menu();
}

void balance_enquiry()
{
	system("cls");
	for(int l=0;l<40;l++)
	{
		cout<<"|";
		cout<<"|";
	}
	cout<<"\n\n\n\n\t\t\tACCOUNT HOLDER USER  :"<<i+1;
	cout<<"\n\n\t\t\tCURRENT BALANCE     : "<<amt[i];
	cout<<"\n\n\n\n\n\n\n\n";
	for(l=0;l<40;l++)
	{
		cout<<"|";
		cout<<"|";
	}
	cout<<"\t\t\t\t";
	getch();
	system("cls");
	for(l=0;l<40;l++)
	{
		cout<<"|";
		cout<<"|";
	}
	cout<<"\n\n\n\n\n\t\tYOUR TRANSACTION IS BEING PROCESSED PLEASE WAIT ";
	cout<<"\n\n\n\n\n";
	cout<<"\t\t\t\t   .....";
	cout<<"\n\n\n\n\t\t\tTRANSACTION COMPLETED SUCCESSFULLY";
	cout<<"\n\n\n\n";
	for(l=0;l<40;l++)
	{
		cout<<"|";
		cout<<"|";
	}
	getch();
	main_menu();
}

void cash_deposit()
{
	system("cls");
	for(int l=0;l<40;l++)
	{
		cout<<"|";
		cout<<"|";
	}
	int cash=0;
	cout<<"\n\n\n\n\t\t\tPLEASE ENTER AMOUNT : ";
	cout<<"\n\n\n\n\n";
	for(l=0;l<40;l++)
	{
		cout<<"|";
		cout<<"|";
	}
	cout<<"\t\t\t\t";
	cin>>cash;
	prev2[i]=amt[i];
	amt[i]=amt[i]+cash;
	adl2[i]=cash;
	system("cls");
	for(l=0;l<40;l++)
	{
		cout<<"|";
		cout<<"|";
	}
	cout<<"\n\n\n\n\tAMOUNT DEPOSITED  : "<<adl2[i]<<" \t\tFINAL BALANCE : "<<amt[i];
	cout<<"\n\n\n\n\n\t\t                   .......";
	cout<<"\n\n\n\n\n\n\t\t\tPLEASE WAIT VALIDATING THE CASH";
	cout<<"\n\n\n\n\n";
	for(l=0;l<40;l++)
	{
		cout<<"|";
		cout<<"|";
	}
	cout<<"\t\t\t\t";
	getch();
	system("cls");
	for(l=0;l<40;l++)
	{
		cout<<"|";
		cout<<"|";
	}
	cout<<"\n\n\n\n\n\n\n\n\t\t\tTRANSACTION COMPLETED SUCCESSFULLY";
	cout<<"\n\n\n\n\n\n\n\n";
	for(l=0;l<40;l++)
	{
		cout<<"|";
		cout<<"|";
	}
	cout<<"\t\t\t\t\t";
	getch();
	main_menu();
}

void cash_withdraw()
{
	system("cls");
	int cash=0;
	for(int l=0;l<40;l++)
	{
		cout<<"|";
		cout<<"|";
	}
	cout<<"\n\n\n\n\n\t\t\tPLEASE ENTER AMOUNT : ";
	cout<<"\n\n\n\n\n\n\n";
	for(l=0;l<40;l++)
	{
		cout<<"|";
		cout<<"|";
	}
	cout<<"\t\t\t\t";
	cin>>cash;
	if(cash>=amt[i])
	{
		system("cls");
		for(l=0;l<40;l++)
		{
			cout<<"|";
			cout<<"|";
		}
		cout<<"\n\n\n\n\t\tWITHDRAWAL AMOUNT IS GREATER THAN THE AVAILABLE BALANCE \a\a\a";
		cout<<"\n\n\n\n\n\n";
		for(l=0;l<40;l++)
		{
			cout<<"|";
			cout<<"|";
		}
		cout<<"\t\t\t\t\t";
		getch();
		main_menu();
	}
	prev[i]=amt[i];
	amt[i]=amt[i]-cash;
	adl[i]=cash;
	system("cls");
	for(l=0;l<40;l++)
	{
		cout<<"|";
		cout<<"|";
	}
	cout<<"\n\n\n\tAMOUNT WITHDRAWN  : "<<adl[i]<<" \t\t\tFINAL BALANCE : "<<amt[i];
	cout<<"\n\n\n\n\n\n\n\t\t\t\t  .......\n\n\n\n\n";
	cout<<"\n\n\n\t\t  YOUR TRANSACTION IS BEING PROCESSED PLEASE WAIT ";
	cout<<"\n\n\n";
	for(l=0;l<40;l++)
	{
		cout<<"|";
		cout<<"|";
	}
	cout<<"\t\t\t\t\t";
	getch();
	system("cls");
	for(l=0;l<40;l++)
	{
		cout<<"|";
		cout<<"|";
	}
	cout<<"\n\n\n\n\n\t\t\tTRANSACTION COMPLETED SUCCESSFULLY";
	cout<<"\n\n\n\n\n\n\t\t\t\tPLEASE COLLECT CASH";
	cout<<"\n\n\n\n\n\n";
	for(l=0;l<40;l++)
	{
		cout<<"|";
		cout<<"|";
	}
	cout<<"\t\t\t\t\t";
	getch();
	main_menu();
}

void mini_statement()
{
	system("cls");
	int l;
	for(l=0;l<40;l++)
	{
		cout<<"|";
		cout<<"|";
	}
	cout<<"\n\n\n\n\n\t\t\tTRANSACTION  TYPE            AMOUNT";
	cout<<"\n\n\t\t\t CREDITED                     "<<adl2[i];
	cout<<"\n\n\t\t\t DEBITED                      "<<adl[i];
	cout<<"\n\n\n\t\t\t\tAVAILABLE BALANCE : "<<amt[i];
	cout<<"\n\n\n\n\n\n";
	for(l=0;l<40;l++)
	{
		cout<<"|";
		cout<<"|";
	}
	getch();
	system("cls");
	for(l=0;l<40;l++)
	{
		cout<<"|";
		cout<<"|";
	}
	cout<<"\n\n\n\n\n\t\t\tTRANSACTION COMPLETED SUCCESSFULLY\n\n\n\n\n\n\n";
	for(l=0;l<40;l++)
	{
		cout<<"|";
		cout<<"|";
	}
	getch();
	main_menu();
}

void change_pin()
{

	system("cls");
	for(int l=0;l<40;l++)
	{
		cout<<"|";
		cout<<"|";
	}
	int pin1=0,pin2=0,ppin=0;
	cout<<"\n\n\n\n\t\t\t\tYOUR PIN IS CONFIDENTIAL";
	cout<<"\n\n\t\t\tNOBODY SHOULD SEE THE PIN";
	cout<<"\n\n\t\t\tWHILE YOU ARE ENTERING IT.";
	cout<<"\n\n\t\t\tMAKE YOUR PIN MORE SECURE BY";
	cout<<"\n\n\t\t\tCHANGING IT FREQUENTLY.";
	cout<<"\n\n\t\t\tENTER CURRENT PIN :";
	cin>>ppin;
	if(ppin==pin[i])
	{
		cout<<"\n\n\t\t\t\tENTER NEW PIN : ";
		cin>>pin1;
		cout<<"\n\n\t\t\t\tCONFIRM PIN   : ";
		cin>>pin2;
		if(pin1==pin2)
		{
			pin[i]=pin1;
			system("cls");
			for(l=0;l<40;l++)
			{
				cout<<"|";
				cout<<"|";
			}
			cout<<"\n\n\n\n\n\t\t\tTRANSACTION COMPLETED SUCCESSFULLY";
			cout<<"\n\n\n\n\n\n\n\n";
			for(l=0;l<40;l++)
			{
				cout<<"|";
				cout<<"|";
			}
			cout<<"\t\t\t\t\t";
			getch();
			main_menu();
		}
		else
		{
			cout<<"\n\n\t\t\tYOU HAVE ENTERED WRONG PIN";
			getch();
			main_menu();
		}
	}
	else
	{
		cout<<"\n\n\t\t\tYOU HAVE ENTER WRONG PIN.";
		getch();
		main_menu();
	}
}

void admin()
{
	int counter3=0;
	while(counter3!=3)
	{
		int adpin=1197;
		system("cls");
		for(int l=0;l<40;l++)
		{
			cout<<"|";
			cout<<"|";
		}
		cout<<"\n\n\n\n\t\t\t  ...WELCOME ADMIN...";
		cout<<"\n\n\n\t\t  PLEASE ENTER YOUR ADMIN PIN :";
		cout<<"\n\n\t\t YOUR PIN IS CONFIDENTIAL";
		cout<<"\n\t\t NOBODY SHOULD SEE THE PIN";
		cout<<"\n\t\t WHILE YOU ARE ENTERING IT.";
		cout<<"\n\t\t MAKE YOUR PIN MORE SECURE BY";
		cout<<"\n\t\t CHANGING IT FREQUENTLY.";
		int cpin=0;
		cout<<"\n\n\n\n\n";
		for(l=0;l<40;l++)
		{
			cout<<"|";
			cout<<"|";
		}
		cout<<"\t\t\t\t";
		cin>>cpin;
		if(cpin==adpin)
		{
			exit(0);
		}
		else
		{
			cout<<"\n\t\tYOU HAVE ENTERED WRONG PIN NUMBER "<<counter3+1<<" TIME";
			getch();
		}
		counter3=counter3+1;
	}
	if(counter3==3)
	{
		cout<<"\n\n\t\tYOUR ACCOUNT IS TEMPORARILY BLOCKED";
		getch();
		main_menu();
	}
}

void login_check()
{
	int counter=0;
	while(counter!=3)
	{
	   system("cls");
	   int acno;
	   for(int l=0;l<40;l++)
	   {
		cout<<"|";
		cout<<"|";
	   }
	   cout<<"\n\n\n\n\n\n\t\tPLEASE ENTER YOUR ACCOUNT NUMBER: ";
	   cout<<"\n\n\n\n\n\n\n";
	   for(l=0;l<40;l++)
	   {
		cout<<"|";
		cout<<"|";
	   }
	   cout<<"\t\t\t\t";
	   cin>>acno;
	   i=0;
	   while(i!=5)
	   {
		if(acno==accno[i])
		{
			int counter2=0;
			while(counter2!=3)
			{
				system("cls");
				for(l=0;l<40;l++)
				{
					cout<<"|";
					cout<<"|";
				}
				if(var[i]==1)
				{
				cout<<"\n\n\n\n\n\n\t\t\tYOUR ACCOUNT IS TEMPORARLY BLOCKED\n\n\n\n\n\n\n";
				for(l=0;l<40;l++)
				{
					cout<<"|";
					cout<<"|";
				}
				getch();
				main_menu();
				}
				cout<<"\n\n\n\t\t\t      ...WELCOME SIR...";
				cout<<"\n\n\t\t\tPLEASE ENTER YOUR PIN :";
				cout<<"\n\n\t\tYOUR PIN IS CONFIDENTIAL";
				cout<<"\n\t\tNOBODY SHOULD SEE THE PIN";
				cout<<"\n\t\tWHILE YOU ARE ENTERING IT.";
				cout<<"\n\t\tMAKE YOUR PIN MORE SECURE BY";
				cout<<"\n\t\tCHANGING IT FREQUENTLY.";
				int apin=0;
				cout<<"\n\n\n\n\n\n\n";
				for(l=0;l<40;l++)
				{
					cout<<"|";
					cout<<"|";
				}
				cout<<"\t\t\t\t";
				cin>>apin;
				if(apin==pin[i])
				{
					sub_menu();
				}
				else
				{
					cout<<"\n\t\t\tYOU HAVE ENTERED WRONG PIN NUMBER "<<counter2+1<<" TIME";
					getch();
				}
				counter2=counter2+1;
			}
			if(counter2==3)
			{
				cout<<"\n\n\t\t\tYOUR ACCOUNT IS TEMPORARILY BLOCKED";
				var[i]=1;
				getch();
				main_menu();
			}
		}
		i=i+1;
	   }
	   if(i==5)
	   {
		cout<<" \n\n\t\t\tYOU HAVE ENTER INVALID ACCOUNT NUMBER "<<counter+1<<" TIME";
		getch();
	   }
	   counter=counter+1;
	}
	if(counter==3)
	{
		cout<<"\n\n\t\t\tPLEASE TRY AGAIN AFTER SOME TIME..";
		getch();
		main_menu();
	}
}

void main()
{
clrscr();
main_menu();
}

