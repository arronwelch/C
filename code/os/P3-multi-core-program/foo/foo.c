extern int x;
int x = 0;
int foo() {
  int volatile t = x;
  t += 1;
  x = t;
}

int main() {
 // int x = 0;
  foo();
}

