#include <iostream>
#include<graphics.h>
#include<math.h>
using namespace std;
class figure
{
	float length,delx,dely;
	int d,h,xc,yc;
public:
void drawline(float x1,float y1,float x2,float y2)
{
	float x,y;
	if(abs(x2-x1)>=abs(y2-y1))
	{
	length=abs(x2-x1);
	}
	else
		length=abs(y2-y1);

	delx=(x2-x1)/length;
	dely=(y2-y1)/length;

	x=x1+0.5;
	y=y1+0.5;

	putpixel(floor(x),floor(y),RED);

	int i=1;
	while(i<=length)
	{
	x=x+delx;
	y=y+dely;
	i=i+1;
	putpixel(floor(x),floor(y),RED);
	}	
}
void drawcircle(int r,int xc,int yc)
{
	int x,y;
	d=3-2*r;
	x=0;
	y=r;
	do
	{
	putpixel(x+xc,y+yc,RED);
	putpixel(y+xc,x+yc,RED);
	putpixel(y+xc,-x+yc,RED);
	putpixel(x+xc,-y+yc,RED);
	putpixel(-x+xc,-y+yc,RED);
	putpixel(-y+xc,-x+yc,RED);
	putpixel(-y+xc,x+yc,RED);
	putpixel(-x+xc,y+yc,RED);
	if(d<0)
	{
	d=d+4*x+6;
	x=x+1;
	}
	else
	{
	d=d+4*(x-y)+10;
	y=y-1;
	x=x+1;
	}
	}while(x<=y);
}
void fig(float xmin,float ymin,float xmax,float ymax)
{
	float r,a,b,c,temp;
	a=xmax-xmin;
	b=ymax-ymin;
	temp=pow(a,2)+pow(b,2);
	c=sqrt(temp);
	r=a*b/(2*c);
	drawline(((xmin+xmax)/2),ymin,xmin,((ymin+ymax)/2));
	drawline(xmin,((ymin+ymax)/2),((xmin+xmax)/2),ymax);
	drawline(((xmin+xmax)/2),ymax,xmax,((ymin+ymax)/2));
	drawline(xmax,((ymin+ymax)/2),((xmin+xmax)/2),ymin);
	drawcircle(r,((xmin+xmax)/2),((ymin+ymax)/2));
	
}
};
int main()

{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,NULL);
	float xmin,xmax,ymin,ymax;
	cout<<"Enter window boundaries:";
	cout<<"Enter bottom left coordinates respectively:";
	cin>>xmin>>ymax;
	cout<<"Enter top right coordinates respectively:";
	cin>>xmax>>ymin;
	setcolor(DARKGRAY);
	rectangle(xmin,ymin,xmax,ymax);
	figure f1;
	f1.fig(xmin,ymin,xmax,ymax);
	getch();
	closegraph();
	return 0;	
}
/*Test Coordinates
200,400
400,200
*/
