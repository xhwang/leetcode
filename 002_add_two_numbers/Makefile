
CXX=g++
CXXFLAGS=-g -Wall -std=c++11

all: add_two_numbers.o
	$(CXX) -o demo add_two_numbers.o

add_two_numbers.o: add_two_numbers.cpp
	$(CXX) $(CXXFLAGS) -c add_two_numbers.cpp

clean:
	rm -rf *.o demo
