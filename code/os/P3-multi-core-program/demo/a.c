#include <stdio.h>

int main(){
  int *p; //
  p = NULL;
  p = (int *) 12345678;

  *p = 1;
  return 0;
}

int myfun(){
  int a = 0;
  printf("process in\n");

  return 1;
}
