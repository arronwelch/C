# function call
```bash
vim funcall.c
gcc *.c -g -m32
objdump -dS a.out | less
gcc *.c -S
vim *.s
gdb a.out
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
x/20x $esp
```
