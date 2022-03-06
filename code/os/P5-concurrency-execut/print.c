#include <threads.h>
#include <stdio.h>

#define M 2
#define N 3

void thread_entry(int tid) {
  for ( int i =1; i <= M; i++ )
  {
    printf("[T%d]'s %d-th operation\n",tid , i);
  }
}

int main() {
  for(int i=0; i < N; i++)
    create(thread_entry);
}

