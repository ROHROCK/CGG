//#include <conio.h>
#include <iostream>
#include <graphics.h>
#include <stdlib.h>
using namespace std;

//Declaration of class point
class point
{
    public:
    int x,y;
};

class poly
{
    private:
        point p[20]; //EDGE TABLE
        int inter[20],x,y;
        int v,xmin,ymin,xmax,ymax;

    public:
        int c;
        int cl;
        void read(); //ok
        void calcs(); //ok
        void display();
        void ints(float);
        void sort(int);
        void prepareScreen();
};


void poly::read()
{
    int i;
    cout<<"\n\t SCAN_FILL ALGORITHM";
    cout<<"\n Enter the no of vertices of polygon:";
    cin>>v;
    if(v>2) //polygon is possible or not
    {
        for(i=0;i<v; i++) //ACCEPT THE VERTICES
        {
            cout<<"\nEnter the co-ordinate no.- "<<i+1<<" : ";
            cout<<"\n\tx"<<(i+1)<<"=";
            cin>>p[i].x;
            cout<<"\n\ty"<<(i+1)<<"=";
            cin>>p[i].y;
        }
        cout<<"\n\tEnter the colour u want:(0-15)->"; //Selecting colour
        cin>>cl;
        //setting the last and first vertex same
        p[i].x=p[0].x;
        p[i].y=p[0].y;
        //setting the min and max for x and y , to be set intiall vetex
        xmin=xmax=p[0].x;
        ymin=ymax=p[0].y;
    }
    else
        cout<<"\n Enter valid no. of vertices.";
}
//FUNCTION FOR FINDING
void poly::calcs()
{ //MAX,MIN
    for(int i=0;i<v;i++)
    {
        if(xmin>p[i].x)
          xmin=p[i].x;
        if(xmax<p[i].x)
          xmax=p[i].x;
        if(ymin>p[i].y)
          ymin=p[i].y;
        if(ymax<p[i].y)
          ymax=p[i].y;
    }
}
//DISPLAY FUNCTION
void poly::display()
{
    float s;

    s=ymin+0.1; //???

    while(s<=ymax)
    {
        ints(s);
        sort(s);
        s++;
    }
}

void poly::ints(float z) //DEFINE FUNCTION INTS
{
    int x1,x2,y1,y2,temp;
    c=0;
    for(int i=0;i<v;i++) //run till n vectices
    {
        //x1,y1 = current vertex , x2,y2 = next vertex
        x1=p[i].x;
        y1=p[i].y;
        x2=p[i+1].x;
        y2=p[i+1].y;
        //check if next vertex is below the current vertex
        if(y2<y1)
        {
          // swap the current vertex with next vertex;
            temp=x1;
            x1=x2;
            x2=temp;
            temp=y1;
            y1=y2;
            y2=temp;
        }
        //check if the scanline is in the valid position .. meaning in-between y2 and y1
        if(z<=y2&&z>=y1)
        {
            if((y1-y2)==0) //if the difference is 0 then no scanline will be printed hence only store x with currect vertex x
              x=x1;
            else // used to make changes in x. so that we can fill our polygon after certain distance
              {
                  x=((x2-x1)*(z-y1))/(y2-y1); //formula to calculate the x cordinate
                  x=x+x1; //update the x co=ordinate
              }
            if(x<=xmax && x>=xmin) //if the x value is between the range
              inter[c++]=x;       //intersection x is stored
        }
    }
}

void poly::sort(int z) //SORT FUNCTION
{
    int temp,j,i;
        setcolor(cl);
        for(i=0;i<v;i++)
        {
            line(p[i].x,p[i].y,p[i+1].x,p[i+1].y); // used to make hollow outlines of a polygon
        }
        delay(100);
        for(i=0; i<c;i+=2)
        {
            // delay(50);
            line(inter[i],z,inter[i+1],z);  // Used to fill the polygon ....
        }
}

void poly::prepareScreen(){
    int gm= VGAMAX,gd= DETECT;
    initgraph(&gd, &gm, NULL);
}
int main() //START OF MAIN
{
    poly x;
    x.read();
    x.calcs();
    x.prepareScreen();
    x.display();
    getch();
    closegraph(); //CLOSE OF GRAPH
    return 0;
}
