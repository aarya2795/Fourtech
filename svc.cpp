//============================================================================
// Name        : svc.cpp
// Author      : nisha
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>

using namespace std;


typedef struct fileVersion
{
	int n; //version number
	char line[10];

	struct fileVersion *link; //link to the next file version
}fileVersion;

class svc
{
	fileVersion *version,*first;
	fstream fp;
	int num;
    public:
	       svc()
	       {

	    	   first=0;
	    	   num=0;
	    	   version=new fileVersion;
	    	   version->link=NULL;
	    	   version->n=1;


	       }
	       void append();
	       void del();
	       void display(int);

};


void svc :: append()
{
	fileVersion *v=new fileVersion;
	cout<<"\n Enter the line to append :";
	cin>>v->line;


	num++;
	v->link=NULL;
	fp.open("test.txt",ios::out|ios::app);
	fp<<"\n"<<v->line;
    v->n=num;
	if(num==1)
	{
		version=v;
		first=version;
	}
	else
		{
		  version->link=v;
		  version=v;
		}
	cout<<"\n Successfully committed!";
	fp.close();
}

void svc :: display(int no)
{
	int count=0;
	fileVersion *temp=new fileVersion;
	fileVersion *temp1=new fileVersion;
	temp=first;
	temp1=first;
	cout<<"Version No:"<<no;
	do
		{
			if(count==0)
			{
				fp.open("test.txt",ios::out|ios::trunc);
				fp<<temp->line;

			}
			else
			{
				fp.open("test.txt",ios::app);
				fp<<temp->line;

			}

			cout<<"\n"<<temp->line;
			temp1=temp;
			temp=temp->link;

			count++;
//			fp.close();
	}	while(temp1->n!=no);

}

int main()
{
	int option;
	int fvno;
	char ans='y';
	svc SVC;
	while(ans=='y'||ans=='Y')
	{
		 cout<<"\n ** SIMPLE VERSION CONTROL **";
	     cout<<"\n ~MENU~ \n";
	     cout<<"\n 1.Append a line\n 2.Delete a line\n 3.Display Contents of Nth version";
	     cout<<"\n Enter your option::";
	     cin>>option;
	     switch(option)
	     {
	        case 1:  SVC.append();
	                 break;
	        case 2: // svc.del();
	                 break;
	        case 3:  cout<<"\n Enter version of file you want to display :";
	                 cin>>fvno;
	                 SVC.display(fvno);
	                 break;
	     }
	     cout<<"\n Do you want to continue?(y/n)";
	     cin>>ans;
	}
	return 0;
}
