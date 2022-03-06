
#include <threads.h>

#define N 100000000

long sum = 0;

void do_sum() {
  for(int i=0;i<N; i++) {
    lock();
    sum++;
    unlock();
  }
}

void print() {
  printf("sum=%ld\n",sum);
}

int main() {
  create(do_sum);
  create(do_sum);
  join(print);
}
