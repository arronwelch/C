
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int mrand(void);
void msrand(unsigned int seed);

int main()
{
    //system("date");

    int *ip, n = 10;

    ip = (int *)calloc(n, sizeof(int));

    free(ip);

    msrand(time(NULL));
    for (size_t i = 0; i < 10; i++)
    {        
        printf("%d ", mrand());
    }

    return 0;
}

//
//
//for (p =head; p!= NULL; p=p->next) /* WRONG */
//    free(p);
//for(p = head; p != NULL; p = q)
// {
//   q = p->next;
//   free(p);
// }
//
//

unsigned long int next = 1;

/* rand: return pseudo-random integer on 0..32767 */
int mrand(void)
{
    next = next * 1103515245 + 12345;
    return (unsigned int)(next / 65536) % 32768;
}

/* srand: set seed for rand() */
void msrand(unsigned int seed)
{
    next = seed;
}
