#define DELAY_COUNT 100

void delay() {
  for(volatile int i = 0; i < DELAY_COUNT; i++);
}


extern int x;
extern int y;

#define barrier() asm volatile ("":::"memory")

void foo() {
  x++;
  barrier();
  x++;// avoid access to x become together
  y++;// access to y can't move to before barrier()
}
