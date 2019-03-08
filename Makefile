all:
	gcc -g -Wall main.c reader.c word.c dict.c -o reader
run:
	valgrind ./reader.out

