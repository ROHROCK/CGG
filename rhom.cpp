//Code to perform transformation on rhombus and equilateral triangle
#include<iostream>
#include<graphics.h>

using namespace std;

class transformation{
  int XRhom,YRhom; //co-ordinates for X and Y rhombus
  int XETri[4],YETrip[4]; //co-ordinates for X and Y triangle
public:
  void getRhom()
  {
    int l,b;
    cout<<"Enter the vertex points for Rhombus: "<<endl;
    cin>>XRhom>>YRhom;
    cout<<"Enter the length: "<<endl;
    cin>>l;
    cout<<"Enter the breadth: "<<endl;
    cin>>b;
    int X[]
    prepareScreen();
    line(XRhom,YRhom,XRhom+20,b);
    line(XRhom+20,b,XRhom+l+20,b);
    line(XRhom+l+20,b,XRhom+l,YRhom);
    line(XRhom+l,YRhom,XRhom,YRhom);
    getch();
    closegraph();
  }
  //Code to shear
  void XShear()
  {
    //XShearing
    int xs;
    cout<<"Enter the X Shearing value: "<<endl;
    cin>>xs;

    int XShearMat[][]
  }
  void YShear()
  {
    int ys;
    cout<<"Enter the y Shearing value: "<<endl;
    cin>>ys;

  }
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
				dc.getRhom();
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
