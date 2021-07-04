/*
Pizza parlour accepting maximum M orders. Orders are served in first come first served
basis. Order once placed cannot be cancelled. Write C++ program to simulate the system
using circular queue using array.
*/

#include <iostream>
using namespace std;
#define morder 5
class pizza
{
    int porder[morder];
    int front,rear;
public:
    pizza()
    {
     front=rear=-1;
    }
    
    int queuefull()
    {
     if((front==0)&&(rear==(morder-1))||(front==(rear+1)%morder))
         return 1;
     else
         return 0;
    }
    
    int qempty()
    {
        if(front==-1)
            return 1;
        else
            return 0;
    }
    void order(int);
    void pay(int);
    void o_in_queue();
};


void pizza::order(int item)
{
    if(queuefull())
        cout<<"\nVery Sorry !!!! No more orders....\n";
    else
    {
        if(front==-1)		//empty case
        {
            front=rear=0;		//front++ rear++
        }
        else
        {
            rear=(rear+1)%morder;
        }
        porder[rear]=item;
    }
}

void pizza::pay(int nos)
{
    int item;
    char ans;
    if(qempty())
        cout<<"\nSorry !!! There are no pending orders....\n";
    else
    {
      cout<<"\nDeliverd orders as follows...\n";
      for(int i=0;i<nos;i++)
      {
          item=porder[front];
          if(front==rear)
          {
               front=rear=-1;		//go to initial state again.
          }
          else
          {
              front=(front+1)%morder;
          }
          cout<<"\t"<<item;
      }
      cout<<"\nTotal amount to pay = "<<nos*100;
      cout<<"\nThank you visit Again....\n";
    }
}

void pizza::o_in_queue()
{
    int temp;
    if(qempty())
    {
        cout<<"\nSorry !! There is no pending order...\n";
    }
    else
    {
        temp=front;
        cout<<"\nPending Order as follows..\n";
        while(temp!=rear)
        {
            cout<<"\t"<<porder[temp];
            temp=(temp+1)%morder;
        }
        cout<<"\t"<<porder[temp];
    }
}


int main()
{
    pizza piz;
    int ch,pc,nos;
    do
    {
     cout<<"\t------ Welcome To Pizza Parlor ------\n";
     cout << "\n1.Give order\n2.Payment\n3.Pending Orders\n4.Exit";
     cout<<"\nEnter your choice: ";
     cin>>ch;
     switch(ch)
     {
      case 1:cout<<"\nWhich Pizza You would like to order\n";
             cout<<"\n1.Pasta Pizza\n2.Double Cheeze Pizza\n3.Chicken Cheeze Pizza";
             cout<<"\nPlease enter your order: ";
             cin>>pc;
             piz.order(pc);
             break;
             
      case 2:cout<<"\nHow many Pizza do you want?";
             cin>>nos;
             piz.pay(nos);
             break;
             
             
      case 3:cout<<"\n Following orders are in queue to deliver....as follows..\n";
             piz.o_in_queue();
             break;
     }
    }while(ch!=4);

    return 0;
}
/*Output:
        ------ Welcome To Pizza Parlor ------

1.Give order
2.Payment
3.Pending Orders
4.Exit
Enter your choice: 1

Which Pizza You would like to order

1.Pasta Pizza
2.Double Cheeze Pizza
3.Chicken Cheeze Pizza
Please enter your order: 2
        ------ Welcome To Pizza Parlor ------

1.Give order
2.Payment
3.Pending Orders
4.Exit
Enter your choice: 1

Which Pizza You would like to order

1.Pasta Pizza
2.Double Cheeze Pizza
3.Chicken Cheeze Pizza
Please enter your order: 1
        ------ Welcome To Pizza Parlor ------

1.Give order
2.Payment
3.Pending Orders
4.Exit
Enter your choice: 2

How many Pizza do you want?1

Deliverd orders as follows...
        2
Total amount to pay = 100
Thank you visit Again....
        ------ Welcome To Pizza Parlor ------

1.Give order
2.Payment
3.Pending Orders
4.Exit
Enter your choice: 3

 Following orders are in queue to deliver....as follows..

Pending Order as follows..
        1       ------ Welcome To Pizza Parlor ------

1.Give order
2.Payment
3.Pending Orders
4.Exit
Enter your choice: 4
NAME:Abdulmuiz 
RN.:62*/

