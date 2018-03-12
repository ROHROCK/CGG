/*Write c++ program for line drawing using DDA or bresenham algorithm with
patterns such as solid , dotted , dashed , dash dot and thick*/
#include<graphics.h>
#include<iostream>

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

  void bresenham()
  {
    //int gd = DETECT ,gm = VGAMAX;
    int s1=0,s2=0,exchange_flag=0,i=0;
    float x,y,dy=0 ,dx=0;
    getXY();
    //initgraph(&gd,&gm,NULL);
    prepareScreen();

    dx = abs(x2-x1);
    dy = abs(y2-y1);
    x = x1;
    y = y1;
    s1 =sign(x2-x1);
    s2 =sign(y2-y1);

    putpixel(x1,y1,RED);
    cout<<x<<","<<y;
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
        if (exchange_flag == 1 )
          y = y +s2;
        else
          x = x + s1;

       e = e + 2*dy; //update the error variable
       putpixel(x,y,BLUE);
       i++;
      }while(i <= dx);

	getchar();
  closegraph();
  }
  void bresenhamCustom(int flag) // dotted line
  {
    int counter = 0;
    int s1=0,s2=0,exchange_flag=0,i=0;
    float x,y,dy=0 ,dx=0;
    getXY();
    prepareScreen();
    //-----------------------------ALGO for bresenham
    dx = abs(x2-x1);
    dy = abs(y2-y1);
    x = x1;
    y = y1;
    s1 =sign(x2-x1);
    s2 =sign(y2-y1);

    putpixel(x1,y1,BLUE);
    cout<<x<<","<<y;
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
        if (exchange_flag == 1 )
          y = y +s2;
        else
          x = x + s1;

       e = e + 2*dy; //update the error variable
       if((int)x%2 == 0 && flag == 0)
        putpixel(x,y,BLUE);
       else if(flag == 1 && counter < 4){
          putpixel(x,y,BLUE);
          counter++;
        }
        else if(flag == 1 && counter >= 4)
          counter = 0;

       i++;
      }while(i <= dx);

	getch();
  closegraph();
  }
  void bresenhamDotted_Dash() // dotted line
  {
    int counter = 0;
    int s1=0,s2=0,exchange_flag=0,i=0;
    float x,y,dy=0 ,dx=0;
    getXY();
    prepareScreen();
    //-----------------------------ALGO for bresenham
    dx = abs(x2-x1);
    dy = abs(y2-y1);
    x = x1;
    y = y1;
    s1 =sign(x2-x1);
    s2 =sign(y2-y1);

    putpixel(x1,y1,BLUE);
    cout<<x<<","<<y;
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
        if (exchange_flag == 1 )
          y = y +s2;
        else
          x = x + s1;

       e = e + 2*dy; //update the error variable

       if(counter < 5){
          putpixel(x,y,BLUE);// draw the line
        }
        else if(counter >= 8){
          putpixel(x,y,RED);
          counter = 0;      //draw a single pixel
        }
       counter++;
       i++;
      }while(i <= dx);

	getch();
  closegraph();
  }
  void bresenhamThick() // dotted line
  {
    int counter = 0;
    int s1=0,s2=0,exchange_flag=0,i=0;
    float x,y,dy=0 ,dx=0;
    getXY();
    prepareScreen();
    //-----------------------------ALGO for bresenham
    dx = abs(x2-x1);
    dy = abs(y2-y1);
    x = x1;
    y = y1;
    s1 =sign(x2-x1);
    s2 =sign(y2-y1);

    putpixel(x1,y1,BLUE);
    cout<<x<<","<<y;
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
        if (exchange_flag == 1 )
          y = y +s2;
        else
          x = x + s1;

       e = e + 2*dy; //update the error variable

       putpixel(x,y,BLUE);// draw the line
       putpixel(x+0.5,y+0.5,BLUE);
       putpixel(x-0.5,y+0.5,BLUE);
       i++;
      }while(i <= dx);

	getch();
  closegraph();
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
    cout<<"1.Draw Plain Line"<<endl;
    cout<<"2.Draw Dotted Line"<<endl;
    cout<<"3.Draw Dash Line"<<endl;
    cout<<"4.Draw Dash + Dotted Line"<<endl;
    cout<<"5.Draw Thick Line"<<endl;
    cout<<"6.Exit"<<endl;
    cin>>ch;
    switch (ch) {
      case 6: exit(EXIT_SUCCESS);
      case 1:
          obj.bresenham(); break;
      case 2:
          obj.bresenhamCustom(0); break;
     case 3:
          obj.bresenhamCustom(1); break;
     case 4:
          obj.bresenhamDotted_Dash(); break;
     case 5:
          obj.bresenhamThick(); break;

      default:
        cout<<"Wrong choice !"<<endl;
    }
    cout<<"Do you want to continue ? [Y/N]"<<endl;
    cin>>status;
  } while(status == 'y' || status == 'Y');
  return 0;
}
