//Code to perform transformation on rhombus and equilateral triangle
#include<iostream>
#include<graphics.h>
#define PI 3.14159265
using namespace std;

class transformation{
  int XR[4],YR[4]; //co-ordinates for X and Y rhombus
  int Tri[3][2]; //co-ordinates for X and Y triangle
  int i;
  int Rhom[4][3];
  int angle;
public:
  transformation()
  {
    XR[4]={0};
    YR[4]={0};
    Rhom[4][3]={0};
    Tri[3][2]={0};
  }
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
    cout<<"Enter the Y Shearing value: "<<endl;
    cin>>ys;
    prepareScreen();
    for(i = 0 ; i < 3 ; i++)
      line(Rhom[i][0],Rhom[i][1],Rhom[i+1][0],Rhom[i+1][1]);

    line(Rhom[i][0],Rhom[i][1],Rhom[0][0],Rhom[0][1]); //Last
    //XShearing

    float XShearMat[3][3]={0};

    XShearMat[0][0]=1;
    XShearMat[0][1]=ys;
    XShearMat[1][1]=1;
    XShearMat[2][2]=1;
    // cout<<"Code Check: Rhom -----------"<<endl;
    //  for (int i = 0; i < 4; i++) {
    //    for(int j = 0 ; j < 3 ; j++)
    //      cout<<i<<" "<<j<<" "<<Rhom[i][j]<<endl;
    //  }
    // cout<<"Code Check: -----------"<<endl;
    // cout<<"Code Check: YShear -----------"<<endl;
    //  for (int i = 0; i < 3; i++) {
    //    for(int j = 0 ; j < 3 ; j++)
    //      cout<<i<<" "<<j<<" "<<XShearMat[i][j]<<endl;
    //  }
    // cout<<"Code Check: -----------"<<endl;
    int mult[4][3]={0};
    // Multiplying matrix a and b and storing in array mult.
   for(int i = 0; i < 4; ++i)
       for(int j = 0; j < 3; ++j)
           for(int k = 0; k < 3; ++k)
           {
               mult[i][j] += Rhom[i][k] * XShearMat[k][j];
           }

          // Code check
          // cout<<"Code Check: Result -----------"<<endl;
          //  for (int i = 0; i < 3; i++) {
          //    for(int j = 0 ; j < 3 ; j++)
          //      cout<<i<<" "<<j<<" "<<mult[i][j]<<endl;
          //  }
          // cout<<"Code Check: -----------"<<endl;
    //After Shearing
    //For drawing rhombus on the screen
    setcolor(RED);
    for(i = 0 ; i < 3 ; i++)
      line(mult[i][0],mult[i][1],mult[i+1][0],mult[i+1][1]);

    line(mult[i][0],mult[i][1],mult[0][0],mult[0][1]); //Last
    getch();
    closegraph();

  }

  void getTri()
  {
    int xc=0,yc=0,side=0;
    cout<<"Enter the center points for triangle "<<endl;
    cin>>xc>>yc;
    cout<<"Enter the Length of Equilateral Triangle"<<endl;
    cin>>side;
    int TTri[3][2]={{xc-side,yc+side},
                {xc,yc-side},
                {xc+side,yc+side}};

    // Tri[0][0]=xc-side;
    // Tri[0][1]=yc+side
    //Copy the data to matrix
    for (int i = 0; i < 3; i++) {
      for(int j = 0 ; j < 2 ; j++)
      Tri[i][j]=TTri[i][j];
    }
    //Code check
    // for (int i = 0; i < 3; i++) {
    //   for(int j = 0 ; j < 2 ; j++)
    //     cout<<i<<" "<<j<<" "<<Tri[i][j]<<endl;
    // }

  }
  /*
  Function to perform Shearing on Equilateral Triangle
  */
  void XTriShear()
  {
    int xs,i;
    getTri();
    cout<<"Enter the X Shearing value: "<<endl;
    cin>>xs;
    prepareScreen();
    for(i  = 0 ; i < 2 ; ++i)
      line(Tri[i][0],Tri[i][1],Tri[i+1][0],Tri[i+1][1]);

     line(Tri[i][0],Tri[i][1],Tri[0][0],Tri[0][1]);
    //XShearing

    float XShearMat[2][2];

    XShearMat[0][0]=1;
    XShearMat[0][1]=0;
    XShearMat[1][0]=xs;
    XShearMat[1][1]=1;

    int mult[3][2]={0};

    cout<<"Code Check !:------------------------"<<endl;
    for(int i = 0 ; i < 3 ; i ++)
      for(int j = 0 ; j < 2 ; j ++)
        cout<<"Mult["<<i<<"]"<<"["<<j<<"]="<<mult[i][j]<<endl;
    cout<<"Code Check End------------------------"<<endl;

    // Multiplying matrix a and b and storing in array mult.
   for(int i = 0; i < 3; ++i)
       for(int j = 0; j < 2; ++j)
           for(int k = 0; k < 2; ++k)
           {
               mult[i][j] = mult[i][j] + (Tri[i][k] * XShearMat[k][j]);
           }

    //After Shearing
    //For drawing rhombus on the screen
    setcolor(RED);
    for(i  = 0 ; i < 2 ; i ++)
      line(mult[i][0],mult[i][1],mult[i+1][0],mult[i+1][1]);

    line(mult[i][0],mult[i][1],mult[0][0],mult[0][1]);
    getch();
    closegraph();
  }
  void YTriShear(){
    int SY,i;
    getTri();
    cout<<"Enter the Y Shearing value: "<<endl;
    cin>>SY;
    prepareScreen();
    for(i  = 0 ; i < 2 ; ++i)
      line(Tri[i][0],Tri[i][1],Tri[i+1][0],Tri[i+1][1]);

     line(Tri[i][0],Tri[i][1],Tri[0][0],Tri[0][1]);

    float XShearMat[2][2]={0};

    XShearMat[0][0]=1;
    XShearMat[0][1]=SY;
    XShearMat[1][1]=1;

    int mult[3][2]={0};
    // Multiplying matrix a and b and storing in array mult.
   for(int i = 0; i < 3; ++i)
       for(int j = 0; j < 2; ++j)
           for(int k = 0; k < 2; ++k)
           {
               mult[i][j] = mult[i][j] + (Tri[i][k] * XShearMat[k][j]);
           }

    //After Shearing
    //For drawing rhombus on the screen
    setcolor(RED);
    for(i  = 0 ; i < 2 ; i ++)
      line(mult[i][0],mult[i][1],mult[i+1][0],mult[i+1][1]);

    line(mult[i][0],mult[i][1],mult[0][0],mult[0][1]);
    getch();
    closegraph();
  }
  /*
  Function to perform Rotation on Equilateral Triangle
  */
  void RotateTri(){
    getTri();
    getAngle();
    //Proper data filled
    int result[][2] = CalculateRotation(3,2);

    }
  }
  /*
  Function To Calculate The Rotation Matrix Required
  */
  void CalculateRotation(int row , int col)
  {
    int RotationMat[row][col]={0};
    RotationMat[0][0] = cos(angle*PI/180);
    RotationMat[0][1] = sin(angle*PI/180);
    RotationMat[1][0] = -sin(angle*PI/180);
    RotationMat[1][1] = cos(angle*PI/180);
    //Init result matrix
    int result[row][col]={0};

    for (int i = 0; i < row; i++) {
      for(int j = 0 ; j < col ; j++)
        for(int z = 0 ; z < 2; z++)
            result[i][j] = result[i][j] + (Tri[j][z]*RotationMat[z][j]);

    return result;
  }
  /*
  Function to get angle from user
  */
  void getAngle(){
    cout<<"Enter the rotation Angle: "<<endl;
    cin>>angle;
  }
  void RotateRhom(){}
  //Function To Rotate A Rhombus
  void drawRhom(int Rhom[4][3]){
    Rhom[1][0] +=20;
    Rhom[2][0] += 20;
    for(int i = 0 ; i < 3 ; i++)
      line(Rhom[i][0],Rhom[i][1],Rhom[i+1][0],Rhom[i+1][1]);

    line(Rhom[3][0],Rhom[3][1],Rhom[0][0],Rhom[0][1]);
  }
  //Function To Scale A Rhom
  void ScaleRhom(){
    int Sx,Sy,i;
    getRhom();
    cout<<"Enter the X Scaling value: "<<endl;
    cin>>Sx;
    cout<<"Enter the Y Scaling value: "<<endl;
    cin>>Sy;
    prepareScreen();
    drawRhom(Rhom);
    float ScaleMat[2][2]={0};
    ScaleMat[0][0]=Sx;
    ScaleMat[1][1]=Sy;
    int res[4][3]={0};
    //Calculation
    for(int i =0 ; i < 4 ; i++) //Rows of 1st Mat
    {
      for(int a = 0 ; a < 2 ; a++) //Col of 2nd Mat
        for(int b = 0 ; b < 2 ; b++) //Row of 1nd Mat
          res[i][a] = res[i][a] + (Rhom[i][b] * ScaleMat[b][a]);
    }

    //After Scaling
    setcolor(RED);
    drawRhom(res);
    getch();
    closegraph();
  }
  //Function To Scale A Triangle
  void ScaleTri(){
    int Sx,Sy,i;
    getTri();
    cout<<"Enter the X Scaling value: "<<endl;
    cin>>Sx;
    cout<<"Enter the Y Scaling value: "<<endl;
    cin>>Sy;
    prepareScreen();
    for(i  = 0 ; i < 2 ; ++i)
      line(Tri[i][0],Tri[i][1],Tri[i+1][0],Tri[i+1][1]);

     line(Tri[i][0],Tri[i][1],Tri[0][0],Tri[0][1]);
    //XShearing

    float ScaleMat[2][2]={0};

    ScaleMat[0][0]=Sx;
    ScaleMat[1][1]=Sy;

    int mult[3][2]={0};

    // Multiplying matrix a and b and storing in array mult.
   for(int i = 0; i < 3; ++i)
       for(int j = 0; j < 2; ++j)
           for(int k = 0; k < 2; ++k)
           {
               mult[i][j] = mult[i][j] + (Tri[i][k] * ScaleMat[k][j]);
           }

    //After Shearing
    //For drawing rhombus on the screen
    setcolor(RED);
    for(i  = 0 ; i < 2 ; i ++)
      line(mult[i][0],mult[i][1],mult[i+1][0],mult[i+1][1]);

    line(mult[i][0],mult[i][1],mult[0][0],mult[0][1]);
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
        dc.ScaleTri();
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
