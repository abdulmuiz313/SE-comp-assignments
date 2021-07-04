#include <iostream>
using namespace std;

class node
{
	bool bit;
	node *next,*prev;
	friend class bl;
};

class bl
{
	node *head1,*head2,*head3;
	public:
		void rnumbers();
		node *create(node *temp);
		void printnumbers();
		void print(node *temp);
		void complement();
		void comp1(node *temp);
		node *comp2(node *temp);
		void add();
		node *addnos(node *temp1,node *temp2);
		bl()
		{
			head1=head2=head3=NULL;
		}
};

void bl::rnumbers()
{
	cout<<"\nEnter first binary no.\n";
	head1=create(head1);
	cout<<"\nEnter second binary no.\n";
	head2=create(head2);
}

node *bl::create(node *temp)
{
	int n;
	node *last,*p;
	cout<<"\nEnter total no. of bits\n";
	cin>>n;
	
	for (int i=0;i<n;i++)
	{
		p= new node;
		cout<<"Enter bit value\n";
		cin>>p->bit;
		p->prev=NULL;
		p->next=NULL;
		
		if (temp==NULL)
		{
			temp=p;
			last=p;
		}
		else 
		{
			last->next=p;
			p->prev=last;
			last=p;
		}
	}
return(temp);
}

void bl::printnumbers()
{
	cout<<"\n\nFirst no.is:\n\n\t";
	print(head1);
	cout<<"\n\nSecond no.is:\n\n\t";
	print(head2);
}

void bl::print(node *temp)
{
	if(temp==NULL){
		cout<<"\nEmpty";
	}
	else
	do 
	{
		cout<<temp->bit<<"  ";
		temp=temp->next;
	}
	while(temp!=NULL);
	
}

void bl::add()
{
	cout<<"\n\nAddition of two nos. is:\n\n\t";
	head3=addnos(head1,head2);
	print(head3);
}

node* bl::addnos(node *temp1,node *temp2)
{
	int c,sum,bit2,bit1;
	node *p;
	if(temp1!=NULL && temp2==NULL)
	{
		head3=temp1;
	}
	else if(temp1==NULL && temp2!=NULL)
	{
		head3=temp2;
	}
	else
	{
		c=0;
		sum=0;
		while(temp1->next!=NULL)
			temp1=temp1->next;
		while(temp2->next!=NULL)
			temp2=temp2->next;
		while(temp1!=NULL || temp2!=NULL)
		{
			if(temp1!=NULL)
				bit1=temp1->bit;
			else 
				bit1=0;
			if(temp2!=NULL)
				bit2=temp2->bit;
			else 
				bit2=0;
			sum=bit1+bit2+c;
			c=sum/2;
			sum=sum%2;
			
			p= new node;
			p->bit=sum;
			p->next=p->prev=NULL;			
			
			if(head3==NULL)
			{
				head3=p;
			}
			else
			{
				p->next=head3;
				head3->prev=p;
				head3=p;
			}
			if(temp1!=NULL)
				temp1=temp1->prev;
			if(temp2!=NULL)
				temp2=temp2->prev;
		}	
		if(c==1)
		{
			p=new node;
			p->bit=c;
			p->next=p->prev=NULL;
			p->next=head3;
			head3->prev=p;
			head3=p;
		}
		
	}
return head3;
}

void bl::complement()
{
	cout<<"\n\n1's Complement of first no.is:\n\n\t";
	comp1(head1);
	print(head1);
	cout<<"\n\n2's Complement of first no.is:\n\n\t";
	head1=comp2(head1);
	print(head1);
	
	cout<<"\n\n1's Complement of 2nd no.is:\n\n\t";
	comp1(head2);
	print(head2);
	cout<<"\n\n2's Complement of 2nd no.is:\n\n\t";
	head2=comp2(head2);
	print(head2);
	
}

void bl::comp1(node *temp)
{
	
	while(temp!=NULL)
	{
		if(temp->bit==1)
			temp->bit=0;
		else
			temp->bit=1;
		temp=temp->next;
	}
}
node *bl::comp2(node *temp)
{
	node *s1,*s2;
	s1=temp;
	while(temp->next!=NULL)
		temp=temp->next;
	int c, sum;
	c=1;
	
	while(temp!=NULL)
	{
		sum=temp->bit+c;
		c=sum/2;
		sum=sum%2;
		
		temp->bit=sum;
		temp=temp->prev;
	}
	
	if(c==1)
	{
		s2=new node;
		s2->bit=c;
		s2->prev=NULL;
		s2->next=s1;
		s1->prev=s2;
		s1=s2;
	}
	return(s1);
}

int main()
{
	bl newobj;
	newobj.rnumbers();
	newobj.printnumbers();
	newobj.add();
	newobj.complement();
	
	return 0;
}
