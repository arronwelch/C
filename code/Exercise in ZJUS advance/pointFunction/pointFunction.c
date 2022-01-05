#include <stdio.h>

void f(int i)
{
    printf("in f(), %d\n",i);
}

void g(int i)
{
    printf("in g(), %d\n",i);
}

void h(int i)
{
    printf("in h(), %d\n",i);
}

int main(void)
{
    int i = 0;
    int *p = &i;
    *p = 20;
    int a[] = {1,2};
    void (*pf)(int) = f;
    printf("%p\n",&i);
    printf("%p\n",p);
    printf("%p\n",&a);

    printf("%p\n",main);
    printf("%p\n",f);
    printf("%p\n",pf);

    f(20);
    (*pf)(10);

    void (*fa[])(int) = {f,g,h};

    scanf("%d",&i);
    if (i >= 0 && i < sizeof(fa)/sizeof(fa[0]))
    {
        (*fa[i])(0);
    }

    return 0;
}