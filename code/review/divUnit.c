// #include <stdio.h>

// /*
// 180 2
// 90  2
// 45  3
// 15  3
// 5   5
// 1

// 93938

// 2000000014
// */

// int isPrime(int a)
// {
//     int flag = 1;
//     for (int i = 2; i < a/2; i++)
//     {
//         if(a%i == 0)
//             flag = 0;
//     }

//     return flag;
// }

// int main()
// {
//     int x;
//     scanf("%d", &x);
//     for (int i = 2; x > 1;)
//     {
//         if (x % i == 0)
//         {
//             x /= i;
//             printf("%d ", i);
//         }
//         else if( isPrime(x))
//             i = x;
//         else
//             i++;
//     }
//     printf("\n");

//     return 0;
// }


#include <stdio.h>
 
int main(void){
    int n;
    while(scanf("%d", &n) == 1){
        int tmp = n;
        for(int i = 2; i * i <= tmp && n >= i; i++){
            while(n % i == 0){
                printf("%d ", i);
                n /= i;
            }
        }
        if(n - 1) printf("%d ", n);
        putchar('\n');
    }
    return 0;
}