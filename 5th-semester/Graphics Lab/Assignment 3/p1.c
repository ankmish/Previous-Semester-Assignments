/*
NAME - ANKIT MISHRA
REG NO - 20168047
PROGRAM - Mid-Point Line Tracing Algorithm
*/
#include<stdio.h>
#include<graphics.h>
void midPoint(int X1, int Y1, int X2, int Y2)
{
    int dx = X2 - X1;
    int dy = Y2 - Y1;
    // initial value of decision parameter d
    int d = dy - (dx/2);
    int x = X1, y = Y1;
    putpixel (x,y,YELLOW);    
    // iterate through value of X
    while (x < X2)
    {
        x++;
        // E or East is chosen
        if (d < 0)
            d = d + dy;
        // NE or North East is chosen
        else
        {
            d += (dy - dx);
            y++;
        }
        // Plot intermediate points
        putpixel(x,y,YELLOW);
        delay(100);
    }
}
int main()
{
     int gd = DETECT, gm;
    // Initialize graphics function
     int X1, Y1, X2, Y2;
     printf("\n Enter the (x0,yo) : ");
     scanf("%d %d",&X1,&Y1);
     printf("\n Ener the (x1,y1) :");
     scanf("%d %d",&X2,&Y2);
     initgraph (&gd, &gm, "");
     midPoint(X1, Y1, X2, Y2);
     getch();
     Sclosegraph();
     return 0;
}
