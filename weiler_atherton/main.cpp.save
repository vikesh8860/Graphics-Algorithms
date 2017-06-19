#include <graphics.h>
#include <bits/stdc++.h>
using namespace std;
struct point {
    int x, y;
};
struct boolPoint {
    point p;
    bool mode;

    boolPoint()
    {
        mode = false;
    }
};

point getMousePoints();
boolPoint getBoolPoint(point p, bool mode);
boolPoint getBoolPoint(boolPoint p, bool mode);
vector<vector<point>> clip(point wMin, point wMax, vector<point> poly);
vector<boolPoint> clipL(int xmin, vector<point> poly);
vector<boolPoint> clipR(int xmax, vector<boolPoint> poly);
vector<boolPoint> clipT(int ymax, vector<boolPoint> poly);
vector<boolPoint> clipB(int ymin, vector<boolPoint> poly);

int main()
{
    point cw[5];
    int i;
    initwindow(640,480,"Weiler Atherton Polygon Clipping");
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
    drawpoly(5, (int*)cw);
    vector<point> poly;
    cout << "Enter Polygon Points (Right click to stop): ";
    while(!ismouseclick(WM_RBUTTONDOWN))
    {
        poly.push_back(getMousePoints());
    }
    cout << endl;
    poly.push_back(poly[0]);
    setcolor(WHITE);
    drawpoly(poly.size(), (int*) &poly[0]);
    delay(500);
    vector<vector<point>> polygons = clip(cw[0], cw[2], poly);
    int color = 5;
    setcolor(GREEN);
    setlinestyle(SOLID_LINE, 1, 2);
    for(auto polygon: polygons)
    {
        setfillstyle(BKSLASH_FILL, color);
        color = (color+1)%16;
        if(color==1)
            color++;
        fillpoly(polygon.size(), (int*) &polygon[0]);
    }
    cout << "DONE!";
    getch();
    closegraph();
    return 0;
}

point getMousePoints()
{
    point p;
    while(!ismouseclick(WM_LBUTTONDOWN));
    getmouseclick(WM_LBUTTONDOWN, p.x, p.y);
    delay(100);
    cout << p.x << ' ' << p.y << endl;
    return p;
}

vector<vector<point>> clip(point wMin, point wMax, vector<point> poly)
{
    vector<boolPoint> clippedPoints;
    clippedPoints = clipL(wMin.x, poly);
    clippedPoints = clipR(wMax.x, clippedPoints);
    clippedPoints = clipT(wMax.y, clippedPoints);
    clippedPoints = clipB(wMin.y, clippedPoints);
    vector<boolPoint> l, r, t, b, cw;
    int rad = 2;
    for(auto x: clippedPoints)
    {
        boolPoint k = x;
        k.mode = !k.mode;
        if(x.p.x == wMin.x)
            l.push_back(k);
        else if(x.p.x == wMax.x)
            r.push_back(k);
        else if(x.p.y == wMin.y)
            b.push_back(k);
        else if(x.p.y == wMax.y)
            t.push_back(k);
    }
    sort(l.begin(), l.end(), [](boolPoint a, boolPoint b){return (a.p.y>b.p.y);});
    sort(r.begin(), r.end(), [](boolPoint a, boolPoint b){return (a.p.y<b.p.y);});
    sort(t.begin(), t.end(), [](boolPoint a, boolPoint b){return (a.p.x>b.p.x);});
    sort(b.begin(), b.end(), [](boolPoint a, boolPoint b){return (a.p.x<b.p.x);});
    boolPoint tl, tr, bl, br;
    bl.p = wMin;
    tr.p = wMax;
    tl.p.x = wMin.x;
    tl.p.y = wMax.y;
    br.p.y = wMin.y;
    br.p.x = wMax.x;
    tr.mode = tl.mode = bl.mode = br.mode = true;
    cw.push_back(tl);
    cw.insert(cw.end(), t.begin(), t.end());
    cw.push_back(tr);
    cw.insert(cw.end(), r.begin(), r.end());
    cw.push_back(br);
    cw.insert(cw.end(), b.begin(), b.end());
    cw.push_back(bl);
    cw.insert(cw.end(), l.begin(), l.end());
    vector<vector<point>> polygons;
    int i;
    while(1)
    {
        vector<point> polygon;
        point temp;
        i=0;
        while(!clippedPoints[i].mode && i<clippedPoints.size())
            i++;
        if(i == clippedPoints.size())
            break;
        temp = clippedPoints[i].p;
        while(1)
        {
            i = 0;
            while((temp.x!=clippedPoints[i].p.x || temp.y!=clippedPoints[i].p.y) && i<clippedPoints.size())
                i++;
            if(i==clippedPoints.size() || !clippedPoints[i].mode)
                break;
            while(clippedPoints[i].mode)
            {
                polygon.push_back(clippedPoints[i].p);
                clippedPoints[i].mode = false;
                i++;
                i%=clippedPoints.size();
                temp = clippedPoints[i].p;
            }
            i = 0;
            while((temp.x!=cw[i].p.x || temp.y!=cw[i].p.y) && i<cw.size())
                i++;
            if(i==cw.size() || !cw[i].mode)
                break;
            while(cw[i].mode)
            {
                polygon.push_back(cw[i].p);
                cw[i].mode = false;
                i++;
                i%=cw.size();
                temp = cw[i].p;
            }
        }
        polygon.push_back(polygon[0]);
        polygons.push_back(polygon);
    }
    return polygons;
}

vector<boolPoint> clipL(int xmin, vector<point> poly)
{
    vector<boolPoint> clippedPoints;
    point p, q, t;
    double m;
    for(int i=1;i<poly.size();i++)
    {
        p = poly[i-1];
        q = poly[i];
        if(p.x==q.x)        // Slope is infinity
        {
            if(q.x>=xmin)
                clippedPoints.push_back(getBoolPoint(q, true));
        }
        else
        {
            m = ((float)(p.y-q.y))/(p.x-q.x);
            if(p.x<xmin && q.x>=xmin)
            {
                t.x = xmin;
                t.y = p.y + (m*(xmin-p.x));
                clippedPoints.push_back(getBoolPoint(t, true));
                clippedPoints.push_back(getBoolPoint(q, true));
            }
            else if(p.x>=xmin && q.x>=xmin)
                clippedPoints.push_back(getBoolPoint(q, true));
            else if(p.x>=xmin && q.x<xmin)
            {
                t.x = xmin;
                t.y = p.y + m*(xmin-p.x);
                clippedPoints.push_back(getBoolPoint(t, false));
            }
        }
    }
    clippedPoints.push_back(clippedPoints[0]);
    return clippedPoints;
}

vector<boolPoint> clipR(int xmax, vector<boolPoint> poly)
{
    vector<boolPoint> clippedPoints;
    point p, q, t;
    boolPoint a;
    double m;
    for(int i=1;i<poly.size();i++)
    {
        a = poly[i];
        p = poly[i-1].p;
        q = poly[i].p;
        if(p.x==q.x)        // Slope is infinity
        {
            if(q.x<=xmax)
                clippedPoints.push_back(a);
        }
        else
        {
            m = ((float)(p.y-q.y))/(p.x-q.x);
            if(p.x>xmax && q.x<=xmax)
            {
                t.x = xmax;
                t.y = p.y + (m*(xmax-p.x));
                clippedPoints.push_back(getBoolPoint(t, true));
                clippedPoints.push_back(a);
            }
            else if(p.x<=xmax && q.x<=xmax)
                clippedPoints.push_back(a);
            else if(p.x<=xmax && q.x>xmax)
            {
                t.x = xmax;
                t.y = p.y + m*(xmax-p.x);
                clippedPoints.push_back(getBoolPoint(t, false));
            }
        }
    }
    clippedPoints.push_back(clippedPoints[0]);
    return clippedPoints;
}

vector<boolPoint> clipB(int ymin, vector<boolPoint> poly)
{
    vector<boolPoint> clippedPoints;
    point p, q, t;
    boolPoint a;
    double m;
    for(int i=1;i<poly.size();i++)
    {
        a = poly[i];
        p = poly[i-1].p;
        q = poly[i].p;
        if(p.y==q.y)        // Slope is infinity
        {
            if(q.y>=ymin)
                clippedPoints.push_back(a);
        }
        else
        {
            m = ((float)(p.x-q.x))/(p.y-q.y);
            if(p.y<ymin && q.y>=ymin)
            {
                t.y = ymin;
                t.x = p.x + (m*(ymin-p.y));
                clippedPoints.push_back(getBoolPoint(t, true));
                clippedPoints.push_back(a);
            }
            else if(p.x>=ymin && q.y>=ymin)
                clippedPoints.push_back(a);
            else if(p.y>=ymin && q.y<ymin)
            {
                t.y = ymin;
                t.x = p.x + m*(ymin-p.y);
                clippedPoints.push_back(getBoolPoint(t, false));
            }
        }
    }
    return clippedPoints;
}

vector<boolPoint> clipT(int ymax, vector<boolPoint> poly)
{
    vector<boolPoint> clippedPoints;
    point p, q, t;
    boolPoint a;
    double m;
    for(int i=1;i<poly.size();i++)
    {
        a = poly[i];
        p = poly[i-1].p;
        q = poly[i].p;
        if(p.y==q.y)        // Slope is infinity
        {
            if(q.y<=ymax)
                clippedPoints.push_back(a);
        }
        else
        {
            m = ((float)(p.x-q.x))/(p.y-q.y);
            if(p.y>ymax && q.y<=ymax)
            {
                t.y = ymax;
                t.x = p.x + (m*(ymax-p.y));
                clippedPoints.push_back(getBoolPoint(t, true));
                clippedPoints.push_back(a);
            }
            else if(p.y<=ymax && q.y<=ymax)
                clippedPoints.push_back(a);
            else if(p.y<=ymax && q.y>ymax)
            {
                t.y = ymax;
                t.x = p.x + m*(ymax-p.y);
                clippedPoints.push_back(getBoolPoint(t, false));
            }
        }
    }
    clippedPoints.push_back(clippedPoints[0]);
    return clippedPoints;
}

boolPoint getBoolPoint(point p, bool mode)
{
    boolPoint x;
    x.p = p;
    x.mode = mode;
    return x;
}

boolPoint getBoolPoint(boolPoint p, bool mode)
{
    p.mode = mode;
    return p;
}
