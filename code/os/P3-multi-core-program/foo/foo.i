# 1 "foo.c"
# 1 "<built-in>"
# 1 "<command-line>"
# 31 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 32 "<command-line>" 2
# 1 "foo.c"
extern int x;
int foo() {
  int volatile t = x;
  t += 1;
  x = t;
}
