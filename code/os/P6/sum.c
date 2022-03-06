#include <threads.h>

#define N 10000000
#define PREFIX

long sum;

void do_sum() {
  for(int i =0; i < N; i++) {
    asm volatile(PREFIX "addq $1, %0":"=m"(sum));
  }
}

void print() {
  printf("sum=%ld\n",sum);
}

int main() {
  for(int i=0;i<4;i++)
    create(do_sum);
  join(print);
}

