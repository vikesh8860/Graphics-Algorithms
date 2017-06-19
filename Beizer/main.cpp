#include<graphics.h>
#include<math.h>
struct point
{
    double x,y;
};
point mul(double t,point p1,point p2,point p3,point p4)
{
    double t_matrix[1][4]={t*t*t,t*t,t,1},inverse[4][4]={-1,3,-3,1,3,-6,3,0,-3,3,0,0,1,0,0,0},final_mat[1][4]={0,0,0,0};
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
    int i,a,b;
    double t;
    point p[10],p1;
    while(1){
    for(i=0;i<4;i++)
    {
        while(!ismouseclick(WM_LBUTTONDOWN)){}
        getmouseclick(WM_LBUTTONDOWN,a,b);
        p[i].x=a;
        p[i].y=b;
    }
    //point p,p1={100,100},p2={250,100},p3={120,190},p4={180,150};
    for(t=0;t<=1;t+=0.0001){
        p1=mul(t,p[0],p[1],p[2],p[3]);
        putpixel(p1.x,p1.y,15);
    }
    }
    getch();
    closegraph();
}
