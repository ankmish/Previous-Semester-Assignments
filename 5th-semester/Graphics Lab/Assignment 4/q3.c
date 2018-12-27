/*
NAME - ANKIT MISHRA
REG NO - 20168047
PROGRAM - CAR  DRAWING
*/
#include<graphics.h>
#include<stdio.h>
int main()
{
	int gd = DETECT, gm;
	initgraph(&gd, &gm,NULL);
	setcolor(WHITE);
	
	circle(100,285,15);delay(100);
	circle(200,285,15);delay(100);
	
	arc(100,285,180,0,17.5);delay(100);
	arc(200,285,180,0,17.5);delay(100);
	
	line(65,285,85,285);delay(100);
	line(115,285,185,285);delay(100);
	line(215,285,235,285);delay(100);
	line(65,260,235,260);
	
	line(65,285,65,260);delay(100);
	line(235,285,235,260);delay(100);
	line(100,260,115,235);delay(100);
	line(200,260,185,235);delay(100);
	line(115,235,185,235);delay(100);
	setcolor(4);
	getch();
	closegraph();

}
