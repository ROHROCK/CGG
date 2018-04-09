/*Write C++/Java program to generate Hilbert curve using concept of fractals
Application in computer graphics :
Because of this locality property, the Hilbert curve is widely used in computer science. For example, the range of IP addresses used by computers can be mapped into a picture using the Hilbert curve.
Code to generate the image would map from 2D to 1D to find the color of each pixel,
and the Hilbert curve is sometimes used because it keeps nearby IP addresses close to each other in the picture.
*/
#include<iostream>
#include<graphics.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

void move(int j,int h,int &x,int &y) //modify the co-ordinates according to the j
{
  if(j==1)
  y-=h;
  else if(j==2)
  x+=h;
  else if(j==3)
  y+=h;
  else if(j==4)
  x-=h;
  lineto(x,y);
}

void hilbert(int r,int d,int l,int u,int i,int h,int &x,int &y) //where r = right , d = down , u = up , l = left
{
  if(i>0)
  {
    i--;
    hilbert(d,r,u,l,i,h,x,y);
    move(r,h,x,y); // j = 2
    hilbert(r,d,l,u,i,h,x,y);
    move(d,h,x,y); // j = 3
    hilbert(r,d,l,u,i,h,x,y);
    move(l,h,x,y); // j = 4
    hilbert(u,l,d,r,i,h,x,y);
  }
}

int main()
{
  int n,x1,y1;
  int x0=10,y0=10,x,y,h=10,r=2,d=3,l=4,u=1;

  cout<<"\nGive the iteration of n: ";
  cin>>n;
  x=x0;y=y0;
  int gm = VGAMAX,gd=DETECT;
  initgraph(&gd,&gm,NULL);
  moveto(x,y);
  hilbert(r,d,l,u,n,h,x,y);
  getch();

  closegraph();

  return 0;
}
