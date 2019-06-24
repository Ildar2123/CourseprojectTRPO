all:
	gcc -Wall search.h search.c main.c -o prog
	

.PHONY: test
test:
	gcc -Wall -I./ search.c test/tmain.c test/tests.c -o UnitTestsProg