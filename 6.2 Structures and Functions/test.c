
#include <stdio.h>

#define XMAX 320
#define YMAX 200

/* function declaration */
struct point makepoint(int, int);
struct point addpoint(struct point, struct point);

/* global variable */
struct point /* an optional name --- a structure tag */
{
    int x; /* menbers */
    int y; /* menbers */
};

struct rect
{
    struct point pt1;
    struct point pt2;
};

int main(void)
{
    struct rect screen;
    struct point middle;
    screen.pt1 = makepoint(0, 0);
    screen.pt2 = makepoint(XMAX, YMAX);
    middle = makepoint((screen.pt1.x + screen.pt2.x) / 2, (screen.pt1.y + screen.pt2.y) / 2);
    printf("middle = (%d,%d)\n",middle.x,middle.y);

    struct point ptadd;
    ptadd = addpoint(middle,middle);
    printf("middle + middle = (%d,%d)\n",ptadd.x,ptadd.y);

    return 0;
}

/* makepoint: make a point from x and y components */
struct point makepoint(int x, int y)
{
    struct point temp;

    temp.x = x;
    temp.y = y;
    return temp;
}

/* addpoints: add two points */
struct point addpoint(struct point p1, struct point p2)
{
    p1.x += p2.x;
    p1.y += p2.y;

    return p1;
}