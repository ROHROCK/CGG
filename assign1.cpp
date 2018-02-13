//Write C++/Java program to draw line using DDA and Bresenham's algorithm .
//Inherit pixel class and Use function overloading.
#include<graphics.h>
#include<iostream>
#include<cmath>

using namespace std;

class LineDrawing{
  int x1,y1,x2,y2;
public:
  LineDrawing(){
	x1=x2=y1=y2=0;}
  void getXY(){
    cout<<"Enter the Co-ordinates for Line: "<<endl;
    cin>>x1>>y1>>x2>>y2;
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
	  x1 = x1 + xmid;
	  y1 = ymid - y1;
	  x2 = x2 + xmid;
	  y2 = ymid - y2;
  }

  void DDA()
  {
    int gd = DETECT ,gm = VGAMAX;
    getXY();
    prepareScreen();

  	int dx = x2-x1;
  	int dy = y2-y1;

  	int step = abs(dx)>abs(dy)?abs(dx):abs(dy);

  	float xinc = dx/(float)step;
  	float yinc = dy/(float)step;

  	for(int i = 0 ; i <= step ; i++)
  	{
  		putpixel(x1,y1,RED);
  		x1 += xinc;
  		y1 += yinc;
  		delay(10);
  	}
	getch();
  	closegraph();
  }
  void bresenham()
  {
    int gd = DETECT ,gm = VGAMAX;
    int s1=0,s2=0,exchange_flag=0,i=0;
    float x,y,dy=0 ,dx=0;
    getXY();
    initgraph(&gd,&gm,NULL);
    prepareScreen();

    dx = abs(x2-x1);
    dy = abs(y2-y1);
    x = x1;
    y = y1;
    s1 =sign(x2-x1);
    s2 =sign(y2-y1);

    putpixel(x1,y1,RED);

    if(dy > dx)
    {
      int temp = dx;
      dx = dy;
      dy = temp;
      exchange_flag = 1;
    }else
      exchange_flag = 0;

      float e = (2*dy)-dx;

      i = 1;
      do {
        while(e >= 0)
        {
          if (exchange_flag == 1)
            x = x + s1;
          else
            y = y + s2;

          e = e - (2*dx); //update the error variable
        }
        if (exchange_flag == 1)
          y = y +s2;
        else
          x = x + s1;

       e = e + 2*dy; //update the error variable
       putpixel(x,y,BLUE);
       i++;
      }while(i <= dx);

	getchar();
  }

int sign(float val) {
  if(val < 0)
    return -1;
  else if(val > 0 )
    return 1;
  else
    return 0;
}

void swap(int dx ,int dy)
{
  int temp;
     temp = dx;
     dx = dy;
     dy = temp;
}
};



int main()
{
  int Xmax , Ymax;
  LineDrawing obj;
  int ch;
  char status;
  do {
    cout<<"1.Draw line using DDA Algorithm"<<endl;
    cout<<"2.Draw line using Bresenham Algorithm"<<endl;
    cout<<"3.Exit"<<endl;
    cin>>ch;
    switch (ch) {
      case 3: exit(EXIT_SUCCESS);
      case 1:
          obj.DDA();
      break;
      case 2:
          obj.bresenham(); break;
      default:
        cout<<"Wrong choice !"<<endl;
    }
    cout<<"Do you want to continue ? [Y/N]"<<endl;
    cin>>status;
  } while(status == 'y' || status == 'Y');
  return 0;
}
