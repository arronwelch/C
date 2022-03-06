CC=gcc
CFLAG=-I.

all: print

#must is tab in newline start
print:
	$(CC) $(CFLAG) -O1 print.c -o print.out -lpthread
	$(CC) $(CFLAG) -O1 sum_lock.c -o sum_lock.out -lpthread
       

clean:
	rm -f *.out
