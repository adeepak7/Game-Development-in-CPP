#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<dos.h>
#include<graphics.h>
#include<conio.h>
void main()
{
	int x1,y1,x2,y2,x3,y3,radius=25,angle=0,cr,gd,gm,points[5];
	char p[10]="AHIRE";
	clrscr();
	printf("\nEnter colmn:");
	scanf("%d",&x1);
	printf("\nEnter row:");
	scanf("%d",&y1);
	detectgraph(&gd,&gm);
	initgraph(&gd,&gm,"C:\\BGI");
	randomize();
	while(!kbhit())
	{
	     x2=x1+radius*cos(angle*3.142/180);
	     y2=y1+radius*sin(angle*3.142/180);
	     clrscr();
	    // rectangle(x1-(2*radius),y1-(3*radius),x1+(6*radius),y1-radius);
	     rectangle(x1-2*radius,y1,x1-radius-5,y1);
	     rectangle(x1+5*radius+5,y1,x1+6*radius,y1);
	      rectangle(x1-2*radius,y1,x1-2*radius,y1-2*radius);
	     arc(x1+4*radius,y1,0,90,2*radius);
	     int  points[]={x1-2*radius,y1-2*radius,x1,y1-4*radius,x1+3*radius,y1-4*radius,x1+4*radius,y1-2*radius,x1-2*radius,y1-2*radius};
	     outtextxy(x1+radius+5,y1-radius,p);
	     drawpoly(5,points);
	     arc(x1,y1,0,180,radius+5);
	     circle(x1,y1,radius);
	     rectangle(x1,y1,x2,y2);
	     arc(x1+4*radius,y1,0,180,radius+5);
	     rectangle(x1+radius+5,y1,x1+3*radius-5,y1);
	     circle(x1+4*radius,y1,radius);
	     rectangle(x1+4*radius,y1,x2+4*radius,y2);
	     delay(100);
	    angle+=90;
	    x1++;
	}
	getch();
	closegraph();
	return;
}

