// C-program for circle drawing
// using Bresenham’s Algorithm
// in computer-graphics
#include <graphics.h>
#include <math.h>
#include <iostream>

using namespace std;

// driver function
class drawCircle{
	int xc , yc ;
	int r;
public:
	void getXY(){
    cout<<"Enter the Co-ordinates: "<<endl;
    cin>>xc>>yc;
		cout<<"Enter the Radius: "<<endl;
		cin>>r;
  }
	void prepareScreen()
	{
		int xmax,ymax,xmid,ymid;
		int gd = DETECT ,gm = VGAMAX;
		initgraph(&gd,&gm,NULL);
		xmax=getmaxx();
		ymax=getmaxy();
		xmid=xmax/2;
		ymid=ymax/2;
		line(xmid,0,xmid,ymax);
		line(0,ymid,xmax,ymid);
		xc = xc + xmid; //xmid value taken from the graphics lib and calculate the the centre of the circle x pos
		yc = ymid - yc; //ymid value taken from the graphics lib
	}
	void drawCircleBresenham()
	{
		int x = 0, y = r;
		int d = 3 - 2 * r;
		while (y >= x)
		{
			// for each pixel we will
			// draw all eight pixels
			putpixel(xc+x, yc+y, RED);
			delay(100);
			putpixel(xc-x, yc+y, BLUE);
			delay(100);
			putpixel(xc+x, yc-y, GREEN);
			delay(100);
			putpixel(xc-x, yc-y, YELLOW);
			delay(100);
			putpixel(xc+y, yc+x, WHITE);
			delay(100);
			putpixel(xc-y, yc+x, YELLOW);
			delay(100);
			putpixel(xc+y, yc-x, YELLOW);
			delay(100);
			putpixel(xc-y, yc-x, YELLOW);
			delay(100);
			x++;
			// check for decision parameter
			// and correspondingly
			// update d, x, y
			if (d > 0)
			{
				y--; //the circle will be drawn at the lower side
				d = d + 4 * (x - y) + 10;
			}
			else
				d = d + 4 * x + 6; //the circle will be drawn at the upper side 
		}
	}

	void drawConcentric()
	{
		getXY();
		int no_of_concentric= 0;
		cout<<"Enter the number of Concentric circles you want: "<<endl;
		cin>>no_of_concentric;
		prepareScreen();
		while(no_of_concentric > 0)
		{
			if(r < 0 )
				return ;

			drawCircleBresenham();
			r = (int)r / 1.5;
			no_of_concentric--;
		}
		getch();
		closegraph();
	}
};
int main()
{
	drawCircle dc;

	int ch;
  char status;
  do {
    cout<<"1.Draw Circle: "<<endl;
		cout<<"2.Draw Concentric Circle: "<<endl;
    cout<<"3.Exit"<<endl;
    cin>>ch;
    switch (ch) {
      case 3: exit(EXIT_SUCCESS);
      case 1:
				dc.getXY();
				dc.prepareScreen();
				dc.drawCircleBresenham();
				getch();
				closegraph();
      break;

			case 2:
				dc.drawConcentric();
				getch();
				closegraph();
			break;

      default:
        cout<<"Wrong choice !"<<endl;
    }
    cout<<"Do you want to continue ? [Y/N]"<<endl;
    cin>>status;
  } while(status == 'y' || status == 'Y');
	getch();
	closegraph();

	return 0;
}
