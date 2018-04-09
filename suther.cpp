#include<iostream>
#include<graphics.h>
#define round(a) ((int)(a+0.5))
int k; //use as global INDEX for arr[20]
float xmin,ymin,xmax,ymax,arr[20],m;
using namespace std;

/*
  @param : x1 ,y1 - first vertex , x2 , y2 -second vertex
  brief: This function will clip the left side of the polygon
*/
void clipl(float x1,float y1,float x2,float y2)
{
    //Check if the second vertex to the right side of first vertex
    if(x2-x1)
        m=(y2-y1)/(x2-x1); //then calculate the slope of line
    else
        m=100000; //else conside the slope to be indefinate...

    //if both vertex are right side meaning .. BOTH vertex INSIDE
    //Then ... only add the second vertex the output arr
    if(x1 >= xmin && x2 >= xmin)
    {
        arr[k]=x2;
        arr[k+1]=y2;
        k+=2; //inc the array index by 2 ...
    }
    //If first vertex is OUTSIDE and second vertex in INSIDE
    //Then .... find the point of intersection and store both vertices
    if(x1 < xmin && x2 >= xmin)
    {
        //calculate the intersected point ...
        arr[k]=xmin; //point of intersection
        arr[k+1]=y1+m*(xmin-x1); //calculate the y-coordinate for new intersected point
        //Then store the second vertex in the output arr
        arr[k+2]=x2;
        arr[k+3]=y2;
        k+=4; //as 2 vertices are entered into the array
    }
    //If first vertex is INSIDE and second vertex is OUTSIDE ...
    //Then ... find the intersection point only and store it
    if(x1 >= xmin  && x2 < xmin)
    {
        arr[k]=xmin;
        arr[k+1]=y1+m*(xmin-x1); //self explainable ...
        k+=2;
    }
}
void clipt(float x1,float y1,float x2,float y2)
{
    if(y2-y1)
        m=(x2-x1)/(y2-y1);
    else
        m=100000;
    if(y1 <= ymax && y2 <= ymax)
    {
        arr[k]=x2;
        arr[k+1]=y2;
        k+=2;
    }
    if(y1 > ymax && y2 <= ymax)
    {
        arr[k]=x1+m*(ymax-y1);
        arr[k+1]=ymax;
        arr[k+2]=x2;
        arr[k+3]=y2;
        k+=4;
    }
    if(y1 <= ymax  && y2 > ymax)
    {
        arr[k]=x1+m*(ymax-y1);
        arr[k+1]=ymax;
        k+=2;
    }
}

void clipr(float x1,float y1,float x2,float y2)
{
    if(x2-x1)
        m=(y2-y1)/(x2-x1);
    else
        m=100000;
    if(x1 <= xmax && x2 <= xmax)
    {
        arr[k]=x2;
        arr[k+1]=y2;
        k+=2;
    }
    if(x1 > xmax && x2 <= xmax)
    {
        arr[k]=xmax;
        arr[k+1]=y1+m*(xmax-x1);
        arr[k+2]=x2;
        arr[k+3]=y2;
        k+=4;
    }
    if(x1 <= xmax  && x2 > xmax)
    {
        arr[k]=xmax;
        arr[k+1]=y1+m*(xmax-x1);
        k+=2;
    }
}

void clipb(float x1,float y1,float x2,float y2)
{
    if(y2-y1)
        m=(x2-x1)/(y2-y1);
    else
        m=100000;
    if(y1 >= ymin && y2 >= ymin)
    {
        arr[k]=x2;
        arr[k+1]=y2;
        k+=2;
    }
    if(y1 < ymin && y2 >= ymin)
    {
        arr[k]=x1+m*(ymin-y1);
        arr[k+1]=ymin;
        arr[k+2]=x2;
        arr[k+3]=y2;
        k+=4;
    }
    if(y1 >= ymin  && y2 < ymin)
    {
        arr[k]=x1+m*(ymin-y1);
        arr[k+1]=ymin;
        k+=2;
    }
}

void prepareScreen()
{
    int gdriver=DETECT,gmode=VGAMAX;
    initgraph(&gdriver,&gmode,NULL);
}

int main()
{
    int n,i,polyy[20],poly[20];
    float xi,yi,xf,yf;
    cout<<"Coordinates of rectangular clip window :\nxmin,ymin :";
    cin>>xmin>>ymin;
    cout<<"xmax,ymax  :";
    cin>>xmax>>ymax;
    cout<<"\n\nPolygon to be clipped :\nNumber of sides :";
    cin>>n;
    cout<<"Enter the coordinates :";
    for(i=0;i<2*n;i++) //get the vertex from the user
	   cin>>polyy[i]; //store in array .. which is in floating point

    //store the starting point and end points are same as it is polygon
    polyy[i]=polyy[0]; //x
    polyy[i+1]=polyy[1]; //y points

    //create a copy of vertiex in poly[]
    for(i=0;i < 2*n+2;i++)
	     poly[i]= polyy[i];

    prepareScreen();
    setcolor(RED);
    rectangle(xmin,ymax,xmax,ymin);

    setcolor(WHITE);
    fillpoly(n,polyy); //fill the polygon by WHITE color
	  getch(); //accept input then continue ..
    cleardevice(); //to redraw to the output screen
    k=0;

    //clip LEFT for first vertex and second vertex
    for(i=0;i < 2*n;i+=2)
		  clipl(polyy[i],polyy[i+1],polyy[i+2],polyy[i+3]);

    n=k/2; //number of sides will divide by 2
    cout<<k<<" "<<n;
    for(i=0;i < k;i++) //This might not run
		  polyy[i]=arr[i];

    polyy[i]=polyy[0];
    polyy[i+1]=polyy[1];
    k=0;

    for(i=0;i < 2*n;i+=2)
		  clipt(polyy[i],polyy[i+1],polyy[i+2],polyy[i+3]);

    n=k/2;
    for(i=0;i < k;i++)
		  polyy[i]=arr[i];

    polyy[i]=polyy[0];
    polyy[i+1]=polyy[1];
    k=0;
    for(i=0;i < 2*n;i+=2)
		  clipr(polyy[i],polyy[i+1],polyy[i+2],polyy[i+3]);

    n=k/2;

    for(i=0;i < k;i++)
		  polyy[i]=arr[i];

    polyy[i]=polyy[0];
    polyy[i+1]=polyy[1];
    k=0;
    for(i=0;i < 2*n;i+=2)
		  clipb(polyy[i],polyy[i+1],polyy[i+2],polyy[i+3]);
    for(i=0;i < k;i++)
		  poly[i]=round(arr[i]);
    if(k)
		  fillpoly(k/2,poly);
    setcolor(RED);
    rectangle(xmin,ymax,xmax,ymin);
    //cout<<"\tCLIPPED POLYGON";
    getch();
    closegraph();
    return 0;
}
