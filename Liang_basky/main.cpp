#include <iostream>
#include <graphics.h>
#include <conio.h>
#include <vector>

using namespace std;

struct point {
    float x, y;
};

point getMousePoints();
int roundOff(float x);
bool clipTest(float p, float q, float *t1, float *t2);
void clipline(point winMin, point winMax, point p1, point p2);

int main()
{
    point cw[5];
    int i;
    initwindow(640,480,"Liang Barksky Line Clipping");
    cout << "Enter rectangular clipping window coordinates (TL and BR)\n";
    i = 0;
    while(i<2)
    {
        cw[i*2] = getMousePoints();
        i++;
    }
    cw[1].x = cw[2].x;
    cw[1].y = cw[0].y;
    cw[3].x = cw[0].x;
    cw[3].y = cw[2].y;
    cw[4] = cw[0];
    setcolor(WHITE);
    for(int i=0;i<4;i++)
    {
        line(cw[i].x, cw[i].y, cw[i+1].x, cw[i+1].y);
    }
    point l[2];
    l[0] = getMousePoints();
    l[1] = getMousePoints();
    setcolor(GREEN);
    line(l[0].x, l[0].y, l[1].x, l[1].y);
    setcolor(YELLOW);
    clipline(cw[0], cw[2], l[0], l[1]);
    closegraph();
    return 0;
}

point getMousePoints()
{
    point p;
    int x, y;
    while(!ismouseclick(WM_LBUTTONDOWN));
    getmouseclick(WM_LBUTTONDOWN, x, y);
    p.x = x;
    p.y = y;
    delay(100);
    cout << p.x << ' ' << p.y << endl;
    return p;
}

bool clipTest(float p, float q, float *t1, float *t2)
{
    float r;
    bool retVal=true;

    if(p<0.0)
    {
        r=q/p;
        if(r>*t2)
            retVal=false;
        else
            *t1=max(*t1,r);
    }
    else if(p>0.0)
    {
        r=q/p;
        if(r<*t1)
            retVal=false;
        else
            *t2=min(*t2,r);
    }
    else
    {
        if(q<0.0)
            retVal=false;
    }

    return retVal;

}

void clipline(point winMin, point winMax, point p1, point p2)
{
    float t1=0.0,t2=1.0, dx=p2.x-p1.x, dy=p2.y-p1.y;

    if(clipTest(-dx, p1.x-winMin.x, &t1, &t2))
    {
        if(clipTest(dx,winMax.x-p1.x,&t1,&t2))
        {
            if(clipTest(-dy,p1.y-winMin.y,&t1,&t2))
            {
                if(clipTest(dy,winMax.y-p1.y,&t1,&t2))
                {
                    //change only if u1 and u2 are changed
                    if(t2 < 1.0)
                    {
                        p2.x = p1.x + t2*dx;
                        p2.y = p1.y + t2*dy;
                    }

                    if(t1 > 0.0)
                    {
                        p1.x = p1.x + t1*dx;
                        p1.y = p1.y + t1*dy;
                    }

                    line(roundOff(p1.x),roundOff(p1.y),roundOff(p2.x),roundOff(p2.y));
                    getch();
                }
            }
        }
    }
}

int roundOff(float x)
{
    return (int)(x+0.5);
}
