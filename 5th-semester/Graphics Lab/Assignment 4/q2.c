/*
NAME - ANKIT MISHRA
REG NO - 20168047
PROGRAM - HUT  DRAWING
*/
#include<graphics.h>
#include<stdio.h>
int main()
{

	int gd =DETECT,gm;
	initgraph(&gd, &gm, "");
	setcolor(RED);
	
	rectangle(150,180,250,300);
	delay(100);
	
	rectangle(250,180,420,300);
	delay(100);
	
	setcolor(GREEN);
	rectangle(180,250,220,300);
	delay(100);
	
	setcolor(RED);
	line(200,100,150,180);
	delay(100);
	
	line(200,100,250,180);
	delay(100);
	setcolor(GREEN);
	
	circle(200,150,20);
	delay(100);
	setcolor(RED);
	delay(100);
	
	line(200,100,370,100);
	line(370,100,420,180);
	setcolor(BLUE);
	
	line(234,100,284,180);
	line(268,100,318,180);
	delay(100);
	
	line(302,100,352,180);
	line(336,100,386,180);
	setcolor(YELLOW);
	delay(100);
	
	rectangle(290,210,340,260);
	setcolor(GREEN);
	line(315,210,315,260);
	delay(100);
	
	line(290,235,340,235);
	line(200,260,200,290);
	line(180,250,200,260);
	delay(100);
	
	line(180,300,200,290);
	getch();
	closegraph();

return 0;

}
