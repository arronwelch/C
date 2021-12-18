
#include <stdio.h>

struct point/* an optional name --- a structure tag */
{
    int x;/* menbers */
    int y;/* menbers */
};

struct/* unnamed structure */
{
    int a;
    int b;
}x,y,z;

struct point pt;

struct point maxpt = { 320, 200 };

struct rect {
    struct point pt1;
    struct point pt2;
};

struct rect screen;

int main()
{
    printf("(%d,%d)\n",pt.x,pt.y);

    double dist, sqrt(double);

    dist = sqrt((double)maxpt.x * maxpt.y + (double) maxpt.y * maxpt.y);
    
    printf("dist = %f\n",dist);

    screen.pt1.x = maxpt.x;
    screen.pt1.y = maxpt.y;

    printf("screen.pt1.x = %d\n",screen.pt1.x);
    printf("screen.pt1.y = %d\n",screen.pt1.y);

    printf("screen area = %d\n",(screen.pt1.x) * (screen.pt1.y));

    return 0;
}
