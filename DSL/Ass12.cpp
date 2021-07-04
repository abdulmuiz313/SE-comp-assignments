#include<iostream> 
using namespace std;

 
void init();
void insert_r(); 
void insert_f(); 
int del_r();
int del_f(); 
int full_r(); 
int full_f(); 
int isempty();
void display();
int a[5],f,r,size=5; 
void init()
{
	f=-1;
	r=-1;
}

void insert_r()
{
	int x;
	if(!full_r())
	{
		cout<<"Enter data:"; cin>>x;
		r=r+1; a[r]=x;
		if(f==-1)
		{
			f=0;
		}
		display();
	}
	else
	{
		cout<<"Queue is full\n";
	}
}

void insert_f()
{
	int x;
	if(!full_f())
	{
		cout<<"Enter data:"; cin>>x;
		if(f==-1)
		{
			f=r=0;
		}
		else
		{
			f=f-1;
		}
		a[f]=x; 
		display();
	}	
	else
	{
		cout<<"Queue is full\n";
	}
}

int del_f()
{	
	int x; 
	if(!isempty())
	{
		x=a[f];
		cout<<"\n Element deleted = "<<x;
		if(f==r)
		{
			f=-1;
			r=-1;
		}	
		else
		{
			f=f+1; display();
		}
	}
	else
	{
		cout<<"Queue is empty\n";
	}
	
	return x;
}

int del_r()
{
	int x; 
	if(!isempty())
	{
		x=a[r];
		cout<<"\n Element deleted = "<<x;
		if(r==f)
		{
			f=-1;
			r=-1;
		}
		else
		{
			r=r-1; display();
		}
	}
	else
	{
	cout<<"Queue is empty\n";
	}
return x;
}

int full_f()
{
	if(f==0)
		return 1;
	return 0;
}

int full_r()
{
	if(r==size-1)
		return 1;
	return 0;
}


int isempty()
{
	if(f==-1)
	{return 1;}	
	return 0;
}

void display()
{
	int i; 
	cout<<"\nQueue="; 
	for(i=f;i!=r;i=i+1)
	{
		cout<<"\t"<<a[i];
	}
	cout<<"\t"<<a[i];
}
int main()
{
 int ch,x; 
 init(); 
 while(1)
{
	cout<<"\n\nMenu\n1.Insert at Front\n2.Insert at Rear" "\n3.Delete at Front\n4.Delete at rear" "\n5.Exit\nEnter choice:";
	cin>>ch; 
	switch(ch)
	{
	case 1:insert_f();
		break; 
	case 2:insert_r();
		break; 
	case 3:del_f();
		break; 
	case 4:del_r();
		break; 
	case 5:	
	return 0;
	}
}
	
}
/*Output:


Menu
1.Insert at Front
2.Insert at Rear
3.Delete at Front
4.Delete at rear
5.Exit
Enter choice:1
Enter data:1

Queue=  1

Menu
1.Insert at Front
2.Insert at Rear
3.Delete at Front
4.Delete at rear
5.Exit
Enter choice:2
Enter data:2

Queue=  1       2

Menu
1.Insert at Front
2.Insert at Rear
3.Delete at Front
4.Delete at rear
5.Exit
Enter choice:4

 Element deleted = 2
Queue=  1

Menu
1.Insert at Front
2.Insert at Rear
3.Delete at Front
4.Delete at rear
5.Exit
Enter choice:3

 Element deleted = 1

Menu
1.Insert at Front
2.Insert at Rear
3.Delete at Front
4.Delete at rear
5.Exit
Enter choice:4
Queue is empty


Menu
1.Insert at Front
2.Insert at Rear
3.Delete at Front
4.Delete at rear
5.Exit
Enter choice:5
NAME:Abdulmuiz
R.N.:62*/
