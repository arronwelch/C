#include <threads.h>

#define N 10000000

typedef struct spinlock {
  intptr_t locked;
} spinlock_t;

void spin_init(spinlock_t *lk) {
  lk->locked = 0;
}

void spin_lock(spinlock_t *lk) {
  while(atomic_xchg(&lk->locked,1));
}

void spin_unlock(spinlock_t *lk) {
  atomic_xchg(&lk->locked,0);
}

spinlock_t lk;

long volatile sum = 0;

void do_sum() {
  for(int i=0; i<N; i++) {
    //spin_lock(&lk);
    lock();
    sum++;
    //spin_unlock(&lk);
    unlock();
  }
}

void print() {
  printf("sum=%ld\n",sum);
}

int main() {
  spin_init(&lk);
  for(int i=0;i<4;i++)
    create(do_sum);
  join(print);
}
