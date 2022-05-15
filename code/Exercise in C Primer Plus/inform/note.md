# Unix System
Historically, the Unix C compiler, invoked with the __cc__ command, defined the language.But it didn't keep pace with the developing standard, and it has been retired.However, Unix systems typically provide a C compiler from some other source, and then make the __cc__ command an alias for that compiler.So you still can proceed with the same command, even though it may invoke different compilers in different systems.
```bash
$ cc inform.c
$ ls
$ ./a.out
```
# The GNU Compiler Collection and the LLVM Project
```bash
$ cc -v
$ gcc -std=c99 inform.c
$ gcc -std=c1x inform.c
$ gcc -std=c11 inform.c
```
