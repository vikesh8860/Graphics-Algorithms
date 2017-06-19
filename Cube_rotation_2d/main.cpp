
//only rotation about z-axis
// cube    E     F
//      H  |   G |
//      |  A   | B
//      D      C
#include <iostream>
#include <bits/stdc++.h>
#include <graphics.h>
typedef struct point point;
#define M_PI 3.14159
using namespace std;
struct point
{
  double x,y,z;
};
double angle=(M_PI*2)/180;
double t[20];
struct point p[100];
void one(point a,point b,point c,point d,int i,int j,int p1,int p2);


void rotate_about_z()
{

    t[0]=(p[0].x)*cos(angle)-(p[0].y)*sin(angle);   t[1]=(p[0].x)*sin(angle)+(p[0].y)*cos(angle);
    t[2]=(p[1].x)*cos(angle)-(p[1].y)*sin(angle);   t[3]=(p[1].x)*sin(angle)+(p[1].y)*cos(angle);
    t[4]=(p[4].x)*cos(angle)-(p[4].y)*sin(angle);   t[5]=(p[4].x)*sin(angle)+(p[4].y)*cos(angle);
    t[6]=(p[5].x)*cos(angle)-(p[5].y)*sin(angle);   t[7]=(p[5].x)*sin(angle)+(p[5].y)*cos(angle);
    t[8]=(p[2].x)*cos(angle)-(p[2].y)*sin(angle);   t[9]=(p[2].x)*sin(angle)+(p[2].y)*cos(angle);
    t[10]=(p[3].x)*cos(angle)-(p[3].y)*sin(angle);  t[11]=(p[3].x)*sin(angle)+(p[3].y)*cos(angle);
    t[12]=(p[7].x)*cos(angle)-(p[7].y)*sin(angle);  t[13]=(p[7].x)*sin(angle)+(p[7].y)*cos(angle);
    t[14]=(p[6].x)*cos(angle)-(p[6].y)*sin(angle);  t[15]=(p[6].x)*sin(angle)+(p[6].y)*cos(angle);
    p[0].x=t[0];p[0].y=t[1];p[1].x=t[2];p[4].x=t[4];p[5].x=t[6];p[2].x=t[8];p[3].x=t[10];p[7].x=t[12];
    p[6].x=t[14];p[1].y=t[3];p[4].y=t[5];p[5].y=t[7];p[2].y=t[9];p[3].y=t[11];p[7].y=t[13];p[6].y=t[15];
}
void rotate_about_x()
{

    t[0]=(p[0].y)*cos(angle)-(p[0].z)*sin(angle);   t[1]=(p[0].y)*sin(angle)+(p[0].z)*cos(angle);
    t[2]=(p[1].y)*cos(angle)-(p[1].z)*sin(angle);   t[3]=(p[1].y)*sin(angle)+(p[1].z)*cos(angle);
    t[4]=(p[4].y)*cos(angle)-(p[4].z)*sin(angle);   t[5]=(p[4].y)*sin(angle)+(p[4].z)*cos(angle);
    t[6]=(p[5].y)*cos(angle)-(p[5].z)*sin(angle);   t[7]=(p[5].y)*sin(angle)+(p[5].z)*cos(angle);
    t[8]=(p[2].y)*cos(angle)-(p[2].z)*sin(angle);   t[9]=(p[2].y)*sin(angle)+(p[2].z)*cos(angle);
    t[10]=(p[3].y)*cos(angle)-(p[3].z)*sin(angle);  t[11]=(p[3].y)*sin(angle)+(p[3].z)*cos(angle);
    t[12]=(p[7].y)*cos(angle)-(p[7].z)*sin(angle);  t[13]=(p[7].y)*sin(angle)+(p[7].z)*cos(angle);
    t[14]=(p[6].y)*cos(angle)-(p[6].z)*sin(angle);  t[15]=(p[6].y)*sin(angle)+(p[6].z)*cos(angle);
    p[0].y=t[0];p[0].z=t[1];p[1].y=t[2];p[4].y=t[4];p[5].y=t[6];p[2].y=t[8];p[3].y=t[10];p[7].y=t[12];
    p[6].y=t[14];p[1].z=t[3];p[4].z=t[5];p[5].z=t[7];p[2].z=t[9];p[3].z=t[11];p[7].z=t[13];p[6].z=t[15];
}
void rotate_about_y()
{

    t[0]=(p[0].z)*cos(angle)-(p[0].x)*sin(angle);   t[1]=(p[0].z)*sin(angle)+(p[0].x)*cos(angle);
    t[2]=(p[1].z)*cos(angle)-(p[1].x)*sin(angle);   t[3]=(p[1].z)*sin(angle)+(p[1].x)*cos(angle);
    t[4]=(p[4].z)*cos(angle)-(p[4].x)*sin(angle);   t[5]=(p[4].z)*sin(angle)+(p[4].x)*cos(angle);
    t[6]=(p[5].z)*cos(angle)-(p[5].x)*sin(angle);   t[7]=(p[5].z)*sin(angle)+(p[5].x)*cos(angle);
    t[8]=(p[2].z)*cos(angle)-(p[2].x)*sin(angle);   t[9]=(p[2].z)*sin(angle)+(p[2].x)*cos(angle);
    t[10]=(p[3].z)*cos(angle)-(p[3].x)*sin(angle);  t[11]=(p[3].z)*sin(angle)+(p[3].x)*cos(angle);
    t[12]=(p[7].z)*cos(angle)-(p[7].x)*sin(angle);  t[13]=(p[7].z)*sin(angle)+(p[7].x)*cos(angle);
    t[14]=(p[6].z)*cos(angle)-(p[6].x)*sin(angle);  t[15]=(p[6].z)*sin(angle)+(p[6].x)*cos(angle);
    p[0].z=t[0];p[0].x=t[1];p[1].z=t[2];p[4].z=t[4];p[5].z=t[6];p[2].z=t[8];p[3].z=t[10];p[7].z=t[12];
    p[6].z=t[14];p[1].x=t[3];p[4].x=t[5];p[5].x=t[7];p[2].x=t[9];p[3].x=t[11];p[7].x=t[13];p[6].x=t[15];
}
void draw_cube_front()
{
    //draw the front view of the cube
    line(120+p[0].x,200-p[0].y,120+p[1].x,200-p[1].y);
    line(120+p[1].x,200-p[1].y,120+p[2].x,200-p[2].y);
    line(120+p[2].x,200-p[2].y,120+p[3].x,200-p[3].y);
    line(120+p[3].x,200-p[3].y,120+p[0].x,200-p[0].y);
    line(120+p[4].x,200-p[4].y,120+p[5].x,200-p[5].y);
    line(120+p[5].x,200-p[5].y,120+p[6].x,200-p[6].y);
    line(120+p[6].x,200-p[6].y,120+p[7].x,200-p[7].y);
    line(120+p[7].x,200-p[7].y,120+p[4].x,200-p[4].y);
    line(120+p[0].x,200-p[0].y,120+p[4].x,200-p[4].y);
    line(120+p[1].x,200-p[1].y,120+p[5].x,200-p[5].y);
    line(120+p[2].x,200-p[2].y,120+p[6].x,200-p[6].y);
    line(120+p[3].x,200-p[3].y,120+p[7].x,200-p[7].y);
    outtextxy(120,250,"Front view");

}
void draw_cube_top()
{
    //draw the front view of the cube
    line(350+p[0].x,110-p[0].z,350+p[1].x,110-p[1].z);
    line(350+p[1].x,110-p[1].z,350+p[2].x,110-p[2].z);
    line(350+p[2].x,110-p[2].z,350+p[3].x,110-p[3].z);
    line(350+p[3].x,110-p[3].z,350+p[0].x,110-p[0].z);
    line(350+p[4].x,110-p[4].z,350+p[5].x,110-p[5].z);
    line(350+p[5].x,110-p[5].z,350+p[6].x,110-p[6].z);
    line(350+p[6].x,110-p[6].z,350+p[7].x,110-p[7].z);
    line(350+p[7].x,110-p[7].z,350+p[4].x,110-p[4].z);
    line(350+p[0].x,110-p[0].z,350+p[4].x,110-p[4].z);
    line(350+p[1].x,110-p[1].z,350+p[5].x,110-p[5].z);
    line(350+p[2].x,110-p[2].z,350+p[6].x,110-p[6].z);
    line(350+p[3].x,110-p[3].z,350+p[7].x,110-p[7].z);
      outtextxy(350,150,"Top view");
}
void draw_cube_side()
{
    //draw the front view of the cube
    line(300+p[0].z,300-p[0].y,300+p[1].z,300-p[1].y);
    line(300+p[1].z,300-p[1].y,300+p[2].z,300-p[2].y);
    line(300+p[2].z,300-p[2].y,300+p[3].z,300-p[3].y);
    line(300+p[3].z,300-p[3].y,300+p[0].z,300-p[0].y);
    line(300+p[4].z,300-p[4].y,300+p[5].z,300-p[5].y);
    line(300+p[5].z,300-p[5].y,300+p[6].z,300-p[6].y);
    line(300+p[6].z,300-p[6].y,300+p[7].z,300-p[7].y);
    line(300+p[7].z,300-p[7].y,300+p[4].z,300-p[4].y);
    line(300+p[0].z,300-p[0].y,300+p[4].z,300-p[4].y);
    line(300+p[1].z,300-p[1].y,300+p[5].z,300-p[5].y);
    line(300+p[2].z,300-p[2].y,300+p[6].z,300-p[6].y);
    line(300+p[3].z,300-p[3].y,300+p[7].z,300-p[7].y);
     outtextxy(300,350,"Side view");

}
void show(int c)
{
  if(c==1)
  rotate_about_z();
  else if(c==2)
  rotate_about_x();
  else if(c==3)
  rotate_about_y();
  draw_cube_front();
  draw_cube_top();
  draw_cube_side();

}
int main()
{
    //initial coordinates
    p[0].x=0; p[0].y=0; p[0].z=0;     p[1].x=80; p[1].y=0;  p[1].z=0;    p[2].x=80;p[2].y=0;p[2].z=80;       p[3].x=0;p[3].y=0;p[3].z=80;
    p[4].x=0; p[4].y=80; p[4].z=0;    p[5].x=80; p[5].y=80; p[5].z=0;   p[6].x=80;p[6].y=80;p[6].z=80;      p[7].x=0;p[7].y=80;p[7].z=80;

    int gm=DETECT,gd;
    int a;
    char c;
    initgraph(&gm,&gd,"C:\\TC\\BGI");
    show(a);
    while(1)
    {
        c=getch();
        cleardevice();
        if(c=='z')
            a=1;
        else if(c=='x')a=2;
        else if(c=='c')a=3;
        else break;
        show(a);

    }
    getch();
    closegraph();
    return 0;
}
void one(point a,point b,point c,point d,int i,int j,int p1,int p2)
{
    double xn,xnn,xs,xss,xw,xwn,xwnn,xws,xwss,xww,xwwn,xwwnn,xwws,xwwss,xe,xen,xenn,xes,xess,xee,xeen,xeenn,xees,xeess;
    double yn,ynn,ys,yss,yw,ywn,ywnn,yws,ywss,yww,ywwn,ywwnn,ywws,ywwss,ye,yen,yenn,yes,yess,yee,yeen,yeenn,yees,yeess;
    if(j==2)
    {
        a.x=a.x;
        a.y=a.z;
        b.x=b.x;
        b.y=b.z;
        c.x=c.x;
        c.y=c.z;
        d.x=d.x;
        d.y=d.z;
    }
    else if(j==3)
    {
        a.y=a.y;
        a.x=a.z;
        b.y=b.y;
        b.x=b.z;
        c.y=c.y;
        c.x=c.z;
        d.y=d.y;
        d.x=d.z;
    }
    xss=(d.x+c.x)/2;
    xnn=(a.x+b.x)/2;
    xn=(xnn*3+xss)/4;
    xs=(xnn+3*xss)/4;

    xwss=(3*d.x+c.x)/4;
    xwnn=(3*a.x+b.x)/4;
    xwn=(3*xwnn+xwss)/4;
    xw=(2*xwnn+2*xwss)/4;
    xws=(xwnn+3*xwss)/4;

    xwwss=d.x;
    xwwnn=a.x;
    xwwn=(3*xwwnn+xwwss)/4;
    xww=(2*xwwnn+2*xwwss)/4;
    xwws=(xwwnn+3*xwwss)/4;

    xess=(d.x+3*c.x)/4;
    xenn=(a.x+3*b.x)/4;
    xen=(3*xenn+xess)/4;
    xe=(2*xenn+2*xess)/4;
    xes=(xenn+3*xess)/4;

    xeess=c.x;
    xeenn=b.x;
    xeen=(3*xeenn+xeess)/4;
    xee=(2*xeenn+2*xeess)/4;
    xees=(xeenn+3*xeess)/4;

    yss=(d.y+c.y)/2;
    ynn=(a.y+b.y)/2;
    yn=(ynn*3+yss)/4;
    ys=(ynn+3*yss)/4;

    ywss=(3*d.y+c.y)/4;
    ywnn=(3*a.y+b.y)/4;
    ywn=(3*ywnn+ywss)/4;
    yw=(2*ywnn+2*ywss)/4;
    yws=(ywnn+3*ywss)/4;

    ywwss=d.y;
    ywwnn=a.y;
    ywwn=(3*ywwnn+ywwss)/4;
    yww=(2*ywwnn+2*ywwss)/4;
    ywws=(ywwnn+3*ywwss)/4;

    yess=(d.y+3*c.y)/4;
    yenn=(a.y+3*b.y)/4;
    yen=(3*yenn+yess)/4;
    ye=(2*yenn+2*yess)/4;
    yes=(yenn+3*yess)/4;

    yeess=c.y;
    yeenn=b.y;
    yeen=(3*yeenn+yeess)/4;
    yee=(2*yeenn+2*yeess)/4;
    yees=(yeenn+3*yeess)/4;

    if(i==1)
    {
        line(p1+(int)xs,p2-(int)ys,p1+(int)xn,p2-(int)yn);
    }
    else if(i==2)
    {
        line(p1+(int)xwn,p2-(int)ywn,p1+(int)xen,p2-(int)yen);
        line(p1+(int)xen,p2-(int)yen,p1+(int)xe,p2-(int)ye);
        line(p1+(int)xe,p2-(int)ye,p1+(int)xw,p2-(int)yw);
        line(p1+(int)xw,p2-(int)yw,p1+(int)xws,p2-(int)yws);
        line(p1+(int)xws,p2-(int)yws,p1+(int)xes,p2-(int)yes);
    }
    else if(i==3)
    {
        line(p1+(int)xwn,p2-(int)ywn,p1+(int)xen,p2-(int)yen);
        line(p1+(int)xen,p2-(int)yen,p1+(int)xes,p2-(int)yes);
        line(p1+(int)xe,p2-(int)ye,p1+(int)xw,p2-(int)yw);
        line(p1+(int)xes,p2-(int)yes,p1+(int)xws,p2-(int)yws);
    }
    else if(i==4)
    {
        line(p1+(int)xwn,p2-(int)ywn,p1+(int)xw,p2-(int)yw);
        line(p1+(int)xen,p2-(int)yen,p1+(int)xes,p2-(int)yes);
        line(p1+(int)xe,p2-(int)ye,p1+(int)xw,p2-(int)yw);
    }
    else if(i==5)
    {
        line(p1+(int)xwn,p2-(int)ywn,p1+(int)xen,p2-(int)yen);
        line(p1+(int)xwn,p2-(int)ywn,p1+(int)xw,p2-(int)yw);
        line(p1+(int)xe,p2-(int)ye,p1+(int)xw,p2-(int)yw);
        line(p1+(int)xe,p2-(int)ye,p1+(int)xes,p2-(int)yes);
        line(p1+(int)xws,p2-(int)yws,p1+(int)xes,p2-(int)yes);
    }
    else
    {
        line(p1+(int)xe,p2-(int)ye,p1+(int)xes,p2-(int)yes);
        line(p1+(int)xe,p2-(int)ye,p1+(int)xw,p2-(int)yw);
        line(p1+(int)xes,p2-(int)yes,p1+(int)xws,p2-(int)yws);
        line(p1+(int)xws,p2-(int)yws,p1+(int)xwn,p2-(int)ywn);
    }
}
