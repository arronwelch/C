#include "acllib.h"
#include <stdio.h>

int Setup()
{
    initConsole();
    printf("please input width:");
    int width,height;
    scanf("%d",&width);
    height = width;
    initWindow("test",100,100,width,height);
    beginPaint();
    setPenColor(BLUE);
    setPenWidth(1);
    setPenStyle(PEN_STYLE_DASHDOTDOT);
    line(20,20,width-20,height-20);
    // putPixel(100,150,RGB(255,0,255));
    putPixel(100,150,GREEN);
    endPaint();

    return 0;
}
