extern int x;
int foo() {
  int volatile t = x;
  t += 1;
  x = t;
}
