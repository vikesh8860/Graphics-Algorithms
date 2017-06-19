#include <graphics.h>
#include <math.h>
#include <bits/stdc++.h>

using namespace std;

int xmin, ymin, xmax, ymax;

int firstEndPointRegion(int x, int y);
int findRegionP1(int x1, int y1);
void clipline1(int x1, int y1, int x2, int y2);
void clipline2(int x1, int y1, int x2, int y2);
void clipline3(int x1, int y1, int x2, int y2);
void clipline4(int x1, int y1, int x2, int y2);
void clipline5(int x1, int y1, int x2, int y2);
void clipline6(int x1, int y1, int x2, int y2);
void clipline7(int x1, int y1, int x2, int y2);
void clipline8(int x1, int y1, int x2, int y2);
void clipline9(int x1, int y1, int x2, int y2);

int main(){
    int x1, y1, x2, y2;
    int ch;
    float m;

    cout << "Enter the minimum and maximum values for the clipping window:\n";
    cin >> xmin >> ymin >> xmax >> ymax;
    cout<<"Enter the points:\n";
    cin >> x1 >> y1 >> x2 >> y2;

    initwindow(640, 480, "Nicholl-Lee-Nicholl Line Clipping");
    setcolor(12);
    rectangle(xmin, ymin, xmax, ymax);
    setcolor(10);
    line(x1, y1, xmin, ymin);
    line(x1, y1, xmax, ymin);
    line(x1, y1, xmax, ymax);
    line(x1, y1, xmin, ymax);
    getch();
    setcolor(12);
    setcolor(3);
    line(x1, y1, x2, y2);
    //getch();
    ch = firstEndPointRegion(x1, y1);
    switch(ch){
        case 1 : clipline1(x1, y1, x2, y2);
                 break;
        case 2 : clipline2(x1, y1, x2, y2);
                 break;
        case 3 : clipline3(x1, y1, x2, y2);
                 break;
        case 4 : clipline4(x1, y1, x2, y2);
                 break;
        case 5 : clipline5(x1, y1, x2, y2);
                 break;
        case 6 : clipline6(x1, y1, x2, y2);
                 break;
        case 7 : clipline7(x1, y1, x2, y2);
                 break;
        case 8 : clipline8(x1, y1, x2, y2);
                 break;
        case 9 : clipline9(x1, y1, x2, y2);
                 break;
        default: cout<<"\nInvalid Input.";
    };
    getch();
    return 0;
}

int firstEndPointRegion(int x, int y){
    if(x >= xmin && x <= xmax && y >= ymin && y <= ymax)
        return 1;
    else if(x <= xmin && y >= ymin && y <= ymax)
        return 2;
    else if(x <= xmin && y <= ymin)
        return 3;
    else if(y <= ymin && x >= xmin && x <= xmax)
        return 4;
    else if(x >= xmax && y <= ymin)
        return 5;
    else if(x >= xmax && y>=ymin && y <= ymax)
        return 6;
    else if(x >= xmax && y >= ymax)
        return 7;
    else if( x >= xmin && x <= xmax && y >= ymax)
        return 8;
    else if(x <= xmin && y >= ymax)
        return 9;
    else
        return 0;
}

// Point P1 is inside the clip window
void clipline1(int x1, int y1, int x2, int y2){
    int draw = 1;
    float m, m1, m2, m3, m4;
    int nx1, ny1, nx2, ny2;

    // Calculate slopes for all the lines passing thru vertices and including the input line
    m = ((float)(y2 - y1)) / (x2 - x1);
    m1 = ((float)(ymin - y1)) / (xmin - x1);
    m2 = ((float)(ymin - y1)) / (xmax - x1);
    m3 = ((float)(ymax - y1)) / (xmax - x1);
    m4 = ((float)(ymax - y1)) / (xmin - x1);
    nx1 = x1;
    ny1 = y1;

    if(((abs(m) >= m1 && x2 < x1) || (abs(m) > abs(m2) && x2 > x1)) && y1 > y2){
        getch();
        if(y2 > ymin){
            nx2 = x2;
            ny2 = y2;
        }
        else{
            ny2 = ymin;
            nx2 = x1 + (ymin - y1) / m;
        }
    }
    else if(m > m2 && m < m3 && x2 >= x1){
        if(x2 < xmax){
            nx2 = x2;
            ny2 = y2;
        }
        else{
            nx2 = xmax;
            ny2 = y1 + (xmax - x1) * m;
        }
    }
    else if((abs(m) >= m3 && x2 > x1) || (abs(m) > abs(m4) && x2 < x1)){
        if(y2 < ymax){
            nx2 = x2;
            ny2 = y2;
        }
        else{
            ny2 = ymax;
            nx2 = x1 + (ymax - y1) / m;
        }
    }
    else if(m > m4 && m < m1){
        if(x2 > xmin){
            nx2 = x2;
            ny2 = y2;
        }
        else{
            nx2 = xmin;
            ny2 = y1 + (xmin - x1) * m;
        }
    }

    getch();
    setcolor(12);
    rectangle(xmin, ymin, xmax, ymax);
    if(draw){
        setcolor(10);
        line(x1, y1, xmin, ymin);
        line(x1, y1, xmax, ymin);
        line(x1, y1, xmax, ymax);
        line(x1, y1, xmin, ymax);
        setlinestyle(SOLID_FILL, 1, 2);setcolor(YELLOW);setlinestyle(SOLID_FILL, 1, 2);
        line(nx1, ny1, nx2, ny2);
    }
}

void clipline2(int x1, int y1, int x2, int y2){
    int draw = 1;
    float m, m1, m2, m3, m4;
    int nx1, ny1, nx2, ny2;
    m = ((float)(y2 - y1)) / (x2 - x1);
    m1 = ((float)(ymin - y1)) / (xmin - x1);
    m2 = ((float)(ymin - y1)) / (xmax - x1);
    m3 = ((float)(ymax - y1)) / (xmax - x1);
    m4 = ((float)(ymax - y1)) / (xmin - x1);

    if(m > m3 && m < m2 && x2 > xmin){
        if(y2 > ymin){
            nx1 = xmin;
            ny1 = y1 + m * (xmin - x1);
            nx2 = x2;
            ny2 = y2;
        }
        else{
            nx1 = xmin;
            ny1 = y1 + m * (xmin - x1);
            ny2 = ymin;
            nx2 = x1 + (ymin - y1) / m;
        }
    }
    else if(m > m2 && m < m3 && x2 > xmin){
        if(x2 < xmax){
            nx1 = xmin;
            ny1 = y1 + m * (xmin - x1);
            nx2 = x2;
            ny2 = y2;
        }
        else{
            nx1 = xmin;
            ny1 = y1 + m * (xmin - x1);
            nx2 = xmax;
            ny2 = y1 + (xmax - x1) * m;
        }
    }
    else if(m > m3 && m < m4 && x2 > xmin){
        if(y2 < ymax){
            nx1 = xmin;
            ny1 = y1 + m * (xmin - x1);
            nx2 = x2;
            ny2 = y2;
        }
        else{
            nx1 = xmin;
            ny1 = y1 + m * (xmin - x1);
            ny2 = ymax;
            nx2 = x1 + (ymax - y1) / m;
        }
    }
    else
        draw = 0;

    setcolor(12);
    rectangle(xmin, ymin, xmax, ymax);
    if(draw){
        setcolor(10);
        line(x1, y1, xmin, ymin);
        line(x1, y1, xmax, ymin);
        line(x1, y1, xmax, ymax);
        line(x1, y1, xmin, ymax);
        setlinestyle(SOLID_FILL, 1, 2);setcolor(YELLOW);setlinestyle(SOLID_FILL, 1, 2);
        line(nx1, ny1, nx2, ny2);
    }
}

void clipline3(int x1, int y1, int x2, int y2){
    int draw = 1;
    float m, m1, m2, m3, m4, tm1, tm2;
    int nx1, ny1, nx2, ny2;
    int flag, t;
    tm1 = ((float)(ymin - y1)) / (xmin - x1);
    tm2 = ((float)(ymax - ymin)) / (xmax - xmin);
    m = ((float)(y2 - y1)) / (x2 - x1);
    m1 = ((float)(ymin - y1)) / (xmax - x1);
    m2 = ((float)(ymax - y1)) / (xmax - x1);
    m3 = ((float)(ymin - y1)) / (xmin - x1);
    m4 = ((float)(ymax - y1)) / (xmin - x1);
    if(tm1 < tm2){
        flag = 2;
        t = m2;
        m2 = m3;
        m3 = t;
    }
    else
        flag = 1;

    if(m > m1 && m < m2){
        if(x2 > xmax && y2 > ymin){
            ny1 = ymin;
            nx1 = x1 + (ymin - y1) / m;
            nx2 = xmax;
            ny2 = y1 + m * (xmax - x1);
        }
        else if(y2 > ymin && x2 < xmax){
            ny1 = ymin;
            nx1 = x1 + (ymin - y1) / m;
            ny2 = y2;
            nx2 = x2;
        }
    }
    else if(m > m2 && m < m3){
        if(flag == 1){
            if(y2 >= ymax){
                ny1 = ymin;
                nx1 = x1 + (ymin - y1) / m;
                nx2 = x1 + (ymax - y1) / m;
                ny2 = ymax;
            }
            else if(y2 >= ymin){
                ny1 = ymin;
                nx1 = x1 + (ymin - y1) / m;
                nx2 = x2;
                ny2 = y2;
            }
        }
        else{
            if(x2 >= xmax){
                nx1 = xmin;
                ny1 = y1 + m * (xmin - x1);
                nx2 = xmax;
                ny2 = y1 + m * (xmax - x1);
            }
            else if(x2 >= xmin){
                nx1 = xmin;
                ny1 = y1 + m * (xmin - x1);
                nx2 = x2;
                ny2 = y2;
            }
        }
    }
    else if(m > m3 && m < m4){
        if(y2 >= ymax){
            nx1 = xmin;
            ny1 = y1 + m * (xmin - x1);
            nx2 = x1 + (ymax - y1) / m;
            ny2 = ymax;
        }
        else if(y2 >= ymin){
            nx1 = xmin;
            ny1 = y1 + m * (xmin - x1);
            ny2 = y2;
            nx2 = x2;
        }
    }
    else
        draw = 0;

   getch();
   setcolor(12);
   rectangle(xmin, ymin, xmax, ymax);
   if(draw){
        setcolor(10);
        line(x1, y1, xmin, ymin);
        line(x1, y1, xmax, ymin);
        line(x1, y1, xmax, ymax);
        line(x1, y1, xmin, ymax);
        setlinestyle(SOLID_FILL, 1, 2);setcolor(YELLOW);setlinestyle(SOLID_FILL, 1, 2);
        line(nx1, ny1, nx2, ny2);
    }
}

void clipline4(int x1, int y1, int x2, int y2){
    int draw = 1;
    float m, m1, m2, m3, m4;
    int nx1, ny1, nx2, ny2;
    m = ((float)(y2 - y1)) / (x2 - x1);
    m1 = ((float)(ymin - y1)) / (xmin - x1);
    m2 = ((float)(ymin - y1)) / (xmax - x1);
    m3 = ((float)(ymax - y1)) / (xmax - x1);
    m4 = ((float)(ymax - y1)) / (xmin - x1);

    if(m <= m1 && m <= m2 && y2 >= ymin){
        if(x2 >= xmin){
            nx1 = x1 + (xmin - x1) / m;
            ny1 = ymin;
            nx2 = x2;
            ny2 = y2;
        }
        else{
            nx1 = x1 + (ymin - y1) / m;
            ny1 = ymin;
            ny2 = y2 + m * (xmin - x2);
            nx2 = xmin;
        }
    }
    else if(m <= m2 && m <= m3 && y2 >= xmin){
        if(y2 <= ymax){
            nx1 = x1 + (ymin - y1) / m;
            ny1 = ymin;
            nx2 = x2;
            ny2 = y2;
        }
        else{
            nx1 = x1 + (ymin - y1) / m;
            ny1 = ymin;
            nx2 = x2 + (ymax - y2) / m;
            ny2 = ymax;
        }
    }
    else if(m <= m3 && m >= m4 && y2 >= ymin){
        if(x2 < xmax){
            nx1 = x1 + (ymin - y1) / m;
            ny1 = ymin;
            nx2 = x2;
            ny2 = y2;
        }
        else{
            nx1 = x1 + (ymin - y1) / m;
            ny1 = ymin;
            ny2 = y1 + m * (xmax - x1);
            nx2 = xmax;
        }
    }
    else
        draw = 0;

    setcolor(12);
    rectangle(xmin, ymin, xmax, ymax);
    if(draw){
        setcolor(10);
        line(x1, y1, xmin, ymin);
        line(x1, y1, xmax, ymin);
        line(x1, y1, xmax, ymax);
        line(x1, y1, xmin, ymax);
        setlinestyle(SOLID_FILL, 1, 2);setcolor(YELLOW);setlinestyle(SOLID_FILL, 1, 2);
        line(nx1, ny1, nx2, ny2);
    }
}

void clipline5(int x1, int y1, int x2, int y2){
    int draw = 1;
    float m, m1, m2, m3, m4;
    int nx1, ny1, nx2, ny2;
    m = ((float)(y2 - y1)) / (x2 - x1);
    m1 = ((float)(ymin - y1)) / (xmin - x1);
    m2 = ((float)(ymin - y1)) / (xmax - x1);
    m3 = ((float)(ymax - y1)) / (xmax - x1);
    m4 = ((float)(ymax - y1)) / (xmin - x1);

    if(m > m4 && m < m2 && y2 > ymin){
        if(y2 < ymax && x2 > xmin){
            nx1 = xmax;
            ny1 = y1 + m * (xmax - x1);
            nx2 = x2;
            ny2 = y2;
        }
        else{
            nx1 = xmax;
            ny1 = y1 + m * (xmax - x1);
            nx2 = xmin;
            ny2 = y1 + m * (xmin - x1);
            cout << endl << nx1 << " " << ny1;
        }
    }
    else if(m > m3 && m < m4 && y2 > ymin){
        if(y2 < ymax){
            nx1 = xmax;
            ny1 = y1 + m * (xmax - x1);
            nx2 = x2;
            ny2 = y2;
        }
        else{
            nx1 = xmax;
            ny1 = y1 + m * (xmax - x1);
            nx2 = x1 + (ymax - y1) / m;
            ny2 = ymax;
        }
    }
    else if(m < m1 && m < m2 && y2 > ymin){
        if(y2 > ymax){
            nx1 = x1 + (ymin - y1) / m;
            ny1 = ymin;
            nx2 = x2;
            ny2 = y2;
        }
        else{
            nx1 = x1 + (ymin - y1) / m;
            ny1 = ymin;;
            nx2 = xmin;
            ny2 = y1 + m * (xmin - x1);
        }
    }
    else
        draw = 0;

    setcolor(12);
    rectangle(xmin, ymin, xmax, ymax);
    if(draw){
        setcolor(10);
        line(x1, y1, xmin, ymin);
        line(x1, y1, xmax, ymin);
        line(x1, y1, xmax, ymax);
        line(x1, y1, xmin, ymax);
        setlinestyle(SOLID_FILL, 1, 2);setcolor(YELLOW);setlinestyle(SOLID_FILL, 1, 2);
        line(nx1, ny1, nx2, ny2);
    }
}

void clipline6(int x1, int y1, int x2, int y2){
    int draw = 1;
    float m, m1, m2, m3, m4;
    int nx1, ny1, nx2, ny2;
    m = ((float)(y2 - y1)) / (x2 - x1);
    m1 = ((float)(ymin - y1)) / (xmin - x1);
    m2 = ((float)(ymin - y1)) / (xmax - x1);
    m3 = ((float)(ymax - y1)) / (xmax - x1);
    m4 = ((float)(ymax - y1)) / (xmin - x1);

    if(m < m4 && m < m1 && x2 < xmax){
        if(y2 > ymin){
            nx1 = xmax;
            ny1 = y1 + m * (xmin - x1);
            nx2 = x2;
            ny2 = y2;
        }
        else{
            nx1 = xmax;
            ny1 = y1 + m * (xmin - x1);
            nx2 = x2 + (ymin - y2) / m;
            ny2 = ymin;
        }
    }
    else if(m < m1 && m < m2 && x2 < xmax){
        if(x2 > xmin){
            nx1 = xmax;
            ny1 = y1 + m * (xmax - x1);
            nx2 = x2;
            ny2 = y2;
        }
        else{
            nx1 = xmax;
            ny1 = y1 + m * (xmax - x1);
            nx2 = xmin;
            ny2 = y1 + m * (xmin - x1);
        }
    }
    else if(m < m2 && m > m3 && x2 < xmax){
        if(y2 > ymin){
            nx1 = xmax;
            ny1 = y1 + m * (xmax - x1);
            nx2 = x2;
            ny2 = y2;
        }
        else{
            nx1 = xmax;
            ny1 = y1 + m * (xmax - x1);
            nx2 = x2 + (ymin - y2) / m;
            ny2 = ymin;
        }
    }
    else
        draw = 0;

    setcolor(12);
    rectangle(xmin, ymin, xmax, ymax);
    if(draw){
        setcolor(10);
        line(x1, y1, xmin, ymin);
        line(x1, y1, xmax, ymin);
        line(x1, y1, xmax, ymax);
        line(x1, y1, xmin, ymax);
        setlinestyle(SOLID_FILL, 1, 2);setcolor(YELLOW);setlinestyle(SOLID_FILL, 1, 2);
        line(nx1, ny1, nx2, ny2);
    }
}

void clipline7(int x1, int y1, int x2, int y2){
    int draw = 1;
    float m, m1, m2, m3, m4;
    int nx1, ny1, nx2, ny2;
    m = ((float)(y2 - y1)) / (x2 - x1);
    m1 = ((float)(ymin - y1)) / (xmin - x1);
    m2 = ((float)(ymin - y1)) / (xmax - x1);
    m3 = ((float)(ymax - y1)) / (xmax - x1);
    m4 = ((float)(ymax - y1)) / (xmin - x1);

    if(m <= m3 && m >= m4 && y2 <= ymax){
        if(x2 >= xmin && y2 >= ymin){
            nx1 = x1 + (ymax - y1) / m;
            ny1 = ymax;
            nx2 = x2;
            ny2 = y2;
        }
        else{
            nx1 = xmax;
            ny1 = y1 + m * (xmax - x1);
            nx2 = x1 + (ymin - y1) / m;
            ny2 = ymin;
        }
    }
    else if(m <= m3 && m <= m2 && y2 < ymax){
        if(x2 > xmin){
            nx1 = x1 + (ymax - y1) / m;
            ny1 = ymax;
            nx2 = x2;
            ny2 = y2;
        }
        else{
            nx1 = x1 + (ymax - y1) / m;
            ny1 = ymax;
            nx2 = xmin;
            ny2 = y1 + m * (xmin - x1);
        }
    }
    else if(m >= m1 && m >= m4 && y2 < ymax){
        if(y2 > ymin){
            nx1 = xmax;
            ny1 = y1 + m * (xmax - x1);
            nx2 = x2;
            ny2 = y2;
        }
        else{
            nx1 = xmax;
            ny1 = y1 + m * (xmax - x1);
            ny2 = ymin;
            nx2 = x1 + (ymin - y1) / m;
        }
    }
    else
        draw = 0;

    setcolor(12);
    rectangle(xmin, ymin, xmax, ymax);
    if(draw){
        setcolor(10);
        line(x1, y1, xmin, ymin);
        line(x1, y1, xmax, ymin);
        line(x1, y1, xmax, ymax);
        line(x1, y1, xmin, ymax);
        setlinestyle(SOLID_FILL, 1, 2);setcolor(YELLOW);setlinestyle(SOLID_FILL, 1, 2);
        line(nx1, ny1, nx2, ny2);
    }
}

void clipline8(int x1, int y1, int x2, int y2){
    int draw = 1;
    float m, m1, m2, m3, m4;
    int nx1, ny1, nx2, ny2;
    m = ((float)(y2 - y1)) / (x2 - x1);
    m1 = ((float)(ymin - y1)) / (xmin - x1);
    m2 = ((float)(ymin - y1)) / (xmax - x1);
    m3 = ((float)(ymax - y1)) / (xmax - x1);
    m4 = ((float)(ymax - y1)) / (xmin - x1);

    if(m >= m1 && m <= m2 && y2 < ymax){
        if(x2 > xmin){
            nx1 = x1 + (xmin - x1) / m;
            ny1 = ymin;
            nx2 = x2;
            ny2 = y2;
        }
        else{
            nx1 = x1 + (ymin - y1) / m;
            ny1 = ymin;
            ny2 = y2 + m * (xmin - x2);
            nx2 = xmin;
        }
    }
    else if(m >= m1 && m >= m4 && y2 < ymax){
        if(y2 > ymin){
            nx1 = x1 + (ymax - y1) / m;
            ny1 = ymax;
            nx2 = x2;
            ny2 = y2;
        }
        else{
            nx1 = x1 + (ymax - y1) / m;
            ny1 = ymax;
            nx2 = x1 + (ymin - y1) / m;
            ny2 = ymin;
        }
    }
    else if(m <= m1 && m >= m2 && y2 < ymax){
        if(x2 > xmin){
            nx1 = x1 + (ymax - y1) / m;
            ny1 = ymax;
            nx2 = x2;
            ny2 = y2;
        }
        else{
            nx1 = x1 + (ymax - y1) / m;
            ny1 = ymax;
            nx2 = xmin;
            ny2 = y1 + m * (xmin - x1);
        }
    }
    else
        draw = 0;

    setcolor(12);
    rectangle(xmin, ymin, xmax, ymax);
    if(draw){
        setcolor(10);
        line(x1, y1, xmin, ymin);
        line(x1, y1, xmax, ymin);
        line(x1, y1, xmax, ymax);
        line(x1, y1, xmin, ymax);
        setlinestyle(SOLID_FILL, 1, 2);setcolor(YELLOW);setlinestyle(SOLID_FILL, 1, 2);
        line(nx1, ny1, nx2, ny2);
    }
}

void clipline9(int x1, int y1, int x2, int y2){
    int draw = 1;
    float m, m1, m2, m3, m4;
    int nx1, ny1, nx2, ny2;
    m = ((float)(y2 - y1)) / (x2 - x1);
    m1 = ((float)(ymin - y1)) / (xmin - x1);
    m2 = ((float)(ymin - y1)) / (xmax - x1);
    m3 = ((float)(ymax - y1)) / (xmax - x1);
    m4 = ((float)(ymax - y1)) / (xmin - x1);

    cout << (m < m3) << (m > m2);

    if(m >= m4 && m >= m2 && y2 < ymax){
        if(x2 < xmax){
            nx1 = x1 + (ymax - y1) / m;
            ny1 = ymax;
            nx2 = x2;
            ny2 = y2;
        }
        else{
            nx1 = x1 + (ymax - y1) / m;
            ny1 = ymax;
            nx2 = xmax;
            ny2 = y1 + m * (xmax - x1);
        }
    }
    else if(m >= m1 && m <= m4 && y2 < ymax){
        if(x2 < xmax && y2 > ymin){
            nx1 = xmin;
            ny1 = y1 + m * (xmin - x1);
            nx2 = x2;
            ny2 = y2;
        }
        else{
            nx1 = xmin;
            ny1 = y1 + m * (xmin - x1);
            nx2 = x1 + (ymin - y1) / m;
            ny2 = ymin;
        }
    }
    else if(m <= m3 && m >= m2 && y2 < ymax){
        if(x2 > xmin){
            nx1 = x1 + (ymax - y1) / m;
            ny1 = ymax;
            nx2 = x2;
            ny2 = y2;
        }
        else{
            nx1 = x1 + (ymax - y1) / m;
            ny1 = ymax;
            nx2 = xmin;
            ny2 = y1 + m * (xmin - x1);
        }
    }
    else
        draw = 0;

    setcolor(12);
    rectangle(xmin, ymin, xmax, ymax);
    if(draw){
        setcolor(10);
        line(x1, y1, xmin, ymin);
        line(x1, y1, xmax, ymin);
        line(x1, y1, xmax, ymax);
        line(x1, y1, xmin, ymax);
        setlinestyle(SOLID_FILL, 1, 2);setcolor(YELLOW);setlinestyle(SOLID_FILL, 1, 2);
        line(nx1, ny1, nx2, ny2);
    }
}
