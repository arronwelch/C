#include <stdio.h>

extern int a;//external variable
void h(void);

int main()
{
    // a = 10;
    void f(void);
    f();
    printf("%d\n",a);
    void g(void);
    g();
    h();
    g();
    h();
    return 0;
}

void f(void)
{
    auto int a = 11;//automatic variable/local variable
    printf("%d\n",a);
}

void g(void)
{
    extern int b;//external variable
    printf("%d\n",b);
}

void h(void)
{
    static int c = 20;
    printf("%d\n",c++);
}

int a;//external variable are initialized to zero by default.
int b = 12;
