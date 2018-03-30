//Code to perform transformation on rhombus and equilateral triangle
#include<iostream>
#include<graphics.h>

using namespace std;

class transformation{
  int XR[4],YR[4]; //co-ordinates for X and Y rhombus
  int XETri[4],YETri[4]; //co-ordinates for X and Y triangle
  int i;
  int Rhom[4][2];
public:
  void getRhom()
  {
    int XRhom,YRhom;
    int l,b;
    cout<<"Enter the intial points for Rhombus: "<<endl;
    cin>>XRhom>>YRhom;
    cout<<"Enter the length: "<<endl;
    cin>>l;
    cout<<"Enter the breadth: "<<endl;
    cin>>b;

    //Storing the appropiate co-ordinates in array
    XR[0]=XRhom;YR[0]=YRhom;
    XR[1]=XRhom;YR[1]=YRhom-b;
    XR[2]=XRhom+l,YR[2]=YRhom-b;
    XR[3]=XRhom+l,YR[3]=YRhom;
    Rhom[0][0]=  XR[0];
    Rhom[0][1]=YR[0];
    Rhom[1][0]=XR[1];
    Rhom[1][1]=YR[1];
    Rhom[2][0]=XR[2];
    Rhom[2][1]=YR[2];
    Rhom[3][0]=XR[3];
    Rhom[3][1]=YR[3];
  }
  //Code to shear
  void XShear()
  {
    int xs;
    getRhom();
    cout<<"Enter the X Shearing value: "<<endl;
    cin>>xs;
    prepareScreen();
    for(i = 0 ; i < 3 ; i++)
      line(Rhom[i][0],Rhom[i][1],Rhom[i+1][0],Rhom[i+1][1]);

    line(Rhom[i][0],Rhom[i][1],Rhom[0][0],Rhom[0][1]); //Last
    //XShearing

    float XShearMat[2][2] ={{1,0},{xs,1}};
    int mult[4][2]={0};
    // Multiplying matrix a and b and storing in array mult.
   for(int i = 0; i < 4; ++i)
       for(int j = 0; j < 2; ++j)
           for(int k = 0; k < 2; ++k)
           {
               mult[i][j] += Rhom[i][k] * XShearMat[k][j];
           }

    //After Shearing
    //For drawing rhombus on the screen
    setcolor(RED);
    for(i = 0 ; i < 3 ; i++)
      line(mult[i][0],mult[i][1],mult[i+1][0],mult[i+1][1]);

    line(mult[i][0],mult[i][1],mult[0][0],mult[0][1]); //Last
    getch();
    closegraph();

  }
  void YShear()
  {
    int ys;
    getRhom();
    cout<<"Enter the X Shearing value: "<<endl;
    cin>>ys;
    prepareScreen();
    for(i = 0 ; i < 3 ; i++)
      line(Rhom[i][0],Rhom[i][1],Rhom[i+1][0],Rhom[i+1][1]);

    line(Rhom[i][0],Rhom[i][1],Rhom[0][0],Rhom[0][1]); //Last
    //XShearing

    float XShearMat[2][2] ={{1,ys},{0,1}};
    int mult[4][2]={0};
    // Multiplying matrix a and b and storing in array mult.
   for(int i = 0; i < 4; ++i)
       for(int j = 0; j < 2; ++j)
           for(int k = 0; k < 2; ++k)
           {
               mult[i][j] += Rhom[i][k] * XShearMat[k][j];
           }

    //After Shearing
    //For drawing rhombus on the screen
    setcolor(RED);
    for(i = 0 ; i < 3 ; i++)
      line(mult[i][0],mult[i][1],mult[i+1][0],mult[i+1][1]);

    line(mult[i][0],mult[i][1],mult[0][0],mult[0][1]); //Last
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

int main()
{
	transformation dc;

	int ch;
  char status;
  do {
    cout<<"1.To Shear Rhombus X-Axis: "<<endl;
		cout<<"2.To Shear Rhombus Y-Axis: "<<endl;
    cout<<"3.To Shear Equilateral triangle X-Axis: "<<endl;
    cout<<"4.To Shear Equilateral Y-Axis: "<<endl;
    cout<<"5.To Rotate Rhombus: "<<endl;
    cout<<"6.To Rotate Equilateral triangle "<<endl;
    cout<<"7.To Scale Rhombus"<<endl;
    cout<<"8.To Scale Equilateral"<<endl;
    cout<<"10.Exit"<<endl;
    cin>>ch;
    switch (ch) {
      case 10: exit(EXIT_SUCCESS);
      case 1:
				dc.XShear();
      break;
      case 2:
        dc.YShear();
      break;
      case 3:
        dc.XTriShear();
      break;
      case 4:
        dc.YTriShear();
      break;
      case 5:
        dc.RotateTri();
      break;
      case 6:
        dc.RotateRhom();
      break;
      case 7:
        dc.ScaleRhom();
      break;
      case 8:
        sc.ScaleTri();
      break;
      
      default:
        cout<<"Wrong choice !"<<endl;
    }
    cout<<"Do you want to continue ? [Y/N]"<<endl;
    cin>>status;
  } while(status == 'y' || status == 'Y');
	getch();
	closegraph();

	return 0;
}
