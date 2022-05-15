# C Primer Plus, 6th Edition
## Preface
## Approach and Goals
To gain the greatest benefit, you should take as active a role as possible in studying the topics in this book.Don't just read the examples, enter them into your system, and try them.
## 1. Getting Ready
### Language Standards
Currently, many C implementations are available.Ideally, when you write a C program, it should work the same on any implementation, providing it doesn't use machine-specific programming.For this to be true in practice, different implementations need to conform to a recognized standard.
At first, there was no official standard for C.Instead, the first edition of *The C programming Language* by Brian Kernighan and Dennis Ritchie (1978) became the accepted standard, usually referred to as *K&R C* or *Classic C*.In particular, the "C Reference Manual" in that book's appendix acted as the guide to C implementations.Compilers, for example, would claim to offer a full K&R implementation.However, although this appendix defined the C language, it did not define the C library. More than most languages, C depends on its library, so there is need for a library standard, too.In the absence of any official standard, the library supplied with the Unix implementation became a de facto standard.

#### The First ANSI/ISO C Standard
 - Trust the programmer.
 - Don't prevent the programmer from doing what needs to be done.
 - Keep the language small and simple.
 - Provide only one way to do an operation.
 - Make it fast, even if it is not guaranteed to be portable.
#### The C99 Standard
 1. providing ways to deal with international character sets.
 2. correction of deficiencies
 3. improvement of computational usefulness
#### The C11 Standard
The committee raised some new guiding principles.One was that the "trust the programmer" goal should be tempered somewhat in the face 
of contemporary concerns of programming security and safety.One was that C99 hasn't been as well received and supported by vendors as C90 was.As a consequence, some features of C99 became optional for C11.One reason is that the committee felt that vendors serving the small machine market shouldn't be required to support features not used in their targeted environments.Another observation was that the standard was being revised not because it was broken but because there was a need to track new technologies.One example of this is the addition of optional support for concurrent programming in response to the trend of using multiple processors in computers.
### Programming Mechanics

#### Unix System
Historically, the Unix C compiler, invoked with the __cc__ command, defined the language.But it didn't keep pace with the developing standard, and it has been retired.However, Unix systems typically provide a C compiler from some other source, and then make the __cc__ command an alias for that compiler.So you still can proceed with the same command, even though it may invoke different compilers in different systems.
```bash
$ cc inform.c
$ ls
$ ./a.out
```
#### The GNU Compiler Collection and the LLVM Project
```bash
$ cc -v
$ gcc -std=c99 inform.c
$ gcc -std=c1x inform.c
$ gcc -std=c11 inform.c
```
#### Command-Line Compilers for the PC(Windows package)
 - Cygwin and MinGW:These come with the newest (or near-newest) version of GCC, which supports C99 and at least some of C11.
 - The Borland C++ Compiler 5.5 is another free download;it supports C90.

