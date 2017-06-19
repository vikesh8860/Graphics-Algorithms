#include<stdio.h>
#include<conio.h>
#include <iostream>
#include<graphics.h>
#include<math.h>
using namespace std;
struct point
{
    double x,y;
};
point mul(double t,point p1,point p2,point p3,point p4)
{
    double t_matrix[1][4]={t*t*t,t*t,t,1},inverse[4][4]={2,-2,1,1,-3,3,-2,-1,0,0,1,0,1,0,0,0},final_mat[1][4]={0,0,0,0};
    int i,j,k;
    for(i=0;i<1;i++)
        for(j=0;j<4;j++)
          for(k=0;k<4;k++)
                final_mat[i][j]+=t_matrix[i][k]*inverse[k][j];
    point p;
    p.x=final_mat[0][0]*p1.x+final_mat[0][1]*p2.x+final_mat[0][2]*p3.x+final_mat[0][3]*p4.x;
    p.y=final_mat[0][0]*p1.y+final_mat[0][1]*p2.y+final_mat[0][2]*p3.y+final_mat[0][3]*p4.y;
    return p;
}
void draw(int x1,int y1,int x2,int y2,int x3,int y3,int col)
{
    double t;
    point p,p1={100,150},p2={100,160},p3={10,-40},p4={-100,0};
    for(t=0;t<=1;t+=0.01){
        p=mul(t,p1,p2,p3,p4);
        putpixel(p.x+x1,p.y+y1,col);
    }
    p1={100,160},p2={95,170},p3={100,-2},p4={-70,-40};
    for(t=0;t<=1;t+=0.01){
        p=mul(t,p1,p2,p3,p4);
        putpixel(p.x+x1,p.y+y1,col);
    }
    p1={95,170},p2={100,190},p3={-3,-40},p4={0,50};
    for(t=0;t<=1;t+=0.01){
        p=mul(t,p1,p2,p3,p4);
        putpixel(p.x+x1,p.y+y1,col);
    }


    p1={130,147},p2={160,147},p3={10,0},p4={10,0};
    for(t=0;t<=1;t+=0.01){
        p=mul(t,p1,p2,p3,p4);
        putpixel(p.x+x2,p.y+y2,col);
    }
    p1={160,147},p2={150,173},p3={-120,0},p4={50,-30};
    for(t=0;t<=1;t+=0.01){
        p=mul(t,p1,p2,p3,p4);
        putpixel(p.x+x2,p.y+y2,col);
    }
    p1={150,173},p2={160,165},p3={50,-30},p4={50,-40};
    for(t=0;t<=1;t+=0.01){
        p=mul(t,p1,p2,p3,p4);
        putpixel(p.x+x2,p.y+y2,col);
    }


    p1={180,145},p2={180,160},p3={-100,6},p4={10,-10};
    for(t=0;t<=1;t+=0.01){
        p=mul(t,p1,p2,p3,p4);
        putpixel(p.x+x3,p.y+y3,col);
    }
    p1={180,160},p2={185,175},p3={-100,10},p4={10,-60};
    for(t=0;t<=1;t+=0.01){
        p=mul(t,p1,p2,p3,p4);
        putpixel(p.x+x3,p.y+y3,col);
    }
    p1={185,175},p2={180,190},p3={-10,-40},p4={0,100};
    for(t=0;t<=1;t+=0.01){
        p=mul(t,p1,p2,p3,p4);
        putpixel(p.x+x3,p.y+y3,col);
    }
}
int main()
{
    int gd,gm=DETECT;
    initgraph(&gm,&gd,"C:\\TC\\BGI");
    int i=1,j=30,x1=0,y1=0,x2=0,y2=0,x3=0,y3=0,u;
    double t;
    draw(x1,y1-30,x2,y2-30,x3,y3-30,15);
    draw(0,0,0,0,0,0,0);
    while(i<=6)
    {
       if(i==1)
       {
           while(y1<=30)
           {
               draw(x1,y1,x2,y2,x3,y3,15);
               draw(x1,y1,x2,y2,x3,y3,0);
               y1+=2;
               x2+=2;y2+=2;
               x3-=2;y3+=2;
           }
       draw(x1,y1,x2,y2,x3,y3,15);
       y3+=30;
       y2+=30;
       y1+=30;
       }
       if(i==2)
       {
          while(y2<=90)
           {
               draw(x1,y1,x2,y2,x3,y3,15);
               draw(x1,y1,x2,y2,x3,y3,0);
               y2+=2;
               x1+=2;y1+=2;
               x3-=2;y3+=2;
           }
       draw(x1,y1,x2,y2,x3,y3,15);
       y3+=30;
       y2+=30;
       y1+=30;
       }
       if(i==3)
       {
          while(y3<=150)
           {
               draw(x1,y1,x2,y2,x3,y3,15);
               draw(x1,y1,x2,y2,x3,y3,0);
               y3+=2;
               x1+=2;y1+=2;
               x2-=2;y2+=2;
           }
       draw(x1,y1,x2,y2,x3,y3,15);
       y3+=30;
       y2+=30;
       y1+=30;
       }
       if(i==4)
       {
          while(y1<=210)
           {
               draw(x1,y1,x2,y2,x3,y3,15);
               draw(x1,y1,x2,y2,x3,y3,0);
               y1+=2;
               x3+=2;y3+=2;
               x2-=2;y2+=2;
           }
       draw(x1,y1,x2,y2,x3,y3,15);
       y3+=30;
       y2+=30;
       y1+=30;
       }
       if(i==5)
       {
          while(y2<=270)
           {
               draw(x1,y1,x2,y2,x3,y3,15);
               draw(x1,y1,x2,y2,x3,y3,0);
               y2+=2;
               x1-=2;y1+=2;
               x3+=2;y3+=2;
           }
       draw(x1,y1,x2,y2,x3,y3,15);
       y3+=30;
       y2+=30;
       y1+=30;
       }
       //draw(x1,y1,x2,y2,x3,y3,15);

      i++;
    }
    getch();
    closegraph();
}
