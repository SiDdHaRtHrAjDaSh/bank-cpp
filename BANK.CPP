/*
    COMPUTER SCIENCE FINAL YEAR PROJECT
    2017-2018
    Siddharth raj dash
    banking software
*/


		     //DECLARATION OF HEADER FILES
#include<iostream.h>
#include<process.h>
#include<fstream.h>
#include<stdlib.h>
#include<graphics.h>
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<iomanip.h>
#include<dos.h>
#include<math.h>

		   //declaration of class account_holder
class account_holder
{


int pin_no;
public:
char account_no[20];
char password[20];

char name[20];
char mobile_no[20];
double loan_pending;
float premium;
double bank_balance;
float interest;
float duration;
float principle;
account_holder()
{
strcpy(account_no,"\0");
strcpy(password,"\0");
pin_no=0;
strcpy(name,"\0");
strcpy(mobile_no,"\0");
loan_pending=0;
premium=0;
bank_balance=0;
interest=0;
}
char* ret_accno()
{
return(account_no);
}
void assign_pin()
{
int y=random(100),z=random(200),x=1000*(random(8)+1);
pin_no=y+z+x;
}
int ret_pin()
{
return(pin_no);
}
void display()
{
cout<<"\nACCOUNT INFORMATION\n-------------------\n";
cout<<"NAME           : "<<name<<endl;
cout<<"ACCOUNT NUMBER : "<<account_no<<endl;
cout<<"MOBILE NUMBER  : "<<mobile_no<<endl;
cout<<"LOAN PENDING   : "<<loan_pending<<endl;
cout<<"PRINCIPLE      : "<<principle<<endl;
cout<<"PREMIUM        : "<<premium<<endl;
cout<<"INTEREST       : "<<interest<<endl;
cout<<"DURATION       : "<<duration<<endl;
cout<<"BANK BALANCE   : "<<bank_balance<<endl;
}
}acc_holder;



		     //help(): displays the way to us the program.

void help()
{
clrscr();
int gdriver = EGA, gmode = EGAHI;
initgraph(&gdriver, &gmode, " ");
 cout<<"\n\n\nWELCOME TO INDIAN BANK\n";
 cout<<"********************** \n";
 cout<<"\n\nThis is a bank operated by two parts , the accountant and the account holder.\n";
 cout<<"\n\nSTAFF\n-----\nwith this mode of access you can do the following operations\n";
 cout<<"1)add a new account holder\n";
 cout<<"2)search an existing account holder and get its information\n";
 cout<<"\nACCOUNT HOLDER\n--------------\n";
 cout<<"with this mode of access you can do the following operations\n";
 cout<<"1)Withdraw money\n";
 cout<<"2)Dposite money\n";
 cout<<"3)Check account status.\n";
 cout<<"4)Transfer  money between two accounts.\n";
 cout<<"5)Get loans at a fixed interest rate.\n";
 cout<<"6)Do transactions.\n";
 cout<<"\n\npress any key to exit";
 char p;
 cin>>p;
}

	      /* add_account_holder():
		 a function to add a new account holder. */


void add_account_holder()
{
fstream f1;
f1.open("account_holder.dat",ios::out|ios::binary);
begin:
clrscr();
randomize();
int gdriver = EGA, gmode = EGAHI;
initgraph(&gdriver, &gmode, "");
setbkcolor(RED);
cout<<"\t\t\tBANK ENROLLMENT PORTAL\n";
cout<<"\t\t\t**********************\n\n";
cout<<"Enter the details of the accountant\n";
cout<<"Name      :";gets(acc_holder.name);cout<<endl;
cout<<"Moblie no :";gets(acc_holder.mobile_no);cout<<endl;
cout<<"Enter account number to be assigned :";cin>>acc_holder.account_no;cout<<endl;
cout<<"Enter your desired password :";cin>>acc_holder.password;cout<<endl;
cout<<"Enter the primary ammount to be stored :";cin>>acc_holder.bank_balance;cout<<endl;
cout<<"Generating pin\n";
acc_holder.assign_pin();
cout<<"Your PIN is \n";
cout<<"\t\t"<<acc_holder.ret_pin()<<endl<<endl;
f1.write((char*)&acc_holder,sizeof(acc_holder));
cout<<"To the account holder:\n\n";
cout<<"please remember these details for future banking. for any assistanc please \ncontact our staff\nbest reagrds,\nbanking team\n";
cout<<"\nACCOUNT SUCCESSFULLY CREATED\nPress any key to continue or press p to create anathor account\n";
char ch;
cin>>ch;
if(ch=='p')
goto begin;
clrscr();
f1.close();
}
  /*
     search_account_holder():
     a function to search an existing account holder and view the information.
  */


void search_account_holder()
{
fstream f2;
f2.open("account_holder.dat",ios::in|ios::binary);
clrscr();
int gdriver = EGA, gmode = EGAHI;
initgraph(&gdriver, &gmode, "");
setbkcolor(RED);
cout<<"\t\t\tSEARCHING PORTAL\n";
cout<<"\t\t\t****************\n\n";
cout<<"\nEnter the account number to be searched:\n";
char s[20];
gets(s);
int pos;
while(!f2.eof())
{

f2.read((char*)&acc_holder,sizeof(acc_holder));
if(strcmpi(acc_holder.account_no,s)==0)
{

if(f2)
acc_holder.display();

}

}
f2.close();
int q ;
cin>>q;
}


     //accountant():menu to carry out functions of accountant.


void accountant()
{

int gdriver = EGA, gmode = EGAHI;
initgraph(&gdriver, &gmode, "");
setbkcolor(RED);
char u_name[20],password[20];
cout<<"\t\t\t*******************\n";
cout<<"\t\t\tWELCOME TO THE BANK\n";
cout<<"\t\t\t*******************\n\n\n\n";
cout<<"\t\t\tEnter your user name:\n\t\t\t--------------------\n\t\t\t\n\n\t\t\t";
gets(u_name);
if((strcmp(u_name,"Siddhu@12345")==0)||(strcmp(u_name,"Messi10")==0)||(strcmp(u_name,"Msdhoni7")==0))
cout<<"\n\n\t\t\tEnter your password:\n\t\t\t-------------------\n\t\t\t\n\n\t\t\t";
gets(password);
if(strcmp(password,"**********")==0)
{
clrscr();
initgraph(&gdriver, &gmode, "");
setbkcolor(RED);
cout<<endl<<endl;
cout<<"\t    *           * * * *  * * * *    * * * *   * * * *   *  *  \n";
cout<<"\t    *           *     *  *          *         *         *    *\n";
cout<<"\t    *           *     *  *   * *    *   * *   * * * *   *    *\n";
cout<<"\t    *           *     *  *     *    *     *   *         *    *\n";
cout<<"\t    * * * * *   * * * *  * * * *    * * * *   * * * *   *  *  \n";
cout<<endl<<endl;
cout<<"\t\t\t    * * * * *  *       * \n";
cout<<"\t\t\t        *      * *     * \n";
cout<<"\t\t\t        *      *   *   * \n";
cout<<"\t\t\t        *      *     * * \n";
cout<<"\t\t\t    * * * * *  *       * \n";
cout<<endl;
char ch;
cout<<"\t\tpress any key to contnue\n";
cin>>ch;
staff:
clrscr();
initgraph(&gdriver, &gmode, "");
setbkcolor(RED);
cout<<"\t\t\t**********\n";
cout<<"\t\t\tSTAFF MENU\n";
cout<<"\t\t\t**********\n";
cout<<endl<<endl;
cout<<"1) ADD ACCOUNT HOLDER\n";
cout<<"2) SEARCH ACCOUNT HOLDER\n";
cout<<"3) LOG OFF\n";
int a;
l1:
cin>>a;
switch(a)
{
    case 1:add_account_holder();break;
    case 2:search_account_holder();break;
    case 3:goto eof;
}
goto staff;
eof:
}}

       //witdraw(): To withdraw money from the user's account.

void withdraw()
{
int pos;
fstream f3;
f3.open("account_holder.dat",ios::in|ios::out|ios::binary);
clrscr();
int gdriver = EGA, gmode = EGAHI;
initgraph(&gdriver, &gmode, "");
setbkcolor(BLUE);
cout<<"\t\t\tCASH WITHDRAWAL\n";
cout<<"\t\t\t***************\n\n";
cout<<"\nEnter your account number :";char acc[20];gets(acc);
cout<<"\nEnter your PIN :";int a;cin>>a;
cout<<"\nEnter the ammount to be withdrawn :";double w;cin>>w;cout<<endl;
cout<<"\nProcessing your request:\n";
randomize();
bar(100 ,200 , 100,210);bar(400 ,200 , 400,210);
bar(100 ,200 , 400,200);bar(100 ,210 , 400,210);
for(int i=0;i<30;i++)
{
bar(100 ,200 , 110+(i*10),210);
delay(random(300));
}
cout<<endl<<endl;

while(!f3.eof())
{
pos=f3.tellg();
f3.read((char*)&acc_holder,sizeof(acc_holder));
if((strcmpi(acc_holder.account_no,acc)==0)&&(acc_holder.ret_pin()==a))
{
f3.seekp(pos);
if(f3)
acc_holder.bank_balance-=w;
if(acc_holder.bank_balance>=0)
{f3.write((char*)&acc_holder,sizeof(acc_holder));
if(f3)
{cout<<endl<<endl;
acc_holder.display();} }
else
cout<<"you are bankrupted !";
}
}
char p;
cin>>p;
f3.close();
}

       //deposite(): To deposite money into the user's account.

void deposite()
{
int pos;
fstream f4;
f4.open("account_holder.dat",ios::in|ios::out|ios::binary);
clrscr();
int gdriver = EGA, gmode = EGAHI;
initgraph(&gdriver, &gmode, "");
setbkcolor(BLUE);
cout<<"\t\t\tCASH DEPOSIT\n";
cout<<"\t\t\t************\n\n";
cout<<"\nEnter your account number :";char acc[20];gets(acc);
cout<<"\nEnter your PIN :";int a;cin>>a;
cout<<"\nEnter the ammount to be deposited :";double d;cin>>d;cout<<endl;
cout<<"\nProcessing your request:\n";
randomize();
bar(100 ,200 , 100,210);bar(400 ,200 , 400,210);
bar(100 ,200 , 400,200);bar(100 ,210 , 400,210);
for(int i=0;i<30;i++)
{
bar(100 ,200 , 110+(i*10),210);
delay(random(300));
}
cout<<endl<<endl;
while(!f4.eof())
{
pos=f4.tellg();
f4.read((char*)&acc_holder,sizeof(acc_holder));
if((strcmpi(acc_holder.account_no,acc)==0)&&(acc_holder.ret_pin()==a))
{

acc_holder.bank_balance+=d;
f4.seekp(pos);
f4.write((char*)&acc_holder,sizeof(acc_holder));
cout<<endl;
if(f4)
acc_holder.display();

}
}
cout<<"Press any key to continue\n";
char p;
cin>>p;
f4.close();
}


	  //account_status(): To view account information of an user.

void account_status()
{
int pos;
fstream f4;
f4.open("account_holder.dat",ios::in|ios::binary);
clrscr();
int gdriver = EGA, gmode = EGAHI;
initgraph(&gdriver, &gmode, "");
setbkcolor(BLUE);
cout<<"\t\t\tYOUR ACCOUNT INFORMATION\n";
cout<<"\t\t\t************************\n\n";
cout<<"\nEnter your account number :";char acc[20];gets(acc);
cout<<"\nEnter your PIN :";int a;cin>>a;
cout<<"\nProcessing your request:\n";
randomize();
bar(100 ,150 , 100,160);bar(400 ,150 , 400,160);
bar(100 ,150 , 400,150);bar(100 ,160 , 400,160);
for(int i=0;i<30;i++)
{
bar(100 ,150 , 110+(i*10),160);
delay(random(300));
}
cout<<endl<<endl;
while(!f4.eof())
{
pos=f4.tellg();
f4.read((char*)&acc_holder,sizeof(acc_holder));
if((strcmpi(acc_holder.account_no,acc)==0)&&(acc_holder.ret_pin()==a))
{
f4.seekp(pos);
if(f4)
cout<<"\n\n\n\n";
acc_holder.display();break;
}

}
cout<<"\nPress any key continue\n";
char p;
cin>>p;
f4.close();
}

	 //loanrequest(): To get desired loan with fixed interest.


void loanrequest()
{
cout<<"\t\t\t*********\n";
cout<<"\t\t\tLOAN MENU\n";
cout<<"\t\t\t*********\n";
int pos;
fstream f4;
f4.open("account_holder.dat",ios::in|ios::out|ios::binary);
clrscr();
int gdriver = EGA, gmode = EGAHI;
initgraph(&gdriver, &gmode, "");
setbkcolor(BLUE);
cout<<"\t\t\tLOAN PROCESSING\n";
cout<<"\t\t\t***************\n\n";
cout<<"\nEnter your account number :";char acc[20];gets(acc);
cout<<"\nEnter your PIN :";int a;cin>>a;
cout<<"\nEnter the loan required:";double d;cin>>d;cout<<endl;
cout<<"\nEnter your desired time of repayment:";int rpay;cin>>rpay;
int intr;
if(rpay<=2)
{intr=7;}
if((rpay>2)&&(rpay<=3))
{intr=8;}
if((rpay>3)&&(rpay<=5))
{intr=10;}
if(rpay>=5)
{intr=12;}

cout<<"\nProcessing your request:\n";
randomize();
bar(100 ,200 , 100,210);bar(400 ,200 , 400,210);
bar(100 ,200 , 400,200);bar(100 ,210 , 400,210);
for(int i=0;i<30;i++)
{
bar(100 ,200 , 110+(i*10),210);
delay(random(300));
}
cout<<"\n\n\nThe interest rate is"<<intr<<"%";

cout<<"\nYour loan has been approved\n";
while(!f4.eof())
{
pos=f4.tellg();
f4.read((char*)&acc_holder,sizeof(acc_holder));
if((strcmpi(acc_holder.account_no,acc)==0)&&(acc_holder.ret_pin()==a))
{
f4.seekp(pos);
if(f4)
acc_holder.principle+=d;acc_holder.bank_balance+=d;acc_holder.interest=intr;
acc_holder.duration=rpay;
int amt;
amt=d+((d*intr*rpay)/100);
acc_holder.loan_pending=amt;
f4.write((char*)&acc_holder,sizeof(acc_holder));
cout<<endl;
acc_holder.display();
break;
}
}
cout<<"\nPress any key to continue\n";
char p;
cin>>p;
f4.close();
}


	//moneytransfer(): To trannsfer money from one account to another.


void moneytransfer()
{
cout<<"\t\t\t*********\n";
cout<<"\t\t\tTRANSFERS\n";
cout<<"\t\t\t*********\n";
int pos;
fstream f4;
f4.open("account_holder.dat",ios::in|ios::out|ios::binary);
clrscr();
int gdriver = EGA, gmode = EGAHI;
initgraph(&gdriver, &gmode, "");
setbkcolor(BLUE);
cout<<"\t\t\tMONEY TRANSFERS\n";
cout<<"\t\t\t***************\n\n";
cout<<"\nEnter your account number :";char acc[20];gets(acc);
cout<<"\nEnter your PIN :";int a;cin>>a;
cout<<"\nEnter the ammount to be transfered:";double d;cin>>d;cout<<endl;
cout<<"\nEnter the receiver account number :";char r_acc_no[20];cin>>r_acc_no;
cout<<"\nProcessing your request:\n";
randomize();
bar(100 ,200 , 100,210);bar(400 ,200 , 400,210);
bar(100 ,200 , 400,200);bar(100 ,210 , 400,210);
for(int i=0;i<30;i++)
{
bar(100 ,200 , 110+(i*10),210);
delay(random(300));
}

cout<<"\n\n\n\nMoney successfully transfered\n";
while(!f4.eof())
{
pos=f4.tellg();
f4.read((char*)&acc_holder,sizeof(acc_holder));
if((strcmpi(acc_holder.account_no,acc)==0)&&(acc_holder.ret_pin()==a))
{
f4.seekp(pos);
acc_holder.bank_balance-=d;
f4.write((char*)&acc_holder,sizeof(acc_holder));
cout<<endl;
if(f4)
acc_holder.display();

}
if((strcmpi(acc_holder.account_no,r_acc_no)==0))
{
f4.seekp(pos);
acc_holder.bank_balance+=d;
f4.write((char*)&acc_holder,sizeof(acc_holder));
cout<<endl;
if(f4)
acc_holder.display();
}

}
cout<<"Press any key to continue:";
char p;
cin>>p;
f4.close();
}

	  //payloan(): To pay pending loans with interest.

void payloan()
{
int pos;
fstream f4;
f4.open("account_holder.dat",ios::in|ios::out|ios::binary);
clrscr();
int gdriver = EGA, gmode = EGAHI;
initgraph(&gdriver, &gmode, "");
setbkcolor(BLUE);
cout<<"\t\t\tLOAN PROCESSING\n";
cout<<"\t\t\t***************\n\n";
cout<<"\nEnter your account number :";char acc[20];gets(acc);
cout<<"\nEnter your PIN :";int a;cin>>a;
cout<<"\nProcessing your request:\n";
randomize();
bar(100 ,200 , 100,210);bar(400 ,200 , 400,210);
bar(100 ,200 , 400,200);bar(100 ,210 , 400,210);
for(int i=0;i<30;i++)
{
bar(100 ,200 , 110+(i*10),210);
delay(random(200));
}

char s[]={"!@#$%^&*()_+"};
char ch1[20];

int pay;
char ch;
while(!f4.eof())
{
  pos=f4.tellg();
  f4.read((char*)&acc_holder,sizeof(acc_holder));

  if((strcmpi(acc_holder.account_no,acc)==0)&&(acc_holder.ret_pin()==a))
      {
	  f4.seekp(pos);
	  if(acc_holder.loan_pending==0)
	  {cout<<"You have no loans pending\n";break;}
	  else
	  {
	  cout<<"\n\n\n\n\n\nThe ammount pending is "<<acc_holder.loan_pending<<" Which has to be paid in "<<acc_holder.duration<<" years"<<endl;
	  cout<<"\nwould you like to pay now?\n";cin>>ch;
	  if(ch=='y')
	     {
		   cout<<"\nEnter the ammount you want to pay\n";cin>>pay;
		   cout<<"\nEnter the captcha to complete transaction:\n";
		   cout<<"\n!@#$%^&*()_+\n";
		   cout<<"\nEnter captcha here:   ";gets(ch1);
		   if(strcmp(s,ch1)==0)
			  {
			    acc_holder.loan_pending-=pay;acc_holder.bank_balance-=pay;
			    if(acc_holder.loan_pending==0){acc_holder.principle=0;acc_holder.interest=0;acc_holder.duration=0;}
			    f4.write((char*)&acc_holder,sizeof(acc_holder));

			   }

	    }

else	goto feos;

   cout<<endl;
  if(f4)
  {
  cout<<"\nTRANSACTION COMPLETE\n";
  acc_holder.display();
  }
  }
   }

 }
feos:
f4.close();
}

	   //account_holder(): Menu to access account_holder's functions.

void account_holder()
{
retry:
clrscr();
int gdriver = EGA, gmode = EGAHI;
initgraph(&gdriver, &gmode, "");
setbkcolor(BLUE);
char acc_no[20],password[20];
cout<<"\t\t\t**********************\n";
cout<<"\t\t\tWELCOME ACCOUNT HOLDER\n";
cout<<"\t\t\t**********************\n\n\n\n";
cout<<"\t\t\tEnter your accout number:\n\t\t\t--------------------\n\t\t\t\n\n\t\t\t";
gets(acc_no);
fstream f2;

f2.open("account_holder.dat",ios::in|ios::binary);
while(!f2.eof())
{

f2.read((char*)&acc_holder,sizeof(acc_holder));
if(f2)
if(strcmp(acc_holder.account_no,acc_no)==0)
{
cout<<"\n\n\t\t\tEnter your password:\n\t\t\t-------------------\n\t\t\t\n\n\t\t\t";
gets(password);
if(strcmp(acc_holder.password,password)==0)
goto continueation;
}
}
cout<<"Account no does not exist";
cout<<"\ndo you want to retry";
char l;
cin>>l;
if(l=='y')
goto retry;


continueation:
f2.close();
clrscr();
initgraph(&gdriver, &gmode, "");
setbkcolor(BLUE);
cout<<endl<<endl;
cout<<"\t    *           * * * *  * * * *    * * * *   * * * *   *  *  \n";
cout<<"\t    *           *     *  *          *         *         *    *\n";
cout<<"\t    *           *     *  *   * *    *   * *   * * * *   *    *\n";
cout<<"\t    *           *     *  *     *    *     *   *         *    *\n";
cout<<"\t    * * * * *   * * * *  * * * *    * * * *   * * * *   *  *  \n";
cout<<endl<<endl;
cout<<"\t\t\t    * * * * *  *       * \n";
cout<<"\t\t\t        *      * *     * \n";
cout<<"\t\t\t        *      *   *   * \n";
cout<<"\t\t\t        *      *     * * \n";
cout<<"\t\t\t    * * * * *  *       * \n";
cout<<endl;
char ch;
cout<<"pree any key to contnue\n";
cin>>ch;
start:
clrscr();
initgraph(&gdriver, &gmode, "");
setbkcolor(BLUE);
cout<<"\t\t\t************\n";
cout<<"\t\t\tBANKING MENU\n";
cout<<"\t\t\t************\n";
cout<<endl<<endl;
cout<<"1) CASH WITHDRAWAL\n";
cout<<"2) CASH DEPOSITE\n";
cout<<"3) ACCOUNT STATUS\n";
cout<<"4) LOAN OPTIONS\n";
cout<<"5) MONEY TRANSFER\n";
cout<<"6) PAY LOAN\n";
cout<<"7) LOG OUT\n\n";
int option;
entry:
cin>>option;
switch(option)
{
case 1:withdraw();break;
case 2:deposite();break;
case 3:account_status();break;
case 4:loanrequest();break;
case 5:moneytransfer();break;
case 6:payloan();break;
case 7:goto end;
default :cout<<"!!! INVALID ENTRY !!! try again\n";
	 goto entry;
}
int halt;
cin>>halt;
goto start;
end:


}

	/*
	   main() :
	   Begining of everything. Allows you to choose the mode of visit.
	*/

void main()
{
int gdriver = EGA, gmode = EGAHI;
initgraph(&gdriver, &gmode, "");
int midx,midy;
midx = getmaxx() / 2;
midy = getmaxy() / 2;
settextstyle(DEFAULT_FONT,HORIZ_DIR,4);
outtextxy(midx-110,midy-50,"WELCOME ");
outtextxy(midx-200,midy+10,"TO INDIAN BANK");
settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
outtextxy(midx-120,midy+80,"Projet by Siddharth Raj Dash XII-E ");
getch();
again:
clrscr();
initgraph(&gdriver, &gmode, "");

	int gd,gm;
	int r,i,a,b,x,y;
	float PI=3.14;

	detectgraph(&gd,&gm);
	setcolor(RED);
	rectangle(300,100,450,125);
	setfillstyle(SOLID_FILL,RED);
	floodfill(305,101,RED);
	setcolor(WHITE);
	rectangle(300,125,450,150);
	setfillstyle(SOLID_FILL,WHITE);
	floodfill(305,129,WHITE);
	setcolor(GREEN);
	rectangle(300,150,450,175);
	setfillstyle(SOLID_FILL,GREEN);
	floodfill(305,153,GREEN);
	a=375;
	b=137.5;
	r=12.5;
	setcolor(BLUE);
	circle(a,b,r);
	for(i=0;i<=360;i=i+15)
	{
		x=r*cos(i*PI/180);
		y=r*sin(i*PI/180);
		line(a,b,a+x,b-y);
	}

setbkcolor(9);
int mode;
cout<<"\t\t\t**********************\n";
cout<<"\t\t\tWELCOME TO INDIAN BANK\n";
cout<<"\t\t\t**********************\n";
cout<<endl<<endl<<endl<<endl;
cout<<"ENTER MODE OF VISIT:\n\n";
cout<<"1) ACCOUNTANT\n";
cout<<"2) ACCOUNT HOLDER\n";
cout<<"3) HELP\n";
cout<<"4) CLOSE PROGRAM\n\n\n";
cout<<"Slelct your desired option:\n";
cin>>mode;
switch(mode)
{
case 1:accountant();break;
case 2:account_holder();break;
case 3:help();break;
case 4: clrscr();
	settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
	outtextxy(50,midy-50,"THANK YOU FOR BANKING WITH US");
	getch();
	exit(0);
default:cout<<"invalid entry. try again \n";
}
goto again;
}