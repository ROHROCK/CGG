// C-program for circle drawing
// using Bresenham’s Algorithm
// in computer-graphics
#include <graphics.h>
#include <math.h>
#include <iostream>

// driver function
int main()
{
	int xc = 100, yc = 100, r = 50;
	int gd = DETECT,gm=VGAMAX;

	initgraph(&gd, &gm, NULL); // initialize graph
	
	int x = 0, y = r;
	int d = 3 - 2 * r;
	while (y >= x)
	{
		// for each pixel we will
		// draw all eight pixels
		putpixel(xc+x, yc+y, RED);
		putpixel(xc-x, yc+y, RED);
		putpixel(xc+x, yc-y, RED);
		putpixel(xc-x, yc-y, RED);
		putpixel(xc+y, yc+x, YELLOW);
		putpixel(xc-y, yc+x, YELLOW);
		putpixel(xc+y, yc-x, YELLOW);
		putpixel(xc-y, yc-x, YELLOW);
		delay(300);
		x++;
	
		// check for decision parameter
		// and correspondingly 
		// update d, x, y
		if (d > 0)
		{
			y--; 
			d = d + 4 * (x - y) + 10;
		}
		else
			d = d + 4 * x + 6;
		
	}	
	getch();
	closegraph();

	return 0;
}
	

