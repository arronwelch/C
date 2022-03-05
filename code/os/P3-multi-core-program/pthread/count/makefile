all:counter-O0 counter-O1 counter-O2

counter-O0:
	gcc -O0 -o counter-O0.out -I.. counter.c -lpthread

counter-O1:
	gcc -O1 -o counter-O1.out -I.. counter.c -lpthread

counter-O2:
	gcc -O2 -o counter-O2.out -I.. counter.c -lpthread

clean:
	rm *.out
