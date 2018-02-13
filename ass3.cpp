//2D transformation program
#include<iostream>
#include<graphics.h>
// Using macros to convert degree to radian
// and call sin() and cos() as these functions
// take input in radians
#define SIN(x) sin(x * 3.141592653589/180)
#define COS(x) cos(x * 3.141592653589/180)

using namespace std;

class transformation{
  int Sx,Sy,T[2];
  int x[3],y[3]; //this will store three lines to draw a triangle
  int x1[3];
  int y1[3];
public:
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
    // xc = xc + xmid; //xmid value taken from the graphics lib and calculate the the centre of the circle x pos
    // yc = ymid - yc; //ymid value taken from the graphics lib
  }

  //it
  void rotate(int x_pivot, int y_pivot,
            int angle)
  {
      int x1[3],y1[3];
      for(int i = 0 ; i < 3 ; i++)
      {
          x1[i] = x[i];
          y1[i] = y[i];
      }
      int i = 0;
      while (i < 3) //3 is the size of array
      {
          // Shifting the pivot point to the origin
          // and the given points accordingly
          int x_shifted = x[i] - x_pivot;
          int y_shifted = y[i] - y_pivot;

          // Calculating the rotated point co-ordinates
          // and shifting it back
          x[i] = x_pivot + (x_shifted*COS(angle)
                            - y_shifted*SIN(angle));
          y[i] = y_pivot + (x_shifted*SIN(angle)
                            + y_shifted*COS(angle));
          i++;
      }
      prepareScreen();
      //print the original coordinates
      line(x1[0],y1[0],x1[1],y1[1]);
      line(x1[1],y1[1],x1[2],y1[2]);
      line(x1[2],y1[2],x1[0],y1[0]);
      //print the rotated cordinates
      for(int i = 0 ; i < 2 ; i++)
      {
      	line(x[i],y[i],x[i+1],y[i+1]);
      }
      line(x[2],y[2],x[0],y[0]);
      getch();
      closegraph();
  }
  void rotateFunction()
  {
    int angle = 0;
    cout<<"Enter the angle: "<<endl;
    cin>>angle;
    rotate(0,0,angle);//first two arguments are pivotx and pivoty
  }

  //accept the values f
  void getCo()
  {
    cout<<"Enter the co-ordinates for triangle: "<<endl;
    for(int i = 0 ; i < 3 ; i++)
    {
      cout<<"Enter the x and y co-ordinates"<<i+1<<": "<<endl;
      cin>>x[i]>>y[i];
    }
  }
  void getS(){
    cout<<"Enter the Sx: "<<endl;
    cin>>Sx;
    cout<<"Enter the Sy: "<<endl;
    cin>>Sy;
  }

  void scaleFunction()
  {
    getS();
    prepareScreen();
    drawTriangle();
    scale();
  }
  void drawTriangle()
  {
    //code to draw a triangle
    line(x[0],y[0],x[1],y[1]);
    line(x[1],y[1],x[2],y[2]);
    line(x[2],y[2],x[0],y[0]);
  }
  //this code will scale the corrdinates array by getting the scale value for the user
  void scale()
  {
    int scale[2][2] = {Sx,0,0,Sy}; //Init the scale matrix
    int p[2][1];
    //scaling the traingle
    for(int i = 0 ; i < 3 ; i++)
    {
      p[0][0] = x[i];
      p[1][0] = y[i];

      int temp[2][1] = {0};
      for(int a = 0 ; a < 2; a++)
        for(int j = 0 ; j < 1 ; j++)
          for(int k = 0 ; k < 2 ; k++)
            temp[a][j] += (scale[a][k] * p[k][j]);

      p[0][0] = temp[0][0];
      p[1][0] = temp[1][0];

      x[i] = p[0][0];
      y[i] = p[1][0];
    }

    //After Scaling
    line(x[0],y[0],x[1],y[1]);
    line(x[1],y[1],x[2],y[2]);
    line(x[2],y[2],x[0],y[0]);
    getch();
    closegraph();
  }

  void translationFunction()
  {
    translationInputs();
    prepareScreen();
    drawTriangle();
    //Draw the tanslated points
    line(x1[0],y1[0],x1[1],y1[1]);
    line(x1[1],y1[1],x1[2],y1[2]);
    line(x1[2],y1[2],x1[0],y1[0]);
    getch();
    closegraph();
  }
  void translationInputs()
  {
    cout<<"Enter the translation Factor For X and Y : "<<endl;
    cin>>T[0]>>T[1];
    for(int i = 0 ; i < 3 ; i ++)
    {
        x1[i] = x[i];
        y1[i] = y[i];
        x1[i]+=T[0];
        y1[i]+=T[1];
    }
  }
};

int main(){
    transformation obj;
  	int ch;
    char status;
    do {
      obj.getCo();
      cout<<"1.Scaling of Object: "<<endl;
  		cout<<"2.Translation of Object:  "<<endl;
      cout<<"3.Rotation of Object"<<endl;
      cout<<"4.Exit"<<endl;
      cout<<"**********************"<<endl;
      cout<<"Enter your choice: "<<endl;
      cin>>ch;
      switch (ch) {
        case 4: exit(EXIT_SUCCESS);
        case 1:
          obj.scaleFunction();
        break;

  			case 2:
  				obj.translationFunction();
  			break;

        case 3:
          obj.rotateFunction();
        break;
        default:
          cout<<"Wrong choice !"<<endl;
      }
      cout<<"Do you want to continue ? [Y/N]"<<endl;
      cin>>status;
    } while(status == 'y' || status == 'Y');
    return 0;
}
