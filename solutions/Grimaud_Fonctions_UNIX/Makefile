# Makefile pour UNIX like functions
all: myecho mycat mywc

.PHONY: clean all

myecho: Grimaud_myecho.c
	gcc -o $@ $<

mycat: Grimaud_mycat.c
	gcc -o $@ $<

mywc: Grimaud_mywc.c
	gcc -o $@ $<

clean:
	rm *.o myecho mycat mywc

