#include <graphics.h>
#include <iostream.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <dos.h>
#include <string.h>
# define PI 3.14
	int l,k;
	int di;
	char s[50];
	void dispdice();
	void credits();
	void erase(int,int);
/* for the point co-ordinates */
class pointscl
{
	public:
		int x,y;
};
/* for players posistion */
struct token
{
	int curr;
}p[4];

/* bkgrnd() function for drawing the board,coloring and numbering */
void bkgrnd()
{
	int left, top, right, bottom;    //for each box in the board
	pointscl points[102];
	char str[20];
	int i,j,mod=0,setc;
	setcolor(YELLOW);
	top=10;
	bottom=55;
	for(i=1; i<=10; i++)
	{
		left=10; right=55;
		for(j=1;j<=10;j++)
		{
			rectangle(left,top,right,bottom);           //draws the rectangle
			points[101-((i-1)*10+j)].x=(left+right)/2;  //finds the x-co ordinate
			points[101-((i-1)*10+j)].y=(top+bottom)/2;  //finds the y-co ordinate

			//  sprintf(str,"%d",points[101-((i-1)*10+j)].y);
			//  outtextxy(points[101-((i-1)*10+j)].x,points[101-((i-1)*10+j)].y,str)

			left+=45; right+=45;

		}
		top+=45; bottom+=45;
	}

	   /* for coloring the boxes and numbering */

	for(i=1,l=0;i<=10;i+=2,l+=90)                  //for 1,3,5,7,9 rows from bottom
		for(j=1, k=0;j<=10;j++,k+=45)
		{
			int crd;
			crd=10*(i-1)+j;
			char crds[5];
			itoa(crd,crds,10);

			if((crd%2)==0)
			{
				setfillstyle(SOLID_FILL,4);
				floodfill(32+k-1,437-l+1,YELLOW);
			}

			else
			{
				setfillstyle(SOLID_FILL,0);
				floodfill(32+k-1,437-l+1,YELLOW);
			}
			setcolor(WHITE);
			outtextxy(32+k,437-l,crds);       //numbering
		}

	for(i=2,l=0;i<=10;i+=2,l+=90)             //for 2,4,6,8,10 rows from bottom
		for(j=1, k=0;j<=10;j++,k+=45)
		{
			int crd;
			crd=10*(i-1)+j;
			char crds[5];
			itoa(crd,crds,10);

			if((crd%2)==0)
			{
				setfillstyle(SOLID_FILL,4);
				floodfill(437-k,392-l,YELLOW);
			}

			else
			{
				setfillstyle(SOLID_FILL,0);
				floodfill(437-k,392-l,YELLOW);
			}
			setcolor(WHITE);
			outtextxy(437-k,392-l,crds);           //numbering
	    }
	    setcolor(YELLOW);
	    rectangle(484,300,626,450);
 }

 /* draws the ladder */
void ladder(double Xx1,double Yy1,double Xx2,double Yy2)
{
	double X1,Y1,X2,Y2,x1,y1,x2,y2,x1_2,y1_2,x2_2,y2_2,actualDistance,soFarDistance,ctrlpointX,ctrlpointY,distanceSeparator,m,temp;
	int signX,signY;


	      X1=Xx1+40;
	      Y1=Yy1+25;
	      X2=Xx2+40;
	      Y2=Yy2+25;


		distanceSeparator=20*sqrt(2);
		m=(Xx2-Xx1)/(Yy2-Yy1);
		ctrlpointX = distanceSeparator*sin(PI/2-(atan(m)));
		ctrlpointY = sqrt(distanceSeparator*distanceSeparator-ctrlpointX*ctrlpointX);

		temp=X1;
		X1=X2;
		X2=temp;

		temp=Y1;
		Y1=Y2;
		Y2=temp;

		setcolor(YELLOW);
		x1=X1; y1=Y1;
		x2=X2; y2=Y2;
		signY=1;
		if(X2>X1) {signY=-1;      }
		line(x1,y1,x2,y2);
		line(x1+ctrlpointX,y1+(signY)*ctrlpointY,x2+ctrlpointX,y2+(signY)*ctrlpointY);



		x1=X1; y1=Y1;
		x2=25*m/sqrt(m*m+1)+x1;
		if(m==0) y2=50+y1;			//if Ladder is vertical
		else y2=((x2-x1)/m)+y1;

		x1_2=X1+ctrlpointX; y1_2=Y1+(signY)*ctrlpointY;
		x2_2=25*m/sqrt(m*m+1)+x1_2;
		if(m==0) y2_2=50+y1_2;			//if Ladder is vertical
		else y2_2=((x2_2-x1_2)/m)+y1_2;
		actualDistance = sqrt(pow((X2-X1),2)+pow((Y2-Y1),2));
		soFarDistance =  sqrt(pow((x2-X1),2)+pow((y2-Y1),2));
		while((actualDistance-soFarDistance)>=10)
		{
			line(x2,y2,x2_2,y2_2);
			x1=x2; y1=y2;
			x2=25*m/sqrt(m*m+1)+x1;
			if(m==0) y2=50+y1;			//if Ladder is vertical
			else y2=((x2-x1)/m)+y1;

			x1_2=x2_2; y1_2=y2_2;
			x2_2=25*m/sqrt(m*m+1)+x1_2;
			if(m==0) y2_2=50+y1_2;			//if Ladder is vertical
			else y2_2=((x2_2-x1_2)/m)+y1_2;
			soFarDistance =  sqrt(pow((x2-X1),2)+pow((y2-Y1),2));
		}
	}

      /* draws the snake */
 void snake()
 {
	 setcolor(GREEN);
 for(int i=0;i<5;i++)        //snake from 68 to 29
 {
	arc(347+i,184+i,90,270,22);
	arc(347+i,207+22+i,270,90,22);
	arc(347+i,252+22+i,90,270,22);
	arc(347,319+22+i,0,90,45);
 }
	setcolor(BLUE);
 for(i=0;i<5;i++)            //snake from 98 to 37
 {
	arc(122,32+44+i,90,270,35);
	arc(122,103+44+i,270,90,35);
	arc(122,174+44+i,90,270,35);
	arc(122,245+44+i,360,90,35);
 }
	setcolor(MAGENTA);
 for(i=0;i<5;i++)             //snake from 25 to 6
 {
	arc(212,327+22+i,270,90,22);
	arc(212,394+22+i,90,350,44);
 }
 for(i=0;i<5;i++)             //snake from 87 to 55
 {
	 arc(302,77+22+i,90,270,22);
	 arc(302,122+22+i,270,90,22);
	 arc(302,187+22+i,90,195,44);
 }
}
	 /* dice() generates a random value and displays respective dice */
int dice()
{

	int d;
	char s[4];
	d=random(6)+1;    //generates a random value between 1 and 6
if(d==1)          //if dice value is 1
{
	  setfillstyle(SOLID_FILL,0);
	  floodfill(485,30,YELLOW);
	  setcolor(BLUE);
	  setfillstyle(SOLID_FILL,BLUE);
	  rectangle(500,50,600,150);
	  floodfill(502,52,BLUE);
	  setcolor(WHITE);
	  setfillstyle(SOLID_FILL,WHITE);
	  circle((500+600)/2,(50+150)/2,4);
	  floodfill((500+600)/2,(50+150)/2,WHITE);
}
if(d==2)   //if dice value is 2
{
	setfillstyle(SOLID_FILL,0);
	floodfill(485,30,YELLOW);
	setcolor(BLUE);
	setfillstyle(SOLID_FILL,BLUE);
	rectangle(500,50,600,150);
	floodfill(502,52,BLUE);
	setcolor(WHITE);
	setfillstyle(SOLID_FILL,WHITE);
	circle((500+600)/2+30,(50+150)/2,4);
	floodfill((500+600)/2+30,(50+150)/2,WHITE);
	setfillstyle(SOLID_FILL,WHITE);
	circle((500+600)/2-30,(50+150)/2,4);
	floodfill((500+600)/2-30,(50+150)/2,WHITE);
	setfillstyle(SOLID_FILL,WHITE);
}
if(d==3)      //if dice value is 3
{
	setfillstyle(SOLID_FILL,0);
	floodfill(485,30,YELLOW);
	setcolor(BLUE);
	setfillstyle(SOLID_FILL,BLUE);
	rectangle(500,50,600,150);
	floodfill(502,52,BLUE);
	setcolor(WHITE);
	setfillstyle(SOLID_FILL,WHITE);
	circle((500+600)/2,(50+150)/2,4);
	floodfill((500+600)/2,(50+150)/2,WHITE);
	setfillstyle(SOLID_FILL,WHITE);
	circle(530,80,4);
	floodfill(530,80,WHITE);
	setfillstyle(SOLID_FILL,WHITE);
	circle(570,120,4);
	floodfill(570,120,WHITE);
}
if(d==4)     //if dice value is 4
{
	setfillstyle(SOLID_FILL,0);
	floodfill(485,30,YELLOW);
	setcolor(BLUE);
	setfillstyle(SOLID_FILL,BLUE);
	rectangle(500,50,600,150);
	floodfill(502,52,BLUE);
	setcolor(WHITE);
	setfillstyle(SOLID_FILL,WHITE);
	circle(530,80,4);
	floodfill(530,80,WHITE);
	setfillstyle(SOLID_FILL,WHITE);
	circle(570,80,4);
	floodfill(570,80,WHITE);
	setfillstyle(SOLID_FILL,WHITE);
	circle(530,120,4);
	floodfill(530,120,WHITE);
	setfillstyle(SOLID_FILL,WHITE);
	circle(570,120,4);
	floodfill(570,120,WHITE);
}
if(d==5)    //if dice value is 5
{
	setfillstyle(SOLID_FILL,0);
	floodfill(485,30,YELLOW);
	setcolor(BLUE);
	setfillstyle(SOLID_FILL,BLUE);
	rectangle(500,50,600,150);
	floodfill(502,52,BLUE);
	setcolor(WHITE);
	setfillstyle(SOLID_FILL,WHITE);
	circle((500+600)/2,(50+150)/2,4);
	floodfill((500+600)/2,(50+150)/2,WHITE);
	setfillstyle(SOLID_FILL,WHITE);
	circle(530,80,4);
	floodfill(530,80,WHITE);
	setfillstyle(SOLID_FILL,WHITE);
	circle(530,120,4);
	floodfill(530,120,WHITE);
	setfillstyle(SOLID_FILL,WHITE);
	circle(570,80,4);
	floodfill(570,80,WHITE);
	setfillstyle(SOLID_FILL,WHITE);
	circle(570,120,4);
	floodfill(570,120,WHITE);
}
if(d==6)       //if dice value is 6
{
	setfillstyle(SOLID_FILL,0);
	floodfill(485,30,YELLOW);

	setcolor(BLUE);
	setfillstyle(SOLID_FILL,BLUE);
	rectangle(500,50,600,150);
	floodfill(502,52,BLUE);

	setcolor(WHITE);

	setfillstyle(SOLID_FILL,WHITE);
	circle(530,80,4);
	floodfill(530,80,WHITE);

	setfillstyle(SOLID_FILL,WHITE);
	circle(570,80,4);
	floodfill(570,80,WHITE);

	setfillstyle(SOLID_FILL,WHITE);
	circle((530+570)/2,80,4);
	floodfill((530+570)/2,80,WHITE);

	setfillstyle(SOLID_FILL,WHITE);
	circle(530,120,4);
	floodfill(530,120,WHITE);

	setfillstyle(SOLID_FILL,WHITE);
	circle((530+570)/2,120,4);
	floodfill((530+570)/2,120,WHITE);

	setfillstyle(SOLID_FILL,WHITE);
	circle(570,120,4);
	floodfill(570,120,WHITE);
}
	return(d);
}

void cp_tok(int pos,int g)
{
	if(g==1)
		setcolor(WHITE);
	if(g==2)
		setcolor(2);
	if(g==3)
		setcolor(3);
	if(g==4)
		setcolor(LIGHTGRAY);
	int i,l,j,k,crd;
	for(i=1,l=0;i<=10;i+=2,l+=90)
		for(j=1, k=0;j<=10;j++,k+=45)
		{
			crd=10*(i-1)+j;
		if(crd==pos)
			{
			if(g==1)
				circle(20+k,425-l,5);
			if(g==2)
				circle(40+k,425-l,5);
			if(g==3)
				circle(20+k,445-l,5);
			if(g==4)
				circle(42+k,446-l,5);

			}
		}

	for(i=2,l=0;i<=10;i+=2,l+=90)
		for(j=1, k=0;j<=10;j++,k+=45)
		{
			crd=10*(i-1)+j;
			if(crd==pos)
			{
				if(g==1)
					circle(425-k,384-l,5);
				if(g==2)
					circle(444-k,384-l,5);
				if(g==3)
					circle(425-k,404-l,5);
				if(g==4)
					circle(444-k,405-l,5);
			}
		}
}


void gameplay()
{

	int np=4,i,j;
	int lb[5]={8,36,62,73};
	int lt[5]={29,77,81,91};
	int sh[5]={25,68,87,98};
	int st[5]={6,29,55,37};
	char ch;

	char pp[10];
	for(i=1;i<=np;i++)
	{
		p[i].curr=1;
		cp_tok(p[i].curr,i);
	}

	setcolor(YELLOW);
	rectangle(484,200,626,225);

	do
	{
		for(i=1;i<=np;i++)
		{
			setfillstyle(SOLID_FILL,0);
			floodfill(485,201,YELLOW);
			if(i==1)
				setcolor(WHITE);
			if(i==2)
				setcolor(2);
			if(i==3)
				setcolor(3);
			if(i==4)
				setcolor(LIGHTGRAY);

			sprintf(pp," PLAYER %d",i);
			outtextxy(489,210,pp);

			ch=getch();
			if((int)ch==27) //ASCII code for esc is 27
				exit(0);
			else if((int)ch==32)
			{
				setfillstyle(SOLID_FILL,0);
				floodfill(485,301,YELLOW);
				dispdice();
			}
			else
			{       setfillstyle(SOLID_FILL,0);
				floodfill(485,301,YELLOW);
				setcolor(RED);
				outtextxy(485,310,"PRESS SPACE BAR");
				outtextxy(485,320,"TO ROLL THE DICE!!");
			}
			erase(p[i].curr,i);
			di=dice();
			p[i].curr=p[i].curr+di;

			for(j=0;j<5;j++)   //for snake
				if(p[i].curr==sh[j])
				{
					p[i].curr=st[j];
					setfillstyle(SOLID_FILL,0);
					floodfill(485,301,YELLOW);
					setcolor(RED);
					outtextxy(485,310,"SNAKEE !!!!!!!!!");
				}

			for(j=0;j<5;j++)   //for ladder
				if(p[i].curr==lb[j])
				{
					p[i].curr=lt[j];
					setfillstyle(SOLID_FILL,0);
					floodfill(485,301,YELLOW);
					setcolor(RED);
					outtextxy(485,310,"LADDER !!!!!!!!!");
				}

				if(p[i].curr>100)
				{
					p[i].curr-=di;
				}
				cp_tok(p[i].curr,i);

			if(p[i].curr==100)
			{
				 cleardevice();
				 setbkcolor(0);
				for(int i1=1;i1<=14;++i1)
				{
					delay(200);
					cleardevice();
					setcolor(i1);
					settextstyle(7,0,6);
					sprintf(s,"Player %d wins!!",i);
					outtextxy(120+random(31),50+random(31),s);
				}
				ch=getch();
				if(ch!=0)
				{
					credits();
					getch();
					exit(0);
				}
			}
			if(i==np)
			{
				i=0;
			}

		}
	}while(p[i].curr<=100);
}

void dispdice()
{
	setcolor(YELLOW);
	rectangle(484,29,626,168);
	setfillstyle(SOLID_FILL,0);
	floodfill(485,30,YELLOW);

	setcolor(BLUE);
	setfillstyle(SOLID_FILL,BLUE);
	rectangle(490,40,590,140);
	rectangle(520,60,620,160);
	floodfill(618,158,BLUE);
	floodfill(522,62,BLUE);
	line(490,40,520,60);
	line(490,140,520,160);
	line(590,40,620,60);
	setcolor(WHITE);

	setfillstyle(SOLID_FILL,WHITE);
	circle((520+620)/2,(60+160)/2,4);
	floodfill((520+620)/2,(60+160)/2,WHITE);
	delay(700);



	setfillstyle(SOLID_FILL,0);
	floodfill(485,30,YELLOW);
	setcolor(BLUE);
	setfillstyle(SOLID_FILL,BLUE);
	rectangle(500,50,600,150);
	floodfill(502,52,BLUE);
	setcolor(WHITE);
	setfillstyle(SOLID_FILL,WHITE);
	circle((500+600)/2,(50+150)/2,4);
	floodfill((500+600)/2,(50+150)/2,WHITE);
	setfillstyle(SOLID_FILL,WHITE);
	circle(530,80,4);
	floodfill(530,80,WHITE);

	setfillstyle(SOLID_FILL,WHITE);
	circle(570,120,4);
	floodfill(570,120,WHITE);
	delay(700);


	setfillstyle(SOLID_FILL,0);
	floodfill(485,30,YELLOW);
	setcolor(BLUE);
	setfillstyle(SOLID_FILL,BLUE);
	bar3d(490,60,590,160,25,1);
	floodfill(492,62,BLUE);
	setcolor(WHITE);
	setfillstyle(SOLID_FILL,WHITE);
	circle((490+590)/2-20,(60+160)/2,4);
	floodfill((490+590)/2-20,(60+160)/2,WHITE);
	setfillstyle(SOLID_FILL,WHITE);
	circle((490+590)/2+20,(60+160)/2,4);
	floodfill((490+590)/2+20,(60+160)/2,WHITE);
	delay(700);


	setfillstyle(SOLID_FILL,0);
	floodfill(485,30,YELLOW);
	setcolor(BLUE);
	setfillstyle(SOLID_FILL,BLUE);
	rectangle(500,50,600,150);
	floodfill(502,52,BLUE);

	setcolor(WHITE);
	setfillstyle(SOLID_FILL,WHITE);
	circle((500+600)/2,(50+150)/2,4);
	floodfill((500+600)/2,(50+150)/2,WHITE);
	setfillstyle(SOLID_FILL,WHITE);
	circle(530,80,4);
	floodfill(530,80,WHITE);

	setfillstyle(SOLID_FILL,WHITE);
	circle(570,80,4);
	floodfill(570,80,WHITE);

	setfillstyle(SOLID_FILL,WHITE);
	circle(570,120,4);
	floodfill(570,120,WHITE);

	setfillstyle(SOLID_FILL,WHITE);
	circle(530,120,4);
	floodfill(530,120,WHITE);

	delay(700);


	setfillstyle(SOLID_FILL,0);
	floodfill(485,30,YELLOW);
	setcolor(BLUE);
	setfillstyle(SOLID_FILL,BLUE);
	rectangle(490,40,590,140);
	rectangle(520,60,620,160);
	floodfill(618,158,BLUE);
	floodfill(522,62,BLUE);
	line(490,40,520,60);
	line(490,140,520,160);
	line(590,40,620,60);
	setcolor(WHITE);

	setfillstyle(SOLID_FILL,WHITE);
	circle(550,90,4);
	floodfill(550,90,WHITE);
	setfillstyle(SOLID_FILL,WHITE);
	circle(590,130,4);
	floodfill(590,130,WHITE);
	setfillstyle(SOLID_FILL,WHITE);
	circle(550,130,4);
	floodfill(550,130,WHITE);
	setfillstyle(SOLID_FILL,WHITE);
	circle(590,90,4);
	floodfill(590,90,WHITE);

}

void erase(int pos,int g)
{
	if(pos%2 == 0)
		setcolor(4);
	else
		setcolor(0);
	int i,l,crd,j,k;

	for(i=1,l=0;i<=10;i+=2,l+=90)
		for(j=1, k=0;j<=10;j++,k+=45)
		{
			crd=10*(i-1)+j;
			if(crd==pos)
			{
				if(g==1)
					circle(20+k,425-l,5);
				if(g==2)
					circle(40+k,425-l,5);
				if(g==3)
					circle(20+k,445-l,5);
				if(g==4)
					circle(42+k,446-l,5);
			}
		}

	for(i=2,l=0;i<=10;i+=2,l+=90)
		for(j=1, k=0;j<=10;j++,k+=45)
		{
			crd=10*(i-1)+j;
			if(crd==pos)
			{
				if(g==1)
					circle(425-k,384-l,5);
				if(g==2)
					circle(444-k,384-l,5);
				if(g==3)
					circle(425-k,404-l,5);
				if(g==4)
					circle(444-k,405-l,5);

			}
		}

}

void intro()
{
    int a,check,x,y;
    //int gdriver=DETECT,gmode,errorcode;
    char t[25];
    //initgraph(&gdriver,	&gmode, "D:\\TC\\BGI\\");
    cleardevice();
    for(int o=572;o>=1 ;o-=5)
    {setcolor(GREEN);
    outtextxy(1,o,"..");
    delay(20);
    }
    for(int z=1;z<=624;z+=5)
	{outtextxy(z,1,".");
    outtextxy(z,7,".");
    delay(20);
    }
    for(int w=1;w<=475;w+=5)
    {outtextxy(624,w,"..");
    delay(20);
    }
   for(int p=624;p>=0;p-=5)
   {outtextxy(p,472,".");
   outtextxy(p,465,".");
   delay(20);
   }
      int rrrr=0;
	setbkcolor(BLACK);
    setcolor(6);
    settextstyle(1,0,2);
    outtextxy(115,105,"LOADING....");
    setcolor(RED);
    rectangle(155,175,480,230);
    delay(1500);
    setcolor(RED);
    for(a=155;a<=480;a++)
    {
     rectangle(a,175,(a+1),230);
     delay(8);
     if(a==325) delay(654);
     }
    delay(50);
      setcolor(WHITE);
      settextstyle(7,0,2);
      outtextxy(35,320,"Enter any key to continue except windows key");
    getch();
    cleardevice();
    setcolor(6);
    for(int s=1;s<=225;s++)
    {
	cleardevice();
	circle(305,230,s);
	delay(7);
    }
    settextstyle(4,0,0);
    delay(500);
    setcolor(12);
    outtextxy(110,170,"POLARIS");
    delay(300);

    outtextxy(255,295,"PROJ");
    delay(300);
    outtextxy(340,295,"ECT");
    delay(1000);
    cleardevice();
    setcolor(WHITE);
    setbkcolor(0);
    rectangle(525,450,75,50);
    delay(500);
    settextstyle(7,0,4);
    setcolor(GREEN);
    outtextxy(80,90,"Topic: -");
    delay(700);
    setcolor(RED);
    settextstyle(1,0,0);
    outtextxy(135,185,"  Snake & Ladder  ");
    delay(700);
    setcolor(GREEN);
    settextstyle(6,0,1);
    outtextxy(115,300,"DONE BY : -");
    delay(700);
    setcolor(YELLOW);
    settextstyle(1,0,0);
    outtextxy(160,340,"R.GOWTHAM");
    delay(1500);



    cleardevice();

}

void credits()
{      int i,j,l,n;
	 cleardevice();
	 for(i=474,j=0,l=634,n=0;i>=0;i-=8,j+=10,l-=10,n+=8)
   { setcolor(6);
     line(0,i,j,0);delay(12);
     setcolor(GREEN);
     line(634,n,l,474);delay(12);
   }
  settextstyle(7,0,2);
  setcolor(WHITE);
  outtextxy(120,150,"My Sincere thanks to Project Manager");delay(300);
  outtextxy(210,180," Mr.Anantha Krishnan  ");delay(300);
  outtextxy(225,210," for this opportunity. ");delay(300);
  setcolor(1);
  outtextxy(203,240,"  Special thanks to ");delay(300);
  outtextxy(210,270,"     Parents     ");delay(300);
  outtextxy(210,295,"        &         ");delay(300);
  outtextxy(207,320,"     Friends       ");delay(300);
  setcolor(WHITE);
  outtextxy(205,350,"   Presented by   ");delay(300);
  outtextxy(205,380,"     R.Gowtham ");delay(300);
  delay(1500);
}

int main(void)
{
   /* request auto detection */
   int gdriver = DETECT, gmode, errorcode;


   /* initialize graphics and local variables */
   initgraph(&gdriver, &gmode, "d:\\tc\\bgi");

   /* read result of initialization */
   errorcode = graphresult();
   if (errorcode != grOk)  /* an error occurred */
   {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1); /* terminate with an error code */
   }
	randomize();

	intro();
	settextstyle(0,0,0);
	bkgrnd();
	dice();
	ladder(347-55,437-20,392-55,347-35);       //ladder from 8-29
	ladder(212-55,302-20,167-55,122-35);       //ladder from 36-77
	ladder(347-55,122-20,437-55,32-35);        //ladder from 73-91
	ladder(77-55,167-20,32-55,77-35);          //ladder from 62-81
	snake();
	gameplay();
	getch();
	closegraph();
	return 0;
}
