all: a.out

a.out: tests.cpp LLStack.cpp LLStack.h
	g++ -std=c++11 tests.cpp

test: a.out
	./a.out "$(try)"

clean:
	rm a.out
