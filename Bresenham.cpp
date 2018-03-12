// C++ program for Bresenham’s Line Generation
// Assumptions :
// 1) Line is drawn from left to right.
// 2) x1 < x2 and y1< y2
// 3) Slope of the line is between 0 and 1.
//    We draw a line from lower left to upper
//    right.
#include<bits/stdc++.h>
using namespace std;

// function for line generation
void bresenham(int x1, int y1, int x2, int y2)
{
  //To enable graphics for ubuntu
   // int gd = DETECT,gm=VGAMAX;
   // initgraph(&gd,&gm,NULL);

   int m_new = 2 * (y2 - y1);
   int slope_error_new = m_new - (x2 - x1);
   for (int x = x1, y = y1; x <= x2; x++)
   {
     //plot the pixel

      //putpixel(x,y,RED);
      cout<<x<<","<<y<<endl;

      // Add slope to increment angle formed
      slope_error_new += m_new;

      // Slope error reached limit, time to
      // increment y and update slope error.
      if (slope_error_new >= 0)
      {
         y++;
         slope_error_new  -= 2 * (x2 - x1);
      }
      cout<<"Error: "<<slope_error_new;
   }
  // closegraph();
}

// driver function
int main()
{
  int x1 = 0, y1 = 0, x2 = 8, y2 = -4;
  bresenham(x1, y1, x2, y2);
  return 0;
}
