/*Write C++/Java program to fill polygon using scan line algorithm. Use mouse interfacing to
draw polygon.*/


#include<iostream>
#include<graphics.h>
#include<stdlib.h>

using namespace std;

//const int max =10;
#define max 10
class polygon
{

public :

int n , a[max][2];
int bcolor ,newcolor;
polygon()
{ n=6;
  bcolor=2;
  newcolor=4;
  a[0][0]=20;    a[0][1]=20;
  a[1][0]=60;    a[1][1]=60;
  a[2][0]=120;   a[2][1]=30;
  a[3][0]=200;    a[3][1]=250;
  a[4][0]=120;   a[4][1]=200;
  a[5][0]=20;    a[5][1]=200;
}

void getdata();
void drawpoly();
void scanline();
};

void polygon::scanline()
{ int ymax=a[0][1] , ymin=a[0][1] ,xmin=a[0][0] ,xmax=a[0][0] ;
   for(int i=0 ; i< n ;i++)
	{
        if(xmax<a[i][0])
		{
		   xmax=a[i][0];
		}
        if(xmin>a[i][0])
		{
	        xmin=a[i][0];
		}

	   if(ymin>a[i][1])
		{
	        ymin=a[i][1];
		}
	   if(ymax<=a[i][1])
		{
	        ymax=a[i][1];
		}
	}

cout<<"\n\nxmax ::"<<xmax<<"\n Xmin::"<<xmin<<endl;
cout<<"ymax ::"<<ymax<<"\nymin "<<ymin<<endl;
//x=639
 ymax = 450;
 //ymax=479 ; ymin= 0 ;xmin=0 ;xmax=630;
int ty=ymin+1 ,tx=xmin ,flag=0 ;
	while(ty!=ymax )
		{ tx=xmin;
      //cout<<"nayan";
 		  //putpixel(tx,ty ,BLUE);
      flag=0;
      while( tx!=xmax)
      {  //cout<<"ty"<<ty<<endl;
        if(bcolor==getpixel(tx,ty))
         {
           if(flag==1)
           {flag=0;}
           else if(flag==0)
           {flag=1;}
         }
         //delay(1);
        if(flag==1)
         { //while(bcolor!=getpixel(tx,ty) && tx<xmax){
              putpixel(tx,ty,newcolor);
            //tx++;
            //}
         }
            tx++;
      }
      //if(tx==xmin)
      ty++;

    }


}
void polygon::getdata()
{
   cout<<"\nEnter the total Edges present :" ;
   cin>>n;

 	for(int i = 0 ; i< n ;i++ )
	{  cout<<"\n  Enter the co-ordinate(x,y) : ";
  	   cin>>a[i][0]>>a[i][1];

	}
}


void polygon::drawpoly()
{
 setcolor(2);
    for(int i= 0 ; i< n-1 ;i++)
	{
	   line(a[i][0],a[i][1],a[i+1][0],a[i+1][1]);
	}
   line(a[0][0],a[0][1],a[n-1][0],a[n-1][1]);
}
int main()
{

     polygon p1;
    // p1.getdata();


   int gd ,gm ;
   gd=DETECT;
   gm=VGAMAX;
   initgraph(&gd ,&gm , NULL);
   setcolor(GREEN);
   rectangle(250,250,300,300);
   p1.drawpoly();
   p1.scanline();
   p1.drawpoly();
	getch();

}
