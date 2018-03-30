#include<iostream>
#include<graphics.h>

using namespace std;

class co_ordinates{
public:
  int x ;
  int y;
};

class cohen{
  co_ordinates min , max ;
public:
  /*
  this function will store the clipping window co-ordinates only.
  para : none
  return : none
  */
  void getClippingCoOrdinates()
  {
    cout<<"Enter the Co-ordinates for MIN X "<<endl;
    cin>>min.x;
    cout<<"Enter the Co-ordinates for MIN Y"<<endl;
    cin>>min.y;
    cout<<"Enter the Co-ordinates for MAX X"<<endl;
    cin>>max.x;
    cout<<"Enter the Co-ordinates for MAX Y"<<endl;
    cin>>max.y;
  }

  void prepareScreen()
  {
	  int xmax,ymax,xmid,ymid;
	  int gd = DETECT ,gm = VGAMAX;
	  initgraph(&gd,&gm,NULL);
	  // xmax=getmaxx();
	  // ymax=getmaxy();
	  // xmid=xmax/2;
	  // ymid=ymax/2;
	  // line(xmid,0,xmid,ymax);
	  // line(0,ymid,xmax,ymid);
	  // x1 = x1 + xmid;
	  // y1 = ymid - y1;
	  // x2 = x2 + xmid;
	  // y2 = ymid - y2;
  }

  void drawClippingWindow()
  {
    setcolor(RED);
    line(min.x,min.y,max.x,min.y);
    line(max.x,min.y,max.x,max.y);
    line(max.x,max.y,min.x,max.y);
    line(min.x,max.y,min.x,min.y);
    getch();
  }

  //program to accept the number of sides and place .
  void getPolyCo_ordinates(){
  }

};

int main()
{
  cohen obj;
  obj.getClippingCoOrdinates();
  obj.prepareScreen();
  obj.drawClippingWindow();
  obj.getPolyCo_ordinates()
  //draw the polygon
  return 0;
}
