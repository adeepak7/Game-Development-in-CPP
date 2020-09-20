#include<stdio.h>
#include<stdlib.h>
#include<dos.h>
#include<graphics.h>
#include<conio.h>
#include<string.h>
void main()
{
	int p=1,cnt=0,score=0,j,hit=0,x1=300,y1=300,cr,gd,gm,i=0,flg=0,x=1,y;
	char g[100],w[20]="Your score is ";
	clrscr();
	detectgraph(&gd,&gm);
	initgraph(&gd,&gm,"C:\\BGI");
	y=getmaxy()/2;
	randomize();
       while(p)
       {
	cnt=0;score=0;
	while(cnt<3)
       {
	flg=0;hit=0;
	while(1)
	{
	     if(kbhit()&&flg==0)
	     {
		 flg=1;
		 x=400;
	     }

	     if(flg==0)
	     {
		x=400;
		line(x,y,x+50,y);
		 line(x-10,y,x,y+5);
		 line(x-10,y,x,y-5);
		 line(x,y+5,x,y-5);

	     }
	     if(flg==1)
	     {
		line(x,y,x+50,y);
		 line(x-10,y,x,y+5);
		 line(x-10,y,x,y-5);
		 line(x,y+5,x,y-5);
		x-=10;
	     }
	     rectangle(1,y1,10,y1+100);
	     rectangle(10,y1+20,20,y1+80);
	     rectangle(20,y1+40,30,y1+60);
	     delay(10);
	     if(x==30&&y>=y1+40&&y<=y1+60)
	     {
		hit=3;
		printf("Hit=%d",hit);
		delay(1000);
		flg=0;
		break;

	     }
	     else if(x==20&&y>=y1+20&&y<=y1+80)
	     {
		hit=2;
		printf("Hit=%d",hit);
		delay(1000);
		flg=0;
		break;
	     }
	     else if(x==10&&y>=y1&&y<=y1+100)
	     {
		hit=1;
		printf("Hit=%d",hit);
		delay(1000);
		flg=0;
		break;
	     }
	     else if(x==0)
	     {
		hit=0;
		printf("Hit=%d",hit);
		delay(1000);
		flg=0;
		break;
	     }
		cleardevice();
		if(y1>5&&i==0)
	     y1--;
	     if(y1==5)
	     {i=1;y1++;}
	     if(y1>5&&y1<=380&&i==1)
	     y1++;
	     if(y1==380)
	     i=0;

	}
	x=60;
	cnt++;
	score+=hit*10;
	if(kbhit()!=0)
	getch();
	 }
	printf("\nYour score is %d",score);
	if(score==90)
	printf("\nBulls eye!");
	if(score>=60&&score<90)
	printf("\nWell played");
	if(score>=30&&score<60)
	printf("\nYou need to work hard!");
	if(score<30)
	printf("\nYou are hopeless");
	printf("\nTry again:");
	scanf("%d",&p);
	}
	closegraph();
	return;
}

