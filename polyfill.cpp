/*Write C++/Java program to fill polygon using scan line algorithm*/
#include<graphics.h>
#include<iostream>

using namespace std;

class PolyFill{
   int triangle[8];
   int oldColor , newColor;
public:
  PolyFill(){
    oldColor = BLACK;
    newColor = RED;
  }
  void getXY(){
    cout<<"Enter the Co-ordinates for Traingle: "<<endl;
    for (int i = 0; i < 6; i++) {
      cin>>triangle[i];
    }
    triangle[6] = triangle[0];
    triangle[7] = triangle[1];
  }
  void prepareScreen()
  {
	  int xmax,ymax,xmid,ymid;
	  int gd = DETECT ,gm = VGAMAX;
	  initgraph(&gd,&gm,NULL);
  }
  void drawTriangle()
  {
    getXY();
    prepareScreen();
    drawpoly(4,triangle);
    getch();
    closegraph();
  }

  void fillTriangle()
  {
    prepareScreen();
    drawpoly(4,triangle);
    fillOldcolor(oldColor,newColor,triangle[0],triangle[1]+3);
  }

  void fillOldcolor(int oldColor , int newColor , int x , int y)
  {
    if(getpixel(x,y) != oldColor )
      return;
      putpixel(x,y,newColor);
      fillOldcolor(oldColor,newColor,x+1,y);
      fillOldcolor(oldColor,newColor,x-1,y);
      fillOldcolor(oldColor,newColor,x,y+1);
      fillOldcolor(oldColor,newColor,x,y-1);

  }
};

int main()
{
  PolyFill obj;
  int ch;
  char status;
  do {
    cout<<"******************"<<endl;
    cout<<"1.Draw Polygon "<<endl;
    cout<<"2.Fill Polygon "<<endl;
    cout<<"3.Exit"<<endl;
    cout<<"****************"<<endl;
    cout<<"Enter your choice: "<<endl;
    cin>>ch;
    switch (ch) {
      case 1: obj.drawTriangle(); break;
      case 2: obj.fillTriangle(); break;
      default:
        cout<<"Wrong choice !"<<endl;
    }
    cout<<"Do you want to continue ? [Y/N]"<<endl;
    cin>>status;
  } while(status == 'y' || status == 'Y');
  return 0;
}
