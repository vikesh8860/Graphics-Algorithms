#include <iostream>
#include <graphics.h>
using namespace std;

int main()
{
  int gdriver=DETECT,gmode,errorcode;
    initgraph(&gdriver,&gmode,"C:\\TC\\BGI");
    errorcode=graphresult();
    if(errorcode!=grOk)
    {
        cout<<"Graphics error:\n"<<grapherrormsg(errorcode);
        cout<<"Press any key to halt:";
        getch();
        exit(1);
    }
    setcolor(getmaxcolor());
    line(10,10,20,20);
    line(10,20,20,20);
    line(20,10,20,20);
    line(20,20,30,30);
    line(10,30,30,30);
    line(30,10,30,30);
    getch();
    closegraph();
    return 0;
}
