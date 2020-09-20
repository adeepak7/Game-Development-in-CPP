#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<dos.h>
#include<graphics.h>
#include<conio.h>
void main()
{
	int ax[100],ay[100],flg2=0,tmp=-1,p=0,gd=DETECT,gm,flg=0,x=240,y=240,x1,y1,cnt=0,fx=250,fy=250,score=0,kill=0,xb,yb;
	char ch;
	detectgraph(&gd,&gm);
	initgraph(&gd,&gm,"C:\\tc\\BGI");
	randomize();
	x1=300;y1=400;
	setcolor(5);
	circle(x1,y1,5);
	while(kbhit()==0)
	{
		setcolor(6);
		circle(x,y,10);
		delay(100);
		p=0;
		tmp=score;
		while(tmp>0)
			{
			   p++;
			   setcolor(0);
			   circle(ax[p],ay[p],10);tmp--;
			}
			p=0;
			ax[p]=x;ay[p]=y;
		tmp=score;
		p=score-1;
		if(x==660)
	       x=20;

	      else if(y==460)
	       y=20;
	       else if(x==0)
	       x=660;
	      else if(y==0)
	       y=460;
	       tmp=score;
	       while(1)
	       {
			tmp--;
			if(tmp==0||tmp==-1)
			break;
			if(ax[0]==ax[tmp]&&ay[0]==ay[tmp])
			{
				cleardevice();
				setcolor(5);
				outtextxy(250,250,"Game Over");// system("PAUSE");
				outtextxy(250,260,"Try again:");
				scanf("%d",&flg2);
				printf("\b");
				if(flg2==1)
				break;
				else
				return;
			}


	       }
	       if(flg2==1)
	       { flg2=0;cleardevice();
	       score=0;
	       continue;}
		while(p>=0)
		{
		ax[p+1]=ax[p];ay[p+1]=ay[p];
		 p--;

		}
		setcolor(0);
		circle(x,y,10);
	       if(flg==0)
		x+=10;
		//ax[p]=x;ay[p]=y;
		if(ch==32)
		break;
		while(kbhit())
		ch=getch();
	       if(ch=='s')
	       {y+=20;flg=1;}
	       if(ch=='a')
	       {x-=20;flg=1;}
	       if(ch=='w')
	       {y-=20;flg=1;}
	       if(ch=='d')
	       {x+=20;flg=1;}
	      /* if(x==620)
	       {x=0;}
	       if(y==460)
	       y=0;
	       if(x==0)
	       x=620;
	       if(y==0)
	       y=460;*/
		 if(sqrt(pow((x1-x),2)+pow((y1-y),2))<=15)
		       {	score++;
				printf("\b\b\b\b\b\b\b\b\bScore:%d",score);
				kill=1;
				sound(2000);
				delay(100);
				nosound();
				setcolor(6);
			}
	  /*     if(x==620)
	       x=20;
	       if(y==460)
	       y=20;
	       if(x==20)
	       x=620;
	       if(y==20)
	       y=460;  */
			tmp=score;
			p=0;
			while(tmp>0)
			{  p++;
			   setcolor(6);
			   circle(ax[p],ay[p],10); tmp--;
			}
			tmp=score;



		 if(cnt==abs(x1-fx)+abs(y1-fy)+40||kill==1)
		 {
			cnt=0; kill=0;
			setcolor(0);
			circle(x1,y1,5);
			fx=x;fy=y;
			x1=random(getmaxx());
			y1=random(getmaxy());
			setcolor(5);
			circle(x1,y1,5);
		}
		 cnt++;


	}
}
