// #define name replacement \
//         test

// // no substitution in printf("YES") or in YESMAN

// #define forever for(;;) /* infinite loop */

// #define max(A,B) ((A) > (B) ? (A) : (B) )

// max(i++,j++) /* WRONG */

// #define square(x) x * x /* WRONG */
// #define square(x) (x) * (x) /* correct */

// #undef getchar

// int getchar(void) //ensure a routine is really a function
// {
//     ...
// }

// #define dprint(expr) printf(#expr " = %g\n",expr) //a debugging print macro

// dprint(x/y);

// printf("x/y" " = %g\n",x/y);

// printf("x/y = %g\n",x/y);

// #define paste(front,back) front ## back
// paste(name,1);

#include <stdio.h>

#define forever for(;;) /* infinite loop */
#define max(A,B) ((A) > (B) ? (A) : (B) )
#define square(x) (x) * (x)
#define dprint(expr) printf(#expr " = %g\n",expr) //a debugging print macro
#define paste(front,back) front ## back
#define swap(t,x,y) { t tmp = (x); (x) = (y); (y) = tmp;}

//1----------------------------------
#if !define(HDR) //1 if the name has been defined,and 0 otherwise.
#define HDR

/* contents of hdr.h go here */

#endif
//1----------------------------------

//2----------------------------------
#if SYSTEM == SYSV
    #define HDR "sysv.h"
#elif SYSTEM == BSD
    #define HDR "bsd.h"
#elif SYSTEM == MSDOS
    #define HDR "msdos.h"
#else
    #define HDR "default.h"
#endif

#include HDR
//2----------------------------------

//3----------------------------------
#ifndef HDR //The #ifndef and #ifdef lines are specialized forms that test whether a name is defined
#define HDR

/* contents of hdr.h go here */

#endif
//3----------------------------------

int main(void)
{
    int a,b,c;
    a = 1;
    b = 2;
    dprint(max(a,b));
    double c1 = 1005.123;
    paste(c,1);
    dprint(c1);
    swap(int,a,b);
    printf("a = %d\n",a);
    printf("b = %d\n",b);
    
    forever;
    
    return 0;
}