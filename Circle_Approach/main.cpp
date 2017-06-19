#include <iostream>
#include <graphics.h>
#include <bits/stdc++.h>
using namespace std;
void print_pixel(int x,int y,int x1,int y1)
{
    putpixel(x1+x,y1+y,WHITE);
    putpixel(x1+y,y1+x,WHITE);
    putpixel(x1+x,y1-y,WHITE);
    putpixel(x1+y,y1-x,WHITE);
    putpixel(x1-x,y1-y,WHITE);
    putpixel(x1-y,y1-x,WHITE);
    putpixel(x1-x,y1+y,WHITE);
    putpixel(x1-y,y1+x,WHITE);
}
void print_circle_midpoint_1st(int x1,int y1,float R)
{   //major movement in x
    float d=5/4-R;
    int x=0,y=R;
    while(x<=y)
    {
        print_pixel(x,y,x1,y1);
        if(d<0)
        {
            d+=2*x+3;
        }
        else
        {
            d+=2*(x-y)+5;
            y--;
        }
        x++;
    }
}
void print_circle_midpoint_2nd(int x1,int y1,float R)
{
    float d=5/4-R;
    int deltaE=3,deltaSE=5-2*R,x=0,y=R;
    while(x<=y)
    {
        print_pixel(x,y,x1,y1);
        if(d<0)
        {
            d+=deltaE;
            deltaE+=2;
            deltaSE+=2;
        }
        else
        {
            d+=deltaSE;
            deltaE+=2;
            deltaSE+=4;
            y--;
        }
        x++;
    }
}
void print_circle_bresenham_1st(int x1,int y1,float R)
{
    int x=0,y=R,d=3-2*R;
    while(x<=y)
    {
        print_pixel(x,y,x1,y1);
        if(d<0)
        {
            d+=4*x+6;
        }
        else
        {
            d+=4*(x-y)+10;
            y--;
        }
        x++;
    }
}
void print_circle_bresenham_2nd(int x1,int y1,float R)
{
    int x=0,y=R,d=3-2*R,deltaS=6,deltaT=10-4*R;
    while(x<=y)
    {
        print_pixel(x,y,x1,y1);
        if(d<0)
        {
            d+=deltaS;
            deltaS+=4;
            deltaT+=4;
        }
        else
        {
            d+=deltaT;
            deltaS+=4;
            deltaT+=8;
            y--;
        }
        x++;
    }
}
int main()
{
    int gm=DETECT,gd,i=0,a,b,c,d;
    initgraph(&gm,&gd,"C:\\TC\\BGI");
    while(i++<100){
        while(!ismouseclick(WM_LBUTTONDOWN)) {}
        getmouseclick(WM_LBUTTONDOWN,a,b);
        while(!ismouseclick(WM_LBUTTONDOWN)) {}
        getmouseclick(WM_LBUTTONDOWN,c,d);
        //print_circle_midpoint_1st(a,b,sqrt(pow((c-a),2)+pow((d-b),2)));
        //print_circle_midpoint_2nd(a,b,sqrt(pow((c-a),2)+pow((d-b),2)));
        //print_circle_bresenham_1st(a,b,sqrt(pow((c-a),2)+pow((d-b),2)));
          print_circle_bresenham_2nd(a,b,sqrt(pow((c-a),2)+pow((d-b),2)));
    }
    getch();
    closegraph();
    return 0;
}
