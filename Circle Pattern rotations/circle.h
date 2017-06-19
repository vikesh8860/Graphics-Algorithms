#ifndef CIRCLE_H_INCLUDED
#define CIRCLE_H_INCLUDED
void putcircle(int x,int y,int xleft,int yright,int col)
{
    if(col){
    putpixel(xleft+x,yright-y,WHITE);
    putpixel(xleft+y,yright-x,WHITE);
    putpixel(xleft+x,yright+y,WHITE);
    putpixel(xleft+y,yright+x,WHITE);
    putpixel(xleft-x,yright-y,WHITE);
    putpixel(xleft-y,yright-x,WHITE);
    putpixel(xleft-x,yright+y,WHITE);
    putpixel(xleft-y,yright+x,WHITE);
    }
    else
    {
    putpixel(xleft+x,yright-y,BLACK);
    putpixel(xleft+y,yright-x,BLACK);
    putpixel(xleft+x,yright+y,BLACK);
    putpixel(xleft+y,yright+x,BLACK);
    putpixel(xleft-x,yright-y,BLACK);
    putpixel(xleft-y,yright-x,BLACK);
    putpixel(xleft-x,yright+y,BLACK);
    putpixel(xleft-y,yright+x,BLACK);
    }
}
void print_circle(int x,int y,int xleft,int yright,int col)
{
 int d=5/4-y;
 while(x<=y)
 {
     if(d<=0)
        d+=2*x+3;
     else
     {
         d+=2*(x-y)+5;
         y--;
     }
     x++;
     putcircle(x,y,xleft,yright,col);
 }
}
#endif // CIRCLE_H_INCLUDED
