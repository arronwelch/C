# function call
```bash
gcc funcall.c -g
objdump -dS a.out | less
gcc -S funcall.c
gdb a.out
```
```gdb
start
s
s
disassemble
si
si
si
si
si
bt
info registers
x/20 $esp
quit
y
```

```
yum install libgcc.i686 glibc-devel.i686
y
gcc -m32 funcall.c -g
gdb a.out
```
## Calling Convention(ABI, Application Binary Interface)

## main Function and Startup Example Exercise
```bash
vim hello.s
as hello.s -o hello.o
ld hello.o -o hello

# gcc command default outfile name
vim main.c
gcc -S main.c         # -> main.s
gcc -c main.s         # -> main.o
gcc main.o -o main    # -> main

# use gcc to link the file "hello.o" which product by cmd "as hello.s -o hello.o"
gcc hello.o -o hello.out

# Startup Routine
# /usr/lib/gcc/x86_64-redhat-linux/8/../../../../lib64/crt1.o (include _start)
# _start need to call main function

gcc main.o -o main
ld /usr/lib/crt1.o /usr/lib/crti.o main.o -o main -lc -dynamic-linker /lib/ld-linux.so.2
readelf /usr/lib/crt1.o
readelf /usr/lib/crti.o
nm /usr/lib/crt1.o
nm /usr/lib/crti.o
```
