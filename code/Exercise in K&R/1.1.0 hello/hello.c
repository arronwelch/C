
/* review C language
   Exercise 1 hello world

    > deft@deft-virtual-machine:~/study/C/code/Exercise in K&R/1.1.0 hello$ cc hello.c
    > deft@deft-virtual-machine:~/study/C/code/Exercise in K&R/1.1.0 hello$ ./a.out
    > hello, world
    > deft@deft-virtual-machine:~/study/C/code/Exercise in K&R/1.1.0 hello$ find -name "*.out" -delete
   2021-08-02 */

#include <stdio.h>
int main(int argc, char *argv[])
{
    printf("hello, world\n");

    return 0;
}
