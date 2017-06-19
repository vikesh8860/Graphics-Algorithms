#include <iostream>
#include <graphics.h>
using namespace std;
struct point{
    int x,y;
};
void dda_line(double x1,double y1,double x2,double y2);
void floodfill(int x,int y,int fillcolor,int boundary)
{
    int current=getpixel(x,y);
    if(current!=boundary&&current!=fillcolor)
    {
        putpixel(x,y,fillcolor);
        floodfill(x,y+1,fillcolor,boundary);
        floodfill(x,y-1,fillcolor,boundary);
        floodfill(x+1,y,fillcolor,boundary);
        floodfill(x-1,y,fillcolor,boundary);
    }
}
int main()
{
    int gm=DETECT,gd,i=0,j;
    point p[10];
    memset(p,0,sizeof(p));
    initgraph(&gm,&gd,"C:\\TC\\BGI");
    while(i<5){
        while(!ismouseclick(WM_LBUTTONDOWN)){delay(1);}
        getmouseclick(WM_LBUTTONDOWN,p[i].x,p[i].y);
        cout<<i<<p[i].x<<" "<<p[i].y<<"\n";
        i++;
    }
    p[i].x=p[0].x; p[i].y=p[0].y;
    for(j=0;j<i;j++)
    {
        dda_line(p[j].x*1.0,p[j].y*1.0,p[j+1].x*1.0,p[j+1].y*1.0);
    }
    while(!ismouseclick(WM_LBUTTONDOWN)){delay(1);}
        getmouseclick(WM_LBUTTONDOWN,i,j);
    floodfill(i,j,5,WHITE);
    getch();
    closegraph();
    return 0;
}
void dda_line(double x1,double y1,double x2,double y2)
{

    double dy=y2-y1,dx=x2-x1;
    double m=dy/dx;
    if(x1<=x2&&y1<=y2)    // 4th quad
    {
        if(abs(dy)<abs(dx))
        {
            while(x1<=x2)
            {
                putpixel(x1,y1,WHITE);
                y1+=m;
                x1++;
            }
        }
        else
        {
            while(y1<=y2)
            {
                putpixel(x1,y1,WHITE);
                x1+=1/m;
                y1++;
            }
        }

    }
    else if(x1<=x2&&y1>=y2)
    {
        if(abs(dy)<abs(dx))
        {
            while(x1<=x2)
            {
                putpixel(x1,y1,WHITE);
                y1+=m;
                x1++;
            }
        }
        else
        {
            while(y1>=y2)
            {
                putpixel(x1,y1,WHITE);
                x1-=1/m;
                y1--;
            }
        }
    }
    else if(x1>=x2&&y1<=y2)
    {
        if(abs(dy)<abs(dx))
        {
            while(x1>=x2)
            {
                putpixel(x1,y1,WHITE);
                y1-=m;
                x1--;
            }
        }
        else
        {
            while(y1<=y2)
            {
                putpixel(x1,y1,WHITE);
                x1+=1/m;
                y1++;
            }
        }
    }
    else
    {
        if(abs(dy)<abs(dx))
        {
            while(x1>=x2)
            {
                putpixel(x1,y1,WHITE);
                y1-=m;
                x1--;
            }
        }
        else
        {
            while(y1>=y2)
            {
                putpixel(x1,y1,WHITE);
                x1-=1/m;
                y1--;
            }
        }
    }
}
