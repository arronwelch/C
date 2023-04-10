# 1. the first simple assembly program
## Assembler
```bash
as hello.s -o hello.o
```
## Linker
```bash
ld hello.o -o hello
```
## Loader
```bash
./hello
echo $?
```

## objdump
```bash
objdump -D hello.o > hello.o.objdump.s
objdump -D hello > hello.objdump.s
```

## System Call
```
int $0x80
# eax 1 -> select system call function: _exit()
# ebx 4 -> parameter to system call function : _exit()
```

## intel and AT&T
movl %edx, %eax # AT&T : UNIX
mov eax, edx # intel : Intel & Windows
