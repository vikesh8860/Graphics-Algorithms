#include <iostream>
#include <graphics.h>
#include <bits/stdc++.h>
using namespace std;
struct point
{
    float x,y;
};
point translation(point p,int dx,int dy)
{
    float a[3][1]= {p.x,p.y,1},tran[3][3]= {{1,0,dx},{0,1,dy},{0,0,1}},result[3][1]= {0,0,0};
    int i,j,k;
    for(i=0; i<3; i++)
    {
        for(j=0; j<1; j++)
        {
            for(k=0; k<3; k++)
                result[i][j]+=tran[i][k]*a[k][j];
        }
    }
    p.x=result[0][0];
    p.y=result[1][0];
    return p;
}
point rotation(point p,int angle)
{
    float a[3][1]= {p.x,p.y,1},rot[3][3]= {{cos(3.14159*angle/180),-sin(3.14159*angle/180),0},{sin(3.14159*angle/180),cos(3.14159*angle/180),0},{0,0,1}},result[3][1]= {0,0,0};
    int i,j,k;
    for(i=0; i<3; i++)
    {
        for(j=0; j<1; j++)
        {
            for(k=0; k<3; k++)
                result[i][j]+=rot[i][k]*a[k][j];
        }
    }
    p.x=result[0][0];
    p.y=result[1][0];
    return p;
}
point scaling(point p,int sx,int sy)
{
    float a[3][1]= {p.x,p.y,1},sca[3][3]= {{sx,0,0},{0,sy,0},{0,0,1}},result[3][1]= {0,0,0};
    int i,j,k;
    for(i=0; i<3; i++)
    {
        for(j=0; j<1; j++)
        {
            for(k=0; k<3; k++)
                result[i][j]+=sca[i][k]*a[k][j];
        }
    }
    p.x=result[0][0];
    p.y=result[1][0];
    return p;
}
int main()
{
    int gm=DETECT,gd,i=0,a,b;
    initgraph(&gm,&gd,"C:\\TC\\BGI");
    point p[10];
    for(i=0; i<3; i++)
    {
        while(!ismouseclick(WM_LBUTTONDOWN)) {}
        getmouseclick(WM_LBUTTONDOWN,a,b);
        p[i].x=a;
        p[i].y=b;
    }
    p[i].x=p[0].x;
    p[i].y=p[0].y;
    for(i=0; i<3; i++)
    {
        line(p[i].x,p[i].y,p[i+1].x,p[i+1].y);
    }
    float x=p[0].x,y=p[0].y;
    for(i=0; i<=3; i++)
        p[i]=translation(p[i],-x,-y);
    for(i=0; i<=3; i++)
        p[i]=rotation(p[i],-30);
    for(i=0; i<=3; i++)
        p[i]=translation(p[i],x,y);
    for(i=0; i<3; i++)
    {
        line(300+p[i].x,p[i].y,300+p[i+1].x,p[i+1].y);
    }
    outtextxy(100,400,"Before Rotation");
    outtextxy(400,400,"After Rotation");
    getch();
    closegraph();
    return 0;
}
