CC=gcc
CFLAG=-I.

all: a hello-mt stack-probe

#must is tab in newline start
a:
	$(CC) $(CFLAG) -O1 a.c -o a.out -lpthread

hello-mt:
	gcc -I. -O1 hello-mt.c -o hello-mt.out -lpthread

stack-probe:
	gcc -I. -O1 stack-probe.c -o stack-probe.out -lpthread

clean:
	rm -f a.out hello-mt.out stack-probe.out
