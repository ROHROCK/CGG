//Write a c++ program to draw a convex polygon and fill it with desired color Using
//seed fill algorithm

#include<iostream>
#include<graphics.h>

using namespace std;

class objectDrawing
{
  int choice;
public:
  void colorMenu()
  {
  cout<<" Name	Value \n BLACK 	0 \n BLUE	1 \n GREEN	2 \n CYAN	3 \n RED	4 \n MAGENTA	5 \nBROWN	6 \n LIGHTGRAY	7 \n DARKGRAY	8"<<endl;
  cout<<"LIGHTBLUE	9 \n LIGHTGREEN	10 \n LIGHTCYAN	11 \n LIGHTRED	12 \n LIGHTMAGENTA	13 \n YELLOW	14 \n WHITE	15"<<endl;
  cout<<*******************<<endl;
  cout<<"Enter your choice: "<<endl;
  cin>>choice;
   if(choice > 15 || choice < 1)
     choice  = -1
    
  }
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
      int choice;
      int x1,y1,x2,y2,x3,y3;
      cout<<"Enter the Co-ordinates: "<<endl;
      cin>>x1>>y1;
      cout<<"2nd Point: "<<endl;
      cin>>x2>>y2;
      cout<<"3rd Point: "<<endl;
      cin>>x3>>y3;
      choice = colorMenu();
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
