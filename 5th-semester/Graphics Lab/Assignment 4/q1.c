/*
NAME - ANKIT MISHRA
REG NO - 20168047
PROGRAM - SMILEY  DRAWING
*/
#include <graphics.h>
#include<stdio.h>
int main()
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"");
	setcolor(YELLOW);	

	circle(300, 150, 100);
	setcolor(WHITE);
	
	circle(250, 130, 25);
     circle(350, 130, 25);
	setcolor(BLUE);
	
	circle(250, 145, 8);
     circle(350, 145, 8);
	setcolor(RED);
	ellipse(300, 160, 45, 135,70,60);
	delay(10000);
	
	getch();
     closegraph();
	return 0;	
}
