#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
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
int main()
{
    int gd,gm=DETECT;
    initgraph(&gm,&gd,"C:\\TC\\BGI");
    int i;
    double t;
    point p,p1={100,150},p2={550,150},p3={10,0},p4={10,0};
    for(t=0;t<=1;t+=0.0001){
        p=mul(t,p1,p2,p3,p4);
        putpixel(p.x,p.y,15);
    }
    p1={120,150},p2={120,300},p3={0,10},p4={0,10};
    for(t=0;t<=1;t+=0.0001){
        p=mul(t,p1,p2,p3,p4);
        putpixel(p.x,p.y,15);
    }
    p1={220,150},p2={220,300},p3={0,10},p4={0,10};
    for(t=0;t<=1;t+=0.0001){
        p=mul(t,p1,p2,p3,p4);
        putpixel(p.x,p.y,15);
    }
    p1={120,150},p2={220,150},p3={-100,-100},p4={100,350};
    for(t=0;t<=1;t+=0.0001){
        p=mul(t,p1,p2,p3,p4);
        putpixel(p.x,p.y,15);
    }
    p1={220,220},p2={150,220},p3={-1,-100},p4={1,100};
    for(t=0;t<=1;t+=0.0001){
        p=mul(t,p1,p2,p3,p4);
        putpixel(p.x,p.y,15);
    }
    p1={150,220},p2={220,220},p3={1,100},p4={-1,-100};
    for(t=0;t<=1;t+=0.0001){
        p=mul(t,p1,p2,p3,p4);
        putpixel(p.x,p.y,15);
    }

    p1={320,150},p2={320,300},p3={0,500},p4={0,500};
    for(t=0;t<=1;t+=0.0001){
        p=mul(t,p1,p2,p3,p4);
        putpixel(p.x,p.y,15);
    }

    p1={320,220},p2={250,220},p3={-1,-100},p4={1,100};
    for(t=0;t<=1;t+=0.0001){
        p=mul(t,p1,p2,p3,p4);
        putpixel(p.x,p.y,15);
    }
    p1={250,220},p2={320,220},p3={1,100},p4={-1,-100};
    for(t=0;t<=1;t+=0.0001){
        p=mul(t,p1,p2,p3,p4);
        putpixel(p.x,p.y,15);
    }
    p1={320,220},p2={380,220},p3={1,-100},p4={0,50};
    for(t=0;t<=1;t+=0.0001){
        p=mul(t,p1,p2,p3,p4);
        putpixel(p.x,p.y,15);
    }

    p1={380,220},p2={365,250},p3={0,50},p4={-1,20};
    for(t=0;t<=1;t+=0.0001){
        p=mul(t,p1,p2,p3,p4);
        putpixel(p.x,p.y,15);
    }
    p1={320,150},p2={305,90},p3={-100,-700},p4={300,-80};
    for(t=0;t<=1;t+=0.0001){
        p=mul(t,p1,p2,p3,p4);
        putpixel(p.x,p.y,15);
    }
    p1={460,180},p2={440,150},p3={-30,80},p4={100,0};
    for(t=0;t<=1;t+=0.0001){
        p=mul(t,p1,p2,p3,p4);
        putpixel(p.x,p.y,15);
    }
    p1={440,150},p2={420,225},p3={80,0},p4={-200,70};
    for(t=0;t<=1;t+=0.0001){
        p=mul(t,p1,p2,p3,p4);
        putpixel(p.x,p.y,15);
    }
    p1={418,223},p2={490,300},p3={1,90},p4={90,7};
    for(t=0;t<=1;t+=0.0001){
        p=mul(t,p1,p2,p3,p4);
        putpixel(p.x,p.y,15);
    }
    p1={520,150},p2={520,300},p3={0,500},p4={0,500};
    for(t=0;t<=1;t+=0.0001){
        p=mul(t,p1,p2,p3,p4);
        putpixel(p.x,p.y,15);
    }
    getch();
    closegraph();
}
