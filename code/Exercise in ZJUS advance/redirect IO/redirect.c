
/** 
     *  prog < infile
     *  prog > outfile
     *  prog1 | prog2
 * gcc redirect.c -o redirect
 * ./redirect
 * 1234
 * 1234
 * 1:5
 * ./redirect > outfile.out
 * 12345
 * more outfile.out
 * 12345
 * 1:6
 * cat > 12.in
 * 12
 * Ctrl + D
 * more 12.in
 * 12
 * ./redirect < 12.in
 * 12
 * 1:3
 * ./redirect < 12.in > 12.out
 * more 12.out
 * 12
 * 1:3
 * */

#include <stdio.h>

int main(int argc, char const *argv[])
{
    int num = 0;
    int var_cnt = scanf("%d", &num);
    int char_cnt = printf("%d\n", num);
    printf("%d:%d\n", var_cnt, char_cnt);

    return 0;
}