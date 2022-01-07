#include <stdio.h>
#include <stdlib.h>

void f(int i)
{
    printf("in f(), %d\n", i);
}

void g(int i)
{
    printf("in g(), %d\n", i);
}

void h(int i)
{
    printf("in h(), %d\n", i);
}

int plus(int a, int b)
{
    return a + b;
}

int minus(int a, int b)
{
    return a - b;
}

void cal(int (*f)(int, int))
{
    printf("%d\n", (*f)(2, 3));
}

int main(void)
{
    int i = 0;
    int *p = &i;
    *p = 20;
    int a[] = {1, 2};
    f;
    void (*pf)(int) = f;
    int *pint = (int *)malloc(sizeof(int));
    *pint = 100;
    printf("&i:\t%p\n", &i);
    printf("p:\t%p\n", p);
    printf("&a:\t%p\n", &a);
    printf("&a[0]:\t%p\n", &a[0]);
    printf("&a[1]:\t%p\n", &a[1]);
    printf("pint:\t%p\n", pint);

    printf("main:\t%p\n", main);
    printf("f:\t%p\n", f);
    printf("pf:\t%p\n", pf);

    f(20);
    (*pf)(10);

    void (*fa[])(int) = {f, g, h};

    scanf("%d", &i);
    if (i >= 0 && i < sizeof(fa) / sizeof(fa[0]))
    {
        (*fa[i])(i);
    }
    free(pint);

    cal(plus);
    cal(minus);

    return 0;
}