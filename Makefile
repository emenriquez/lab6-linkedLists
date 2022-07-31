all: a.out

a.out: tests.cpp Lab5.cpp
	g++ -std=c++11 tests.cpp

test: a.out
	./a.out "$(try)"

clean:
	rm a.out
