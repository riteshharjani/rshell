all: rshell

rshell: main.cpp lib/linenoise.o
	g++ -std=c++11 main.cpp lib/linenoise.o -o rshell
linenoise.o: lib/linenoise.c lib/linenoise.h
	gcc -c lib/linenoise.c -o lib/linenoise.o

clean:
	rm lib/*.o rshell
