  #include<iostream>
#include<fstream>
#include<ctime>
#include<bits/stdc++.h>

using namespace std;

class shopping
{ 
private:
	int pcode;
	float price;
	float gst;
	string pname;
	string cname;
	//char t[9];
	public:
		int  menu();
		int adminitrastor();
		int buyer();
		int add();
		int edit();
		int rem();
		int list();
		int receipt();
};
 int  shopping::menu()
{
	int choice;
	string email;
	string password;
	 cout<<" \n           MAIN MENU           \n";
	 cout<<" \n              1.administrator   \n";
	 cout<<" \n              2.buyer   \n";
	 cout<<" \n              3.exit   \n";
	 cout<<" please select:    ";
	 cin>>choice;
	 
	 switch(choice)
	 { 
	    m:
	 	case 1:
	 		cout<<"  please login  \n";
	 		cout<<" enter  email  \n";
	 		cin>>email;
	 		cout<<" enter  password \n";
	 		cin>>password;
	 		if(email=="ourshop@gmail.com"&& password=="shop@123")
	 		{
	 			adminitrastor();
	 			
			 }
			 else
			 {
			 	cout<<" \n invalid email and password \n";
			 	
			 }
			 break;
			 
		case 2:
			{
				buyer();
			}
			
		case 3:
		     exit(0);
		     
		default:
			cout<<"/n please select from above option\n";
			  
	 }
	 goto m;
	 
}  

int shopping::adminitrastor()
{   
    m:
	int choice;
	cout<<"\n      administractor menu     \n ";
	cout<<"\n       1.add the product          \n";
	cout<<" \n      2.modify product                             \n";
	cout<<"\n       3.delete product            \n "   ;
	cout<<"\n       4.back to main menu    \n";
	cout<<"\n please enter above option  \n ";
	cin>>choice;
	switch(choice)
	{
		case 1:
			add();
			break;
		case 2:
		   edit();
		   break;
		case 3:
		   rem();
		   break;
		 case 4:
		 menu();
		 break;
		 default:
		 cout<<"invalid input"	;
	}
	goto m;	
 }
int shopping::buyer()
{  
    m:
	int choice;
    fstream ccname;
	cout<<" \n add the product to card \n";
	cout<<"    1.buy product \n";
	cout<<"    2.go back      \n";
	cout<<"    enter your choice:   ";
	cin>>choice;
		cout<<"\n enter your name\n ";
	    cin>>cname;
	
	switch(choice)
	{
	   case 1:
	      receipt();
	       break;
	       
	    case 2:
		 menu();
		 break;
		default:
			cout<<"\n invalid choice  \n";
			
	}
	goto m;
}
int shopping::add()
{  
     m:
	fstream data;
	int c; 
	int token=0;
	float p;
	float d;
	string n;
	cout<<"      \n add new product  \n" ;
	
	cout<<"\n       product code of the product \n ";
	cin>>pcode;
	cout<<" \n      name of product    \n";
	cin>>pname;
	cout<<"\n       price of product  \n";
	cin>>price;
	cout<<" \n      GST on product   \n";
	cin>>gst;
	 data.open("datastore1.txt",ios::in);//open file in reading mode
	 if(!data)
	 {
	 	data.open("datastore1.txt",ios::app| ios::out);  //open file in append and writing mode(ering data to file)
	 	data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<gst<<"\n";
	 	data.close();
	 	
	 }
	else
	{
		data>>c>>n>>p>>d;
		 while(!data.eof())
		 {
		 	if(c==pcode)
		 	{
		 		token++;
		 		
			 }
			 data>>c>>n>>p>>d;
		 }
		 data.close();
		 
		 if(token==1)
		 {
		 	goto m;
		 }
		 else
		 {
		 	
	 	   data.open("datastore1.txt",ios::app| ios::out);
	     	data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<gst<<"\n";
	    	data.close();
		 }
	}
	cout<<"\n input recorded\n";
}
int shopping::edit()
{
	fstream data,data1;
	int pkey;
	int token=0;
	int c;
	float p;
	float d;
	string n;
	cout<<"\n  modify the record \n";
	cout<<"\n  product code: ";
	cin>>pkey;
	data.open("datastore1.txt",ios::in);
	if(!data)
	{
		cout<<" flie doesnt found \n";
		
	}
	else
	{
		data1.open("database1.txt",ios::app|ios::out);
		data>>pcode>>pname>>price>>gst;
		while(!data.eof())
		{
			if(pkey==pcode)
			{
			 cout<<"\n product new code :";
			 cin>>c;
			  cout<<"\n product new name :";
			 cin>>n;
			  cout<<"\n product new price :";
			 cin>>p;
			  cout<<"\n product gst :";
			 cin>>d;
			 data1<<" "<<c<<""<<n<<""<<p<<""<<d<<"\n";
			 cout<<"record edited";
			 token++;
			}
			else{
				data1<<" "<<pcode<<""<<pname<<" "<<price<<" "<<gst<<"\n";	
			}
			data>>pcode>>pname>>price>>gst;
			
		}
		data.close();
		data1.close();
		remove("datastore1.txt");
		rename("database1.txt","datastore1.txt");
		if(token==0)
		{
			cout<<" \n \n sorry record not found";
		}
	}
}
int shopping::rem()
{
	fstream data,data1;
	int pkey;
	int token=0;
	cout<<"\n    delete product \n";
	cout<<"\n    product code   \n";
	cin>>pkey;
	data.open("datastore1.txt",ios::in);
	if(!data)
	{
	  cout<<"\n file not found\n";
	  
	}
	else
	{
		data1.open("database1.txt",ios::app|ios::out);
		data>>pcode>>pname>>price>>gst;
		while(!data.eof())
		{
			if(pcode==pkey)
			{
				cout<<"\n \n product deleted succesfully";
				token++;
			}
			else
			{
				data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<gst<<"\n";
				
			}
			data>>pcode>>pname>>price>>gst;
		}
		data.close();
		data1.close();
		remove("datastore1.txt");
		rename("database1.txt","datastore1.txt");
		if(token==0)
		{
		 cout<<"\n\n record not found";
		 
		}
	}
	
}
int shopping::list()
{
	fstream data;
	data.open("datastore1.txt",ios::in);
	cout<<"\n\n                                                   \n";
	cout<<"prono  \t  name  \t price  \n";
	cout<<"\n\n                                                   \n";
	data>>pcode>>pname>>price>>gst;
	while(!data.eof())
	{
		cout<<pcode<<"  "<<pname<<"  "<<price<<"  "<<gst<<"\n";
		data>>pcode>>pname>>price>>gst;
	}
	data.close();
		
}
int shopping::receipt()
{ 
    m:
	fstream data;
	int arrc[100];
	int arrq[100];
	char choice,Y;
	int c=0;
	float amount=1;
	float dis=0;
	float total=0;
	time_t now=time(0);
	char* dt=ctime(&now);
   //	cout<<"\n\n\n     \t\t\t\t\t RECEIPT ";
	data.open("datastore1.txt",ios::in);
	if(!data)
	{ 
	 cout<<"\n\n empty";
	
	}
	else
	{
		data.close();
		list();
		cout<<"\n \t\t  * PLEASE PLACE THE ORDER *                     \n";
	
		do
		{
			
			cout<<"enter product code\n";
			cin>>arrc[c];
			cout<<"enter product quantity\n";
			cin>>arrq[c];
			for(int i=0;i<c;i++)	
			{
				if(arrc[c]==arrc[i])
				{
					cout<<"duplicate product code,please try again\n";
					goto m;
				}
			}
			c++;
			cout<<"\n do you want to order another product ,press Y for yes and N for no\n";
			cin>>choice;
			
		}
		while(choice == 'y');
		cout<<"\n\n\t\t\t\t\t\t**** RECEIPT ****   \n";
		cout<<"\n\t\t\t\t\t name:"<<cname<<"t\t\t\t\t\t"<<dt;
		cout<<"\n \t productno.\t prodcutname\t productqua price\t  gst \n";
	//	for(int i=0;i<c;i++)
	//	{
			data.open("datastore1.txt",ios::in);
			data>>pcode>>pname>>price>>gst;
			while(!data.eof())
			{
					for(int i=0;i<sizeof(c);i++)
	            {
				if(pcode==arrc[i])
				{
					amount=0;
					amount= amount+(price*arrq[i]);
					gst=(amount*gst/1000);
					total= total+(amount+(amount*gst));
					cout<<"  \t "<<pcode<<"  \t\t"<<pname<<" \t\t "<<arrq[i]<<"  \t"<<price<<" \t \t"<<gst<<"\n";
					
				}
				data>>pcode>>pname>>price>>gst;
				//total= total+(amount*gst);
			}
			    	data.close();			 	
		}
			
	}
	if(total>1000)
	{
	   total=total-(total*0.1);
	}
	cout<<"\n\n        ";
	cout<<"\n\t\t\t\t your total  :"<<total;
	cout<<"\n\t\t\t\t THANK YOU";
//} 
}

  int main() 
  {
  	shopping s;
  	 s.menu();
  }
