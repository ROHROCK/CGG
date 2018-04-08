#include<iostream>
#include<graphics.h>
#include<stdlib.h>

using namespace std;

class point{
public:
  int x,y;
};

class poly{
private:
  point p[20];
  int inter[20],x,y;
  int v,xmin,ymin,xmax,ymax;
public:
  int c; //counter for intersection
  int cl; //color for filling

  /*
  @param : none
  brief: this function will accept the necessary inputs from the user
  */
  void read()
  {
    int i;
    cout<<"\n\t Scan Fill Algorithm"<<endl;
    cout<<"Enter the no of vertices of polygon"<<endl;
    cin>>v;
    if(v>2){
      for(i=0;i<v;i++){
        cout<<"Enter the co-ordinate no: "<<i+1<<": "<<endl;
        cout<<"\t X: "<<(i+1)<<" = ";
        cin>>p[i].x;
        cout<<"\t Y: "<<(i+1)<<" = ";
        cin>>p[i].y;
      }
      cout<<"Enter the color u want:[0-15]: "<<endl;
      cin>>cl;
      //setting the last and first vertex same
      p[i].x = p[0].x;
      p[i].y = p[0].y;
      //setting the min and max for x and y , to be set intial vertex
      xmin=xmax=p[0].x;
      ymin=ymax=p[0].y;
    }else
      cout<<"Enter valid number of vertices: "<<endl;
  }

  /*
  @param: none
  brief: to calculate the x/y min and max points from the vertex
  */
  void calcs()
  {
    for(int i = 0 ; i < v ; i++)
    {
      if(xmin > p[i].x)
        xmin = p[i].x;
      if(xmax < p[i].x)
        xmax = p[i].x;
      if(ymin > p[i].y)
        ymin = p[i].y;
      if(ymax < p[i].y)
        ymax = p[i].y;
    }
  }

  /*
  @param : none
  brief: it will be the logic for printing the scanline one by one
    and it will perform , finding the intersection and sorting them
    according to s which is the value of current scanline .
  */
  void display()
  {
    float s;
    s = ymin+0.01;
    while(s <= ymax)
    {
      ints(s);
      sort(s);
      s++;
    }
  }

  /*
  @param : float z , which defines the scanline
  breif: This is the heart of the code where intersection is found ,
          and stored in inter[]
  */
  void ints(float z)
  {
    int x1,x2,y1,y2,temp;
    c=0;
    for(int i =0;i<v;i++)
    {
      x1 = p[i].x;
      y1 = p[i].y;
      x2 = p[i+1].x;
      y2 = p[i+1].y;
      //check if next vertex is below the current vertex
      if(y2 < y1)
      {
        //swap the current vertex with the next vertex
        temp = x1;
        x1 = x2;
        x2 = temp;

        temp = y1;
        y1 = y2;
        y2 = temp;
      }
      if(z <= y2&& z>= y1)
      {
        if((y1-y2) == 0)
          x = x1;
        else{
          x = ((x2-x1)*(z-y1))/(y2-y1);
          x += x1;
        }

        if(x <= xmax && x >= xmin)
          inter[c++] = x;
      }
    }
  }

  /*
  param : z , which will be the y-axis
  */
  void sort(int z)
  {
    int temp ,j,i;
    setcolor(cl);
    for(int i = 0 ; i < v; i++)
    {
      line(p[i].x,p[i].y,p[i+1].x,p[i+1].y);
    }
    delay(100);
    for(i = 0 ; i < c ; i+= 2) //why +2 ??
    {
      line(inter[i],z,inter[i+1],z);
    }
  }

  void prepareScreen()
  {
    int gd = DETECT , gm = VGAMAX;
    initgraph(&gd,&gm,NULL);
  }
};

int main()
{
  poly x;
  x.read();
  x.calcs();
  x.prepareScreen();
  x.display();
  getch();
  closegraph();
  return 0;
}
