CFLAGS = -Wall -fpic -coverage -lm -std=c99

testme: testme.c
	gcc  -o testme testme.c $(CFLAGS)

all: testme

clean:
	rm -f *.o *.gcov *.gcda *.gcno *.so *.out testme
