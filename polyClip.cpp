//Cohen sutherland polyclipping
#include<iostream>
#include<graphics.h>
#include<stdio.h>

using namespace std;

typedef struct edge{
  int xco,yco;
}EDG;

typedef struct window{
  int xc,yc;
}WIN;
int i , indx;
EDG ed[30]; //For edge
WIN wi[4]; //Window

//--------------------
class clipp{
public:
    int button,x,y;
    int edg_count;
    EDG edpt[50],edpt1[50];

    void accept_window();
    void draw_window();
    void init_graph();
    void accept_poly();
    void suth_hodge();
}

//Main logic to modify
clipp::suth_hodge()
{
  int i = 0,j = 1, k = 0;
  int interx,intery; //intercept x and intercept y
  //considering the left boundary
  for(int i = 0 ; i <= edg_count ; i++)
  {
    if(ed[i].xco < wi[1].xc && ed[i+1].xco > wi[1].xc) //outside to inside
    //check if edge is outside from the left boundary and
    {
      interx = wi[1].xc;
      intery = (((wi[1].xc-ed[i].xco)*(ed[i].yco-ed[i+1].yco))/(ed[i].xco-ed[i+1].xco))+ed[i].yco;
      circle(interx,intery,2);
      edpt[j].xco = interx;
      edpt[j].yco = intery;
      j++;
      edpt[j].xco = edi[i+1].xco;
      edpt[j].yco = edi[i+1].yco;
      circle(edpt[j].xco,edpt[j].yco,2);
      j++;
    }else if(ed[i].xco > wi[1].xc && edi[i+1].xco > wi[1].xc) //inside to inside
    {
      edpt[j].xco = ed[i+1].xco;
      edpt[j].yco = ed[i+1].yco;
      circle(edpt[j].xco,edpt[j].yco,2);
      j++;
    }else if(ed[i].xco > wi[1].xc && edi[i+1].xco < wi[i].xc) //inside to outside
    {
      interx = wi[1].xc;
      intery = (((wi[1].xc - ed[i].xco )*(ed[i].yco - ed[i+1].yco))/(ed[i].xco - ed[i+1].xco))+ed[i].yco;
      edpt[j].xco = interx;
      edpt[j].yco = intery;
      circle(edpt[j].xco , edpt[j].yco,2);
      j++;
    }
  }

  draw_window();
  setcolor(WHITE);
  //Disp tehe left clip poly
  outtextxy(150,80,"Left clip Polygon will be: ");

  //Draw the polygon
  for(int i = 1; i < j ; i++)
    line(edpt[i].xco,edpt[i].yco,edpt[i+1].xco,edpt[i+1].yco);

  line(edpt[i].xco,edpt[i].yco,edpt[1].xco,edpt[1].yco);
  edpt[j].xco = edpt[1].xco;
  edpt[j].yco = edpt[1].yco;
  getch();  //considering the right boundary
  k = 1;

  for(i = 1 ; i < j ; i++)
  {
    if(edpt[i].xco < wi[2].xc && edpt[i+1].xco > wi[2].xc){
      //inside to outside
      interx = wi[2].xc;
      intery = (((wi[2].xc - ed[i].xco )*(ed[i].yco - ed[i+1].yco))/(ed[i].xco - ed[i+1].xco))+ed[i].yco;
      edpt1[k].xco = interx;
      edpt1[k].yco = intery;
      circle(edpt1[k].xco,edpt1[k].yco,2);
      k++;
    }

    if(edpt[i].xco > wi[2].xc && edpt[i+1].xco < wi[2].xc)
    {
      //outside to inside
      interx = wi[2].xc;
      intery = (((wi[2].xc - ed[i].xco )*(ed[i].yco - ed[i+1].yco))/(ed[i].xco - ed[i+1].xco))+ed[i].yco;
      edpt1[k].xco = interx;
      edpt1[k].yco = intery;
      circle(edpt1[k].xco,edpt1[k].yco,2);
      k++;
      edpt1[k].xco = edpt[i+1].xco;
      edpt1[k].yco = edpt[i+1].yco;
      circle(edpt1[k].xco,edpt1[k].yco,2);
      k++;
    }

    //inside outside code page 4-44
  }
}
