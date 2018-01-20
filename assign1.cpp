#include<graphics.h>
#include<iostream>

using namespace std;

class Pixel{

};

class LineDrawing{
  int x1,y1,x2,y2;
public:
  LineDrawing(){x1=x2=y1=y2=0;}
  void getXY(){
    cout<<"Enter the Co-ordinates for Line: "<<endl;
    cin>>x1>>y1>>x2>>y2;
  }
  void DDA()
  {
    void getXY();
    initgraph(&gd,&gm,NULL);

  	int dx = x2-x1;
  	int dy = y2-y1;

  	step = abs(dx)>abs(dy)?abs(dx):abs(dy);

  	float xinc = dx/(float)step;
  	float yinc = dy/(float)step;

  	for(int i = 0 ; i <= step ; i++)
  	{
  		putpixel(x,y,RED);
  		x += xinc;
  		y += yinc;
  		delay(500);
  	}
  	closegraph();
  }
  void bresenham()
  {
    void getXY();
  }
};

int main()
{
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
          void DDA();
      break;
      case 2:
          void bresenham(); break;
      default:
        cout<<"Wrong choice !"<<endl;
    }
    cout<<"Do you want to continue ? [Y/N]"<<endl;
    cin>>status;
  } while(status == "y" && status == "Y");
  return 0;
}
