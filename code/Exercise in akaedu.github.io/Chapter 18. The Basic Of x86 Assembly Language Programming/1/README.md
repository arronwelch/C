# Assembler
```bash
as hello.s -o hello.o
```
# Linker
```bash
ld hello.o -o hello
```
# Loader
```bash
./hello
echo $?
```

# objdump
```bash
objdump -D hello.o > hello.o.objdump.s
objdump -D hello > hello.objdump.s
```

# System Call
0x80

