#include<iostream>
#include<graphics.h>
using namespace std;

class Clip{
    int MAX;
    int poly_size;
public:
  Clip(){MAX = 5;}
  //Returns X-value of point of intersection of two line
  int x_intersect(int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4)
  {
      int num = (x1*y2 - y1*x2) * (x3-x4) - (x1-x2) *(x3*y4 - y3*x4);
      int den = (x1-x2) * (y3-y4) - (y1-y2) * (x3-x4);
      if(den == 0)
      {
            cout<<"Error ! X"<<endl;
            exit(EXIT_SUCCESS);
      }
      return num/den;
  }

  //Returns Y-Values of point of intersection of two Line
  int y_intersect(int x1,int y1,int x2,int y2,int x3,int y3,int x4 , int y4)
  {
    int num = (x1*y2 - y1*x2) * (y3-y4) -  (y1-y2) * (x3*y4 - y3*x4);
    int den = (x1-x2) * (y3-y4) - (y1-y2) * (x3-x4);
    if(den == 0)
    {
          cout<<"Error Y!"<<endl;
          exit(EXIT_SUCCESS);
    }
    return num/den;
  }

  //main logic of the program !
  void clip(int poly_points[][2],int x1,int y1,int x2,int y2)
  {
    int new_points[MAX][2],new_poly_size;
    //(ix,iy), (kx,ky) are the co-ordinates values of the points
    for(int i = 0 ; i < poly_size ; i++)
    {
      //i and k form a line in polygon
      int k = (int)(i+1) % poly_size; //intersection end points
      //Init the starting points and the end points for polygon
      int ix = poly_points[i][0],iy = poly_points[i][1];
      int kx = poly_points[k][0],ky = poly_points[k][1];

      //Calculate pos of first points w.r.t. clipper line
      int i_pos = (int)(x2-x1) * (iy-y1) - (y2-y1) * (ix-x1);

      //Calculate pos of second points w.r.t. clipper Line
      int k_pos = (int)(x2-x1)*(ky-y1)-(y2-y1)*(kx-x1);

      //Case 1: When both points are inside !
      if(i_pos < 0 && k_pos < 0)
      {
          //Only second point is added !
          new_points[new_poly_size][0] = kx;
          new_points[new_poly_size][1] = ky;
          new_poly_size++;
      }
      //Case 2 : When only first point is outside
      else if(i_pos >= 0 && k_pos < 0)
      {
        //Point of instersection with edge and the second point
        //is added
        new_points[new_poly_size][0] = x_intersect(x1,y1,x2,y2,ix,iy,kx,ky);
        new_points[new_poly_size][1] = y_intersect(x1,y1,x2,y2,ix,iy,kx,ky);
        new_poly_size++;
        //Second point
        new_points[new_poly_size][0] = kx; //place the second x point
        new_points[new_poly_size][1] = ky; //place the second y point
        new_poly_size++;
      }//Case 3: When only second point is outside
      else if(i_pos < 0 && k_pos >= 0){
        //Only point of intersection with edge is added
        new_points[new_poly_size][0] = x_intersect(x1,y1,x2,y2,ix,iy,kx,ky);
        new_points[new_poly_size][1] = y_intersect(x1,y1,x2,y2,ix,iy,kx,ky);
        new_poly_size++;
      }
      //Case 4: When both the points are outside
      else{
          //No points are added !
      }

      //Update the new vertex co-ordinates
      poly_size = new_poly_size;
      for(int i = 0 ; i < poly_size ; i++)
      {
        poly_points[i][0] = new_points[i][0];
        poly_points[i][1] = new_points[i][1];
      }
    }
  }
  //Main control function
  void sutherClip(int poly_points[][2],int poly_size,int clipper_points[][2],int clipper_size)
  {
    int i;
    //i and k are two consecutive indexs
    for(int i = 0 ; i < clipper_size ; i++) //run number of vertex in clipper window
    {
      int k = (int)(i+1)%clipper_size; //this will calculate upto which vertices it will intersect clockwise direction

      //We pass the current array of vertices , it's size and end points of the selected clipper line
      clip(poly_points,clipper_points[i][0],clipper_points[i][1],clipper_points[k][0],clipper_points[k][1]);
    }
    prepareScreen();
    //Print the vertices of clipped polygon
    for(int i = 0 ; i < poly_size-1;i++)
      line(poly_points[i][0],poly_points[i][1],poly_points[i+1][0],poly_points[i+1][1]);

    line(poly_points[i][0],poly_points[i][1],poly_points[0][0],poly_points[0][1]); //final line to be drawn

    getch();
    closegraph();
  }
  void prepareScreen()
  {
    int xmax,ymax,xmid,ymid;
    int gd = DETECT ,gm = VGAMAX;
    initgraph(&gd,&gm,NULL);
  }
};

int main(){
    Clip obj;
  // Defining polygon vertices in clockwise order
   int poly_size = 3;
   int poly_points[20][2] = {{100,150}, {200,250},
                             {300,200}};

   // Defining clipper polygon vertices in clockwise order
   // 1st Example with square clipper
   int clipper_size = 4;
   int clipper_points[][2] = {{150,150}, {150,200},
                             {200,200}, {200,150} };

                             //Calling the clipping function
    obj.sutherClip(poly_points, poly_size, clipper_points,clipper_size);
  return 0;
}
