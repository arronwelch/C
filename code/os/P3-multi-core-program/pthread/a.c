#include <stdio.h>
//#include "threads.h"
#include <threads.h>

void a() { while(1) {  printf("a");} }
void b() { while(1) {  printf("b");} }

int main() {
  setbuf(stdout, NULL); // ???
  create(a);
  create(b);
}
