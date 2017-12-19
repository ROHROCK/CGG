#include<graphics.h>
#include<stdio.h>
#include<math.h>
#include<iostream>

int main()
{
	int gd = DETECT,gm=VGAMAX;
	int x =1,y = 1,x1 = 150,y1 = 150,dx,dy;
	float step;

	initgraph(&gd,&gm,NULL);	
	//cout<<"Enter the Value of x1 and y1: "<<endl;
	//cin>>x>>y;
	//cout<<"Enter the Value of x2 and y2: "<<endl;
	//cin>>x1>>y1;

	dx = x1-x;
	dy = y1-y;

	step = abs(dx)>abs(dy)?abs(dx):abs(dy);

	float xinc = dx/(float)step;
	float yinc = dy/(float)step;

	

	for(int i = 0 ; i <= step ; i++)
	{
		putpixel(x,y,RED);
		x += xinc;
		y += yinc;
		delay(500);
	}
	closegraph();

	return 0 ;
}

