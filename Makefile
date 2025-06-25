# Simple Makefile for Linked List Stack Lab
# Students can use this or just run: g++ -o test main.cpp && ./test

all: test

test: main.cpp LLStack.cpp LLStack.h
	g++ -std=c++11 -o test main.cpp

run: test
	./test

clean:
	rm -f test

.PHONY: run clean
