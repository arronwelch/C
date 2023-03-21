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
