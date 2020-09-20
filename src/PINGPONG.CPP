#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
#include<dos.h>
#include<iostream.h>

int x1=150,y1=415;
int xb[4]={150,250,150,250},yb[4]={100,100,200,200};

int upright()
{
     x1+=2;
     y1-=2;
     return 1;
}
int upleft()
{
	y1-=2;
	x1-=2;
	return 2;
}
int downleft()
{
       y1+=2;
       x1-=2;
       return 3;
}
int downright()
{
	x1+=2;
	y1+=2;
	return 4;
}
void clear_rectangle(int i)
{
   //	if(d==1)
	setcolor(0);
	setfillstyle(1,0);
	rectangle(xb[i],yb[i],xb[i]+50,yb[i]+20);
	floodfill(xb[i]+1,yb[i]+1,0);

}
void  draw_crect(int i)
{
       //	if(d1==1)
	setcolor(15);
	setfillstyle(1,3);
	rectangle(xb[i],yb[i],xb[i]+50,yb[i]+20);
	floodfill(xb[i]+1,yb[i]+1,15);
}
void main()
{
	int gd=DETECT,gm,errorcode;
	int m,pm=4,x=120,y=425,flg1=0,flg2=1,flg3=1,flg4=1,mr,res,cnt1=0,flgc[4]={0,0,0,0},i;
	char ch,w,pw,tch;
	clrscr();
	detectgraph(&gd,&gm);
	initgraph(&gd,&gm,"C:\\tc\\bgi");
	rectangle(98,48,402,452 );
	for(i=0;i<4;i++)
	rectangle(xb[i],yb[i],xb[i]+50,yb[i]+20);
    //	cleardevice();
	while(1)
	{
		setcolor(0);
		rectangle(x-10,y-5,x+70,y+5);
		setcolor(0);
		circle(x1,y1,5);
		while(kbhit())
		ch=getch();

		if(ch==32)
		break;
		if(ch==77)
		{
			x+=1;
			tch=ch;
			if(x+70>=402)
			ch=75;
		}
		if(ch==75)
		{
			x-=1;
			tch=ch;
			if(x-15<=98)
			ch=77;
		}
		if(flg1==0)
		{
		     if(pm==4)
		       m=upright();

		       if(pm==3)
		       m=upleft();
		}

		if(x1+5>=400||flg2==0)
		{
			if(x1+5>=400)
			{
				pm=m;

			}
			flg2=0;
			flg1=1;
			flg3=1;
			flg4=1;
			if(pm==1)
			{
			    m=upleft();
			}
			if(pm==4)
			{
				m=downleft();
			}


		}
		if(y1-5<=50||flg3==0)
		{
			if(y1-5<=50)
			pm=m;
			flg3=0;
			flg2=1;
			flg4=1;
			flg1=1;
			if(pm==2)
			m=downleft();
			if(pm==1)
			m=downright();

		}
		if(x1-5<=100||flg4==0)
		{

			if(x1-5<=100)
			pm=m;
			flg4=0;
			flg2=1;
			flg3=1;
			flg1=1;
			if(pm==3)
			m=downright();
			if(pm==2)
			m=upright();
		}
		if(x1<=x+70&&x1>=x-10&&y-y1==10)
		{
			flg1=0;
			flg2=1;
			flg3=1;
			flg4=1;
			pm=m;
			if(tch==75)
				pm=3;
			if(tch==77)
				pm=4;
		}
		if(y1==445)
		{
			break;
		}
		for(i=0;i<4;i++)
		{
		if(flgc[i]==2)
			continue;
		if(x1>xb[i]&&x1<xb[i]+50&&abs((yb[i]+10-y1))<20&&flgc[i]<2)
		{
				if(pm==3||pm==2)
				{pm=m;flg1=0;flg2=1;flg3=1;flg4=1;}
				else if(pm==4||pm==1)
				{pm=m;flg3=0;flg2=1;flg1=1;flg4=1;}


			flgc[i]++;
			cout<<i<<"  "<<flgc[i]<<"\n";
			if(flgc[i]==1)
			draw_crect(i);
			if(flgc[i]==2)
			clear_rectangle(i);
		}
		if(y1>yb[i]&&y1<yb[i]+20&&flgc[i]<2&&abs(xb[i]+25-x1)<30)
		{
			if(pm==1||pm==2)
			{pm=m;flg4=0;flg1=1;flg2=1;flg3=1;}
			else if(pm==3||pm==4)
			{pm=m;flg2=0;flg1=1;flg3=1;flg4=1;}
			flgc[i]++;
			cout<<i<<"  "<<flgc[i]<<"\n";
			if(flgc[i]==1)
			draw_crect(i);
			if(flgc[i]==2)
			clear_rectangle(i);

		}
		}
		setcolor(15);
		rectangle(x-10,y-5,x+70,y+5);
		setcolor(15);
		circle(x1,y1,5);
		delay(10);



	}
	getch();

}
