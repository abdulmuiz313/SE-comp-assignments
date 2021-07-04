/*Department of Computer Engineering has student's club named 'Pinnacle Club'. 
Students of  second,  third  and  final  year  of  department can  be  granted  membership  on  request. 
Similarly one may cancel the membership of club. 
First node is reserved for president of club and last node is reserved for secretary of club. 
Write C++ program to maintain club member‘s information using singly linkedlist.  
Store  student  PRN  and  Name.  
Write functions to:
a)Add and delete the members as well as president or even secretary.
b)Compute total number of members of club
c)Display members
d)Two linked lists exists for two divisions. 
Concatenate two lists*/
#include<iostream>
using namespace std;
 
typedef struct stud
{
	int PRN; char name[20];
}stud;
typedef struct node
{
	stud s;
	struct node *next;
}node;
node *createnode()
{
	int i,n,cnt=0;
	node *p,*head,*t,*st; 
	head=NULL;
	cout<<"\n Enter the no of nodes:"; 
	cin>>n;
	for(i=0;i<n-1;i++)
	{
		p=new node;
		if (head==NULL)
		{
			cout<<"\n Enter the data for President"; 
			cout<<"\n\n Enter PRN number:"; 
			cin>>p->s.PRN;
			cout<<"\n Enter the name:"; 
			cin>>p->s.name;
			p->next=NULL; 
			head=p;

			cnt++;
		}
		else
		{
		cout<<"\n Enter the data for members"; 
		cout<<"\n\n Enter PRN number:"; 
		cin>>p->s.PRN;
		cout<<"\n Enter the name:"; 
		cin>>p->s.name;
		t=head;
		while(t->next!=NULL) 
			t=t->next;
			t->next=p; cnt++;
		}
	}
	st=new node;
	cout<<"\n Enter the data for Secretary"; 
	cout<<"\n\n Enter PRN number:"; 
	cin>>st->s.PRN;
	cout<<"\n Enter the name:"; 
	cin>>st->s.name;
	t=head;
	while(t->next!=NULL) 
		t=t->next;
		t->next=st; return head;
	}
	void print(node *head)
	{
		node *p; int cnt=0; p=head;
		cout<<"\n ======Club data====="; 
		while(p!=NULL)
		{
			cout<<"\n PRN number: "<<p->s.PRN<<"\n Name: "<<p->s.name<<"====>";
			p=p->next; 
			cnt++;
		}
		cout<<"\n Total no of nodes="<<cnt;
	}
	node *insertb(node *head)
	{
	node *p; p=new node;
	cout<<"\n Enter the data of student"; 
	cout<<"\n\n Enter PRN number:"; 
	cin>>p->s.PRN;
	cout<<"\n Enter the name:"; 
	cin>>p->s.name; 
	if(head==NULL)
	{
		head=p; 
		return p;
	}
	p->next=head; head=p; 
	return head;
	}
	node *insertl(node *head)
	{
		int loc;
		int flag;
		node *p,*q;
		cout<<"\n Enter the PRN after which you want to add:";
		cin>>loc; 
		p=new node;
		cout<<"\n Enter the data of student"; 
		cout<<"\n\n Enter PRN number:"; 
		cin>>p->s.PRN;
		cout<<"\n Enter the name:"; 
		cin>>p->s.name; 
		flag=0;
		if(head==NULL)
		{
			head=p; 
			return p;
		}
		q=head;
		while(q!=NULL)
		{
			if(q->s.PRN==loc)
			{
				flag=1;break;
			}
			q=q->next;
		}
		if(flag==1)
		{
			p->next=q->next;
			q->next=p;
		}
		return head;
	}
	node *inserte(node *head)
	{
		node *p,*q;  
		p=new node;
		cout<<"\n Enter the data of student"; 
		cout<<"\n\n Enter PRN number:"; 
		cin>>p->s.PRN;
		cout<<"\n Enter the name:"; 
		cin>>p->s.name;
		p->next=NULL;
		q=head; 
		while(q->next!=NULL)
			q=q->next;
		q->next=p;
		
	}
	
	node *delb(node *head)
	{
		node *p; 
		if(head==NULL)
		{
			cout<<"\n List is empty"; 
			return head;
		}
	p=head; 
	head=head->next; 
	p->next=NULL; 
	delete p;
	return head;
	}
node *dele(node *head)
{
	node *p,*q;
	if(head==NULL)
	{
		cout<<"\n list is empty"; return head;
	}
	for(q=head;q->next->next!=NULL;q=q->next);
	p=q->next;
	q->next=NULL; 
	delete p;
	return head;
}
node *dell(node *head,int loc)
{
	node *p,*q; 
	int i;
	if (head==NULL)
	{
		cout<<"list is empty"; return head;
	}
	if(loc==1)
	{
		p=head; 
		head=head->next; 
		p->next=NULL; 
		delete p;
		return head;
	}
	q=head; 
	for(i=1;i<loc-1;i++) 
	if(q->next!=NULL) q=q->next;
	else
	{
		cout<<"Underflow"; return head;
	}
	p=q->next;
	q->next=p->next; p->next=NULL; delete p;
	return head;
}
node *reverse(node *head)
{
	node *p,*q,*r; 
	p=NULL;
	q=head; 
	r=q->next;
	while(q!=NULL)
	{
		q->next=p; p=q;
		q=r; 
		if(q!=NULL)
		r=q->next;
	}
	return p;
}
void concat(node *head1,node *head2)
{
	node *p,*q; p=head1; q=head2;
	while(p->next!=NULL) p=p->next;
	p->next=head2; print(head1);
}
node *tnos(node *head)
{
	node *p;
	int cnt=1;
	p=head;
	while(p->next!=NULL)
	{
		p=p->next;
		cnt++;
	}
	cout<<"\n"<<cnt;
	
}
int main()
{
	node *head, *head1, *head2; head= NULL;
	int ch,ele,loc; 
	head=NULL; 
	head1=head2=NULL; 
	while(ch!=12){
	cout<<"\n ========== Pinnacle club ======= \n ";
	cout<<"\n 1.Create \n 2.Print \n 3.Insert New President \n 4.Insert New Secretary\n 5.Insert Member";
	cout<<"\n 6.Delete President \n 7.Delete Secretary \n 8.Delete member \n 9.Reverse \n 10.Concatenate \n 11.Total no. of members \n 12.Exit"; 
	cout<<"\n Enter ur choice:";

	cin>>ch;
	switch(ch)
	{
	case 1: head=createnode();               //CODE 
			break;
	case 2: print(head); 		                   //BY
			break;
	case 3: head=insertb(head);                         //Abdulmuiz 
			break;
	case 4: head=inserte(head); 
			break;
	case 5:	head=insertl(head);
			break;
	case 6: head=delb(head); 
			break;
	case 7: head=dele(head); 
			break;
	case 8: cout<<"\n Enter location to delete:";
			cin>>loc; 
			head=dell(head,loc);
			break;
	case 9: head=reverse(head); 
			break;
	case 10: cout<<"\n========================Data for DivA==========================";
			 head1=createnode();
			 cout<<"\n=========================Data for DivB=========================";
			 head2=createnode(); 
			 concat(head1,head2);
			 break;
	case 11: cout<<"Total no. of members in club are:";
			 head=tnos(head);
			 break;
	}
}
return 0;
}
/*Output:
 ========== Pinnacle club =======

 1.Create
 2.Print
 3.Insert New President
 4.Insert New Secretary
 5.Insert Member
 6.Delete President
 7.Delete Secretary
 8.Delete member
 9.Reverse
 10.Concatenate
 11.Total no. of members
 12.Exit
 Enter ur choice:1

 Enter the no of nodes:3

 Enter the data for President

 Enter PRN number:1

 Enter the name:A

 Enter the data for members

 Enter PRN number:2

 Enter the name:B

 Enter the data for Secretary

 Enter PRN number:3

 Enter the name:C

 ========== Pinnacle club =======

 1.Create
 2.Print
 3.Insert New President
 4.Insert New Secretary
 5.Insert Member
 6.Delete President
 7.Delete Secretary
 8.Delete member
 9.Reverse
 10.Concatenate
 11.Total no. of members
 12.Exit
 Enter ur choice:2

 ======Club data=====
 PRN number: 1
 Name: A====>
 PRN number: 2
 Name: B====>
 PRN number: 3
 Name: C====>
 Total no of nodes=3
 ========== Pinnacle club =======

 1.Create
 2.Print
 3.Insert New President
 4.Insert New Secretary
 5.Insert Member
 6.Delete President
 7.Delete Secretary
 8.Delete member
 9.Reverse
 10.Concatenate
 11.Total no. of members
 12.Exit
 Enter ur choice:6

 ========== Pinnacle club =======

 1.Create
 2.Print
 3.Insert New President
 4.Insert New Secretary
 5.Insert Member
 6.Delete President
 7.Delete Secretary
 8.Delete member
 9.Reverse
 10.Concatenate
 11.Total no. of members
 12.Exit
 Enter ur choice:2

 ======Club data=====
 PRN number: 2
 Name: B====>
 PRN number: 3
 Name: C====>
 Total no of nodes=2
 ========== Pinnacle club =======

 1.Create
 2.Print
 3.Insert New President
 4.Insert New Secretary
 5.Insert Member
 6.Delete President
 7.Delete Secretary
 8.Delete member
 9.Reverse
 10.Concatenate
 11.Total no. of members
 12.Exit
 Enter ur choice:7

 ========== Pinnacle club =======

 1.Create
 2.Print
 3.Insert New President
 4.Insert New Secretary
 5.Insert Member
 6.Delete President
 7.Delete Secretary
 8.Delete member
 9.Reverse
 10.Concatenate
 11.Total no. of members
 12.Exit
 Enter ur choice:2

 ======Club data=====
 PRN number: 2
 Name: B====>
 Total no of nodes=1
 ========== Pinnacle club =======

 1.Create
 2.Print
 3.Insert New President
 4.Insert New Secretary
 5.Insert Member
 6.Delete President
 7.Delete Secretary
 8.Delete member
 9.Reverse
 10.Concatenate
 11.Total no. of members
 12.Exit
 Enter ur choice:8

 Enter location to delete:1

 ========== Pinnacle club =======

 1.Create
 2.Print
 3.Insert New President
 4.Insert New Secretary
 5.Insert Member
 6.Delete President
 7.Delete Secretary
 8.Delete member
 9.Reverse
 10.Concatenate
 11.Total no. of members
 12.Exit
 Enter ur choice:2

 ======Club data=====
 Total no of nodes=0
 ========== Pinnacle club =======

 1.Create
 2.Print
 3.Insert New President
 4.Insert New Secretary
 5.Insert Member
 6.Delete President
 7.Delete Secretary
 8.Delete member
 9.Reverse
 10.Concatenate
 11.Total no. of members
 12.Exit
 Enter ur choice:3

 Enter the data of student

 Enter PRN number:1

 Enter the name:A

 ========== Pinnacle club =======

 1.Create
 2.Print
 3.Insert New President
 4.Insert New Secretary
 5.Insert Member
 6.Delete President
 7.Delete Secretary
 8.Delete member
 9.Reverse
 10.Concatenate
 11.Total no. of members
 12.Exit
 Enter ur choice:4

 Enter the data of student

 Enter PRN number:3

 Enter the name:C

 ========== Pinnacle club =======

 1.Create
 2.Print
 3.Insert New President
 4.Insert New Secretary
 5.Insert Member
 6.Delete President
 7.Delete Secretary
 8.Delete member
 9.Reverse
 10.Concatenate
 11.Total no. of members
 12.Exit
 Enter ur choice:5

 Enter the PRN after which you want to add:1

 Enter the data of student

 Enter PRN number:2

 Enter the name:B

 ========== Pinnacle club =======

 1.Create
 2.Print
 3.Insert New President
 4.Insert New Secretary
 5.Insert Member
 6.Delete President
 7.Delete Secretary
 8.Delete member
 9.Reverse
 10.Concatenate
 11.Total no. of members
 12.Exit
 Enter ur choice:2

 ======Club data=====
 PRN number: 1
 Name: A====>
 PRN number: 2
 Name: B====>
 PRN number: 3
 Name: C====>
 Total no of nodes=3
 ========== Pinnacle club =======

 1.Create
 2.Print
 3.Insert New President
 4.Insert New Secretary
 5.Insert Member
 6.Delete President
 7.Delete Secretary
 8.Delete member
 9.Reverse
 10.Concatenate
 11.Total no. of members
 12.Exit
 Enter ur choice:9

 ========== Pinnacle club =======

 1.Create
 2.Print
 3.Insert New President
 4.Insert New Secretary
 5.Insert Member
 6.Delete President
 7.Delete Secretary
 8.Delete member
 9.Reverse
 10.Concatenate
 11.Total no. of members
 12.Exit
 Enter ur choice:2

 ======Club data=====
 PRN number: 3
 Name: C====>
 PRN number: 2
 Name: B====>
 PRN number: 1
 Name: A====>
 Total no of nodes=3
 ========== Pinnacle club =======

 1.Create
 2.Print
 3.Insert New President
 4.Insert New Secretary
 5.Insert Member
 6.Delete President
 7.Delete Secretary
 8.Delete member
 9.Reverse
 10.Concatenate
 11.Total no. of members
 12.Exit
 Enter ur choice:11
Total no. of members in club are:
3
 ========== Pinnacle club =======

 1.Create
 2.Print
 3.Insert New President
 4.Insert New Secretary
 5.Insert Member
 6.Delete President
 7.Delete Secretary
 8.Delete member
 9.Reverse
 10.Concatenate
 11.Total no. of members
 12.Exit
 Enter ur choice:9

 ========== Pinnacle club =======

 1.Create
 2.Print
 3.Insert New President
 4.Insert New Secretary
 5.Insert Member
 6.Delete President
 7.Delete Secretary
 8.Delete member
 9.Reverse
 10.Concatenate
 11.Total no. of members
 12.Exit
 Enter ur choice:2

 ======Club data=====
 PRN number: 3
 Name: C====>
 PRN number: 2
 Name: B====>
 PRN number: 1
 Name: A====>
 Total no of nodes=3
  ========== Pinnacle club =======

 1.Create
 2.Print
 3.Insert New President
 4.Insert New Secretary
 5.Insert Member
 6.Delete President
 7.Delete Secretary
 8.Delete member
 9.Reverse
 10.Concatenate
 11.Total no. of members
 12.Exit
 Enter ur choice:10

========================Data for DivA==========================
 Enter the no of nodes:3

 Enter the data for President

 Enter PRN number:1

 Enter the name:A

 Enter the data for members

 Enter PRN number:2

 Enter the name:B

 Enter the data for Secretary

 Enter PRN number:3

 Enter the name:C

=========================Data for DivB=========================
 Enter the no of nodes:2

 Enter the data for President

 Enter PRN number:4

 Enter the name:D

 Enter the data for Secretary

 Enter PRN number:5

 Enter the name:E

 ======Club data=====
 PRN number: 1
 Name: A====>
 PRN number: 2
 Name: B====>
 PRN number: 3
 Name: C====>
 PRN number: 4
 Name: D====>
 PRN number: 5
 Name: E====>
 Total no of nodes=5
 */
