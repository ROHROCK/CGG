//Write a c++ program to draw a convex polygon and fill it with desired color Using
//seed fill algorithm

#include<iostream>
#include<graphics.h>

using namespace std;

class objectDrawing
{
  int oldColor;
  int newColor;
public:
  void colorMenu()
  {
    oldColor = 0;
  cout<<" Name	Value \n BLACK 	0 \n BLUE	1 \n GREEN	2 \n CYAN	3 \n RED	4 \n MAGENTA	5 \nBROWN	6 \n LIGHTGRAY	7 \n DARKGRAY	8"<<endl;
  cout<<"LIGHTBLUE	9 \n LIGHTGREEN	10 \n LIGHTCYAN	11 \n LIGHTRED	12 \n LIGHTMAGENTA	13 \n YELLOW	14 \n WHITE	15"<<endl;
  cout<<"*****************"<<endl;
  cout<<"Enter your choice: "<<endl;
  cin>>newColor;
   if(newColor > 15 || newColor < 1)
     newColor  = -1;

  }


  void initializeDisplay()
  {
      int gd=DETECT,gm=VGAMAX;
      initgraph(&gd,&gm,NULL);
  }
  void drawRectangle()
  {
      int x=0,y=0;
      int width,height;
      cout<<"Enter the x and y co-ordinates: "<<endl;
      cin>>x>>y;
      cout<<"Enter the width and height: "<<endl;
      cin>>width>>height;
      colorMenu();
      initializeDisplay();
      rectangle(x,y,x+width,y+height);
      floodfill(x+10,y+10,oldColor,newColor);
      getch();
      closegraph();
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
      colorMenu();
      initializeDisplay();
      line(x1,y1,x2,y2);
      line(x2,y2,x3,y3);
      line(x3,y3,x1,y1);
      floodfill(x2-10,y2+10,oldColor,newColor); //pass the seed value
      getch();
      closegraph();
  }
  void drawSquare()
  {
      int x,y,side;
      cout<<"Enter the value of side: "<<endl;
      cin>>side;
      cout<<"Enter the x and y points: "<<endl;
      cin>>x>>y;
      cout<<"Enter the value for side: "<<endl;
      cin>>side;
      colorMenu();
      initializeDisplay();
      rectangle(x,y,x+side,y+side);
      floodfill(x+10,y+10,oldColor,newColor);
      getch();
      closegraph();
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

int main(){
  objectDrawing obj;
  int ch;
  char status;
  do {
    cout<<"1.Draw Rectangle"<<endl;
    cout<<"2.Draw Square"<<endl;
    cout<<"3.Draw Triangle"<<endl;
    cin>>ch;
    switch (ch) {
      case 3: obj.drawTriangle();
      case 1:
          obj.drawRectangle();
      break;
      case 2:
          obj.drawSquare(); break;
      case 4:
          exit(EXIT_SUCCESS);
      default:
        cout<<"Wrong choice !"<<endl;
    }
    cout<<"Do you want to continue ? [Y/N]"<<endl;
    cin>>status;
  } while(status == 'y' || status == 'Y');
  return 0;
}
