#include<iostream.h>
#include<conio.h>
#include<math.h>
#include<graphics.h>
#include<dos.h>
#include<stdlib.h>

int main()
{
int gd=DETECT,gm;
initgraph(&gd,&gm,"C:\\tc\\bgi");
double x1=200,xp1=200,yp1=300,xp2=400,yp2=300,y1=400,x2,y2,vx,vy,v=0.19;
double d1,d2,ang=6,xg1=100,xg2=100,gp1=0.01,gx1,gy1,gang1,gh1=900*gp1,gp2=0.01,gx2,gy2,gang2,gh2=900*gp2;
vx=v*cos(ang*3.142/180);
vy=v*sin(ang*3.142/180);
y2=y1-vy;
x2=x1+vx;
circle(xp1,yp1,30);
circle(xp2,yp2,30);
setcolor(4);
circle(xp1,yp1,xg1);
circle(xp2,yp2,xg2);
while(y2<=400)
{
if(kbhit())
{
setcolor(15);
circle(x1,y1,7);


d1=sqrt(pow(xp1-x1,2)+pow(yp1-y1,2));
d2=sqrt(pow(xp2-x1,2)+pow(yp2-y1,2));
if(d1<=xg1)
	break;
if(d2<=xg2)
	break;

delay(3);
setcolor(0);
circle(x1,y1,7);
 x1=x2;y1=y2;
 x2=x2+vx;
// vy-=g;
 y2=y2-vy;
 }
}
getch();
x2=x1;
y2=y1;
while(1)
{
   if(d1>(xg1+8)&&d2>(xg2+8))
   break;
   if(d1<38||d2<38)
   break;
   gang1=atan2l(y1-yp1,x1-xp1);
//   gang=labs(gang);
//   cout<<gang;
   gh1=(900*gp1)/(d1*d1);
   gx1=gh1*cos(gang1);
   if(gx1<0)
   gx1*=-1;
   gy1=gh1*sin(gang1);
   if(gy1<0)
   gy1*=-1;
   gang2=atan2l(y1-yp2,x1-xp2);
//   gang=labs(gang);
//   cout<<gang;
   gh2=(900*gp2)/(d2*d2);
   gx2=gh2*cos(gang2);
   if(gx2<0)
   gx2*=-1;
   gy2=gh2*sin(gang2);
   if(gy2<0)
   gy2*=-1;
   if((xp1-x1>=0)&&(yp1-y1<0))
   {	vx+=gx1;
	vy+=gy1;
	x2+=vx;
	y2-=vy;
   }

   if((xp1-x1<0)&&(yp1-y1<0))
   {	vx-=gx1;
	vy+=gy1;
	x2+=vx;
	y2-=vy;
//	cout<<x2<<" "<<y2<<"\n";
   }
   if((xp1-x1<0)&&(yp1-y1>0))
   {
	vx-=gx1;
	vy-=gy1;
	x2+=vx;
	y2-=vy;
   }
   if((xp1-x1)>0&&(yp1-y1)>0)
   {
	vx+=gx1;
	vy-=gy1;
	x2+=vx;
	y2-=vy;
   }
   if((xp2-x1>=0)&&(yp2-y1<0))
   {	vx+=gx2;
	vy+=gy2;
	x2+=vx;
	y2-=vy;
   }

   if((xp2-x1<0)&&(yp2-y1<0))
   {	vx-=gx2;
	vy+=gy2;
	x2+=vx;
	y2-=vy;
//	cout<<x2<<" "<<y2<<"\n";
   }
   if((xp2-x1<0)&&(yp2-y1>0))
   {
	vx-=gx2;
	vy-=gy2;
	x2+=vx;
	y2-=vy;
   }
   if((xp2-x1)>0&&(yp2-y1)>0)
   {
	vx+=gx2;
	vy-=gy2;
	x2+=vx;
	y2-=vy;
   }
   setcolor(15);
   line(x1,y1,x2,y2);
   delay(5);
   if(kbhit())
	break;
   x1=x2;
   y1=y2;
   d1=sqrt(pow(xp1-x1,2)+pow(yp1-y1,2));
   d2=sqrt(pow(xp2-x1,2)+pow(yp2-y1,2));
}
getch();
getch();
closegraph();
return 1;
}