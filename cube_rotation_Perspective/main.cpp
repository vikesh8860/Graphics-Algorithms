//   Our model cube
//         ^ Y
//         |
//         |
//         A--------B -------> X-axis
//        /|       /|
//       D--------C |
//     / | |      | |
//    /  | E--------F
//  Z    |/       |/
//       H--------G
//   X- rotation is about axis AB , Z- rotation is about axis AD ,Y rotation is about AE

#include <iostream>
#include <graphics.h>
#include <bits/stdc++.h>
#include <cmath>
#include <math.h>
#define M_PI 3.14159
using namespace std;
float a[4][8]={{200,350,300,150,200,350,300,150},{150,150,200,200,300,300,350,350},{1,1,1,1,1,1,1,1}};
float angle= (1.00*M_PI)/180;

void rotateabout_z()
{   //for axis
    line(200,150,412,150);  //for x-axis
    line(200,150,100,250); //for z- axis
    line(200,150,200,30); //for y-axis

    //outtextxy(400,400,"Z-Rotation"); //print the text

    //for printing numbers on each face
    setcolor(15);
    outtextxy((a[0][0]+a[0][1]+a[0][2]+a[0][3])/4,(a[1][0]+a[1][1]+a[1][2]+a[1][3])/4,"1");  //  Top face
    outtextxy((a[0][4]+a[0][5]+a[0][6]+a[0][7])/4,(a[1][4]+a[1][5]+a[1][6]+a[1][7])/4,"6");  //  Bottom face
    outtextxy((a[0][1]+a[0][2]+a[0][5]+a[0][6])/4,(a[1][1]+a[1][2]+a[1][5]+a[1][6])/4,"2");  //  Right face
    outtextxy((a[0][0]+a[0][4]+a[0][7]+a[0][3])/4,(a[1][0]+a[1][4]+a[1][7]+a[1][3])/4,"5");  //  Left face
    outtextxy((a[0][0]+a[0][1]+a[0][5]+a[0][4])/4,(a[1][0]+a[1][1]+a[1][5]+a[1][4])/4,"3");  //  Back face
    outtextxy((a[0][3]+a[0][2]+a[0][6]+a[0][7])/4,(a[1][3]+a[1][2]+a[1][6]+a[1][7])/4,"4");  //  Front face


    setcolor(12);
    line(a[0][0],a[1][0],a[0][1],a[1][1]);
    line(a[0][1],a[1][1],a[0][2],a[1][2]);
    line(a[0][2],a[1][2],a[0][3],a[1][3]);
    line(a[0][3],a[1][3],a[0][0],a[1][0]);

    setcolor(13);
    line(a[0][4],a[1][4],a[0][5],a[1][5]);
    line(a[0][5],a[1][5],a[0][6],a[1][6]);
    line(a[0][6],a[1][6],a[0][7],a[1][7]);
    line(a[0][7],a[1][7],a[0][4],a[1][4]);

    setcolor(14);
    line(a[0][0],a[1][0],a[0][4],a[1][4]);
    line(a[0][1],a[1][1],a[0][5],a[1][5]);
    line(a[0][2],a[1][2],a[0][6],a[1][6]);
    line(a[0][3],a[1][3],a[0][7],a[1][7]);

    //Now we will calculate the rotation about the point (a[0][0],a[1][0])=A of  back face

    a[0][1]=a[0][0]+(a[0][1]-a[0][0])*cos(angle)-(a[1][1]-a[1][0])*sin(angle);
    a[1][1]=a[1][0]+(a[1][1]-a[1][0])*cos(angle)+(a[0][1]-a[0][0])*sin(angle);


    a[0][5]=a[0][0]+(a[0][5]-a[0][0])*cos(angle)-(a[1][5]-a[1][0])*sin(angle);
    a[1][5]=a[1][0]+(a[1][5]-a[1][0])*cos(angle)+(a[0][5]-a[0][0])*sin(angle);


    a[0][4]=a[0][0]+(a[0][4]-a[0][0])*cos(angle)-(a[1][4]-a[1][0])*sin(angle);
    a[1][4]=a[1][0]+(a[1][4]-a[1][0])*cos(angle)+(a[0][4]-a[0][0])*sin(angle);



    //rotation about point (a[0][3],a[1][3])=D of front face

    a[0][2]=a[0][3]+(a[0][2]-a[0][3])*cos(angle)-(a[1][2]-a[1][3])*sin(angle);
    a[1][2]=a[1][3]+(a[1][2]-a[1][3])*cos(angle)+(a[0][2]-a[0][3])*sin(angle);


    a[0][6]=a[0][3]+(a[0][6]-a[0][3])*cos(angle)-(a[1][6]-a[1][3])*sin(angle);
    a[1][6]=a[1][3]+(a[1][6]-a[1][3])*cos(angle)+(a[0][6]-a[0][3])*sin(angle);


    a[0][7]=a[0][3]+(a[0][7]-a[0][3])*cos(angle)-(a[1][7]-a[1][3])*sin(angle);
    a[1][7]=a[1][3]+(a[1][7]-a[1][3])*cos(angle)+(a[0][7]-a[0][3])*sin(angle);


}
void rotateabout_x()
{
    //for axis
    line(200,150,412,150);  //for x-axis
    line(200,150,100,250); //for z- axis
    line(200,150,200,30); //for y-axis

    //outtextxy(400,400,"X-Rotation");  //print the text

    //for printing numbers on each face
    setcolor(15);
    outtextxy((a[0][0]+a[0][1]+a[0][2]+a[0][3])/4,(a[1][0]+a[1][1]+a[1][2]+a[1][3])/4,"1");  //  Top face
    outtextxy((a[0][4]+a[0][5]+a[0][6]+a[0][7])/4,(a[1][4]+a[1][5]+a[1][6]+a[1][7])/4,"6");  //  Bottom face
    outtextxy((a[0][1]+a[0][2]+a[0][5]+a[0][6])/4,(a[1][1]+a[1][2]+a[1][5]+a[1][6])/4,"2");  //  Right face
    outtextxy((a[0][0]+a[0][4]+a[0][7]+a[0][3])/4,(a[1][0]+a[1][4]+a[1][7]+a[1][3])/4,"5");  //  Left face
    outtextxy((a[0][0]+a[0][1]+a[0][5]+a[0][4])/4,(a[1][0]+a[1][1]+a[1][5]+a[1][4])/4,"3");  //  Back face
    outtextxy((a[0][3]+a[0][2]+a[0][6]+a[0][7])/4,(a[1][3]+a[1][2]+a[1][6]+a[1][7])/4,"4");  //  Front face

    setcolor(12);
    line(a[0][0],a[1][0],a[0][1],a[1][1]);
    line(a[0][1],a[1][1],a[0][2],a[1][2]);
    line(a[0][2],a[1][2],a[0][3],a[1][3]);
    line(a[0][3],a[1][3],a[0][0],a[1][0]);

    setcolor(13);
    line(a[0][4],a[1][4],a[0][5],a[1][5]);
    line(a[0][5],a[1][5],a[0][6],a[1][6]);
    line(a[0][6],a[1][6],a[0][7],a[1][7]);
    line(a[0][7],a[1][7],a[0][4],a[1][4]);

    setcolor(14);
    line(a[0][0],a[1][0],a[0][4],a[1][4]);
    line(a[0][1],a[1][1],a[0][5],a[1][5]);
    line(a[0][2],a[1][2],a[0][6],a[1][6]);
    line(a[0][3],a[1][3],a[0][7],a[1][7]);

    //Now we will calculate the rotation about the point (a[0][0],a[1][0])=A of   left face

    a[0][3]=a[0][0]+(a[0][3]-a[0][0])*cos(angle)-(a[1][3]-a[1][0])*sin(angle);
    a[1][3]=a[1][0]+(a[1][3]-a[1][0])*cos(angle)+(a[0][3]-a[0][0])*sin(angle);


    a[0][4]=a[0][0]+(a[0][4]-a[0][0])*cos(angle)-(a[1][4]-a[1][0])*sin(angle);
    a[1][4]=a[1][0]+(a[1][4]-a[1][0])*cos(angle)+(a[0][4]-a[0][0])*sin(angle);


    a[0][7]=a[0][0]+(a[0][7]-a[0][0])*cos(angle)-(a[1][7]-a[1][0])*sin(angle);
    a[1][7]=a[1][0]+(a[1][7]-a[1][0])*cos(angle)+(a[0][7]-a[0][0])*sin(angle);



    //rotation about point (a[0][1],a[1][1])=B of right face

    a[0][2]=a[0][1]+(a[0][2]-a[0][1])*cos(angle)-(a[1][2]-a[1][1])*sin(angle);
    a[1][2]=a[1][1]+(a[1][2]-a[1][1])*cos(angle)+(a[0][2]-a[0][1])*sin(angle);


    a[0][6]=a[0][1]+(a[0][6]-a[0][1])*cos(angle)-(a[1][6]-a[1][1])*sin(angle);
    a[1][6]=a[1][1]+(a[1][6]-a[1][1])*cos(angle)+(a[0][6]-a[0][1])*sin(angle);


    a[0][5]=a[0][1]+(a[0][5]-a[0][1])*cos(angle)-(a[1][5]-a[1][1])*sin(angle);
    a[1][5]=a[1][1]+(a[1][5]-a[1][1])*cos(angle)+(a[0][5]-a[0][1])*sin(angle);

}
void rotateabout_y()
{
    //for axis
    line(200,150,412,150);  //for x-axis
    line(200,150,100,250); //for z- axis
    line(200,150,200,30); //for y-axis

    //outtextxy(400,400,"Y-Rotation");  //print the text

    //for printing numbers on each face
    setcolor(15);
    outtextxy((a[0][0]+a[0][1]+a[0][2]+a[0][3])/4,(a[1][0]+a[1][1]+a[1][2]+a[1][3])/4,"1");  //  Top face
    outtextxy((a[0][4]+a[0][5]+a[0][6]+a[0][7])/4,(a[1][4]+a[1][5]+a[1][6]+a[1][7])/4,"6");  //  Bottom face
    outtextxy((a[0][1]+a[0][2]+a[0][5]+a[0][6])/4,(a[1][1]+a[1][2]+a[1][5]+a[1][6])/4,"2");  //  Right face
    outtextxy((a[0][0]+a[0][4]+a[0][7]+a[0][3])/4,(a[1][0]+a[1][4]+a[1][7]+a[1][3])/4,"5");  //  Left face
    outtextxy((a[0][0]+a[0][1]+a[0][5]+a[0][4])/4,(a[1][0]+a[1][1]+a[1][5]+a[1][4])/4,"3");  //  Back face
    outtextxy((a[0][3]+a[0][2]+a[0][6]+a[0][7])/4,(a[1][3]+a[1][2]+a[1][6]+a[1][7])/4,"4");  //  Front face


    setcolor(12);
    line(a[0][0],a[1][0],a[0][1],a[1][1]);
    line(a[0][1],a[1][1],a[0][2],a[1][2]);
    line(a[0][2],a[1][2],a[0][3],a[1][3]);
    line(a[0][3],a[1][3],a[0][0],a[1][0]);

    setcolor(13);
    line(a[0][4],a[1][4],a[0][5],a[1][5]);
    line(a[0][5],a[1][5],a[0][6],a[1][6]);
    line(a[0][6],a[1][6],a[0][7],a[1][7]);
    line(a[0][7],a[1][7],a[0][4],a[1][4]);

    setcolor(14);
    line(a[0][0],a[1][0],a[0][4],a[1][4]);
    line(a[0][1],a[1][1],a[0][5],a[1][5]);
    line(a[0][2],a[1][2],a[0][6],a[1][6]);
    line(a[0][3],a[1][3],a[0][7],a[1][7]);

    //Now we will calculate the rotation about the point (a[0][0],a[1][0])=A of  top face

    a[0][1]=a[0][0]+(a[0][1]-a[0][0])*cos(angle)-(a[1][1]-a[1][0])*sin(angle);
    a[1][1]=a[1][0]+(a[1][1]-a[1][0])*cos(angle)+(a[0][1]-a[0][0])*sin(angle);


    a[0][2]=a[0][0]+(a[0][2]-a[0][0])*cos(angle)-(a[1][2]-a[1][0])*sin(angle);
    a[1][2]=a[1][0]+(a[1][2]-a[1][0])*cos(angle)+(a[0][2]-a[0][0])*sin(angle);


    a[0][3]=a[0][0]+(a[0][3]-a[0][0])*cos(angle)-(a[1][3]-a[1][0])*sin(angle);
    a[1][3]=a[1][0]+(a[1][3]-a[1][0])*cos(angle)+(a[0][3]-a[0][0])*sin(angle);



    //rotation about point (a[0][4],a[1][4])=F of bottom face

    a[0][5]=a[0][4]+(a[0][5]-a[0][4])*cos(angle)-(a[1][5]-a[1][4])*sin(angle);
    a[1][5]=a[1][4]+(a[1][5]-a[1][4])*cos(angle)+(a[0][5]-a[0][4])*sin(angle);


    a[0][6]=a[0][4]+(a[0][6]-a[0][4])*cos(angle)-(a[1][6]-a[1][4])*sin(angle);
    a[1][6]=a[1][4]+(a[1][6]-a[1][4])*cos(angle)+(a[0][6]-a[0][4])*sin(angle);


    a[0][7]=a[0][4]+(a[0][7]-a[0][4])*cos(angle)-(a[1][7]-a[1][4])*sin(angle);
    a[1][7]=a[1][4]+(a[1][7]-a[1][4])*cos(angle)+(a[0][7]-a[0][4])*sin(angle);
}
int main()
{
    int gm=DETECT,gd,i=0;
    char c='z';
    initgraph(&gm,&gd,"C:\\TC\\BGI");
    initwindow(1000,720);
    while(1)
    {

       setcolor(15);
       c=getch();
       cleardevice();
       if(c=='z'){
       rotateabout_z();}
       else if(c=='x'){
        rotateabout_x();}
       else
        {rotateabout_y();}
       // delay(100);
    }
    getch();
    closegraph();
    return 0;
}
