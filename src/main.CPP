#include<iostream.h>
#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<time.h>
#include<dos.h>
class hosdata
{
private:
	char name[30];
    int no;
    char purpose[100];
public:
	char date[10];
	void getdata();
	int retno()
	{
		return no;
	}
	void getd()
	{
		cout<<"Enter Date of appointment as required by you again ";
		gets(date);
	}
	void putdata();
};
void hosdata::getdata()
{
	cout<<"Enter Name of Patient: ";
	gets(name);
	cout<<"Enter the Patient Number: ";
	cin>>no;
	cout<<"Default Date of Appointment/Record Date set as today\n";
	_strdate(date);
	cout<<"Remarks ";
	gets(purpose);
}

void hosdata::putdata()
{
	cout<<"PATIENT NAME: ";
	puts(name);
	retno();
	cout<<"DATE OF LAST VISIT: "<<date<<endl;
	cout<<"REMARKS: ";
	puts(purpose);
}
 void main()
 {
	clrscr();
	int x;
	char ch='y',c;
    hosdata s;
    do
    {
    clrscr();
    textcolor(12);
    cout<<"                    WELCOME TO GANGWANI HOSPITAL"<<endl<<endl;
    cout<<endl<<"                     MENU"<<endl;
    cout<<endl<<"1)ENTER NEW RECORD ENTRY"<<endl;
    cout<<"2)SEARCH RECORD DETAILS"<<endl;
    cout<<"3)MODIFY RECORD"<<endl;
    cout<<"4)DISPLAY DETAILS OF ALL PATIENTS"<<endl;
    cout<<"5)BOOK AN APPOINTMENT"<<endl<<endl;
    cin>>x;
    if (x==1)
    {
    sound(500);
    delay(500);
    nosound();
    clrscr();
    fstream fil("hospital.dat",ios::app|ios::out|ios::binary);
     while(ch=='y'||ch=='Y')
   {
   s.getdata();
   fil.write((char * )&s,sizeof(s));
   cout<<endl;
   cout<<"Do you want to enter more records ? "<<endl;
   cin>>ch;
   if(ch == 'y' || ch == 'Y')
   {
    cout<<endl;
   }
   }
   fil.close();
	}
    else if(x==2)
    {
	sound(350);
	delay(500);
	nosound();
	hosdata s1;
	textcolor(10);
	clrscr();
	fstream file;
	file.open("hospital.dat",ios::in | ios::binary);
	cout<<"Enter the Patient Number you want to search for ";
	int nu,pos;
	cin>>nu;
	char r='n';
	while( file.read((char *)&s1,sizeof(s1)))
   {
    if(s1.retno()==nu)
   {
      r='f';
      cout<<endl;
	  s1.putdata();
	}
    }
     file.close();
     if(r=='n')
     {
	cout<<endl;
	cout<<"RECORD FOUND"<<endl;
	 }
}
    else if(x==3)
    {
    sound(400);
    delay(500);
    nosound();
    textcolor(14);
    clrscr();
    hosdata s2;
    fstream fi;
    fi.open("hospital.dat",ios::in | ios::out | ios::binary);
    cout<<"Enter the Patient Number whose record is to be modified \n";
     int num;
     cin>>num;
     char confirm='n';
   while( fi.read((char *)&s2,sizeof(s2)))
   {
    if(s2.retno()==num)
   {
    cout<<endl;
    s2.putdata();
    cout<<"Are you sure you want to modify this ";
    cin>>confirm;
    if(confirm=='y'||confirm=='Y')
	    {
		cout << "\nEnter the new details of Patient "<<endl;
	    s2.getdata();
	    int pos = -1 * sizeof(s2);
	    fi.seekp(pos, ios::cur);
		fi.write((char*)&s2, sizeof(s2));
		}
	}
   }
  fi.close();
	}
	else if(x==4)
	{
		 sound(600);
		 delay(500);
		 nosound();
		 textcolor(12);
		 clrscr();
		 char ch;
		 hosdata h;
		 fstream fin;
		 fin.open("hospital.dat",ios::binary | ios::in);
		 fin.read((char *)&h,sizeof(h));
		 do
		 {
			clrscr();
			h.putdata();
			cout<<endl<<"PRESS N AND THEN ENTER TO DISPLAY NEXT PATIENT'S DETAILS ";
			cin>>ch;
		 }while(fin.read((char *)&h,sizeof(h)) && ch == 'n');
	if(!fin.eof())
	{
	 cout <<"YOU HAVE CLOSED THE FILE"<<endl;
	}
	else
	{
	cout<<"YOU HAVE REACHED END OF FILE"<<endl;
	}
	fin.close();
	}
	else if(x==5)
	{
		sound(550);
    		delay(500);
    		nosound();
		textcolor(13);
		clrscr();
		hosdata s3;
		int flag=0;
		char h;
		cout<<"Do You have a Patient No. ? ";
		cin>>h;
		if(h=='n'||h=='N')
		{
			int m;
			fstream f("hospital.dat",ios::app|ios::out|ios::binary);
			s3.getdata();
	    f.write((char * )&s3,sizeof(s3));
	    f.close();
	    cout<<"Enter your Patient Number ";
	    cin>>m;
	    cout<<"When do you want the appointment write the date ";
			char d[10];
			gets(d);
	    fstream fo;
	    fo.open("hospital.dat",ios::in | ios::out | ios::binary);
	     while( fo.read((char *)&s,sizeof(s)))
	   {
	      if(strcmp(s.date,d)==0)
	      {
			    cout<<"Appointment not Possible at this Date\n";
			    flag=1;
				break;
			  }
		    }
		    if (flag==0)
		    {
			     cout<<"Appointment confirmed\n";
		    }
		   fo.close();
		}
		else
		{
		  int m;
		  cout<<"Enter your Patient Number ";
	    cin>>m;
	    cout<<"When do you want the appointment write the date ";
			char d[10];
			int flag=0;
			gets(d);
	    fstream fo;
	    fo.open("hospital.dat",ios::in | ios::out);
	     while( fo.read((char *)&s,sizeof(s)))
	   {
	      if(strcmp(s.date,d)==0)
	      {
			    cout<<"Appointment not Possible at this Date\n";
			    flag=1;
				break;
			  }
		    }
		    if (flag==0)
		    {
		       cout<<"\nAppointment Confirmed\n";
		    }
		   fo.close();
		}
		}
		cout<<endl<<"ENTER Y TO RELOAD MENU AGAIN ";
		cin>>c;
}while(c=='Y'||c=='y');
    getche();
}
