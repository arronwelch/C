
#include <stdio.h>

#define XMAX 320
#define YMAX 200
#define min(a,b) ((a) < (b) ? (a) : (b))
#define max(a,b) ((a) > (b) ? (a) : (b))

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

/* function declaration */
struct point makepoint(int, int);
struct point addpoint(struct point, struct point);
int ptinrect(struct point , struct rect );
struct rect canonrect(struct rect );

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

    printf("point middle is in screen ? %s\n",ptinrect(middle,screen) ? "YES" : "NO");

    screen.pt2 = makepoint(0, 0);
    screen.pt1 = makepoint(XMAX, YMAX);
    printf("rect screen = pt1(%d,%d) pt1(%d,%d)\n",screen.pt1.x,screen.pt1.y,screen.pt2.x,screen.pt2.y);
    screen = canonrect(screen);
    printf("rect screen = pt1(%d,%d) pt1(%d,%d)\n",screen.pt1.x,screen.pt1.y,screen.pt2.x,screen.pt2.y);

    struct point *pp;/* 'pp' is a pointer to a structure of type 'structure point' */
    struct point origin = { 123, 456 };
    pp = &origin;
    printf("origin is (%d,%d)\n",(*pp).x,(*pp).y);
    origin.x = 456;
    origin.y = 123;
    printf("origin is (%d,%d)\n",pp->x,pp->y);/* an alternative notation */

    /* these four expressions are equivalent: */
    struct rect r, *rp = &r;
    r.pt1.x = 1;
    printf("r.pt1.x = %d\n",r.pt1.x);
    rp->pt1.x = 2;
    printf("rp->pt1.x = %d\n",rp->pt1.x);
    (r.pt1).x = 3;
    printf("(r.pt1).x  = %d\n",(r.pt1).x );
    (rp->pt1).x = 4;
    printf("(rp->pt1).x = %d\n",(rp->pt1).x);

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

/* ptinrect: return 1 if p in r, 0 if not 
 * we have adopted the convention that 
 * a rectangle includes its left and bottom sides 
 * but not its top and right sides
 */
int ptinrect(struct point p, struct rect r)
{
    return p.x >= r.pt1.x && p.x < r.pt2.x
        && p.y >= r.pt1.y && p.y < r.pt2.y;
}

/* canonrect: canonicalize coordinates of rectangle */
struct rect canonrect(struct rect r)
{
    struct rect temp;

    temp.pt1.x = min(r.pt1.x, r.pt2.x);
    temp.pt1.y = min(r.pt1.y, r.pt2.y);
    temp.pt2.x = max(r.pt1.x, r.pt2.x);
    temp.pt2.y = max(r.pt1.y, r.pt2.y);

    return temp;
}

