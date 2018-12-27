#include<stdlib.h>
#include<stdio.h>
#include<graphics.h>
#include<math.h>

int xa,xb,xc,ya,yb,yc,y1a,y1b,y1c,x1a,x1b,x1c,x2a,x2b,x2c,y2a,y2b,y2c;
int x3a,x3b,x3c,y3a,y3b,y3c,x4a,x4b,x4c,y4a,y4b,y4c,x5a,x5b,x5c,y5a,y5b,y5c;
int tx,shx,t,ch,shy;
float ang,theta,sx,sy;
int main()
{
	int gdriver = DETECT, gmode, errorcode;
	printf("\n\t\t\t 2D Composite Transformations");
	printf("\n\n Enter all coordinates values :");
	scanf("%d %d %d %d %d %d",&xa,&ya,&xb,&yb,&xc,&yc);
	printf("\n\n Enter the value tranlsation factor :");
	scanf("%d",&tx);
	printf("\n\n Enter the rotation angle :");
	scanf("%f",&ang);

	initgraph(&gdriver, &gmode,""); 
	line(xa,ya,xb,yb);
	line(xb,yb,xc,yc);
	line(xc,yc,xa,ya);

	x1a=xa+tx;
	x1b=xb+tx;
	x1c=xc+tx;
	y1a=ya;
	y1b=yb;
	y1c=yc;
	line(x1a,y1a,x1b,y1b); 
	line(x1b,y1b,x1c,y1c);
	line(x1c,y1c,x1a,y1a);
	delay(1);

	theta=((ang*3.14)/180);
	x2a=x1a*cos(theta)-y1a*sin(theta);
	y2a=x1a*sin(theta)+y1a*cos(theta);
	x2b=x1b*cos(theta)-y1b*sin(theta);
	y2b=x1b*sin(theta)+y1b*cos(theta);
	x2c=x1c*cos(theta)-y1c*sin(theta);
	y2c=x1c*sin(theta)+y1c*cos(theta);
	line(x2a,y2a,x2b,y2b);
	line(x2b,y2b,x2c,y2c);
	line(x2c,y2c,x2a,y2a);
	delay(1);


	line(x3a,y3a,x3b,y3b);
	line(x3b,y3b,x3c,y3c);
	line(x3c,y3c,x3a,y3a);
	delay(1);
	delay(10);

	getch();
	closegraph();
	return 0;
}