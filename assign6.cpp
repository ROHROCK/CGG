//Write a c++ program to draw a convex polygon and fill it with desired color Using
//seed fill algorithm

#include<iostream>
#include<graphics.h>

using namespace std;

class objectDrawing
{
public:
  void initializeDisplay()
  {
      int gd=DETECT,gm=VGAMAX;
      initgraph(gd,gm,NULL);
  }
  void drawRectangle()
  {
      drawRect(x,y,width,height);
  }
  void drawTriangle()
  {
      int x1,y1,x2,y2,x3,y3;
      cout<<"Enter the Co-ordinates: "<<endl;
      cin>>x1>>y1;
      cout<<"2nd Point: "<<endl;
      cin>>x2>>y2;
      cout<<"3rd Point: "<<endl;
      cin>>x3>>y3;
      line(x1,y1,x2,y2);
      line(x2,y2,x3,y3);
      line(x3,y3,x1,y1);
  }
  void drawSquare()
  {
      int x,y;
      cout<<"Enter the value of side: "<<endl;
      cin>>side;
      cout<<"Enter the x and y points: "<<endl;
      cin>>x>>y;
      drawRect(x,y,side,side);
      cout<<"Enter the color you want to fill it with: "<<endl;
      
      floodfill()
  }
  void floodfill(int x , int y , int oldcolor , int newcolor)
  {
    if(getpixel(x,y) == oldcolor)
    {
      putpixel(x,y,newcolor);
      floodfill(x+1,y,oldcolor,newcolor);
      floodfill(x,y+1,oldcolor,newcolor);
      floodfill(x-1,y,oldcolor,newcolor);
      floodfill(x,y-1,oldcolor,newcolor);
    }
  }
};
