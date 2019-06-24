all:
	gcc -Wall search.h search.c main.c -o prog
	

.PHONY: test
test:
	gcc -Wall -I./ search.c tmain.c tests.c -o TestsProg