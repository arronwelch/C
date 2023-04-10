# 3. the second assembly program

```bash
$ as max.s -o max.o
$ ld max.o -o max
$ ./max
$ echo $?
$ 222
```
	- .long  : 32bit
	- .byte  : 8bit
	- .ascii :    
		.ascii "Hello world" (declaration 11 char)
		.ascii "Hello world\0" (declaration 12 char, end with '\0' char)
