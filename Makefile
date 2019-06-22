all:
	gcc -Wall search.h search.c main.c -o prog
	

.PHONY: test
test:
	gcc -Wall -I./vendor/ search.c UnitTests/tmain.c UnitTests/tests.c -o UnitTestsProg