#include <iostream>
#include <graphics.h>
typedef struct point point;
using namespace std;
double xmax,ymax,xmin,ymin;
struct point
{
    double x,y;
};
point window[20];
point normal[20];
point line_seg[2];
void dda_line(double x1,double y1,double x2,double y2);

int main()
{
    int sides,gm=DETECT,gd,i;
    initgraph(&gm,&gd,"C:\\TC\\BGI");
    sides=4;
    window[0].x=100;
    window[0].y=100;
    window[1].x=200;
    window[1].y=100;
    window[2].x=200;
    window[2].y=200;
    window[3].x=100;  window[3].y=200;
    window[4].x=window[0].x;
    window[4].y=window[0].y;
    for(i=0; i<sides; i++)
    {
        dda_line(window[i].x,window[i].y,window[i+1].x,window[i+1].y);
    }
    line_seg[0].x=40;
    line_seg[0].y=210;
    line_seg[1].x=250;
    line_seg[1].y=100;
    dda_line(line_seg[0].x,line_seg[0].y,line_seg[1].x,line_seg[1].y);
    getch();
//   cleardevice();
    clip_cyrus(line_seg[0],line_seg[1],sides);
    for(i=0; i<sides; i++)
    {
        dda_line(200+window[i].x,window[i].y,200+window[i+1].x,window[i+1].y);
    }
    outtextxy(110,220,"Before clipping");
    outtextxy(310,220,"After clipping");
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
